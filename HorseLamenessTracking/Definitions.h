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
static std::vector<cv::VideoCapture> webCamList;

/*
// Used to stop the duplication of code, so I can quickly set the HSV values
void ChangeHSVValues(int _h_min,
                     int _h_max,
                     int _s_min,
                     int _s_max,
                     int _v_min,
                     int _v_max) {
    H_MIN = _h_min;
    H_MAX = _h_max;
    S_MIN = _s_min;
    S_MAX = _s_max;
    V_MIN = _v_min;
    V_MAX = _v_max;
}*/

#endif // DEFINITIONS_H
