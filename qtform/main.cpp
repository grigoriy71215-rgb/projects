#include "MainWindow.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow mainWindow;

  mainWindow.setWindowTitle("My Qt Application");
  mainWindow.resize(400, 300);
  mainWindow.show();

  return app.exec();
}
