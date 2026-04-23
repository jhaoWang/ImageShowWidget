#include "mainwindow.h"
#include <QMenuBar>
#include "RenderWindow/CustomGraphicsView.h"
#include <QLayout>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_pMenuBar(Q_NULLPTR)
{
    this->setMinimumSize(1000, 600);

    InitWidget();
}

MainWindow::~MainWindow() {}

bool MainWindow::InitWidget()
{
    m_pView = new CustomGraphicsView(this);
    m_pButton = new QPushButton(this);
    connect(m_pButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);

    QVBoxLayout *mLayout_test = new QVBoxLayout();
    mLayout_test->setContentsMargins(0, 0, 0, 0);
    mLayout_test->setSpacing(0);
    mLayout_test->addWidget(m_pView);
    mLayout_test->addWidget(m_pButton);
    QWidget *mWidget_test = new QWidget(this);
    mWidget_test->setLayout(mLayout_test);

    this->setCentralWidget(mWidget_test);
    return true;
}

void MainWindow::onButtonClicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Select Image", ".", "Image(*.jpg *.png)");
    QImage image = QImage(filename);
    m_pView->setImage(image);
}

