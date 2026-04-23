#include "CustomGraphicsView.h"
#include "CustomImageItem.h"
#include <QMutex>
#include <QLayout>

#define ZOOMMAX 50   //最大放大倍数
#define ZOOMMIN 0.1 //最小缩小倍数

CustomGraphicsView::CustomGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
    , m_pScene(Q_NULLPTR)
    , m_pImageItem(Q_NULLPTR)
    , m_pPosInfoWidget(Q_NULLPTR)
    , m_pPosInfoLabel(Q_NULLPTR)
{
    //禁用滑动条
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //反锯齿
    this->setRenderHint(QPainter::Antialiasing);
    this->setTransformationAnchor(QGraphicsView::AnchorViewCenter);

    this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    setDragMode(QGraphicsView::ScrollHandDrag);
    this->setSceneRect(INT_MIN/2, INT_MIN/2, INT_MAX, INT_MAX);
    setBackground();
    centerOn(0, 0);
    InitWidget();
}

CustomGraphicsView::~CustomGraphicsView(){}

bool CustomGraphicsView::InitWidget()
{
    m_pScene = new QGraphicsScene(this);
    m_pImageItem = new CustomImageItem(this);
    this->setScene(m_pScene);
    m_pScene->addItem(m_pImageItem);

    m_pPosInfoLabel = new QLabel(this);
    m_pPosInfoWidget = new QWidget(this);
    m_pPosInfoLabel->setStyleSheet("color:rgb(200,255,200); "
                              "background-color:rgba(50,50,50,160); "
                              "font: Microsoft YaHei;"
                                "font-size: 15px;");
    m_pPosInfoLabel->setText(" W:0,H:0 | X:0,Y:0 | R:0,G:0,B:0");
    m_pPosInfoWidget->setFixedHeight(25);
    m_pPosInfoWidget->setGeometry(0, this->height() - 25, this->width(), 25);
    m_pPosInfoWidget->setStyleSheet("background-color:rgba(0,0,0,0);");
    QHBoxLayout *pLayout = new QHBoxLayout();
    pLayout->setContentsMargins(0, 0, 0, 0);
    pLayout->setSpacing(0);
    pLayout->addWidget(m_pPosInfoLabel);
    m_pPosInfoWidget->setLayout(pLayout);

    connect(m_pImageItem, &CustomImageItem::RGBValue, this, [&](QString RGBValue){
        m_pPosInfoLabel->setText(RGBValue);
    });

    return true;
}

void CustomGraphicsView::setImage(QImage &qImage)
{
    static QMutex mutex;
    QMutexLocker locker(&mutex);
    m_qImage = qImage.copy();
    m_Image = QPixmap::fromImage(qImage);
    m_pImageItem->w = m_Image.width();
    m_pImageItem->h = m_Image.height();
    m_pImageItem->setPixmap(m_Image);

    fitFrame();
    onCenter();
    show();
}

void CustomGraphicsView::wheelEvent(QWheelEvent *event)
{
    QPoint scrollAngel = event->angleDelta();
    if(scrollAngel.y() > 0 && m_dZoomValue > ZOOMMAX)
    {
        return;
    }
    if(scrollAngel.y() < 0 && m_dZoomValue < ZOOMMIN)
    {
        return;
    }
    scrollAngel.y() > 0 ? onZoom(1.1) : onZoom(0.9);
}

void CustomGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        fitFrame();
        onCenter();
    }
    QGraphicsView::mouseDoubleClickEvent(event);
}

void CustomGraphicsView::paintEvent(QPaintEvent *event)
{
    QPainter paint(this->viewport());
    paint.drawTiledPixmap(QRect(QPoint(0, 0), QPoint(this->width(), this->height())), m_tilePixmap);
    QGraphicsView::paintEvent(event);
}

void CustomGraphicsView::resizeEvent(QResizeEvent *event)
{
    fitFrame();
    onCenter();
    m_pPosInfoWidget->setGeometry(0, this->height() - 25, this->width(), 25);
    QGraphicsView::resizeEvent(event);
}

void CustomGraphicsView::onZoom(float fScalefactor)
{
    m_dZoomValue *= fScalefactor;
    this->scale(fScalefactor, fScalefactor);
}

void CustomGraphicsView::onCenter()
{
    this->centerOn(m_pImageItem->pixmap().width() / 2, m_pImageItem->pixmap().height() / 2);
    m_pImageItem->setPos(0, 0);
}

void CustomGraphicsView::fitFrame()
{
    if(this->width() < 1 || m_Image.width() < 1)
        return;
    double winWidth = this->width();
    double winHeight = this->height();
    double scalWidth = (m_Image.width() + 1) / winWidth;
    double scalHeight = (m_Image.height() + 1) / winHeight;
    double tempScale = scalWidth >= scalHeight ? 1 / scalWidth : 1 / scalHeight;
    double scale = tempScale / m_dZoomValue;

    onZoom(scale);
    m_dZoomValue = tempScale;
}

void CustomGraphicsView::setBackground(bool enabled, bool invertColor)
{
    if (enabled)
    {
        m_tilePixmap.fill(invertColor ? QColor(220, 220, 220) : QColor(35, 35, 35));
        QPainter tilePainter(&m_tilePixmap);
        constexpr QColor color(50, 50, 50, 255);
        constexpr QColor invertedColor(210, 210, 210, 255);
        tilePainter.fillRect(0, 0, 18, 18, invertColor ? invertedColor : color);
        tilePainter.fillRect(18, 18, 18, 18, invertColor ? invertedColor : color);
        tilePainter.end();

        //当取消注释时，视觉窗口背景格会跟随图像一起缩放
        //setBackgroundBrush(m_tilePixmap);
    }
    else
    {
        //setBackgroundBrush(Qt::transparent);
    }
}
