#include <iostream>
using namespace std;

#define H 20
#define W 15

char board[H][W]; // Bảng chơi Tetris

// Khởi tạo board: viền '#' và bên trong ' '
void initBoard() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == H - 1 || j == 0 || j == W - 1)
                board[i][j] = '#';  // viền dưới và hai bên
            else
                board[i][j] = ' ';  // ô trống
        }
    }
}

// Vẽ board ra console
void draw() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            cout << board[i][j];
        cout << endl;
    }
}

int main() {
    initBoard(); // Khởi tạo board rỗng
    draw();      // Vẽ board ra màn hình

    return 0;
}