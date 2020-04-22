#include "tictactoe.h"
#include <QGridLayout>
#include <QSignalMapper>

TicTacToe::TicTacToe(QWidget *parent) : QWidget(parent)
{
    QGridLayout *gridLayout = new QGridLayout(this);
    m_currentPlayer=Player::Invalied;
    QSignalMapper *mapper=new QSignalMapper(this);
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            QPushButton *button=new QPushButton(" ");
            gridLayout->addWidget(button,row,col);
            m_board.append(button);
            mapper->setMapping(button,m_board.count()-1);
            connect(button,SIGNAL(clicked()),mapper,SLOT(map()));
            //connect(button,&QPushButton::clicked,mapper,&QSignalMapper::map);
        }
    }
    connect(mapper,SIGNAL(mapped(int)),this,SLOT(handleButtonClicked(int)));
}

TicTacToe::Player TicTacToe::currentPlayer() const
{
    return m_currentPlayer;
}

void TicTacToe::setCurrentPlayer(TicTacToe::Player player)
{
    if(m_currentPlayer==player)
        return;
    m_currentPlayer=player;
    emit currentPlayerChanged(m_currentPlayer);
}

void TicTacToe::initNewGame()
{
    for (QPushButton *button : m_board) {
        button->setText(" ");
    }
    setCurrentPlayer(Player::Player1);
}

void TicTacToe::handleButtonClicked(int index)
{
    if(m_currentPlayer == Player::Invalied)
        return;
    if(index<0||index>=m_board.size())return;
    if(m_board[index]->text()!=" ") return;
    QString str=m_currentPlayer==Player::Player1?"X":"O";
    m_board[index]->setText(str);
    Player winner=checkWinCondition();
    if(winner==Player::Invalied){
        setCurrentPlayer(currentPlayer() == Player::Player1 ?
                             Player::Player2 : Player::Player1);
        return;
    }else {
        emit gameOver(winner);
    }
}

TicTacToe::Player TicTacToe::checkWinCondition()
{
    for(int i=0;i<4;i++){
        if(m_board[i]->text()== m_board[4]->text() && m_board[4]->text()==m_board[8-i]->text()){
            if(m_board[i]->text()=="X"){
                return Player::Player1;
            }else if(m_board[i]->text()=="O"){
                return Player::Player2;
            }else {
                return Player::Invalied;
            }
        }
    }
    //012
    if(m_board[0]->text()== m_board[1]->text() && m_board[1]->text()==m_board[2]->text()){
        if(m_board[0]->text()=="X"){
            return Player::Player1;
        }else if(m_board[0]->text()=="O"){
            return Player::Player2;
        }else {
            return Player::Invalied;
        }
    }
    //036
    if(m_board[0]->text()== m_board[3]->text() && m_board[3]->text()==m_board[6]->text()){
        if(m_board[0]->text()=="X"){
            return Player::Player1;
        }else if(m_board[0]->text()=="O"){
            return Player::Player2;
        }else {
            return Player::Invalied;
        }
    }
    //258
    if(m_board[2]->text()== m_board[5]->text() && m_board[5]->text()==m_board[8]->text()){
        if(m_board[2]->text()=="X"){
            return Player::Player1;
        }else if(m_board[2]->text()=="O"){
            return Player::Player2;
        }else {
            return Player::Invalied;
        }
    }
    //678
    if(m_board[6]->text()== m_board[7]->text() && m_board[7]->text()==m_board[8]->text()){
        if(m_board[6]->text()=="X"){
            return Player::Player1;
        }else if(m_board[6]->text()=="O"){
            return Player::Player2;
        }else {
            return Player::Invalied;
        }
    }
    for(int i=0;i<9;i++){
        if(m_board[i]->text()==" "){
            return Player::Invalied;
        }
    }
    return Player::Draw;
}
