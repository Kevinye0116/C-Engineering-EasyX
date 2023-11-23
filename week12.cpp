//
// Created by Kevin Ye on 11/23/2023.
// Copyright (c) KevinYe on 11/23/2023.

#include <conio.h>
#include "graphics.h"

void DrawBoard();

void DrawPrompt();

void Highlight(int x, int y);

void Restore(int x, int y);

void DrawCross(int x, int y);

void DrawCircle(int x, int y);

int Judge(char board[3][3], int x, int y);

int main() {
    initgraph(1000, 650);
    int x = 0, y = 0;
    int flag;
    char board[3][3] = {{' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}};
    DrawBoard();
    DrawPrompt();

    Highlight(x, y);
    for (int count = 1; count <= 9;) {
        char op;
        op = getch();
        if (op == 'w') {
            Restore(x, y);
            if (board[y][x] == 'c') DrawCross(x, y);
            else if (board[y][x] == 'o') DrawCircle(x, y);
            if (y == 0) {
                y = 2;
            } else {
                y--;
            }
            Highlight(x, y);
            if (board[y][x] == 'c') DrawCross(x, y);
            else if (board[y][x] == 'o') DrawCircle(x, y);
        } else if (op == 'a') {
            Restore(x, y);
            if (board[y][x] == 'c') DrawCross(x, y);
            else if (board[y][x] == 'o') DrawCircle(x, y);
            if (x == 0) {
                x = 2;
            } else {
                x--;
            }
            Highlight(x, y);
            if (board[y][x] == 'c') DrawCross(x, y);
            else if (board[y][x] == 'o') DrawCircle(x, y);
        } else if (op == 's') {
            Restore(x, y);
            if (board[y][x] == 'c') DrawCross(x, y);
            else if (board[y][x] == 'o') DrawCircle(x, y);
            if (y == 2) {
                y = 0;
            } else {
                y++;
            }
            Highlight(x, y);
            if (board[y][x] == 'c') DrawCross(x, y);
            else if (board[y][x] == 'o') DrawCircle(x, y);
        } else if (op == 'd') {
            Restore(x, y);
            if (board[y][x] == 'c') DrawCross(x, y);
            else if (board[y][x] == 'o') DrawCircle(x, y);
            if (x == 2) {
                x = 0;
            } else {
                x++;
            }
            Highlight(x, y);
            if (board[y][x] == 'c') DrawCross(x, y);
            else if (board[y][x] == 'o') DrawCircle(x, y);
        } else if (op == '\r') {
            if (board[y][x] != ' ') continue;
            else {
                Restore(x, y);
                if (count % 2 == 0) {
                    board[y][x] = 'c';
                    DrawCross(x, y);
                } else {
                    board[y][x] = 'o';
                    DrawCircle(x, y);
                }
                count++;
                flag = Judge(board, x, y);
                if (!flag) continue;
                else break;
            }
        } else if (op == 'q') {
            cleardevice();
            outtextxy(720, 200, _T("Press any key to quit the game!"));
            _getch();
            closegraph();
            return 0;
        }
    }
    if (!flag) outtextxy(720, 300, _T("Oops! It's a draw!"));
    _getch();
    closegraph();
    return 0;
}

void DrawBoard() {
    setlinecolor(YELLOW);
    rectangle(20, 20, 620, 620);
    line(20, 220, 620, 220);
    line(20, 420, 620, 420);
    line(220, 20, 220, 620);
    line(420, 20, 420, 620);
}

void DrawPrompt() {
    outtextxy(720, 50, _T("W:Up"));
    outtextxy(720, 70, _T("A:Left"));
    outtextxy(720, 90, _T("S:Down"));
    outtextxy(720, 110, _T("D:Right"));
    outtextxy(720, 130, _T("Enter:Confirm"));
    outtextxy(720, 150, _T("Q:Quit"));
}

void Highlight(int x, int y) {
    setlinecolor(YELLOW);
    setfillcolor(BLUE);
    fillrectangle(x * 200 + 20, y * 200 + 20, (x + 1) * 200 + 20, (y + 1) * 200 + 20);
}

void Restore(int x, int y) {
    setlinecolor(YELLOW);
    setfillcolor(BLACK);
    fillrectangle(x * 200 + 20, y * 200 + 20, (x + 1) * 200 + 20, (y + 1) * 200 + 20);
}

void DrawCross(int x, int y) {
    setlinecolor(WHITE);
    line(x * 200 + 40, y * 200 + 40, (x + 1) * 200, (y + 1) * 200);
    line(x * 200 + 40, (y + 1) * 200, (x + 1) * 200, y * 200 + 40);
}

void DrawCircle(int x, int y) {
    setlinecolor(WHITE);
    circle(x * 200 + 120, y * 200 + 120, 80);
}

int Judge(char board[3][3], int x, int y) {
    int flag = 0;
    if ((board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ') ||
            (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ') ||
            (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ') ||
            (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != ' ' && board[1][0] != ' ' && board[2][0] != ' ') ||
            (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != ' ' && board[1][1] != ' ' && board[2][1] != ' ') ||
            (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != ' ' && board[1][2] != ' ' && board[2][2] != ' ') ||
            (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ' && board[1][1] != ' ' && board[2][2] != ' ') ||
            (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != ' ' && board[1][1] != ' ' && board[0][2] != ' ')) {
        flag = 1;
        if (board[x][y] == 'c') outtextxy(720, 300, _T("Congratulations! Cross has won!"));
        else if (board[x][y] == 'o') outtextxy(720, 300, _T("Congratulations! Circle has won!"));
    }
    return flag;
}