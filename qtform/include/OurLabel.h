#pragma once

#include <QLabel>

class OurLabel : public QLabel {
  Q_OBJECT

public:
  explicit OurLabel(QWidget *parent = nullptr);
  virtual ~OurLabel() = default;
};
