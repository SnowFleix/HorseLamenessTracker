#include "homewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    cv::VideoCapture mainCamera, secondCamera, thirdCamera, fourthCamera; // change later

    webCamList.clear();
    if (mainCamera.open(0))
        webCamList.push_back(mainCamera);
    if (secondCamera.open(1))
        webCamList.push_back(secondCamera);
    if (thirdCamera.open(2))
        webCamList.push_back(thirdCamera);
    if (fourthCamera.open(3))
        webCamList.push_back(fourthCamera);

    QApplication a(argc, argv);
    HomeWindow w;
    w.show();
    return a.exec();
}
