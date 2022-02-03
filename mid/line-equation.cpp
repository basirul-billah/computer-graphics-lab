#include <graphics.h>
#include <stdio.h>

void line_drawing(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1, i;
    int dy = y2 - y1;

    int m = dy/dx;
    int c = y1 - (m*x1);

    int x=x1;
    int y=y1;

    putpixel(x, y, WHITE);

    if(m<1)
    {
        for(i=x1; i<x2; i++)
        {
            y = (m*i) + c;
            putpixel(i, y, WHITE);
        }
    }
    else
    {
        for(i=y1; i<y2; i++)
        {
            x = (i-c)/m;
            putpixel(x, i, WHITE);
        }
    }
    getch();
}

int main()
{
    int x1, y1, x2, y2, i;

    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\tc\\bgi");

    line_drawing(x1, y1, x2, y2);

    return 0;
}
