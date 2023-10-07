//
// Created by Kevin Ye on 10/7/2023.
// Copyright (c) KevinYe on 10/7/2023.


#include <graphics.h>
#include <conio.h>

int main() {
    int left = 100, top = 100, bottom = 300, right = 500, stangle = 0, endangle = 1, ch;
    initgraph(1024, 768);
    outtextxy(900, 10, _T("1.Circle"));
    outtextxy(900, 30, _T("2.Rectangle"));
    outtextxy(900, 50, _T("3.Ellipse"));
    outtextxy(900, 70, _T("4.Fan"));
    outtextxy(900, 90, _T("0.Exit"));
    while (1) {
        ch = getch();
        if (ch == '1')
            circle(512, 384, 100);
        else if (ch == '2')
            rectangle(left, top, right, bottom);
        else if (ch == '3')
            ellipse(left, top, right, bottom);
        else if (ch == '4')
            pie(left, top, right, bottom, stangle, endangle);
        else if (ch == '0')
            closegraph();
    }
}