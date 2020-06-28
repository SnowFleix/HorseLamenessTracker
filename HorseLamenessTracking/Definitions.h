#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <qimage.h>

// global variables used to change the HSV filers
const int H_MIN = 70;
const int H_MAX = 179;
const int S_MIN = 11;
const int S_MAX = 56;
const int V_MIN = 245;
const int V_MAX = 255;

// max number of objects that can be tracked in one image
const int MAX_NUM_OBJECTS = 99999;

// min and max object areas
const int MIN_OBJECT_AREA = 5 * 5;
const int MAX_OBJECT_AREA = 150 * 150;

// this default image is used when there is no camera connected to the PC
const QImage defaultIamage = QImage("UI/CameraNotConnected.png");

#endif // DEFINITIONS_H
