#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

#define H 20
#define W 15

char board[H][W];
int x = 5, y = 0; // Vị trí của block

// Hàm đưa con trỏ console
void gotoxy(int x, int y)
{
    COORD c = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Khởi tạo bảng
void initBoard()
{
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (i == H - 1 || j == 0 || j == W - 1)
                board[i][j] = '#';
            else
                board[i][j] = ' ';
}

// Vẽ bảng
void draw()
{
    gotoxy(0, 0);
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << board[i][j];
        cout << endl;
    }
}

// Kiểm tra có thể di chuyển
bool canMove(int dx, int dy)
{
    int nx = x + dx;
    int ny = y + dy;

    if (nx <= 0 || nx >= W - 1)
        return false;
    if (ny >= H - 1)
        return false;

    return true;
}

int main()
{
    system("cls");
    initBoard();

    while (1)
    {

        // Điều khiển
        if (kbhit())
        {
            char c = getch();
            if (c == 'a' && canMove(-1, 0)) x--;
            if (c == 'd' && canMove(1, 0)) x++;
            if (c == 's' && canMove(0, 1)) y++;
            if (c == 'q') break;
        }

        // Vẽ vị trí block
        board[y][x] = 'O';
        draw();
        board[y][x] = ' '; // Xóa block để cập nhật frame tiếp

        Sleep(150);
        y++; // block rơi

        if (!canMove(0, 1))
        {
            board[y][x] = 'O';
            draw();
            break;
        }
    }

    return 0;
}
