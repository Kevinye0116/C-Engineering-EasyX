#include <graphics.h>      // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include<stdio.h>

int main() {
    int left, top, bottom, right, stangle, endangle;
    scanf("%d%d%d%d%d%d", &left, &top, &right, &bottom, &stangle, &endangle);
    initgraph(1024, 768);   // ������ͼ���ڣ���СΪ 640x480 ����
    rectangle(left, top, right, bottom);
    ellipse(left, top, right, bottom);
    pie(left, top, right, bottom, stangle, endangle);
    _getch();              // �����������
    closegraph();          // �رջ�ͼ����
    return 0;
}