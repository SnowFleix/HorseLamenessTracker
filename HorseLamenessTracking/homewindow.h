#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

//QT Libraries
#include <QMainWindow>
#include <QThread>
#include <QPixmap>
#include <QFileDialog> // /used for allowing the user to select a file
#include <QGraphicsPixmapItem>
#include <QGraphicsView>

// OpenCV Libraries
#include <opencv2/opencv.hpp>

// My headers
#include "configurationpage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HomeWindow; }
QT_END_NAMESPACE

class HomeWindow : public QMainWindow
{
    Q_OBJECT
    QThread _displayVideoThread;
public:
    HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();
private slots:
    void btnStartNew_Clicked();
    void btnCalibrate_Clicked();
    void btnLoadVideo_Clicked();
    void btnLoadTest_Clicked();
    void btnCompareTests_Clicked();
private:
    Ui::HomeWindow *ui;
    ConfigurationPage configPage; // quick fix change later
    cv::VideoCapture _mainCamera, _secondCamera, _thirdCamera, _fourthCamera;
    void updateFrames();
};
#endif // HOMEWINDOW_H
