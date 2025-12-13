#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

#define H 20
#define W 15

// ================= BOARD =================
char board[H][W];

void gotoxy(int x, int y)
{
    COORD c = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
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

void draw(int score)
{
    gotoxy(0, 0);
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << board[i][j];
        cout << endl;
    }

    cout << "\nScore: " << score << endl;
}

// ================= LINE =================
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

void clearFullLines(int &score)
{
    for (int i = H - 2; i >= 0; i--)
    {
        if (isLineFull(i))
        {
            score += 100;  // 🎯 Commit 15: +100 điểm mỗi hàng

            // Dồn hàng
            for (int k = i; k > 0; k--)
                for (int j = 1; j < W - 1; j++)
                    board[k][j] = board[k - 1][j];

            for (int j = 1; j < W - 1; j++)
                board[0][j] = ' ';

            i++; // kiểm tra lại dòng vừa dồn xuống
        }
    }
}

// ================= BLOCKS =================
char blocks[7][4][4] = {
    // I
    {{' ', 'I', ' ', ' '},
     {' ', 'I', ' ', ' '},
     {' ', 'I', ' ', ' '},
     {' ', 'I', ' ', ' '}},

    // O
    {{' ', 'O', 'O', ' '},
     {' ', 'O', 'O', ' '},
     {' ', ' ', ' ', ' '},
     {' ', ' ', ' ', ' '}},
     
    // T
    {{' ', 'T', 'T', 'T'},
     {' ', ' ', 'T', ' '},
     {' ', ' ', ' ', ' '},
     {' ', ' ', ' ', ' '}},
	
	// S
    {{' ', ' ', 'S', 'S'},
     {' ', 'S', 'S', ' '},
     {' ', ' ', ' ', ' '},
     {' ', ' ', ' ', ' '}},
	
	// Z
    {{' ', 'Z', 'Z', ' '},
     {' ', ' ', 'Z', 'Z'},
     {' ', ' ', ' ', ' '},
     {' ', ' ', ' ', ' '}},
	
	// J
    {{' ', ' ', 'J', ' '},
     {' ', ' ', 'J', ' '},
     {' ', 'J', 'J', ' '},
     {' ', ' ', ' ', ' '}},
	
	// L
    {{' ', 'L', ' ', ' '},
     {' ', 'L', ' ', ' '},
     {' ', 'L', 'L', ' '},
     {' ', ' ', ' ', ' '}}
};

int x = 5, y = 0;
int b = rand() % 7; // loại block

bool canMove(int dx, int dy)
{
    int nx = x + dx;
    int ny = y + dy;

    if (nx <= 0 || nx >= W - 4)
        return false;
    if (ny >= H - 4)
        return false;

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

// ================= MAIN =================
int main()
{
    system("cls");
    initBoard();

    int score = 0;

    while (1)
    {
        // ----------- Điều khiển ----------
        if (kbhit())
        {
            char c = getch();

            if (c == 'a' && canMove(-1, 0)) { eraseBlock(); x--; }
            if (c == 'd' && canMove(1, 0))  { eraseBlock(); x++; }
            if (c == 's' && canMove(0, 1))  { eraseBlock(); y++; }
            if (c == 'q') break;
        }

        // ----------- Rơi tự động ----------
        eraseBlock();
        y++;

        if (!canMove(0, 1))
        {
            block2Board();
            clearFullLines(score);  // commit 14 & 15
            draw(score);
            Sleep(120);

            // reset block
            x = 5;
            y = 0;
            b = rand() % 7;

            continue;
        }

        block2Board();
        draw(score);
        Sleep(120);
    }

    return 0;
}
