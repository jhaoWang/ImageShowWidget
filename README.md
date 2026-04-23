# QT操作相关

## 一、QT安装

1.从qt官网下载在线安装程序。[下载Qt OSS：获取Qt Online安装程序](https://www.qt.io/development/download-qt-installer-oss)

2.点击运行qt安装程序
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260108212016558.png" alt="image-20260108212016558" style="zoom:80%;" />

3.点击下一步，登录注册过的邮箱，输入邮箱信息后点击下一步操作
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260108212150147.png" alt="image-20260108212150147" style="zoom:80%;" />

4.勾选如下图所示两个选项后点击下一步操作
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260108212643668.png" alt="image-20260108212643668" style="zoom:80%;" />
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260108212718060.png" alt="image-20260108212718060" style="zoom:80%;" />

5.选择合适的安装路径，点击自定义安装和下一步操作
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260108213043661.png" alt="image-20260108213043661" style="zoom:80%;" />

6.选择对应的qt版本和相应的扩展组件，点击下一步
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260108213711096.png" alt="image-20260108213711096" style="zoom:80%;" />
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260108214628369.png" alt="image-20260108214628369" style="zoom:80%;" />
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260108214649295.png" alt="image-20260108214649295" style="zoom:80%;" />

7.点接收条款，点击下一步
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260108214742900.png" alt="image-20260108214742900" style="zoom:80%;" />

8.根据安装提示逐步进行安装
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260108214938711.png" alt="image-20260108214938711" style="zoom:80%;" />

9.等待安装完成即可
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260109151531250.png" alt="image-20260109151531250" style="zoom:80%;" />

##   二、添加环境变量

### 2.1添加QT使用时相关的环境变量

1.打开系统环境属性管理界面
![image-20260112142938640](C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112142938640.png)
2.选择环境变量->点击系统变量中的path后确认
![image-20260112143048369](C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112143048369.png)

3.进入编辑页面，添加选中的文件路径，下图中最后三行。注意根据自己的安装路径进行调整。
![image-20260112143208753](C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112143208753.png)

4.添加完毕后逐步点击确认件即可
5.检查环境变量是否添加成功。win+r启动命令行工具，输入qmake-v，检查是否有返回信息。有返回信息表明环境变量添加成功
![image-20260112143504801](C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112143504801.png)

## 三、QT初体验

### 3.1创建项目目录->如下图，创建新的目录文件

![image-20260112143803613](C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112143803613.png)

### 3.2进入项目目录编写源代码,通过代码编译工具均可，此处以visio studio为例。

1.打开visio studio
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112153704317.png" alt="image-20260112153704317" style="zoom:80%;" />

2.打开本地文件夹，刚才创建的项目文件夹
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112153819616.png" alt="image-20260112153819616" style="zoom:80%;" />
3.选择目录后进入vs界面，右击文件名，点击添加新文件，命名为main.cpp
![image-20260112154051829](C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112154051829.png)
![image-20260112154122297](C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112154122297.png)
4.开始编写代码文件
![image-20260112154428708](C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112154428708.png)
5.代码编写完成后，通过qmake对代码进行编译生成

### 3.3通过qmake对编写完成的代码进行编译

1.找到mingw命令工具
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112154707716.png" alt="image-20260112154707716" style="zoom:80%;" />
2.点击进入mingw命令工具

<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112154759170.png" alt="image-20260112154759170" style="zoom:80%;" />
3.切换到代码文件所在目录
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112155022066.png" alt="image-20260112155022066" style="zoom:80%;" />
4.执行qmake -project，生成.pro文件
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112155147216.png" alt="image-20260112155147216" style="zoom:80%;" />
5.通过visio studio打开生成的.pro文件，再文件中添加QT += widgets并保存
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112155334685.png" alt="image-20260112155334685" style="zoom:80%;" />
6.执行qmake命令生成makefile文件
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112155437911.png" alt="image-20260112155437911" style="zoom:80%;" />
7.执行mingw32-make进行编译，生成可执行的.exe文件
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112160101804.png" alt="image-20260112160101804" style="zoom:80%;" />
8.在release文件中找到生成的.exe文件进行运行
<img src="C:\Users\wjh\AppData\Roaming\Typora\typora-user-images\image-20260112160205739.png" alt="image-20260112160205739" style="zoom:80%;" />

代码详解：

```
// main.cpp

#include <QApplication> // 每个qt项目都要包含该头文件,通过该类构建QT的应用程序
#include <QLabel> // 标签类->显示信息->QLable

int main(int argc, char* argv[]) // QT入口函数
{
	// 构建QT应用程序
	QApplication app(argc, argv);

	// 创建标签组件
	QLabel label("hello QT!!!");

	// 显示标签组件
	label.show();  // 大多数情况下通过show函数进行结果显示功能。

	// 让QT的程序进入一个事件循环，不返回
	// 不断让用户操作->触发对应的事件->捕获事件->实现对应功能
	return app.exec();

}
```

### 3.4信号与槽机制

**信号（Signal）**：是**对象**的一种**特殊成员函数**，**没有函数体**，不需要你实现，仅在某个特定事件触发时被**自动发射 (emit)**。比如按钮被点击、输入框文本改变、窗口关闭、自定义的状态变更等，都会发射对应的信号。

**槽（Slot）**：是**对象**的**普通成员函数**（可以是普通成员函数、静态函数、Lambda 表达式），**有完整的函数体**，需要你自己编写具体的业务逻辑代码，本质就是信号的「响应函数」。

信号与槽通过QObject类中的connect函数进行连接，从而实现控件间的通信
QObject::connect(发送信号的对象指针, &发送类::信号函数名, 接收信号的对象指针, &接收类::槽函数名);

信号与槽连接的语法要求：
信号与槽的参数要一致
QOBJECT::connect(A, SIGNAL(sigfun(int)), B, SLOT(slotfun(int)))
可以带有缺省参数
QOBJECT::connect(A, SIGNAL(sigfun(int)), B, SLOT(slotfun(int, int=0)))
信号函数的参数可以多于槽函数，多余参数将被忽略
QOBJECT::connect(A, SIGNAL(sigfun(int,int)), B, SLOT(slotfun(int)))

信号和槽连接的应用：
一个信号可以连接到多个槽
多个信号可以连接到同一个槽
两个信号可以直接连接

### 3.5QT中加载本地图片

```
void Demo_2MainWindow::onLoadImageButtonClicked()
{
    QString curDir = QDir::currentPath();
    QString filename = QFileDialog::getOpenFileName(this, "select the image", curDir, "Images (*.png *.bmp *.jpg)");

    if(filename.isEmpty()){
        QMessageBox::critical(this, "ERROR", "Open img faild");
        return;
    }

    _selectImgLineEdit->setText(filename);
    auto srcImage = QImage(filename);
    _src_imgLabel->setPixmap(QPixmap::fromImage(srcImage).scaled(_src_imgLabel->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
```

3.4QImage和cv::Mat相互转换

```
#ifndef MATTOQIMAGE_H
#define MATTOQIMAGE_H

#include <QImage>
#include <opencv2/opencv.hpp>
#include <QDebug>

/**
 * @brief 工具类：OpenCV Mat 和 Qt QImage 相互转换
 * 支持格式：
 *  - CV_8UC1  <->  QImage::Format_Grayscale8
 *  - CV_8UC3  <->  QImage::Format_RGB888
 *  - CV_8UC4  <->  QImage::Format_ARGB32
 */
class MatToQImage
{
public:
    /**
     * @brief cv::Mat 转 QImage
     * @param mat 输入的 OpenCV Mat（支持 8位 单通道/3通道/4通道）
     * @return 转换后的 QImage，失败返回空图像
     */
    static QImage matToQImage(const cv::Mat& mat)
    {
        // 空 Mat 直接返回空图像
        if (mat.empty()) {
            qWarning() << "matToQImage: 输入 Mat 为空！";
            return QImage();
        }

        switch (mat.type()) {
        // 8位灰度图
        case CV_8UC1: {
            QImage image(mat.data,
                         mat.cols,
                         mat.rows,
                         mat.step,
                         QImage::Format_Grayscale8);
            // 深拷贝，避免共享内存导致崩溃
            return image.copy();
        }

        // 8位3通道 (BGR格式 OpenCV默认)
        case CV_8UC3: {
            cv::Mat rgbMat;
            // OpenCV BGR -> Qt RGB
            cv::cvtColor(mat, rgbMat, cv::COLOR_BGR2RGB);
            QImage image(rgbMat.data,
                         rgbMat.cols,
                         rgbMat.rows,
                         rgbMat.step,
                         QImage::Format_RGB888);
            return image.copy();
        }

        // 8位4通道 (带透明通道)
        case CV_8UC4: {
            QImage image(mat.data,
                         mat.cols,
                         mat.rows,
                         mat.step,
                         QImage::Format_ARGB32);
            return image.copy();
        }

        // 不支持的格式
        default: {
            qWarning() << "matToQImage: 不支持的 Mat 格式：" << mat.type();
            return QImage();
        }
        }
    }

    /**
     * @brief QImage 转 cv::Mat
     * @param image 输入的 Qt QImage
     * @return 转换后的 OpenCV Mat，失败返回空 Mat
     */
    static cv::Mat qImageToMat(const QImage& image)
    {
        // 空图像直接返回
        if (image.isNull()) {
            qWarning() << "qImageToMat: 输入 QImage 为空！";
            return cv::Mat();
        }

        QImage convertedImage;
        switch (image.format()) {
        // 灰度图
        case QImage::Format_Grayscale8: {
            return cv::Mat(image.height(),
                           image.width(),
                           CV_8UC1,
                           const_cast<uchar*>(image.bits()),
                           image.bytesPerLine()).clone();
        }

        // RGB3通道
        case QImage::Format_RGB888: {
            cv::Mat mat(image.height(),
                        image.width(),
                        CV_8UC3,
                        const_cast<uchar*>(image.bits()),
                        image.bytesPerLine());
            // Qt RGB -> OpenCV BGR
            cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);
            return mat.clone();
        }

        // ARGB4通道
        case QImage::Format_ARGB32:
        case QImage::Format_RGBA8888: {
            return cv::Mat(image.height(),
                           image.width(),
                           CV_8UC4,
                           const_cast<uchar*>(image.bits()),
                           image.bytesPerLine()).clone();
        }

        // 其他格式统一转成 RGB888 再转换
        default: {
            convertedImage = image.convertToFormat(QImage::Format_RGB888);
            return qImageToMat(convertedImage);
        }
        }
    }
};

#endif // MATTOQIMAGE_H

```

### 3.6QT中配置Opencv环境

```
# ========== OpenCV 配置 ==========
OPENCV_PATH = D:/OpenCV-MinGW-Build  # 改成你自己的解压路径

INCLUDEPATH += $$OPENCV_PATH/include
INCLUDEPATH += $$OPENCV_PATH/include/opencv2

LIBS += $$OPENCV_PATH/x86/mingw/lib/libopencv_*.a
```

### 3.7 QT中打开文件夹

QT关于文件读取或文件选择等操作，需要依赖QFileDialog类来实现，该类可以直接打开本地文件，类似于Windows中的文件管理器，通过该类一般可以完成文件的打开以及选取操作。使用QFileDialog类时首先需要包含头文件<QFileDialog>

QFileDialog类的基本使用流程：

1. 首先需要构造一个新的QFileDialog的类对象，一般情况下是一个指针，其父类对象是当前界面，因此使用时用this即可
2. 设置文件对话框标题：通过调用**setWindowTitle()**函数实现
3. 设置文件对话框默认文件夹：通过调用**setDirectory()**函数实现
4. 
