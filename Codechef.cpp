#include <iostream>
#include <cturtle.h>

using namespace std;
using namespace cturtle;

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

char currentPlayer = 'X';

void drawBoard() {
    clear();
    penup();
    goto_xy(-200, 200);
    pendown();
    
    // Draw the grid
    for (int i = 0; i < 4; i++) {
        forward(400);
        backward(400);
        left(90);
        forward(200);
        right(90);
    }
    
    // Draw the X's and O's
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                penup();
                goto_xy(-150 + j * 100, 150 - i * 100);
                pendown();
                left(45);
                forward(70);
                backward(140);
                forward(70);
                right(90);
                forward(70);
                backward(140);
                forward(70);
                left(45);
            } else if (board[i][j] == 'O') {
                penup();
                goto_xy(-125 + j * 100, 125 - i * 100);
                pendown();
                circle(25);
            }
        }
    }
    
    update();
}

bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    initializeTurtle();
    speed(0);
    
    while (true) {
        drawBoard();
        
        int x, y;
        cout << "Player " << currentPlayer << ", enter your move (x y): ";
        cin >> x >> y;
        
        if (board[y][x] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }
        
        board[y][x] = currentPlayer;
        
        if (checkWin(currentPlayer)) {
            drawBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        
        if (isBoardFull()) {
            drawBoard();
            cout << "It's a draw!" << endl;
            break;
        }
        
        switchPlayer();
    }
    
    exitTurtle();
    return 0;
}