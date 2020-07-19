#ifndef MARKER_H
#define MARKER_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class Marker
{
public:
    Marker();
    Marker(int frame, int x, int y) { xyPos->insert(std::pair<int, cv::Point>(frame, cv::Point(x, y))); }
    ~Marker(void);

    std::map<int, cv::Point>* getPositions() { return xyPos; }
    void addPosition(int frame, cv::Point p) { xyPos->insert(std::pair<int, cv::Point>(frame, p)); }
    std::list<std::string> getPointsForFile() {
        std::list<std::string> plst;
        for (std::map<int, cv::Point >::iterator ptr = (*xyPos).begin(); ptr != (*xyPos).end(); std::advance(ptr, 1))
            plst.push_back(std::to_string((*ptr).second.x) + " " + std::to_string((*ptr).second.y) + "\n");
        return plst;
    }
    std::vector<cv::Point> getPointsFromMap() {
        std::vector<cv::Point> retV;
        for (std::map<int, cv::Point>::iterator itr = xyPos->begin(); itr != xyPos->end(); ++itr)
            retV.push_back(itr->second);
        return retV;
    }
    cv::Point& getPointAt(int index) {
        int i(0);
        for (std::map<int, cv::Point>::iterator itr = xyPos->begin(); itr != xyPos->end(); ++itr) {
            if (i == index)
                return (*itr).second;
            i++;
        }
        // returns a null pointer, quick fix
        cv::Point returnPointer;
        return returnPointer;
    }
    //std::list<cv::Point> getPoints() { std::list<cv::Point> plst; for (std::map<int, cv::Point >::iterator ptr = xyPos.begin(); ptr != xyPos.end(); std::advance(ptr, 1)) plst.push_back((*ptr).second); return plst; }
    const cv::Point getLastPoint() { return (*(std::prev(xyPos->end()))).second; }
    int getLastFrame() { return (*(std::prev(xyPos->end()))).first; }
    int getXyListSize() { if (xyPos == nullptr) return 0; else return (int)xyPos->size(); }

private:
    std::map<int, cv::Point>* xyPos = new std::map<int, cv::Point>();
};

#endif // MARKER_H
