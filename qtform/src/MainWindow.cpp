#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  ourLabel = new OurLabel();
  ourLabel->setText("Our text");
  horizontalBoxLayout = new QHBoxLayout();
  horizontalBoxLayout->addWidget(ourLabel);
  horizontalBoxLayout->setSpacing(20);
  horizontalBoxLayout->setContentsMargins(20, 10, 20, 10);
  centralWidget = new QWidget(this);
  centralWidget->setLayout(horizontalBoxLayout);
  setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {
  delete ourLabel;
  delete horizontalBoxLayout;
  delete centralWidget;
}
