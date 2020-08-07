#ifndef UTILFUNCTIONS_H
#define UTILFUNCTIONS_H

#pragma once

//QT Libraries
#include <QtCore/qglobal.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QImage>

//STL Libraries
#include <vector>

//OpenCV Libraries
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//Header Files
#include "object.h"
#include "marker.h"
#include "Definitions.h"

namespace util {
    void resizeAnImage(cv::Mat& image, int height, int width);
    // simple int to string function
    std::string intToString(int number);
    QImage matToImage(cv::Mat mat);
    QGraphicsScene* getSceneFromImage(QImage background);
    // function to check if the marker is close enough to another for it to be in that graph
    // TOTO: add multiplyer for frame where
    bool checkIfMarkerIsClose(int frame, cv::Point marker, cv::Point object);
    // finds the marker that's closest to the xy point sent
    Marker* findClosestMarker(int frame, std::list<Marker*>& markers, cv::Point xy);
    // draws the object on the screen onto the current origional image
    void drawObject(std::vector<Object> theObjects, cv::Mat &frame);
    void morphOps(cv::Mat &thresh);
    void trackFilteredObject(std::list<Marker*>& markerLst, int frame, cv::Mat threshold, cv::Mat &cameraFeed);
    void displayMarkersOnScreen(cv::Mat threshold, cv::Mat &cameraFeed);
}

#endif // UTILFUNCTIONS_H
