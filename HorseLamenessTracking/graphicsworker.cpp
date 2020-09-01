#include "graphicsworker.h"

/////////////////////////////////////////////////////////////
/// \brief GraphicsWorker::GraphicsWorker
/// Default constructor, sets the graphicsView collection to
/// the one passed through
///
/// \param graphicsViews
/// The collection of graphicsViews that are going to be fed
/// video
///
GraphicsWorker::GraphicsWorker(std::vector<QGraphicsView*> graphicsViews) : graphicsViewCol_(graphicsViews) { }

/////////////////////////////////////////////////////////////
/// \brief GraphicsWorker::~GraphicsWorker
/// Default destructor, deletes all the data in the class
///
GraphicsWorker::~GraphicsWorker() { }

/////////////////////////////////////////////////////////////
/// \brief GraphicsWorker::process
/// The code for processing the datapassed in the construcor
///
void GraphicsWorker::process() {
    for (int i = 0; i < (int)graphicsViewCol_.size(); i++) {
        cv::Mat frame;
        *webCamList[i] >> frame;
        graphicsViewCol_[i]->setScene(getSceneFromImage(matToImage(frame)));
    }
}

/////////////////////////////////////////////////////////////
/// \brief matToImage
/// Converts a cv::mat to a a QImage
///
/// \param mat
/// The cv::mat to convert
///
/// \return
/// A QImage made from the cv::mat
///
QImage GraphicsWorker::matToImage(cv::Mat mat) {
    return QImage((uchar*)mat.data, mat.cols, mat.rows, QImage::Format_RGB32);
}

/////////////////////////////////////////////////////////////
/// \brief getSceneFromImage
/// Creates a graphics scene from a QImage to be used in a
/// QGraphicsView
///
/// \param background
/// The QImage to create the scene from
///
/// \return
/// The QGraphicsScene to add to the QGraphicsView
///
QGraphicsScene* GraphicsWorker::getSceneFromImage(QImage background) {
    QGraphicsScene* scene = new QGraphicsScene(QRect(0, 0, 600, 400));

    QPixmap Pix(QPixmap::fromImage(background));

    QGraphicsPixmapItem *item1 = scene->addPixmap(Pix);

    // doesnt work
    item1->setPos(-25, 45);
    scene->addPixmap(Pix)->setPos(0,0);

    return scene;
}
