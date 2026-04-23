#ifndef CUSTOMIMAGEITEM_H
#define CUSTOMIMAGEITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class CustomImageItem :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CustomImageItem(QWidget *parent = 0);

protected:
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event);

public:
    int h;
    int w;

signals:
    void RGBValue(QString infoValue);
};

#endif // CUSTOMIMAGEITEM_H
