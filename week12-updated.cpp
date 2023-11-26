//
// Created by Kevin Ye on 11/23/2023.
// Copyright (c) KevinYe on 11/23/2023.

#include <conio.h>
#include "graphics.h"

void Opening();

void Initialize();

void DrawBoard();

void DrawPrompt();

void Highlight(int x, int y);

void Restore(int x, int y);

void DrawCross(int x, int y);

void DrawCircle(int x, int y);

void RedrawCurrent(int current, int x, int y);

int Judge(char board[3][3], int x, int y);

int main() {
    initgraph(1000, 650);
    int x = 0, y = 0;
    int flag;
    char board[3][3] = {{' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}};
    Opening();
    Initialize();
    Highlight(x, y);
    char choice;
    outtextxy(720, 550, _T("Press 'G' to start."));
    do {
        choice = getch();
        if (choice == 'g' || choice == 'r') {
            cleardevice();
            Initialize();
            x = 0;
            y = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) board[i][j] = ' ';
            }
            Highlight(x, y);
            for (int count = 1; count <= 9;) {
                char op;
                op = getch();
                if (op == 'w') {
                    Restore(x, y);
                    RedrawCurrent(board[y][x], x, y);
                    if (y == 0) y = 2;
                    else y--;
                    Highlight(x, y);
                    RedrawCurrent(board[y][x], x, y);
                } else if (op == 'a') {
                    Restore(x, y);
                    RedrawCurrent(board[y][x], x, y);
                    if (x == 0) x = 2;
                    else x--;
                    Highlight(x, y);
                    RedrawCurrent(board[y][x], x, y);
                } else if (op == 's') {
                    Restore(x, y);
                    RedrawCurrent(board[y][x], x, y);
                    if (y == 2) y = 0;
                    else y++;
                    Highlight(x, y);
                    RedrawCurrent(board[y][x], x, y);
                } else if (op == 'd') {
                    Restore(x, y);
                    RedrawCurrent(board[y][x], x, y);
                    if (x == 2) x = 0;
                    else x++;
                    Highlight(x, y);
                    RedrawCurrent(board[y][x], x, y);
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
        }
        Sleep(1000);
        outtextxy(720, 550, _T("Press 'R' to restart!"));
        outtextxy(720, 570, _T("Or press 'Z' to just quit!"));
    } while (choice != 'z');
    closegraph();
    return 0;
}

void Opening() {
    cleardevice();
    outtextxy(375, 300, _T("Welcome to the Tic-Tac-Toe game!"));
    Sleep(1000);
    outtextxy(400, 320, _T("Press any key to continue..."));
    getch();
    cleardevice();
    outtextxy(365, 300, _T("Please read the prompts before starting!"));
    Sleep(1000);
    outtextxy(400, 320, _T("Press any key to continue..."));
    getch();
    cleardevice();
    outtextxy(420, 250, _T("Press 'W' to go up!"));
    outtextxy(420, 270, _T("Press 'A' to go left!"));
    outtextxy(420, 290, _T("Press 'S' to go down!"));
    outtextxy(420, 310, _T("Press 'D' to go right!"));
    outtextxy(380, 330, _T("Press 'Enter' to confirm your play!"));
    outtextxy(375, 350, _T("Press 'Q' to exit the game while playing!"));
    Sleep(1000);
    outtextxy(400, 370, _T("Press any key to continue..."));
    getch();
    cleardevice();
    outtextxy(375, 370, _T("Now press 'Space' to start the game!"));
    while (getch() != ' ') outtextxy(375, 370, _T("Now press 'Space' to start the game!"));
    cleardevice();
}

void Initialize() {
    DrawBoard();
    DrawPrompt();
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

void RedrawCurrent(int current, int x, int y) {
    if (current == 'c') DrawCross(x, y);
    else if (current == 'o') DrawCircle(x, y);
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