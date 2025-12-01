#pragma once

#include "OurLabel.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

class MainWindow : public QMainWindow {
  Q_OBJECT

private:
  OurLabel *ourLabel = nullptr;
  QHBoxLayout *horizontalBoxLayout = nullptr;
  QWidget *centralWidget = nullptr;

public:
  explicit MainWindow(QWidget *parent = nullptr);
  virtual ~MainWindow();
};
