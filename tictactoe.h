#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <QVector>
#include <QPushButton>

class TicTacToe : public QWidget
{
    Q_OBJECT
public:
    explicit TicTacToe(QWidget *parent = nullptr);
    enum Player{
        Invalied,Player1,Player2,Draw
    };
    Q_ENUM(Player);
    Player currentPlayer()const;
    void setCurrentPlayer(Player player);
    void initNewGame();
    Player checkWinCondition();
signals:
    void gameOver(Player winner);
    void currentPlayerChanged(Player player);

private slots:
    void handleButtonClicked(int index);
private:
    QVector<QPushButton*> m_board;
    Player m_currentPlayer;
};

#endif // TICTACTOE_H
