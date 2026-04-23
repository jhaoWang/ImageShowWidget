#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QLabel>

class CustomImageItem;
class CustomGraphicsView :public QGraphicsView
{
    Q_OBJECT
public:
    CustomGraphicsView(QWidget *parent = 0);
    ~CustomGraphicsView();
    bool InitWidget();

    void setImage(QImage &qImage);
protected:
    virtual void wheelEvent(QWheelEvent *event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent* event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

public slots:
    void onZoom(float fScalefactor);
    void onCenter();

private:
    void fitFrame();
    void setBackground(bool enabled = true,bool invertColor = false);

private:
    double m_dZoomValue = 1;
    QGraphicsScene* m_pScene;
    CustomImageItem* m_pImageItem;
    QWidget* m_pPosInfoWidget;//视觉窗口左下方，用于显示鼠标位置以及对应位置像素灰度值
    QLabel* m_pPosInfoLabel; //显示灰度值的标签

    QPixmap m_Image;
    QImage m_qImage;
    QPixmap m_tilePixmap = QPixmap(36, 36);
};

#endif // CUSTOMGRAPHICSVIEW_H
