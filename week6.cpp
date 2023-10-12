//
// Created by Kevin Ye on 10/12/2023.
// Copyright (c) KevinYe on 10/12/2023.

#include <conio.h>
#include "graphics.h"

int main() {
    char choice;
    initgraph(640, 480);
    do {
        cleardevice();
        outtextxy(300, 40, _T("1. Circle"));
        outtextxy(300, 70, _T("2. Rectangle"));
        outtextxy(300, 100, _T("3. Ellipse"));
        outtextxy(300, 130, _T("4. Pie"));
        outtextxy(300, 160, _T("0. Exit"));

        choice = getch();
        cleardevice();
        switch (choice) {
            case '1':circle(200, 200, 100);
                break;
            case '2':fillrectangle(90, 90, 390, 390);
                break;
            case '3':fillellipse(90, 90, 390, 390);
                break;
            case '4': fillpie(60, 60, 380, 380, 0, 3.14);
                break;
            default: outtextxy(100, 450, _T("Press any key to continue..."));
        }
        outtextxy(100, 450, _T("Press any key to continue..."));
        getch();
    } while (choice != '0');
    closegraph();
}