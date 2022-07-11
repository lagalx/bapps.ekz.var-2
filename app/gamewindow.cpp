#include "gamewindow.h"

#include <QMessageBox>
#include <QRandomGenerator>

#include "cardwidget.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::GameWindow) {
  ui->setupUi(this);
  ui->cardsListWidget->setSelectionRectVisible(false);

  initGame();
}

GameWindow::~GameWindow() { delete ui; }

void GameWindow::initGame() {
  scoreSum = 0;
  clickedAmount = 0;

  ui->cardsListWidget->clear();
  ui->scoreLabel->setText(QString::number(scoreSum));

  for (uint i = 0; i < FIELD_SIZE; i++) {
    const auto score =
        QRandomGenerator::global()->bounded(MIN_SCORE, MAX_SCORE);
    addCard(score);
  }
}

void GameWindow::addCard(const uint score) {
  auto listItemW = new QListWidgetItem();
  auto itemW = new CardWidget(score, this);

  listItemW->setSizeHint(itemW->sizeHint());

  ui->cardsListWidget->addItem(listItemW);
  ui->cardsListWidget->setItemWidget(listItemW, itemW);

  QObject::connect(itemW, SIGNAL(cardClicked(uint)), this,
                   SLOT(cardPressed(uint)));
}

void GameWindow::cardPressed(const uint score) {
  scoreSum += score;
  ui->scoreLabel->setText(QString::number(scoreSum));
  clickedAmount++;

  if (clickedAmount != MAX_CLICKED) {
    return;
  }

  endGame();
}

void GameWindow::endGame() {
  QMessageBox::information(this, "Game Results",
                           QString("Your gained score: %1").arg(scoreSum));

  initGame();
}
