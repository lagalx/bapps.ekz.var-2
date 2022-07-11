#include "cardwidget.h"

#include "ui_cardwidget.h"

CardWidget::CardWidget(const uint score, QWidget* parent)
    : QWidget(parent), ui(new Ui::CardWidget) {
  ui->setupUi(this);

  ui->scoreButton->setText("");
  setScore(score);
}

CardWidget::~CardWidget() { delete ui; }

const int CardWidget::getScore() { return score; }

void CardWidget::setScore(const uint score) { this->score = score; }

void CardWidget::on_scoreButton_clicked() {
  ui->scoreButton->setText(QString("%1").arg(score, 4, 10, QChar('0')));
  ui->scoreButton->setEnabled(false);

  emit cardClicked(score);
}
