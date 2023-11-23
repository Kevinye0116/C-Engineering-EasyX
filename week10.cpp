//
// Created by Kevin Ye on 11/9/2023.
// Copyright (c) KevinYe on 11/9/2023.

#include <conio.h>
#include <valarray>
#include "graphics.h"

int main() {
    initgraph(1024, 768);
    setorigin(512, 384);
    line(-512, 0, 512, 0);
    line(0, 384, 0, -384);
    for (double x = -512; x <= 512; x += 0.001) {
        double y1 = sin(x) * 10;
        double y2 = sin(x + 0.001) * 10;
        line(x * 10, y1 * 10, 10 * (x + 0.001), 10 * y2);
    }
    _getch();
    closegraph();
}
