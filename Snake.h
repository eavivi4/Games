#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;

const int width = 20;
const int height = 20;
int snakeX, snakeY, fruitX, fruitY, score;
bool gameOver, winner;
enum dir {STOP, UP, DOWN, LEFT, RIGHT};
dir d;
int tailLength;
int tailX[100];
int tailY[100];

void Board() {

    // Prevent the board from being drawn over and over again, several times
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
                // Print tail or print blank space, depending on x and y coordinates
                bool tail = false;
                for (int k = 0; k < tailLength; k++)
                {
                    if (i == tailY[k] && j == tailX[k])
                    {
                        tail = true;
                        cout << ".";
                    }
                }
                if (tail == false)
                {
                    cout << " ";
                }
                
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

    cout << "Score: " << score << endl;
} 

void Snake() {

    // Start the game
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

    // Win the game if caught 50 fruit
    if (score == 500)
    {
        gameOver = true;
        winner = true;
        cout << "You win!" << endl;
    }
    return;
}

void LoseSnake() {

    // Check if head of snake touches the tail
    for (int i = 0; i < tailLength; i++)
    {
        if (snakeX == tailX[i] && snakeY == tailY[i])
        {
            gameOver = true;
            winner = false;
            cout << "Game Over..." << endl;
        }
    }
    return;
}

void FruitCaught() {

    // If a fruit is caught, generate a new one
    if (snakeX == fruitX && snakeY == fruitY)
    {
        score += 10;
        tailLength++;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
    return;
}

void TailMovement() {

    // Have the tail follow snake's x and y coordinates by moving them up
    int prevX = tailX[0];
    int prevY = tailY[0];
    int currX, currY;
    tailX[0] = snakeX;
    tailY[0] = snakeY;
    for (int i = 1; i < tailLength; i++)
    {
        // Save variables
        currX = tailX[i];
        currY = tailY[i];

        // Switch
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = currX;
        prevY = currY;
    }
    return;
}

void Movements() {

    TailMovement();
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
    
    // Check if out of bounds, if it is, keep in bounds by coming out the other side
    if (snakeX < 0) 
    {
        snakeX = width - 1;   
    }
    if (snakeY < 0)
    {
        snakeY = height - 1;
    }
    if(snakeX >= width)
    {
        snakeX = 0;
    }
    if(snakeY >= height)
    {
        snakeY = 0;
    }

    // Check if fruit caught, won, or lost
    LoseSnake();
    FruitCaught();
    WinSnake();
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
    return;
}

int SnakeGame() {

    // Set important variables
    Snake();
    while (!gameOver)
    {
        // Play the game while it is not won or lost
        Board();
        Input();
        Movements();

        // Prevent the screen from flashing
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }

    return score;
}