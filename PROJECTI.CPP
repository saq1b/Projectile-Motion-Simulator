#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
void stats(double ang, int v){
    cleardevice(); gotoxy(1,1);
    auto double H, R;
    H=pow((v*sin(ang)), 2)/(2*9.8);
    cout<<"Max. Height Reached = "<<H<<" metres\n";
    R=(powl(v, 2)*sin(2*ang))/9.8;
    cout<<"Displacement = "<<R<<" metres";
    getch();
}
void main()
{
  clrscr();
  int gd=DETECT, gm, x, y, u, xrand, yrand, radius, diff;
  initgraph(&gd, &gm, "c:\\turboc3\\bgi");
  clearviewport(); setbkcolor(BLACK);
  lev :
  cout<<"Choose Your Difficulty Level\n1. Easy (Moon)\n2. Bearable (Football)\n3. Hard (Cricket Ball)\n\n\t ENTER YOUR CHOICE ";
  cin>>diff;
  if (diff<1||diff>3)
  {  cout<<"Look at the keyboard\n";
     goto lev;
  }
  clrscr();  clearviewport(); setbkcolor(BLACK);
  radius=(60/diff)-10;
  randomize();
  xrand=rand()%500;  yrand=rand()%350;
  double theta, sl;
  // float time;
  circle(xrand, yrand, radius);
  cout<<"Enter Angle (degrees) "; cin>>theta;
  cout<<"Enter Speed (m/s) "; cin>>u;
  clrscr();
  cleardevice();
  theta*=0.0174532925199433;
 // time=(2*u*sin(theta))/9.8;
  sector(xrand, yrand,0,360,radius,radius);
  for (x=1; x<=getmaxx(); x++)
  {
    y=(x*tan(theta))-(9.8*x*x)/(2*powl((u* cos(theta)), 2));
    sl=(480-y)/x;
    if (sl==0)
       sl=1;
    putpixel(x, 479-y, RED);
    delay(9.8/sl);
    if (kbhit())
       break;
    if(getpixel(x,480-y)==WHITE){
       setcolor(RED);
       setfillstyle(1,RED);
       sector(xrand, yrand,0,360,radius,radius);
       gotoxy(20,20);
       cout<<"What a Shot";
       break;
       }
  }
  getch();
  stats(theta, u);
  char re;
  clrscr();
  clearviewport();
  setbkcolor(BLACK);
  cout<<"Press Y Play Again (any other key to exit)";  re=getche();
  if (re=='y'||re=='Y')
     main();
}

