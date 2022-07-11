#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit GameWindow(QWidget *parent = nullptr);
  ~GameWindow();

  void addCard(const uint score);
  void initGame();
  void endGame();

 public slots:
  void cardPressed(const uint score);

 private:
  Ui::GameWindow *ui;

  const uint FIELD_SIZE = 12;
  const uint MAX_CLICKED = 4;
  uint clickedAmount = 0;
  uint scoreSum = 0;
  const uint MIN_SCORE = 0;
  const uint MAX_SCORE = 9999;
};

#endif  // GAMEWINDOW_H
