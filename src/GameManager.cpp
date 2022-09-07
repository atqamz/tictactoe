#include "../header/GameManager.h"
#include "../header/Board.h"
#include "../header/Player.h"
#include <iostream>

using namespace std;

GameManager::GameManager()
{
    gameOff = false;
}

void GameManager::gameLoop()
{
    while (!gameOff)
    {
        menu();
    }
}

void GameManager::menu()
{
    system("cls");
    cout << "Welcome to TicTacToe" << endl;
    cout << "1. Play" << endl;
    cout << "0. Exit" << endl;
    menuInput();
}

void GameManager::menuInput()
{
    int input;
    cout << "Choose menu: ";
    cin >> input;

    switch (input)
    {
    case 1:
    {
        playMode();
        break;
    }

    case 0:
    {
        gameOff = true;
        break;
    }

    default:
        break;
    }
}

void GameManager::playMode()
{
    system("cls");
    cout << "Play Mode" << endl;
    cout << "1. Singleplayer" << endl;
    cout << "2. Multiplayer" << endl;
    cout << "0. Back" << endl;
    playModeInput();
}

void GameManager::playModeInput()
{
    int input;
    cout << "Choose play mode: ";
    cin >> input;

    switch (input)
    {
    case 1:
    {
        isOver = false;
        singleplayer();
        break;
    }
    case 2:
    {
        isOver = false;
        multiplayer();
        break;
    }
    case 0:
    {
        menu();
    }
    default:
        break;
    }
}

void GameManager::singleplayer()
{
    Board TicTacToe;

    string username1;
    cout << "Enter player 1's username: ";
    cin >> username1;

    Player player1(username1);
    Bot player2("Bot");

    player1.setPlayerTurn();

    while (!isOver)
    {
        system("cls");

        cout << "TicTacToe!!" << endl;

        if (TicTacToe.checkWin())
        {
            isOver = true;

            if (!player1.isTurn)
            {
                cout << "Player 1 wins!" << endl;
            }
            else
            {
                cout << "Player 2 wins!" << endl;
            }

            TicTacToe.printBoard();

            playAgain();

            break;
        }

        if (TicTacToe.checkFull())
        {
            isOver = true;

            cout << "Draw!" << endl;

            TicTacToe.printBoard();
            playAgain();

            break;
        }

        if (player1.isTurn)
            cout << player1.username << "'s turn" << endl;
        else
            cout << player2.username << "'s turn" << endl;

        TicTacToe.printBoard();
        if (player1.isTurn)
        {
            if (TicTacToe.setBoard(player1.playTurn(), 'X'))
            {
                player1.unsetPlayerTurn();
                player2.setPlayerTurn();
            }
        }
        else
        {
            if (TicTacToe.setBoard(player2.playBotTurn(), 'O'))
            {
                player2.unsetPlayerTurn();
                player1.setPlayerTurn();
            }
        }
    }
}

void GameManager::multiplayer()
{
    Board TicTacToe;

    string username1, username2;
    cout << "Enter player 1's username: ";
    cin >> username1;
    cout << "Enter player 2's username: ";
    cin >> username2;

    Player player1(username1);
    Player player2(username2);

    player1.setPlayerTurn();

    while (!isOver)
    {
        system("cls");

        cout << "TicTacToe!!" << endl;

        if (TicTacToe.checkWin())
        {
            isOver = true;

            if (!player1.isTurn)
            {
                cout << "Player 1 wins!" << endl;
            }
            else
            {
                cout << "Player 2 wins!" << endl;
            }

            TicTacToe.printBoard();
            playAgain();

            break;
        }

        if (TicTacToe.checkFull())
        {
            isOver = true;

            cout << "Draw!" << endl;

            TicTacToe.printBoard();
            playAgain();

            break;
        }

        if (player1.isTurn)
            cout << player1.username << "'s turn" << endl;
        else
            cout << player2.username << "'s turn" << endl;

        TicTacToe.printBoard();
        if (player1.isTurn)
        {
            if (TicTacToe.setBoard(player1.playTurn(), 'X'))
            {
                player1.unsetPlayerTurn();
                player2.setPlayerTurn();
            }
        }
        else
        {
            if (TicTacToe.setBoard(player2.playTurn(), 'O'))
            {
                player2.unsetPlayerTurn();
                player1.setPlayerTurn();
            }
        }
    }
}

void GameManager::playAgain()
{
    cout << endl;
    cout << "Play again?" << endl;
    cout << "1. Yes" << endl;
    cout << "0. No" << endl;
    playAgainInput();
}

void GameManager::playAgainInput()
{
    int input;
    cout << "Choose: ";
    cin >> input;

    switch (input)
    {
    case 1:
        break;
    case 0:
        gameOff = true;
        break;
    default:
        break;
    }
}