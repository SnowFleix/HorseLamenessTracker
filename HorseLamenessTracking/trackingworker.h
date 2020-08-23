#ifndef TRACKINGWORKER_H
#define TRACKINGWORKER_H

#include "marker.h"

class TrackingWorker
{
public:
    TrackingWorker(std::vector<Marker*>& markers, int frame, cv::Point xy);
    bool checkIfMarkerIsClose(cv::Point marker);
    Marker* findClosestMarker();
    void checkIfMarkerIsNew(Marker* m);
    bool checkIfFirstMarker();

private:
    std::vector<Marker*>& markers_;
    int frame_;
    cv::Point xy_;
};

#endif // TRACKINGWORKER_H
