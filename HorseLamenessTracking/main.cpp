#include "homewindow.h"

#include <QApplication>
#include <vector>

int main(int argc, char *argv[])
{
    cv::VideoCapture *mainCamera = new cv::VideoCapture(),
                     *secondCamera = new cv::VideoCapture(),
                     *thirdCamera = new cv::VideoCapture(),
                     *fourthCamera = new cv::VideoCapture(); // change later

    webCamList.clear();
    if (mainCamera->open(0))
        webCamList.push_back(mainCamera);
    if (secondCamera->open(1))
        webCamList.push_back(secondCamera);
    if (thirdCamera->open(2))
        webCamList.push_back(thirdCamera);
    if (fourthCamera->open(3))
        webCamList.push_back(fourthCamera);

    QApplication a(argc, argv);
    HomeWindow w;
    w.show();
    return a.exec();
}
