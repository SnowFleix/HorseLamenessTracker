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
    if (hierarchy.size() > MAX_NUM_OBJECTS) {
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

        int posX = moment.m10 / area;
        int posY = moment.m01 / area;

        if(isTracking) {

        }

        objects.push_back(cv::Point(posX, posY));
    }

    //let user know you found an object
    if (objects.size() > 0) {
        //draw object location on screen
        drawObject(objects, cameraFeed);
    }
}
