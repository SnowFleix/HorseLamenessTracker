#include "homewindow.h"
#include "ui_homewindow.h"

/////////////////////////////////////////////////////////////
/// \brief HomeWindow::HomeWindow
/// Default constructor, connects all the ui elements to
/// functions in the class
///
/// \param parent
/// The parent widget that called this constructor
///
HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{

    // set the parent of the config page to this widget
    configPage(this);
    ui->setupUi(this);
    /* Connects all the pushbuttons to the button click handlers */
    connect(ui->btnStartNew, SIGNAL(released()), this, SLOT(btnStartNew_Clicked()));
    connect(ui->btnCalibrate, SIGNAL(released()), this, SLOT(btnCalibrate_Clicked()));
    connect(ui->btnLoadVideo, SIGNAL(released()), this, SLOT(btnLoadVideo_Clicked()));
    connect(ui->btnLoadTest, SIGNAL(released()), this, SLOT(btnLoadTest_Clicked()));
    connect(ui->btnCompare, SIGNAL(released()), this, SLOT(btnCompareTests_Clicked()));
}

/////////////////////////////////////////////////////////////
/// \brief HomeWindow::~HomeWindow
/// Default destructor, makes sure the thread is close
///
HomeWindow::~HomeWindow() {
    delete ui;
    _updateGraphicsViews.quit();
    _updateGraphicsViews.wait();
}

/////////////////////////////////////////////////////////////
/// \brief HomeWindow::btnStartNew_Clicked
/// Handles the user starting a new recording
///
void HomeWindow::btnStartNew_Clicked() {
    //TrackingPage trackingPage;
    //trackingPage.show();
}

/////////////////////////////////////////////////////////////
/// \brief HomeWindow::btnCalibrate_Clicked
/// Opens the calibrartion page
///
void HomeWindow::btnCalibrate_Clicked() {
    configPage.open(false);
    this->hide();
}

/////////////////////////////////////////////////////////////
/// \brief HomeWindow::btnLoadVideo_Clicked
/// Handles the user loading the user loading a video from
/// file
///
void HomeWindow::btnLoadVideo_Clicked() {
    configPage.open(true);
    this->hide();
}

/////////////////////////////////////////////////////////////
/// \brief HomeWindow::btnLoadTest_Clicked
///
void HomeWindow::btnLoadTest_Clicked() {

}

/////////////////////////////////////////////////////////////
/// \brief HomeWindow::btnCompareTests_Clicked
///
void HomeWindow::btnCompareTests_Clicked() {

}

/////////////////////////////////////////////////////////////
/// \brief HomeWindow::updateFrames
///
void HomeWindow::updateFrames() {
    cv::Mat frame;
    ui->graphicsViewCamera1->setScene(util::getSceneFromImage(util::matToImage(frame)));
    *webCamList[1] >> frame;
    ui->graphicsViewCamera2->setScene(util::getSceneFromImage(util::matToImage(frame)));
    *webCamList[2] >> frame;
    ui->graphicsViewCamera3->setScene(util::getSceneFromImage(util::matToImage(frame)));
    *webCamList[3] >> frame;
    ui->graphicsViewCamera4->setScene(util::getSceneFromImage(util::matToImage(frame)));
}
