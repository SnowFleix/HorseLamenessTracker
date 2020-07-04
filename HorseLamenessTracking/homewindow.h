#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include <QFileDialog> // /used for allowing the user to select a file
#include <opencv2/opencv.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class HomeWindow; }
QT_END_NAMESPACE

class HomeWindow : public QMainWindow
{
    Q_OBJECT

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
    cv::VideoCapture _mainCamera, _secondCamera, _thirdCamera, _fourthCamera;
};
#endif // HOMEWINDOW_H
