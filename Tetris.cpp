#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

#define H 20
#define W 15

// ================= Board =================
char board[H][W];

void gotoxy(int x, int y)
{
    COORD c = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// ================= Line =================
bool isLineFull(int r)
{
    for (int j = 1; j < W - 1; j++)
        if (board[r][j] == ' ')
            return false;
    return true;
}

int removeLine()
{
    int count = 0;
    for (int i = 0; i < H - 1; i++)
        if (isLineFull(i))
            count++;
    return count;
}

void clearFullLines()
{
    for (int i = H - 2; i >= 0; i--)
    {
        if (isLineFull(i))
        {

            // Dồn các hàng trên xuống
            for (int k = i; k > 0; k--)
                for (int j = 1; j < W - 1; j++)
                    board[k][j] = board[k - 1][j];

            // Hàng trên cùng thành hàng trống
            for (int j = 1; j < W - 1; j++)
                board[0][j] = ' ';

            i++; // check lại dòng này sau khi dồn
        }
    }
}

void initBoard()
{
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (i == H - 1 || j == 0 || j == W - 1)
                board[i][j] = '#';
            else
                board[i][j] = ' ';
}

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
     {' ', ' ', ' ', ' '}}};

int x = 5, y = 0;
int b = 0; // 0 = I, 1 = O

bool canMove(int dx, int dy)
{
    int nx = x + dx;
    int ny = y + dy;

    // Kiểm tra biên
    if (nx <= 0 || nx >= W - 4)
        return false;
    if (ny >= H - 4)
        return false;

    // Kiểm tra va chạm
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[b][i][j] != ' ')
                if (board[ny + i][nx + j] != ' ')
                    return false;

    return true;
}

void block2Board()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[b][i][j] != ' ')
                board[y + i][x + j] = blocks[b][i][j];
}

void eraseBlock()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[b][i][j] != ' ')
                board[y + i][x + j] = ' ';
}

int main()
{
    system("cls");
    initBoard();

    while (1)
    {

        if (kbhit())
        {
            char c = getch();
            if (c == 'a' && canMove(-1, 0))
            {
                eraseBlock();
                x--;
            }
            if (c == 'd' && canMove(1, 0))
            {
                eraseBlock();
                x++;
            }
            if (c == 's' && canMove(0, 1))
            {
                eraseBlock();
                y++;
            }
            if (c == 'q')
                break;
        }

        eraseBlock();
        y++; // block rơi tự nhiên

        if (!canMove(0, 1))
        {
            block2Board();
            clearFullLines();
            draw();
            Sleep(120);

            // reset new block
            x = 5;
            y = 0;
            b = rand() % 2;

            continue;
        }

        block2Board();
        draw();
        Sleep(120);
    }

    return 0;
}
