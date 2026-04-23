#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class CustomGraphicsView;
class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    bool InitWidget();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
    void onButtonClicked();

private:
    QMenuBar *m_pMenuBar;
    CustomGraphicsView *m_pView;
    QPushButton * m_pButton;
};
#endif // MAINWINDOW_H
