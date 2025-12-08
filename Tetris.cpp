#include <iostream>
using namespace std;

#define H 20
#define W 15

char board[H][W]; // Bảng chơi Tetris

// ================= Board =================
void initBoard() {
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (i == H - 1 || j == 0 || j == W - 1)
                board[i][j] = '#';
            else
                board[i][j] = ' ';
}

void draw() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            cout << board[i][j];
        cout << endl;
    }
}

// ================= Blocks =================
char blocks[2][4][4] = {
    // I
    {{' ','I',' ',' '},
     {' ','I',' ',' '},
     {' ','I',' ',' '},
     {' ','I',' ',' '}},

    // O
    {{' ','O','O',' '},
     {' ','O','O',' '},
     {' ',' ',' ',' '},
     {' ',' ',' ',' '}}
};

int x = 5, y = 0; // vị trí block hiện tại
int b = 0;        // block hiện tại (0: I, 1: O)

// Copy block vào board
void block2Board() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[b][i][j] != ' ')
                board[y + i][x + j] = blocks[b][i][j];
}

int main() {
    initBoard();   // Khởi tạo board
    block2Board(); // Thêm block hiện tại vào board
    draw();        // Vẽ board và block

    return 0;
}
