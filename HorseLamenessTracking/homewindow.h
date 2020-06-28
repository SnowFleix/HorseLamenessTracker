#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
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
};
#endif // HOMEWINDOW_H
