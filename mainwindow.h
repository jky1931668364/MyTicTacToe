#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "tictactoe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void startNewGame();
    void setLabelBold(QLabel *label,bool isBold);
private slots:
    void updateNameLabels();
    void handleGameOver(TicTacToe::Player winner);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
