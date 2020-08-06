#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <qimage.h>
#include <vector>
#include <opencv2/opencv.hpp>

// global variables used to change the HSV filers
static int H_MIN = 70;
static int H_MAX = 179;
static int S_MIN = 11;
static int S_MAX = 56;
static int V_MIN = 245;
static int V_MAX = 255;

// max number of objects that can be tracked in one image
const int MAX_NUM_OBJECTS = 99999;

// min and max object areas
const int MIN_OBJECT_AREA = 5 * 5;
const int MAX_OBJECT_AREA = 150 * 150;

// this default image is used when there is no camera connected to the PC
const QImage defaultIamage = QImage("UI/CameraNotConnected.png");

// quick hack to be able to share the different webcams on each UI
static std::vector<cv::VideoCapture*> webCamList = {nullptr, nullptr, nullptr, nullptr};

#endif // DEFINITIONS_H
