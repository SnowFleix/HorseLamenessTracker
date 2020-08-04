#ifndef UTILFUNCTIONS_H
#define UTILFUNCTIONS_H

#include "object.h"
#include "marker.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <vector>

void resizeAnImage(cv::Mat& image, int height, int width) {
    cv::resize(image, image, cv::Size(height, width));
}

// simple int to string function
std::string intToString(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

// function to check if the marker is close enough to another for it to be in that graph
// TOTO: add multiplyer for frame where
bool checkIfMarkerIsClose(int frame, cv::Point marker, cv::Point object) {
    if (abs(marker.x - object.x) > 20 || abs(marker.y - object.y) > 20) // I need to find a multiplyer that includes frame as if it loses the marker in its current state there is no way that it will be able to find it again after a couple of frames
        return false;
    return true;
}

// finds the marker that's closest to the xy point sent
Marker* findClosestMarker(int frame, std::list<Marker*>& markers, cv::Point xy) {
    for (auto it = markers.begin(); it != markers.end(); ++it)
        if (checkIfMarkerIsClose(frame, (*it)->getLastPoint(), xy))
            return *it;
    return nullptr;
}

// draws the object on the screen onto the current origional image
void drawObject(std::vector<Object> theObjects, cv::Mat &frame) {
    for (int i = 0; i < theObjects.size(); i++) {
        cv::circle(frame, cv::Point(theObjects.at(i).getXPos(), theObjects.at(i).getYPos()), 10, cv::Scalar(0, 0, 255));
        cv::putText(frame, intToString(theObjects.at(i).getXPos()) + " , " + intToString(theObjects.at(i).getYPos()), cv::Point(theObjects.at(i).getXPos(), theObjects.at(i).getYPos() + 20), 1, 1, cv::Scalar(0, 255, 0));
        cv::putText(frame, "Object " + i, cv::Point(theObjects.at(i).getXPos(), theObjects.at(i).getYPos() - 30), 1, 2, cv::Scalar(0, 255, 0));
    }
}

void morphOps(cv::Mat &thresh) {
    cv::Mat erodeElement = getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(1, 1));
    cv::Mat dilateElement = getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));

    cv::erode(thresh, thresh, erodeElement);
    cv::erode(thresh, thresh, erodeElement);

    cv::dilate(thresh, thresh, dilateElement);
    cv::dilate(thresh, thresh, dilateElement);
}

void trackFilteredObject(std::list<Marker*>& markerLst, int frame, cv::Mat threshold, cv::Mat &cameraFeed) {
    std::vector <Object> objects;
    cv::Mat temp;
    threshold.copyTo(temp);
    //these two vectors needed for output of findContours
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    //find contours of filtered image using openCV findContours function
    cv::findContours(temp, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
    bool objectFound = false;
    if (hierarchy.size() > 0) {

        //if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
        if (hierarchy.size() < MAX_NUM_OBJECTS) {

            for (int index = 0; index >= 0; index = hierarchy[index][0]) {

                cv::Moments moment = moments((cv::Mat)contours[index]);
                double area = moment.m00;
                //if the area is less than 20 px by 20px then it is probably just noise
                //if the area is the same as the 3/2 of the image size, probably just a bad filter
                if (area > MIN_OBJECT_AREA && area < MAX_OBJECT_AREA)
                {
                    Object object;

                    object.setXPos(moment.m10 / area);
                    object.setYPos(moment.m01 / area);

                    //probably won't work as markers come onto the screen and then get detected at different times
                    //need to make a way that if a marker gets detected in a new area it will add a new marker to the list
                    if (markerLst.size() > 0) { // if the marker list has markers in it find the closest marker and then add the new point to it
                        Marker* m = findClosestMarker(frame, markerLst, cv::Point(object.getXPos(), object.getYPos()));
                        if (m != nullptr) {
                            if (m->getLastFrame() != frame)
                                m->addPosition(frame, cv::Point(object.getXPos(), object.getYPos()));
                        }
                        else
                            markerLst.push_back(new Marker(frame, object.getXPos(), object.getYPos()));
                    }
                    else
                        markerLst.push_back(new Marker(frame, object.getXPos(), object.getYPos()));

                    objects.push_back(object);

                    objectFound = true;

                }
                else objectFound = false;
            }
            //let user know you found an object
            if (objectFound == true) {
                //draw object location on screen
                drawObject(objects, cameraFeed);
            }
        }
        else putText(cameraFeed, "TOO MUCH NOISE! ADJUST FILTER", cv::Point(0, 50), 1, 2, cv::Scalar(0, 0, 255), 2);
    }
}

void displayMarkersOnScreen(cv::Mat threshold, cv::Mat &cameraFeed) {
    std::vector <Object> objects;
    cv::Mat temp;
    threshold.copyTo(temp);
    //these two vectors needed for output of findContours
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    //find contours of filtered image using openCV findContours function
    cv::findContours(temp, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
    //use moments method to find our filtered object
    bool objectFound = false;
    if (hierarchy.size() > 0) {
        int numObjects = hierarchy.size();
        //if number of objects greater than MAX_NUM_OBJECTS then there is too much noise in the image
        if (numObjects < MAX_NUM_OBJECTS) {

            for (int index = 0; index >= 0; index = hierarchy[index][0]) {

                cv::Moments moment = moments((cv::Mat)contours[index]);
                double area = moment.m00;
                // if the area is less than 20 px by 20px then it is probably just noise
                // if the area is the same as the 3/2 of the image size, probably just a bad filter
                if (area > MIN_OBJECT_AREA && area < MAX_OBJECT_AREA)
                {
                    Object object;

                    object.setXPos(moment.m10 / area);
                    object.setYPos(moment.m01 / area);

                    objects.push_back(object);

                    objectFound = true;

                }
                else objectFound = false;
            }
            if (objectFound == true) {
                // draw object on the screen
                drawObject(objects, cameraFeed);
            }
        }
        else putText(cameraFeed, "TOO MUCH NOISE! ADJUST FILTER", cv::Point(0, 50), 1, 2, cv::Scalar(0, 0, 255), 2);
    }
}

#endif // UTILFUNCTIONS_H
