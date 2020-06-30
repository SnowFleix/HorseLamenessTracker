#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <list>
#include <opencv2/opencv.hpp>

class Object
{
public:
    Object();
    ~Object(void);

    int getXPos();
    void setXPos(int x);

    int getYPos();
    void setYPos(int y);

private:
    int xPos, yPos;
};

#endif // OBJECT_H
