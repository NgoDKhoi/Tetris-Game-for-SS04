#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

#define H 20
#define W 15

// ================= Board =================
char board[H][W];

void gotoxy(int x, int y) {
    COORD c = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void initBoard() {
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (i == H - 1 || j == 0 || j == W - 1)
                board[i][j] = '#';
            else
                board[i][j] = ' ';
}

void draw() {
    gotoxy(0, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            cout << board[i][j];
        cout << endl;
    }
}

// ================= Blocks =================
char blocks[2][4][4] = {
    // I
    {{' ', 'I', ' ', ' '},
     {' ', 'I', ' ', ' '},
     {' ', 'I', ' ', ' '},
     {' ', 'I', ' ', ' '}},

    // O
    {{' ', 'O', 'O', ' '},
     {' ', 'O', 'O', ' '},
     {' ', ' ', ' ', ' '},
     {' ', ' ', ' ', ' '}}
};

int x = 5, y = 0; 
int b = 0; // 0 = I, 1 = O

bool canMove(int dx, int dy) {
    int nx = x + dx;
    int ny = y + dy;

    // Kiểm tra biên
    if (nx <= 0 || nx >= W - 4) return false;
    if (ny >= H - 4) return false;

    // Kiểm tra va chạm
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[b][i][j] != ' ')
                if (board[ny + i][nx + j] != ' ')
                    return false;

    return true;
}

void block2Board() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[b][i][j] != ' ')
                board[y + i][x + j] = blocks[b][i][j];
}

void eraseBlock() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[b][i][j] != ' ')
                board[y + i][x + j] = ' ';
}

int main() {
    system("cls");
    initBoard();

    while (1) {

        if (kbhit()) {
            char c = getch();
            if (c == 'a' && canMove(-1, 0)) { eraseBlock(); x--; }
            if (c == 'd' && canMove(1, 0))  { eraseBlock(); x++; }
            if (c == 's' && canMove(0, 1))  { eraseBlock(); y++; }
            if (c == 'q') break;
        }

        eraseBlock();
        y++; // block rơi tự nhiên

        if (!canMove(0, 1)) {
            block2Board();
            draw();

            // reset new block
            y = 0;
            x = 5;
            b = rand() % 2;
            break;
        }

        block2Board();
        draw();
        Sleep(150);
    }

    return 0;
}
