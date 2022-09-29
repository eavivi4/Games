// #include <windows.h>
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;

const int width = 20;
const int height = 20;
int snakeX, snakeY, fruitX, fruitY, score;
bool gameOver;
enum dir {STOP, UP, DOWN, LEFT, RIGHT};
dir d;

void Board() {

    system("CLS");

    // Top of board
    for (int i = 0; i < width; i++)
    {
        cout << "#";
    }
    cout << endl;

    // Middle and sides of board
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == height - 1)
            {
                cout << "#";
            }
            else if(i == snakeY && j == snakeX)
            {
                cout << ".";
            }
            else if(i == fruitY && j == fruitX)
            {
                cout << "O";
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
        cout << "#";
    }
    cout << endl;
} 

void Snake() {
    gameOver = false;
    d = STOP;
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
        gameOver = true;
        cout << "You win!" << endl;
    }
    return;
}

void LoseSnake() {
    if (snakeX <= 0 || snakeY <= 0 || snakeX >= width || snakeY >= height)
    {
        gameOver = true;
        cout << "Game Over..." << endl;
        
    }
}

void Logic() {
    switch(d)
    {
        // Change this so that the last point of the snake becomes the first one
        case UP:
            snakeY--;
            break;
        case DOWN:
            snakeY++;
            break;
        case RIGHT:
            snakeX++;
            break;
        case LEFT:
            snakeX--;
            break;
    }
    return;
}

void Input() {

    // Keyboard input to move snake
    if (_kbhit())
    {
        switch(_getch())
        {
            case 'w':
                d = UP;
                break;
            case 'd':
                d = RIGHT;
                break;
            case 's':
                d = DOWN;
                break;
            case 'a':
                d = LEFT;
                break;
        }
    }

    // Check if won or lost
    LoseSnake();
    WinSnake();
}

void SnakeGame() {
    Snake();
    while (!gameOver)
    {
        Board();
        Input();
        Logic();

        // Prevent the screen from flashing
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    return;
}