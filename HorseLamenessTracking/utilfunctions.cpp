#include "utilfunctions.h"

/////////////////////////////////////////////////////////////
/// \brief resizeAnImage
/// Self explanitory, resizes a cv::Mat
///
/// \param image
/// Reference to the image we are resizing
///
/// \param height
/// Desired height of the image
///
/// \param width
/// Desired width of the image
///
void resizeAnImage(cv::Mat& image, int height, int width) {
    cv::resize(image, image, cv::Size(height, width));
}

/////////////////////////////////////////////////////////////
/// \brief intToString
/// Converts an int to a string using stringstream
///
/// \param number
/// The int to be converted to a string
///
/// \return
/// The number as a string
///
std::string intToString(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

/////////////////////////////////////////////////////////////
/// \brief toQString
/// Converts a std::string to a QString for easy compatibility
///
/// \param string
/// A std::string
///
/// \return
/// A QString made from the std::string
///
QString toQString(std::string string) {
    return QString::fromStdString(string);
}

/////////////////////////////////////////////////////////////
/// \brief toQString
/// Converts a const wchar_t* to a QString
///
/// \param string
/// The const wchar_t*
///
/// \return
/// A QString made from the const wchar_t*
///
QString toQString(const wchar_t* string) {
    return QString::fromWCharArray(string);
}

/////////////////////////////////////////////////////////////
/// \brief QStringToStdString
/// Converts a QString to a std::string
///
/// \param string
/// The QString to convert to a std::string
///
/// \return
/// The converted std::string
///
std::string QStringToStdString(QString string) {
    return string.toLocal8Bit().constData();
}

/////////////////////////////////////////////////////////////
/// \brief checkIfMarkerIsClose
/// Check if the marker is close enough to another for it to
/// be in that graph
///
/// \param frame
/// The frame number the marker is detected on
///
/// \param marker
/// The marker to check
///
/// \param object
/// The detected object to check if it is close
///
/// \return
/// A boolean for if the marker is close or not
///
bool checkIfMarkerIsClose(int frame, cv::Point marker, cv::Point object) {
    if (abs(marker.x - object.x) > 20 || abs(marker.y - object.y) > 20) // I need to find a multiplyer that includes frame as if it loses the marker in its current state there is no way that it will be able to find it again after a couple of frames
        return false;
    return true;
}

/////////////////////////////////////////////////////////////
/// \brief findClosestMarker
/// Finds the marker that's closest to the xy point sent
///
/// \param frame
/// The frame number the marker is detected on
///
/// \param markers
/// A reference to the list of markers to check
///
/// \param xy
/// The point that the marker was detected at
///
/// \return
/// The pointer to the marker it was closest to
///
Marker* findClosestMarker(int frame, std::list<Marker*>& markers, cv::Point xy) {
    for (auto it = markers.begin(); it != markers.end(); ++it)
        if (checkIfMarkerIsClose(frame, (*it)->getLastPoint(), xy))
            return *it;
    return nullptr;
}

/////////////////////////////////////////////////////////////
/// \brief checkIfMarkerIsNew
/// Checks if a marker detected has been detected before or
/// is a new marker that needs to be added to the list
///
/// \param frame
/// Frame in the video
///
/// \param markers
/// List of markers to add to
///
/// \param m
/// The marker to check
///
/// \param posX
/// Position x of the marker
///
/// \param posY
/// Position y of the marker
///
void checkIfMarkerIsNew(int frame, std::list<Marker*>& markers, Marker* m, int posX, int posY) {
    if (m != nullptr && m->getLastFrame() != frame) {
        m->addPosition(frame, cv::Point(posX, posY));
        return;
    }
    markers.push_back(new Marker(frame, posX, posY));
}

/////////////////////////////////////////////////////////////
/// \brief checkIfFirstMarker
/// Checks if the marker detected is the first one detected
///
/// \param frame
/// The frame the marker was detected on
///
/// \param markers
/// The marker list to check
///
/// \param posX
/// The x position of the object detected
///
/// \param posY
/// The y position of the object detected
///
/// \return
/// A bool whether the marker is the first one or not
///
bool checkIfFirstMarker(int frame, std::list<Marker*>& markers, int posX, int posY) {
    if (markers.size() == 0) { // if the marker list has markers in it find the closest marker and then add the new point to it
        markers.push_back(new Marker(frame, posX, posY));
        return true;
    }
    return false;
}

/////////////////////////////////////////////////////////////
/// \brief drawObject
/// Draws the object on the screen onto the current original
/// image
///
/// \param theObjects
/// Draw all the detected markers on the image
///
/// \param frame
/// The frame taken from the camera
///
void drawObject(std::vector<cv::Point> theObjects, cv::Mat& frame) {
    for (int i = 0; i < theObjects.size(); i++) {
        cv::circle(frame, cv::Point(theObjects[i].x, theObjects[i].y), 10, cv::Scalar(0, 0, 255));
        cv::putText(frame, intToString(theObjects[i].x) + " , " + intToString(theObjects[i].y), cv::Point(theObjects[i].x, theObjects[i].y + 20), 1, 1, cv::Scalar(0, 255, 0));
        cv::putText(frame, "Object " + i, cv::Point(theObjects[i].x, theObjects[i].y - 30), 1, 2, cv::Scalar(0, 255, 0));
    }
}

/////////////////////////////////////////////////////////////
/// \brief morphOps
/// Erodes and dilates the threshold image
///
/// \param thresh
/// The threshold image
///
void morphOps(cv::Mat& thresh) {
    cv::Mat erodeElement = getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(1, 1));
    cv::Mat dilateElement = getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));

    cv::erode(thresh, thresh, erodeElement);
    cv::erode(thresh, thresh, erodeElement);

    cv::dilate(thresh, thresh, dilateElement);
    cv::dilate(thresh, thresh, dilateElement);
}

/////////////////////////////////////////////////////////////
/// \brief trackFilteredObject
/// Tracks markers on an image or draws them on the image
/// without tracking
///
/// \param markerLst
/// The lst of markers to add to
///
/// \param frame
/// The frame we are currently on
///
/// \param threshold
/// The threshold image with the background already removed
///
/// \param cameraFeed
/// The video straight from the camera to draw onto
///
/// \remarks
/// This function is still too busy and I'd like to make it do less
///
void trackFilteredObject(std::list<Marker*>& markerLst, int frame, cv::Mat threshold, cv::Mat& cameraFeed, bool isTracking = false) {
    std::vector <cv::Point> objects;
    cv::Mat temp;
    threshold.copyTo(temp);
    //these two vectors needed for output of findContours
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    //find contours of filtered image using openCV findContours function
    cv::findContours(temp, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);

    if (hierarchy.size() <= 0)
        return;

    //if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
    if (hierarchy.size() <= MAX_NUM_OBJECTS) {
        putText(cameraFeed, "TOO MUCH NOISE! ADJUST FILTER", cv::Point(0, 50), 1, 2, cv::Scalar(0, 0, 255), 2);
        return;
    }

    for (int index = 0; index >= 0; index = hierarchy[index][0]) {
        // get all the moment at i
        cv::Moments moment = moments((cv::Mat)contours[index]);
        double area = moment.m00;

        //if the area is less than 20 px by 20px then it is probably just noise
        //if the area is the same as the 3/2 of the image size, probably just a bad filter
        if (area > MIN_OBJECT_AREA && area < MAX_OBJECT_AREA)
            continue;

        int posX = moment.m10 / area; int posY = moment.m01 / area;

        if(isTracking) {
            if(!checkIfFirstMarker(frame, markerLst, posX, posY)) {
                Marker* m = findClosestMarker(frame, markerLst, cv::Point(posX, posY));
                checkIfMarkerIsNew(frame, markerLst, m, posX, posY);
            }
        }

        objects.push_back(cv::Point(posX, posY));
    }

    //let user know you found an object
    if (objects.size() > 0) {
        //draw object location on screen
        drawObject(objects, cameraFeed);
    }
}
