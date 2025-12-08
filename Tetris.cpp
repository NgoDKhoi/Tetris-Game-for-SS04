#include <iostream>
#include <windows.h>
using namespace std;

#define H 20
#define W 15

char board[H][W];
int x = 5, row = 0;

void initBoard() {
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            board[i][j] = (i == H - 1 || j == 0 || j == W - 1) ? '#' : ' ';
}

void draw() {
    system("cls");
    for (int i = 0; i < H; i++, cout << endl)
        for (int j = 0; j < W; j++)
            cout << board[i][j];
}

int main() {
    initBoard();
    while (1) {
        board[row][x] = 'O';  
        draw();
        Sleep(100);          
        board[row][x] = ' ';
        x++;                

        if (x >= W - 1) x = 1;
    }
}
