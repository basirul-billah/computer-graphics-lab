#include <graphics.h>
#include <stdio.h>
#include <math.h>

void dda_line(float x1, float y1, float x2, float y2)
{
    float x, y, dx, dy, step;

    x = x1;
    y = y1;

    dx = x2-x1;
    dy = y2-y1;

    if(abs(dx)>=abs(dy))
        step=abs(dx);
    else
        step=abs(dy);

    dx = dx/step;
    dy = dy/step;

    int color = 0;

    for(int i=1; i<=step; i++)
    {
        putpixel(round(x), round(y), color);
        x = x + dx;
        y = y + dy;
        i = i + 1;
        color += 2;
        if(color>=15)
            color=0;
    }

    getch();
    closegraph();
}

int main()
{
    float x1, y1, x2, y2;
    int i, gd=DETECT, gm;

    initgraph(&gd,&gm,"c:\\tc\\bgi");

    printf("Enter x1, y1, x2, y2: ");
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);

    dda_line(x1, y1, x2, y2);
}
