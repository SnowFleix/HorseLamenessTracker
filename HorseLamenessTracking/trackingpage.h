#ifndef TRACKINGPAGE_H
#define TRACKINGPAGE_H

//QT Libraries
#include <QWidget>

namespace Ui {
class TrackingPage;
}

class TrackingPage : public QWidget
{
    Q_OBJECT

public:
    explicit TrackingPage(QWidget *parent = nullptr);
    ~TrackingPage();

private slots: // start stop calibrate back
     void btnStart_Clicked();
     void btnStop_Clicked();
     void btnCalibrate_Clicked();
     void btnBack_Clicked();

private:
    Ui::TrackingPage *ui;
    bool isTracking = false;
};

#endif // TRACKINGPAGE_H
