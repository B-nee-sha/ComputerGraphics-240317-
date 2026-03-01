
/*Midpoint Circle Algorithm:
The Midpoint Circle Algorithm is an efficient raster graphics algorithm used to draw a circle by determining the next pixel position based on a midpoint decision parameter.
It starts from the top of the circle and calculates points for one octant using integer arithmetic, then uses symmetry to plot the remaining points in the other seven octants. 
 This reduces computational complexity and avoids floating-point calculations, making it fast and accurate for computer graphics applications.
 */
 
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void draw_circle(int,int,int);
void symmetry(int,int,int,int);
int main()
{
  
    int xc,yc,R;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    printf("Enter the center of the circle:\n");
    printf("Xc =");
    scanf("%d",&xc);
    printf("Yc =");
    scanf("%d",&yc);
    printf("Enter the radius of the circle :");
    scanf("%d",&R);
    draw_circle(xc,yc,R);
    outtextxy(xc-25,yc,"BINISHA");
    getch();
    closegraph();
    return 0;
}
void draw_circle(int xc,int yc,int rad)
{
    int x = 0; int y= rad; 
    int p =1-rad;
    symmetry(x,y,xc,yc);
    for(x=0;y>x;x++)
    {
        if(p<0)
        p += 2*x + 3;
    else
    {
        p += 2*(x-y) + 5;
        y--;
    }
    symmetry(x,y,xc,yc);
    delay(50);
}
}
void symmetry(int x,int y,int xc,int yc)
{
    putpixel(xc+x,yc-y,GREEN); //For pixel (x,y)
    delay(50);
    putpixel(xc+y,yc-x, GREEN); //For pixel (y,x)
    delay(50);
    putpixel(xc+y,yc+x, GREEN); //For pixel (y,-x)
    delay(50);
    putpixel(xc+x,yc+y, GREEN); //For pixel (x,-y)
    delay(50);
    putpixel(xc-x,yc+y, GREEN); //For pixel (-x,-y)
    delay(50);
    putpixel(xc-y,yc+x, GREEN); //For pixel (-y,-x)
    delay(50);
    putpixel(xc-y,yc-x, GREEN); //For pixel (-y,x)
    delay(50);
    putpixel(xc-x,yc-y, GREEN); //For pixel (-x,y)
    delay(50);
}


