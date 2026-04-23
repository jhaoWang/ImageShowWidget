# 1.基于QGraphicView实现一个图片查看器

![image-20260423200813878](C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260423200813878.png)

图片查看器的主要功能是实现图片的显示功能。在QT中，实现一个图片查看功能可以通过两种不同的方式实现：

1. 通过一个QWidget和QLabel的组合实现，直接将图片放在QLabel中显示即可。这种方式存在的缺点是，显示的图片无法实现放大缩小或者拖拽移动等操作。要实现这些操作，就需要重写各种鼠标事件，因此该方式一般仅适用于简单的图片显示。
2. 采用QT的视图模型框架，通过重写QGraphicView类，实现上述的放大缩小以及平移拖拽等操作。

## 1.1 QT视图模型框架介绍

常规认知中，要显示一张图片，只需要一张图片和一个QWidget画布即可。但在视图模型中，要显示一张图片则需要三个东西，分别是：

1. Graphics Scene:场景/场景管理器
2. Graphics View:图形视图，也可以理解为图像显示窗口
3. Graphics PixmapItem:场景中被显示的元素，可以是一张图片，也可以是一些其他东西，如矩形、圆形等其他任何东西

关于三者之间的关系，可以使用下图来进行描述：

![image-20260421083354623](C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260421083354623.png)

## 1.2 视图模型框架的使用方式

如下示例是一个简单的视图模型框架的调用，主要步骤可以概括为：

1. 创建QGraphics Scene实例
2. 创建QGraphics View实例，并绑定到Scene上。通过View的setScene()接口实现
3. 创建QGraphics Item，并将一张图片初始化为Item
4. 对Item设置想要实现的特性功能

实例代码如下：

```QT
#include "mainwindow.h"
#include <QLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    InitWidget();
}

MainWindow::~MainWindow() {}

void MainWindow::InitWidget()
{
    // 创建场景实例
    QGraphicsScene *pScene = new QGraphicsScene(this);
    // 创建View实例
    QGraphicsView *pView = new QGraphicsView(this);
    // 将View绑定到Scene上
    pView->setScene(pScene);

    QImage srcImage("E:\\QTCode\\QGraphicViewLearn\\GraphicView\\200280.jpg");

    // 创建Item实例，由于是要显示图片，因此实例化一个QGraphicsPixmapItem
    QGraphicsPixmapItem *pItem = new QGraphicsPixmapItem();
    // 开启鼠标悬停事件监听
    pItem->setAcceptHoverEvents(true);
    // 给图元设置交互标志，使图片可以被鼠标选中或拖拽
    pItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    // 将图片通过QPixmap设置为图元
    pItem->setPixmap(QPixmap::fromImage(srcImage));
    // 将Item添加到Scene上
    pScene->addItem(pItem);

    QVBoxLayout *pLayout_main = new QVBoxLayout();
    pLayout_main->setContentsMargins(0, 0, 0, 0);
    pLayout_main->setSpacing(0);
    pLayout_main->addWidget(pView);

    QWidget *pWidget_main = new QWidget(this);
    pWidget_main->setLayout(pLayout_main);

    this->setCentralWidget(pWidget_main);
}
```

示例结果如下所示：

![image-20260421090910695](C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260421090910695.png)

上述运行结果仍存在一些问题：

1. 背景颜色不是我们想要的样式
2. 图像元素没有适配窗口界面
3. 双击窗口界面图像元素无法恢复居中
4. 左下角没有半透明的Label，可以显示鼠标的坐标，以及对应图像元素位置的像素值

要实现上述功能，通过上面的几行代码是无法实现的，这就需要我们来重写QGraphicsView类，以此实现图像显示控件的自定义功能。

## 1.3 QGraphicsView自定义类

### 1.3.1 图像缩放

对于窗口图像的缩放功能，需要重写QT中的滚轮事件，具体做法如下：

1. 头函数中声明重写wheelEvent(QWheelEvent *event)事件

2. 通过event->angleDelta()来获取滚轮的转动量

3. 当event->angleDelta().y大于0时，图像进行扩大，反之则进行缩小。这里可以通过定义两个常量限定放大缩小的倍数

4. 执行自定义的缩放函数，这里的缩放是通过QGraphicsView自身的scale函数实现

   ```QT
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
   
   void CustomGraphicsView::onZoom(float fScalefactor)
   {
       m_dZoomValue *= fScalefactor;
       this->scale(fScalefactor, fScalefactor);
   }
   ```

### 1.3.2 图像自适应大小并居中

对于双击鼠标左键实现图像自适应窗口大小并居中的功能，需要重写QGraphicsView的鼠标双击事件来实现。需要注意的是，重写鼠标事件后一定要再次调用父类的鼠标事件。

​	

```QT
void CustomGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        fitFrame();
        onCenter();
    }
    QGraphicsView::mouseDoubleClickEvent(event);
}
```

#### 1.3.2.1 图片居中操作

图片居中操作主要分为两个步骤：

1. 调用QGraphicsView的Centeron函数将图pixmap的中心点设为(0, 0)

2. 利用pixmap的setPos函数将图片置于(0, 0)点

   ```QT
   void CustomGraphicsView::onCenter()
   {
       this->centerOn(m_pImageItem->pixmap().width() / 2, m_pImageItem->pixmap().height() / 2);
       m_pImageItem->setPos(0, 0);
   }
   ```

#### 1.3.2.2 自适应窗口大小

1. 根据图像原始尺寸和当前视觉窗口的大小计算出应缩放的尺寸

2. 根据已经缩放的比例计算还差的缩放比例

3. 补齐应缩放的比例，使得图像和视觉窗口大小相适配

   ```QT
   void CustomGraphicsView::fitFrame()
   {
       if(this->width() < 1 || m_Image.width() < 1)
           return;
       // double scalWidth = (m_Image.width() + 1) / this->width();错误写法
       // double scalHeight = (m_Image.height() + 1) / this->height();错误写法
       double winWidth = this->width();
       double winHeight = this->height();
       double scalWidth = (m_Image.width() + 1) / winWidth;
       double scalHeight = (m_Image.height() + 1) / winHeight;
       double tempScale = scalWidth >= scalHeight ? 1 / scalWidth : 1 / scalHeight;
       double scale = tempScale / m_dZoomValue;
   
       onZoom(scale);
       m_dZoomValue = tempScale;
   }
   ```

### 1.3.3 窗口缩放

要实现窗口缩放后图像依然适应窗口大小的功能，则需要对QGraphicsView的resizeEvent事件进行重写，重写的内容也很简单，就是将自适应大小函数和居中函数写入即可

```QT
void CustomGraphicsView::resizeEvent(QResizeEvent *event)
{
    fitFrame();
    onCenter();
    QGraphicsView::resizeEvent(event);
}
```

# 2.如何捕获视觉窗口中的图像元素信息？

要捕获视觉窗口内的图像元素信息，一般需要对QGraphicsPixmapItem进行操作，因此要实现这一自定义功能，就需要实现一个继承自Item的类，通过成员函数来实现这一功能。即通过重写hoverMoveEvent()事件来实现该功能

hoverMoveEvent()是鼠标悬停移动事件，通过该事件可以获取鼠标当前悬停处的位置信息以及像素值信息

```
#ifndef CUSTOMIMAGEITEM_H
#define CUSTOMIMAGEITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class CustomImageItem :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CustomImageItem();

protected:
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event);

public:
    int h;
    int w;

signals:
    void RGBValue(QString infoValue);
};

#endif // CUSTOMIMAGEITEM_H

```

```
#include "CustomImageItem.h"
#include <QGraphicsSceneHoverEvent>



CustomImageItem::CustomImageItem()
{
    this->setAcceptHoverEvents(true);
}

void CustomImageItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    QPointF mousePosition = event->pos();
    int R, G, B;
    int x, y;
    x = mousePosition.x();
    y = mousePosition.y();
    if(mousePosition.x() < 0)
    {
        x = 0;
    }
    if(mousePosition.y() < 0)
    {
        y = 0;
    }
    pixmap().toImage().pixelColor(x, y).getRgb(&R, &G, &B);
    QString InfoValue = QString("W:%1, H:%2 | X:%3, Y:%4 | R:%5, G:%6, B:%7")
                            .arg(QString::number(w))
                            .arg(QString::number(h))
                            .arg(QString::number(x))
                            .arg(QString::number(y))
                            .arg(QString::number(R))
                            .arg(QString::number(G))
                            .arg(QString::number(B));

    emit RGBValue(InfoValue);
}
```
