#include "configurationpage.h"
#include "ui_configurationpage.h"

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::ConfigurationPage
/// Default constructor, connects all the ui elements to
/// functions in the class
///
/// \param parent
/// The parent widget that called this constructor
///
/// \param isVideo
/// Set to true if the user is viewing a video
///
ConfigurationPage::ConfigurationPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigurationPage)
{
    ui->setupUi(this);

    // connect the colour changing buttons to their slots
    connect(ui->btnRed, SIGNAL(released()), this, SLOT(btnRed_Click()));
    connect(ui->btnBlue, SIGNAL(released()), this, SLOT(btnBlue_Click()));
    connect(ui->btnYellow, SIGNAL(released()), this, SLOT(btnYellow_Click()));
    connect(ui->btnGreen, SIGNAL(released()), this, SLOT(btnGreen_Click()));
    connect(ui->btnBlack, SIGNAL(released()), this, SLOT(btnBlack_Click()));
    connect(ui->btnWhite, SIGNAL(released()), this, SLOT(btnWhite_Click()));

    // connect the finish and pause button to their slots
    connect(ui->btnPause, SIGNAL(released()), this, SLOT(btnPause_Click()));
    connect(ui->btnSubmit, SIGNAL(released()), this, SLOT(btnFinish_Click()));

    // connect the sliders for changing the HSV values to their slots
    connect(ui->horizontalSliderHMax, SIGNAL(valueChanged(int)), this, SLOT(h_max_Changed(int)));
    connect(ui->horizontalSliderHMin, SIGNAL(valueChanged(int)), this, SLOT(h_min_Changed(int)));
    connect(ui->horizontalSliderSMax, SIGNAL(valueChanged(int)), this, SLOT(s_max_Changed(int)));
    connect(ui->horizontalSliderSMin, SIGNAL(valueChanged(int)), this, SLOT(s_min_Changed(int)));
    connect(ui->horizontalSliderVMax, SIGNAL(valueChanged(int)), this, SLOT(v_max_Changed(int)));
    connect(ui->horizontalSliderVMin, SIGNAL(valueChanged(int)), this, SLOT(v_min_Changed(int)));

    // add ticks to the bottom of the sliders
    ui->horizontalSliderHMax->setTickPosition(QSlider::TicksBelow);
    ui->horizontalSliderHMin->setTickPosition(QSlider::TicksBelow);
    ui->horizontalSliderSMax->setTickPosition(QSlider::TicksBelow);
    ui->horizontalSliderSMin->setTickPosition(QSlider::TicksBelow);
    ui->horizontalSliderVMax->setTickPosition(QSlider::TicksBelow);
    ui->horizontalSliderVMin->setTickPosition(QSlider::TicksBelow);

    // Connect the worker to the thread
    GraphicsWorker *worker = new GraphicsWorker({ui->graphicsViewVideoFeed});

    connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), worker, SLOT(process()));
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::~ConfigurationPage
/// Default destructor, generated by QT
///
ConfigurationPage::~ConfigurationPage()
{
    delete ui;
}

// TODO : Check if all these are accurate

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::btnRed_Click
/// Handles the user changing the colour to red
///
void ConfigurationPage::btnRed_Click() {
    H_MIN = 0; H_MAX = 5; S_MIN = 75; S_MAX = 125; V_MIN = 75; V_MAX = 125;
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::btnBlue_Click
/// Handles the user changing the colour to blue
///
void ConfigurationPage::btnBlue_Click() {
    H_MIN = 225; H_MAX = 255; S_MIN = 75; S_MAX = 125; V_MIN = 75; V_MAX = 125;
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::btnYellow_Click
/// Handles the user changint the colour to yellow
///
void ConfigurationPage::btnYellow_Click() {
    H_MIN = 50; H_MAX = 70; S_MIN = 75; S_MAX = 125; V_MIN = 75; V_MAX = 125;
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::btnGreen_Click
/// Handles the user changint the colour to green
///
void ConfigurationPage::btnGreen_Click() {
    H_MIN = 100; H_MAX = 135; S_MIN = 75; S_MAX = 125; V_MIN = 75; V_MAX = 125;
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::btnBlack_Click
/// Handles the user changint the colour to black
///
void ConfigurationPage::btnBlack_Click() {
    H_MIN = 0; H_MAX = 0; S_MIN = 0; S_MAX = 0; V_MIN = 0; V_MAX = 0;
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::btnWhite_Click
/// Handles the user changint the colour to white
///
void ConfigurationPage::btnWhite_Click() {
    H_MIN = 0; H_MAX = 0; S_MIN = 0; S_MAX = 0; V_MIN = 100; V_MAX = 100;
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::btnPause_Click
/// Handles the user pausing the video
///
void ConfigurationPage::btnPause_Click() {
    // make sure we're in video mode
    if (_isVideo) {

    }
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::btnFinish_Click
/// Handles the user closing the page after finishing
///
void ConfigurationPage::btnFinish_Click() {
    close();
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::h_max_Changed
/// Handles the user changing the hmax value
///
/// \param hue
/// The maximum hue for cv::inrange
///
void ConfigurationPage::h_max_Changed(int hue) {
    H_MAX = hue;
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::h_min_Changed
/// Handles the user changing the hmin value
///
/// \param hue
/// The minimum hue for cv::inrange
///
void ConfigurationPage::h_min_Changed(int hue) {
    H_MIN = hue;
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::s_max_Changed
/// Handles the user changing the smax value
///
/// \param saturation
/// The maximum saturation for cv::inrange
///
void ConfigurationPage::s_max_Changed(int saturation) {
    S_MAX = saturation;
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::s_min_Changed
/// Handles teh user changing the smin value
///
/// \param saturation
/// The minimum saturation for cv::inrange
///
void ConfigurationPage::s_min_Changed(int saturation) {
    S_MIN = saturation;
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::v_max_Changed
/// Handles the user changing the vmax value
///
/// \param value
/// The maximum 'value' for cv:inrange
///
void ConfigurationPage::v_max_Changed(int value) {
    V_MAX = value;
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::v_min_Changed
/// Handles teh user changing the vmin value
///
/// \param value
/// The minimum 'value' for cv::inrange
///
void ConfigurationPage::v_min_Changed(int value) {
    V_MIN = value;
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::open
///
///
/// \param isVideo
/// A bool representing if the video is loaded from a video file
/// or taken directly from the webcam
///
void ConfigurationPage::open(bool isVideo) {
    _isVideo = isVideo;

    // if the user is not viewing a video, hide the pause button
    if (!_isVideo)
        ui->btnPause->setVisible(false);

    // call the base function for show
    this->show();
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::operator ()
/// Just sets the parent widget to the passed widget
///
/// \param parent
/// The parent widget that we want to reopen on close
///
void ConfigurationPage::operator()(QWidget *parent) {
    _parent = parent;
}

/////////////////////////////////////////////////////////////
/// \brief ConfigurationPage::closeEvent
/// Overrides the on closeEvent to reopen the parent widget
/// if there was one
///
/// \param event
/// Default QCloseEvent given by QT
///
void ConfigurationPage::closeEvent(QCloseEvent *event) {
    if(_parent) _parent->show();
    event->accept();
}
