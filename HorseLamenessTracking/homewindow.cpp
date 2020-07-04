#include "homewindow.h"
#include "ui_homewindow.h"
#include "trackingpage.h"
#include "configurationpage.h"

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    /* Connects all the pushbuttons to the button click handlers */
    connect(ui->btnStartNew, SIGNAL(released()), this, SLOT(btnStartNew_Clicked()));
    connect(ui->btnCalibrate, SIGNAL(released()), this, SLOT(btnCalibrate_Clicked()));
    connect(ui->btnLoadVideo, SIGNAL(released()), this, SLOT(btnLoadVideo_Clicked()));
    connect(ui->btnLoadTest, SIGNAL(released()), this, SLOT(btnLoadTest_Clicked()));
    connect(ui->btnCompare, SIGNAL(released()), this, SLOT(btnCompareTests_Clicked()));


}

HomeWindow::~HomeWindow() {
    delete ui;
}

void HomeWindow::btnStartNew_Clicked() {
    TrackingPage trackingPage;
    trackingPage.show();
}
void HomeWindow::btnCalibrate_Clicked() {
    ConfigurationPage configPage;
    configPage.show();
}
void HomeWindow::btnLoadVideo_Clicked() {
    ConfigurationPage configPage(nullptr, true);
    configPage.show();
}
void HomeWindow::btnLoadTest_Clicked() {

}
void HomeWindow::btnCompareTests_Clicked() {

}
