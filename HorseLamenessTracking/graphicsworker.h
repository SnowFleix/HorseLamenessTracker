#ifndef GRAPHICSWORKER_H
#define GRAPHICSWORKER_H

//STL Libraries
#include <vector>

//QT Libraries
#include <QObject>
#include <QGraphicsView>
#include <QImage>

//Header files
#include "utilfunctions.h"

class GraphicsWorker : public QObject {
    Q_OBJECT
public:
    GraphicsWorker(std::vector<QGraphicsView*> graphicsViews);
    ~GraphicsWorker();

public slots:
    void process();

signals:
    void finished();
    void error(QString error);

private:
    std::vector<QGraphicsView*> graphicsViewCol_;

    QImage matToImage(cv::Mat mat);
    QGraphicsScene* getSceneFromImage(QImage background);
};

#endif // GRAPHICSWORKER_H
