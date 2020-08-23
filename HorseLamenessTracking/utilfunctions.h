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
#include "Definitions.h"
#include "trackingworker.h"

namespace util {
    void resizeAnImage(cv::Mat& image, int height, int width);
    // simple int to string function
    std::string intToString(int number);
    QString toQString(std::string string);
    QString toQString(const wchar_t* string);
    std::string QStringToStdString(QString string);
    void drawObject(std::vector<cv::Point> theObjects, cv::Mat &frame);
    void morphOps(cv::Mat &thresh);
    void trackFilteredObject(std::list<Marker*>& markerLst, int frame, cv::Mat threshold, cv::Mat &cameraFeed);
    void displayMarkersOnScreen(cv::Mat threshold, cv::Mat &cameraFeed);
}

#endif // UTILFUNCTIONS_H
