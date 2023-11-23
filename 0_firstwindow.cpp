#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include<stdio.h>

int main() {
    int left, top, bottom, right, stangle, endangle;
    scanf("%d%d%d%d%d%d", &left, &top, &right, &bottom, &stangle, &endangle);
    initgraph(1024, 768);   // 创建绘图窗口，大小为 640x480 像素
    rectangle(left, top, right, bottom);
    ellipse(left, top, right, bottom);
    pie(left, top, right, bottom, stangle, endangle);
    _getch();              // 按任意键继续
    closegraph();          // 关闭绘图窗口
    return 0;
}