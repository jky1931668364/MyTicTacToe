#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnStartNewGame,&QPushButton::clicked,this,&MainWindow::startNewGame);
    connect(ui->gameBoard,&TicTacToe::currentPlayerChanged,this,&MainWindow::updateNameLabels);
    connect(ui->gameBoard,&TicTacToe::gameOver,this,&MainWindow::handleGameOver);
    startNewGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startNewGame()
{
    ui->player1Name->setText(tr("Alice"));
    ui->player2Name->setText(tr("Bob"));
    ui->gameBoard->initNewGame();
}

void MainWindow::setLabelBold(QLabel *label,bool isBold)
{
    QFont font=label->font();
    font.setBold(isBold);
    label->setFont(font);
}

void MainWindow::updateNameLabels()
{
    setLabelBold(ui->player1Name,ui->gameBoard->currentPlayer()==TicTacToe::Player::Player1);
    setLabelBold(ui->player2Name,ui->gameBoard->currentPlayer()==TicTacToe::Player::Player2);
}

void MainWindow::handleGameOver(TicTacToe::Player winner)
{
    QString message="";
    if(winner==TicTacToe::Player::Draw){
        message=tr("Game end with Draw.");
    }else{
        QString winnerName=winner==TicTacToe::Player::Player1?
                    ui->player1Name->text():ui->player2Name->text();
        message=tr("%1 wins").arg(winnerName);
    }
    QMessageBox::information(this,"info",message);
    startNewGame();
}

