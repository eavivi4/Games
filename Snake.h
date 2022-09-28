#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
using namespace std;

const int width = 20;
const int height = 20;
int snakeX, snakeY, fruitX, fruitY, score;
bool gameOver;

void Board() {

    system("CLS");

    // Top of board
    for (int i = 0; i < width; i++)
    {
        cout << ".";
    }
    cout << endl;

    // Middle and sides of board
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == height - 1)
            {
                cout << ".";
            }
            else if(i == snakeY && j == snakeX)
            {
                cout << "S";
            }
            else if(i == fruitY && j == fruitX)
            {
                cout << "F";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    // Bottom of board
    for (int i = 0; i < width; i++)
    {
        cout << ".";
    }
    cout << endl;
} 

void Snake() {
    gameOver = false;
    // Have the snake in the middle of the screen
    snakeX = width/2;
    snakeY = height/2;

    // Random position within the board
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void WinSnake() {
    if (snakeX == fruitX && snakeY == fruitY)
    {
        cout << "You win!" << endl;
        gameOver = true;
    }
    return;
}

void LoseSnake() {
    if (snakeX < 0 || snakeY < 0 || snakeX >= width || snakeY >= height)
    {
        cout << "Game Over..." << endl;
        gameOver = true;
    }
}

void Input() {
    // if (_kbhit())
    // {
    //     switch(GetAsyncKeyState())
    //     {
    //         case 'w':
    //             snakeY--;
    //             break;
    //         case 'd':
    //             snakeX++;
    //             break;
    //         case 's':
    //             snakeY++;
    //             break;
    //         case 'a':
    //             snakeX--;
    //             break;
    //     }
    // }
    
    WinSnake();
}



void SnakeGame() {
    Snake();
    while (!gameOver)
    {
        Board();
        Input();
        sleep(40);
    }
    return;
}