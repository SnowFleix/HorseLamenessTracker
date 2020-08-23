#include "trackingworker.h"

/////////////////////////////////////////////////////////////
/// \brief TrackingWorker::TrackingWorker
/// Default constructor, copies the parameters into the
/// private variables
///
/// \param markers
/// The list of markers to add to
///
/// \param frame
/// The frame the video stream is on
///
TrackingWorker::TrackingWorker(std::vector<Marker*>& markers, int frame, cv::Point xy) : markers_(markers), frame_(frame), xy_(xy) { }

/////////////////////////////////////////////////////////////
/// \brief checkIfMarkerIsClose
/// Check if the marker is close enough to another for it to
/// be in that graph
///
/// \param frame
/// The frame number the marker is detected on
///
/// \param marker
/// The marker to check
///
/// \param object
/// The detected object to check if it is close
///
/// \return
/// A boolean for if the marker is close or not
///
bool TrackingWorker::checkIfMarkerIsClose(cv::Point marker) {
    if (abs(marker.x - xy_.x) > 20 || abs(marker.y - xy_.y) > 20) // I need to find a multiplyer that includes frame as if it loses the marker in its current state there is no way that it will be able to find it again after a couple of frames
        return false;
    return true;
}

/////////////////////////////////////////////////////////////
/// \brief findClosestMarker
/// Finds the marker that's closest to the xy point sent
///
/// \param frame
/// The frame number the marker is detected on
///
/// \param markers
/// A reference to the list of markers to check
///
/// \param xy
/// The point that the marker was detected at
///
/// \return
/// The pointer to the marker it was closest to
///
Marker* TrackingWorker::findClosestMarker() {
    for (auto it = markers_.begin(); it != markers_.end(); ++it)
        if (checkIfMarkerIsClose((*it)->getLastPoint()))
            return *it;
    return nullptr;
}

/////////////////////////////////////////////////////////////
/// \brief checkIfMarkerIsNew
/// Checks if a marker detected has been detected before or
/// is a new marker that needs to be added to the list
///
/// \param frame
/// Frame in the video
///
/// \param markers
/// List of markers to add to
///
/// \param m
/// The marker to check
///
/// \param posX
/// Position x of the marker
///
/// \param posY
/// Position y of the marker
///
void TrackingWorker::checkIfMarkerIsNew(Marker* m) {
    if (m != nullptr && m->getLastFrame() != frame_) {
        m->addPosition(frame_, cv::Point(xy_.x, xy_.y));
        return;
    }
    markers_.push_back(new Marker(frame_, xy_.x, xy_.y));
}

/////////////////////////////////////////////////////////////
/// \brief checkIfFirstMarker
/// Checks if the marker detected is the first one detected
///
/// \param frame
/// The frame the marker was detected on
///
/// \param markers
/// The marker list to check
///
/// \param posX
/// The x position of the object detected
///
/// \param posY
/// The y position of the object detected
///
/// \return
/// A bool whether the marker is the first one or not
///
bool TrackingWorker::checkIfFirstMarker() {
    if (markers_.size() == 0) { // if the marker list has markers in it find the closest marker and then add the new point to it
        markers_.push_back(new Marker(frame_, xy_.x, xy_.y));
        return true;
    }
    return false;
}

/////////////////////////////////////////////////////////////
/// \brief TrackingWorker::process
///
void TrackingWorker::process() {
    if(checkIfFirstMarker())
        return;
    Marker* m = findClosestMarker();
    checkIfMarkerIsNew(m);
}

/////////////////////////////////////////////////////////////
/// \brief TrackingWorker::finished
///
void TrackingWorker::finished() {

}

/////////////////////////////////////////////////////////////
/// \brief TrackingWorker::error
///
///
/// \param error
///
void TrackingWorker::error(QString error) {

}
