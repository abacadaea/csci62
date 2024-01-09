#include <iostream>
#include <string>
#include "examplewindow.h"
#include "ui_examplewindow.h"

ExampleWindow::ExampleWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ExampleWindow)
{
    ui->setupUi(this);
    numClicks = 0;

    connect(ui->myButton, &QPushButton::clicked, this, &ExampleWindow::myButtonClick);
    connect(ui->myTable, &QTableWidget::cellClicked, this, &ExampleWindow::myTableClick);
}

void ExampleWindow::myButtonClick () {
    std::cout << "Button clicked" << std::endl;
    numClicks += 1;
    ui->myLabel->setText(QString::fromStdString("Button Clicked " + std::to_string(numClicks)));
    std::string s = ui->myTextBox->toPlainText().toStdString();

    ui->myTable->setRowCount(3);
    ui->myTable->setColumnCount(2);
}

void ExampleWindow::myTableClick (int row, int column) {
    std::cout << "Clicked row " << row << " and column " << column << std::endl;
}

ExampleWindow::~ExampleWindow()
{
    delete ui;
}

