#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>
#include <QPainter>

class MyWindow: public QMainWindow
{
    Q_OBJECT

public:
    MyWindow()
    {
        image = new QPixmap();
        if ( !image->load("/ccp/ccp.png")) {
            printf("Error loading ccp.png\n");
        }
    };
    ~ MyWindow(){
        delete image;
    };
private:
    QPixmap *image;
public:
    void paintEvent(QPaintEvent * e)
    {
        QPainter painter(this);
        painter.drawPixmap(0,0,*image);
    }
    void keyPressEvent(QKeyEvent* e)
    {
        if (e->key() == Qt::Key_PowerDown) {
            qApp->quit();
        }else {
            QMessageBox* box = new QMessageBox();
            box->setWindowTitle(QString("Message"));
            box->setText(QString("You Pressed some other button"));
            box->show();
        }

    };
};