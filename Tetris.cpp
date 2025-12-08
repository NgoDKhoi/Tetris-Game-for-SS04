#include <iostream>
#include <windows.h>
using namespace std;

#define H 20
#define W 15

char board[H][W];
int x = 5, y = 0;

void gotoxy(int x, int y) {
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void initBoard() {
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            board[i][j] = (i == H - 1 || j == 0 || j == W - 1) ? '#' : ' ';
}

void draw() {
    gotoxy(0, 0);
    for (int i = 0; i < H; i++, cout << endl)
        for (int j = 0; j < W; j++)
            cout << board[i][j];
}

int main() {
    initBoard();
    while (1) {
        board[y][x] = 'X';  // block
        draw();
        Sleep(200);

        board[y][x] = ' ';  // xóa vị trí cũ
        y++;                // tăng y → block rơi

        if (y >= H - 1) y = 0; // reset cho dễ test
    }
}
