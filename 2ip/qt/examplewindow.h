#ifndef EXAMPLEWINDOW_H
#define EXAMPLEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ExampleWindow; }
QT_END_NAMESPACE

class ExampleWindow : public QMainWindow
{
    Q_OBJECT

public:
    ExampleWindow(QWidget *parent = nullptr);
    ~ExampleWindow();

    void myButtonClick();
    void myTableClick(int row, int column);

private:
    Ui::ExampleWindow *ui;
    int numClicks;
};
#endif // EXAMPLEWINDOW_H
