#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

#define H 20
#define W 15

// ============================ BOARD ===============================
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

// ============================ BLOCKS ===============================
char blocks[7][4][4] = {
    // I
    {{' ','I',' ',' '},
     {' ','I',' ',' '},
     {' ','I',' ',' '},
     {' ','I',' ',' '}},

    // O
    {{' ','O','O',' '},
     {' ','O','O',' '},
     {' ',' ',' ',' '},
     {' ',' ',' ',' '}},

    // T
    {{' ','T',' ',' '},
     {'T','T','T',' '},
     {' ',' ',' ',' '},
     {' ',' ',' ',' '}},

    // S
    {{' ','S','S',' '},
     {'S','S',' ',' '},
     {' ',' ',' ',' '},
     {' ',' ',' ',' '}},

    // Z
    {{'Z','Z',' ',' '},
     {' ','Z','Z',' '},
     {' ',' ',' ',' '},
     {' ',' ',' ',' '}},

    // J
    {{'J',' ',' ',' '},
     {'J','J','J',' '},
     {' ',' ',' ',' '},
     {' ',' ',' ',' '}},

    // L
    {{' ',' ','L',' '},
     {'L','L','L',' '},
     {' ',' ',' ',' '},
     {' ',' ',' ',' '}}
};

int x = 5, y = 0;
int b = 0;
int score = 0;

// ============================ BLOCK CONTROL ===============================
void eraseBlock() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[b][i][j] != ' ') {
                int ty = y + i;
                int tx = x + j;
                if (ty >= 0 && ty < H && tx >= 0 && tx < W)
                    board[ty][tx] = ' ';
            }
}

void block2Board() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[b][i][j] != ' ')
                board[y + i][x + j] = blocks[b][i][j];
}

bool canMove(int dx, int dy) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[b][i][j] != ' ') {

                int tx = x + j + dx;
                int ty = y + i + dy;

                if (tx <= 0 || tx >= W - 1) return false;
                if (ty >= H - 1) return false;

                if (board[ty][tx] != ' ')
                    return false;
            }
    return true;
}

// ============================ ROTATE ===============================
// Xoay block theo chiều kim đồng hồ
void rotateBlock() {
    char temp[4][4];

    // copy block hiện tại
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp[i][j] = blocks[b][i][j];

    // tạo block xoay
    char rotated[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            rotated[j][3 - i] = temp[i][j];

    // Kiểm tra xoay hợp lệ
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (rotated[i][j] != ' ') {
                int tx = x + j;
                int ty = y + i;

                if (tx <= 0 || tx >= W - 1) return;  
                if (ty >= H - 1) return;
                if (board[ty][tx] != ' ')
                    return;
            }

    // Nếu hợp lệ thì ghi vào blocks[b]
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            blocks[b][i][j] = rotated[i][j];
}

// ============================ LINE CLEAR ===============================
void clearLines() {
    int count = 0;

    for (int i = H - 2; i > 0; i--) {
        int full = 1;
        for (int j = 1; j < W - 1; j++)
            if (board[i][j] == ' ')
                full = 0;

        if (full) {
            count++;

            for (int k = i; k > 0; k--)
                for (int t = 1; t < W - 1; t++)
                    board[k][t] = board[k - 1][t];

            for (int t = 1; t < W - 1; t++)
                board[0][t] = ' ';

            i++;
        }
    }

    score += count * 100;
}

// ============================ DRAW ===============================
void draw() {
    gotoxy(0, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            cout << board[i][j];
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

// ============================ MAIN ===============================
int main() {
    srand(time(0));
    initBoard();

    b = rand() % 7;
    x = 5; y = 0;

    while (1) {

        eraseBlock();

        // ---- Control ----
        if (kbhit()) {
            char c = getch();
            if (c == 'a' && canMove(-1,0)) x--;
            if (c == 'd' && canMove(1,0))  x++;
            if (c == 's' && canMove(0,1))  y++;
            if (c == 'w') rotateBlock();   // 🔄 XOAY KHỐI
            if (c == 'q') break;
        }

        // ---- Auto fall ----
        if (canMove(0,1)) {
            y++;
        } else {
            block2Board();
            clearLines();

            b = rand() % 7;
            x = 5; 
            y = 0;

            if (!canMove(0,0)) {
                draw();
                gotoxy(0, H+2);
                cout << "GAME OVER! Score: " << score;
                break;
            }
        }

        block2Board();
        draw();
        Sleep(170);
    }

    return 0;
}
