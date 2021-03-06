#include <QApplication>
#include <QDebug>
#include "mainwindow.h"
#include "ringBuffer.h"
#include "adcreader.h"
#include <QMutex>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
        QApplication::setGraphicsSystem("raster");
#endif

        QApplication a(argc, argv);

        ring_buffer_t ring_buffer;
        ring_buffer_init(&ring_buffer);

        QMutex mutex;

        ADCreader adcReader(ring_buffer, mutex);
        adcReader.start();

        MainWindow w(0, ring_buffer, mutex);
        w.showFullScreen();


        return a.exec();
}
