#ifndef TRACKINGWORKER_H
#define TRACKINGWORKER_H

// QT Libraries
#include <QObject>

//
#include "marker.h"

class TrackingWorker : public QObject {
     Q_OBJECT
public:
    TrackingWorker(std::vector<Marker*>& markers, int frame, cv::Point xy);
    bool checkIfMarkerIsClose(cv::Point marker);
    Marker* findClosestMarker();
    void checkIfMarkerIsNew(Marker* m);
    bool checkIfFirstMarker();

public slots:
    void process();

signals:
    void finished();
    void error(QString error);

private:
    std::vector<Marker*>& markers_;
    int frame_;
    cv::Point xy_;
};

#endif // TRACKINGWORKER_H
