#include<graphics.h>
#include<stdio.h>
#include<math.h>
int bitir(int puan);
void kaydet();
void rekorlar();
double labirent();
void yem();
void yon();
void level();
void ghost();
void clyde();
void pinky();
int kac(int *x,int *y,int *i,int *j);
int saldir(int *x,int *y,int *i,int *j);
void inky();
void guc();
void ekran();
int oyna(void);
int agiz(char b);
FILE *fp;
char sayi[3],tus,isim[20];  
int i;
int l=7,m=10,seviye,score=0;
int mavi=0,sayac,kovalama=1;
static int f=1;//ölme
char str[11][20];//kayit ismi
int puan[4];
char tmp[20];//skor kayýt
int dizi [20][20]={
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,0},
{0,8,0,0,0,2,0,0,0,2,0,2,0,0,0,2,0,0,8,0},
{0,2,0,0,0,2,0,0,0,2,0,2,0,0,0,2,0,0,2,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},//5
{0,2,0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,0,2,0},
{0,2,0,0,0,2,0,2,0,0,0,0,0,2,2,2,0,0,2,0},
{0,2,2,2,2,2,0,2,2,2,2,2,2,2,0,2,0,0,2,0},//8
{0,2,0,0,0,2,2,2,0,0,0,0,0,2,0,2,0,2,2,0},
{0,2,0,2,2,2,0,2,0,0,0,0,0,2,0,2,2,2,0,0},
{0,2,0,2,0,2,0,2,2,2,2,2,2,2,0,2,0,2,0,0},
{0,2,0,2,0,2,0,2,0,0,0,0,0,2,0,2,0,2,0,0},
{0,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,0},
{0,2,0,0,0,2,0,0,0,2,0,2,0,0,0,2,0,0,2,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,0},
{0,2,0,0,0,2,0,0,0,2,0,0,0,0,0,2,0,2,0,0},
{0,8,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,8,0,0},
{0,2,0,0,0,2,0,0,0,2,0,0,0,0,0,2,2,2,0,0},
{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
int main (void)
{
    initwindow(1000,700);
    ekran();
}
int oyna(void)
{
    int i=0,j=0,k=0,z=0,tekislem=0;
    char tus,yedek,sayi[4];
    cleardevice();
    setfillstyle( 1, YELLOW ); 
    sector(350+i,250+j,30-z,330+z,15,15);
    while(f!=0 && tus!=3)
    {
               if(tekislem==0)
               {
                      if(seviye==1)
                      {
                                     pinky();
                                     clyde();
                                     inky();
                                     ghost();
                                     tekislem+=1;
                      }
                                if(seviye==0)
                                {
                                               inky();
                                               ghost();
                                               tekislem+=1;
                                }
               } 
    sprintf(sayi,"%d",score);
    outtextxy(800,500,sayi); 
    labirent();
    yem();
    if(tus==72) sector(350+i,250+j,120-z,60+z,15,15); 
                else if(tus==80) sector(350+i,250+j,300-z,240+z,15,15);
                else if(tus==75) sector(350+i,250+j,210-z,150+z,15,15);
                else if(tus==77) sector(350+i,250+j,30-z,330+z,15,15); 
    setfillstyle( 1, YELLOW );
    swapbuffers(); 
    tus=getch();           
    girdi:
    for(i;(tus==77 && dizi[l][m+1]!=0);)
    {
    guc();
    while(kbhit()) yedek=getch();
    if((yedek==72 && dizi[l-1][m]!=0) || (yedek==80 && dizi[l+1][m]!=0) || (yedek==75 && dizi[l][m-1]!=0))
                  {
                   tus=yedek;
                   goto girdi;
                  }
             else
                  { 
                    z=agiz(tus);
                    if(dizi[l][m+1]==8)
                               {
                                 score=score+20;
                                 mavi=1;
                                 kovalama=0;
                               }
                    if(dizi[l][m+1]==2)
                    score=score+10;
                    sprintf(sayi,"%d",score);
                    outtextxy(800,500,sayi); 
                    m=m+1;
                    i=i+35;
                    swapbuffers();
                    cleardevice();
                    if(seviye==1)
                                 {
                                       ghost();
                                       clyde();
                                       pinky();
                                       inky();
                                 }
                    if(seviye==0)
                                 {
                                       ghost();
                                       inky();
                                 }
                    setcolor(YELLOW);
                    sector(350+i,250+j,30-z,330+z,15,15);
                    delay(250);
                    yem();
                    labirent();
                    if(mavi==0 && f==0) break; 
                    dizi[l][m]=1;
                  }
    }
    for(i;(tus==75 && dizi[l][m-1]!=0);)
    {
     guc();
     while(kbhit()) yedek=getch();
     if((yedek==72 && dizi[l-1][m]!=0) || (yedek==80 && dizi[l+1][m]!=0) || (yedek==77 && dizi[l][m+1]!=0))
                   {
                    tus=yedek;
                    goto girdi;
                    }
                    else
                    {
                    z=agiz(tus);
                    if(dizi[l][m-1]==2)
                    score=score+10;
                    if(dizi[l][m-1]==8)
                                       {
                                       kovalama=0;
                                       score=score+20;
                                       mavi=1;
                                       }
                    sprintf(sayi,"%d",score);
                    outtextxy(800,500,sayi); 
                    m=m-1;
                    i=i-35;
                    swapbuffers();
                    cleardevice();
                                  if(seviye==1)
                                  {
                                  ghost();
                                  clyde();
                                  pinky();
                                  inky();
                                  }
                                  if(seviye==0)
                                  {
                                  ghost();
                                  inky();
                                  }
                                  setcolor(YELLOW);
                                  sector(350+i,250+j,210-z,150+z,15,15);
                                  delay(250);
                                  yem();
                                  labirent();
                                  if(mavi==0 && f==0) break;
                                  dizi[l][m]=1;
                    }
     }
     for(j;(tus==80 && dizi[l+1][m]!=0);)
     {
     guc();
     while(kbhit()) yedek=getch();
     if((yedek==72 && dizi[l-1][m]!=0) || (yedek==77 && dizi[l][m+1]!=0) || (yedek==75 && dizi[l][m-1]!=0)) 
                   {
                      tus=yedek;
                      goto girdi;
                   }
                   else
                   {
                   z=agiz(tus);
                   if(dizi[l+1][m]==2)
                   score=score+10;
                   if(dizi[l+1][m]==8)
                                      {
                                      kovalama=0;
                                      score=score+20;
                                      mavi=1;
                                      }
                   sprintf(sayi,"%d",score);
                   outtextxy(800,500,sayi); 
                   l=l+1;
                   j=j+35;
                   swapbuffers();
                   cleardevice();
                   if(seviye==1)
                   {
                   ghost();
                   clyde();
                   pinky();
                   inky();
                   }
                   if(seviye==0)
                   {
                   ghost();
                   inky();
                   }
                   setcolor(YELLOW);
                   sector(350+i,250+j,300-z,240+z,15,15);
                   delay(250);
                   yem();
                   labirent();
                   if(mavi==0 && f==0) break;
                   dizi[l][m]=1;
                   }
     }
     for(j;(tus==72 && dizi[l-1][m]!=0);)
     {
     guc();
     while(kbhit()) yedek=getch();
     if((yedek==77 && dizi[l][m+1]!=0) || (yedek==80 && dizi[l+1][m]!=0) || (yedek==75 && dizi[l][m-1]!=0))
     {
      tus=yedek;
      goto girdi;
      }
                  else
                   {
                        z=agiz(tus);
                        if(dizi[l-1][m]==2)
                        score=score+10;
                        if(dizi[l-1][m]==8)
                              { 
                                            kovalama=0;
                                            score=score+20;
                                            mavi=1;
                              } 
                        sprintf(sayi,"%d",score);
                        outtextxy(800,500,sayi); 
                        l=l-1;
                        j=j-35;
                        swapbuffers();
                        cleardevice();
                        if(seviye==1)
                        {
                        ghost();
                        clyde();
                        pinky();
                        inky();
                        }
                        if(seviye==0)
                                     {
                                     ghost();
                                     inky();
                                     }
                        setcolor(YELLOW);
                        sector(350+i,250+j,120-z,60+z,15,15); 
                        delay(250);
                        yem();
                        labirent();
                        if(mavi==0 && f==0) break;
                        dizi[l][m]=1;
                        }
                  }
      }
      swapbuffers();
      readimagefile("go.bmp",0,0,1000,700);
      bitir(score);

      }
double labirent()
{
       int i=0,j=0;
       for(i=0;i<20;i++)
                for( j=0;j<20;j++)
                        if(dizi[j][i]==0)
                                         {
                                         setcolor(WHITE);
                                         line(i*35, j*35, double(i+0.5)*35,double(j+0.5)*35 );
                                         line(double(i+0.5)*35, (j)*35, (i)*35, double(j+0.5)*35 );
                                         line(i*35, j*35, double(i+0.5)*35,double(j+0.5)*35 );
                                         }
}      
void yem()
{
     int i=0,j=0;
     for(i=0;i<20;i++) 
          for( j=0;j<20;j++) 
               if(dizi[j][i]==2) 
               {
               setcolor(YELLOW); 
               fillellipse( i*35,j*35,2,3);
               }
     for(i=0;i<20;i++) 
          for( j=0;j<20;j++)
               if(dizi[j][i]==8)
               { 

               fillellipse( i*35,j*35,8,8); 
               }
}
void ghost()
{
     static int i=0,j=0,x=1,y=1;
     if(kovalama==1)
             {
                     x,y,i,j=kac(&x,&y,&i,&j);
                     if(x==l && y==m) 
                     f=0;
             }
     if(kovalama==0)
             {
                     x,y,i,j=saldir(&x,&y,&i,&j);
             }
     if(mavi==0) readimagefile("blinky.bmp",25+i,25+j,55+i,55+j); 
     if(mavi==1) readimagefile("mavi.bmp",25+i,25+j,55+i,55+j);
}
int agiz(char b)
{ 
    static int z=0;
           if(z<5) 
                   z=z+15; 
           else 
                   z=z-15;
    return z;
}
void clyde()
{
     static int i=0,j=0,x=1,y=18;
            if(kovalama==1)
            {
               x,y,i,j=kac(&x,&y,&i,&j);
               if(x==l && y==m) 
               f=0;
            }
            if(kovalama==0)
            {
               x,y,i,j=saldir(&x,&y,&i,&j);
            }
     if(mavi==0) readimagefile("clyde.bmp",620+i,30+j,650+i,60+j);
     if(mavi==1) readimagefile("mavi.bmp",620+i,30+j,650+i,60+j);
}
void inky()
{
     static int i=0,j=0,x=18,y=9;
            if(kovalama==1)
            {
               x,y,i,j=kac(&x,&y,&i,&j);
               if(x==l && y==m) 
               f=0;
            }
            if(kovalama==0)
            {
               x,y,i,j=saldir(&x,&y,&i,&j);
            }
     if(mavi==0)readimagefile("inky.bmp",300+i,620+j,330+i,650+j);
     if(mavi==1)readimagefile("mavi.bmp",300+i,620+j,330+i,650+j);

}
void pinky()
{
     static int i=0,j=0,x=18,y=10;
            if(kovalama==1)
            {
               x,y,i,j=kac(&x,&y,&i,&j);
               if(x==l && y==m) 
               f=0;
            }
            if(kovalama==0)
            {
               x,y,i,j=saldir(&x,&y,&i,&j);
            }
     if(mavi==0)readimagefile("pinky.bmp",330+i,620+j,360+i,650+j);
     if(mavi==1)readimagefile("mavi.bmp",330+i,620+j,360+i,650+j);
}
int bitir(int puan)
{ 
    swapbuffers(); 
    readimagefile("go.bmp",0,0,1000,700);
    kaydet();
}
void ekran()
{
     char tus;
     int x,y;
     readimagefile("PACMAN.gif",0,0, 1000,700); 
     settextstyle(6,0,1);
     outtextxy(50,50,"Yeni Oyun");
     outtextxy(300,50,"Oyun Tuslari");
     outtextxy(600,50,"Rekorlar");
     outtextxy(850,50,"Cikis");
     outtextxy(50,630,"2011639032");
     outtextxy(50,650,"8-Ender GÜRLER(c)");
     
     while(1)
     { 
             getmouseclick(WM_LBUTTONDOWN,x,y); 
             if(x>50 && x<160 && y>50 && y<70)
                     {
                              level();
                     }
             else if(x>300 && x<440 && y>50 && y<70)
                     {
                     cleardevice();
                     outtextxy(200,50,"Pacmani yonlendirmek icin yon tuslarini kullaniniz.");
                     outtextxy(20,570,"Geri");
                     while(1)
                             {
                             getmouseclick(WM_LBUTTONDOWN,x,y);
                             if(x>20 && x<100 && y>550 && y<600) ekran();
                             }
                     }
             else if(x>600 && x<700 && y>50 && y<70)
                  {
                  rekorlar();
                  }
             else if(x>850 && x<910 && y>50 && y<70)
                  {
                  outtextxy(150,150,"Pacmandan cikmak istiyor musunuz?(E-H)");

                  tus=getch();
                  if(tus=='e') break;
                  if(tus=='h')ekran();
                  }
   }
}
void guc()
     {
      if(mavi==1)sayac=sayac+1;
      if(sayac==10)
                   {
                    mavi=0;
                    sayac=0;
                    kovalama=1;
                    }
      }
int kac(int *x,int *y,int *i,int *j)
{
    int fark,eksi;
    fark=*x-l;
    eksi=*y-m;
    if(fark>=eksi && fark>0 && eksi>0)
        {
                  if(*x>l && dizi[*x-1][*y]!=0) 
                  {
                  *x=*x-1;
                  *j=*j-35;
                  }
                  else if(*y>m && dizi[*x][*y-1]!=0)
                  {
                  *y=*y-1;
                  *i=*i-35;
                  }
                  else if(*y>m && dizi[*x][*y+1]!=0)
                  {
                  *y=*y+1;
                  *i=*i+35;
                  }
        }
    if(fark>=eksi && fark==0 && eksi<0)
        {
                  if(*y<m && dizi[*x][*y+1])
                  {
                  *y=*y+1;
                  *i=*i+35;
                  }
                  else if(*x==l && dizi[*x+1][*y]!=0)
                  {
                  *x=*x+1;
                  *j=*j+35;
                  }
                  else if(*x==l && dizi[*x-1][*y]!=0)
                  {
                  *x=*x-1;
                  *j=*j-35;
                  }
        }
    if(fark>=eksi && eksi==0 && fark>0)
        {
                    if(*x>l && dizi[*x-1][*y]!=0)
                    {
                    *x=*x-1;
                    *j=*j-35;
                    }
                    else if(*y==m && dizi[*x][*y+1]!=0)
                    {
                    *y=*y+1;
                    *i=*i+35;
                    }
                    else if(*y==m && dizi[*x][*y-1]!=0)
                    {
                    *y=*y-1;
                    *i=*i-35;
                    }
        }
    if(fark>=eksi && eksi<0 && fark<0)
        {
                    if(*y<m && dizi[*x][*y+1])
                    {
                    *y=*y+1;
                    *i=*i+35;
                    }
                    else if(*x<l && dizi[*x+1][*y]!=0)
                    {
                    *x=*x+1;
                    *j=*j+35;
                    }
                    else if(*x<l && dizi[*x-1][*y]!=0)
                    {
                    *x=*x-1;
                    *j=*j-35;
                    }
      }
    if(fark>=eksi && eksi<0 && fark>0)
      {
                    if(*y<m && dizi[*x][*y+1])
                    {
                    *y=*y+1;
                    *i=*i+35;
                    }
                    else if(*x>l && dizi[*x-1][*y]!=0)
                    {
                    *x=*x-1;
                    *j=*j-35;
                    } 
                    else if(*x>l && dizi[*x+1][*y]!=0)
                    {
                    *x=*x+1;
                    *j=*j+35;
                    }
      }
      if(fark>=eksi && eksi==0 && fark<0)
      {
                    if(*x<l && dizi[*x+1][*y]!=0)
                    {
                    *x=*x+1;
                    *j=*j+35;
                    }
                    else if(*y==m && dizi[*x][*y+1]!=0)
                    {
                    *y=*y+1;
                    *i=*i+35;
                    }
                    else if(*y==m && dizi[*x][*y-1]!=0)
                    {
                    *y=*y-1;
                    *i=*i-35;
                    }
      }


      if(eksi>fark && fark<0 && eksi<0)
      {
                    if(*x<l && dizi[*x+1][*y]!=0) 
                    {
                    *x=*x+1;
                    *j=*j+35;
                    }
                    else if(*y<m && dizi[*x][*y+1]!=0)
                    {
                    *y=*y+1;
                    *i=*i+35;
                    }
                    else if(*y<m && dizi[*x][*y-1]!=0)
                    {
                    *y=*y-1;
                    *i=*i-35;
                    }
      }
      if(eksi>fark && fark>0 && eksi>0)
      {
                    if(*y>m && dizi[*x][*y-1]!=0)
                    {
                    *y=*y-1;
                    *i=*i-35;
                    }
                    else if(*x<l && dizi[*x+1][*y]!=0)
                    {
                    *x=*x+1;
                    *j=*j+35;
                    }
                    else if(*x>l && dizi[*x-1][*y]!=0)
                    {
                    *x=*x-1;
                    *j=*j-35;
                    }
      }
      if(eksi>fark && fark<0 && eksi>0)
      {
                    if(*y>m && dizi[*x][*y-1]!=0)
                    {
                    *y=*y-1;
                    *i=*i-35;
                    }
                    else if(*x<l && dizi[*x+1][*y]!=0)
                    {
                    *x=*x+1;
                    *j=*j+35;
                    }
                    else if(*x>l && dizi[*x-1][*y]!=0)
                    {
                    *x=*x-1;
                    *j=*j-35;
                    }
      }


      if(eksi>fark && fark==0 && eksi>0)
      {
                    if(*y>m && dizi[*x][*y-1])
                    {
                    *y=*y-1;
                    *i=*i-35;
                    }
                    else if(*x==l && dizi[*x+1][*y]!=0)
                    {
                    *x=*x+1;
                    *j=*j+35;
                    }
                    else if(*x==l && dizi[*x-1][*y]!=0)
                    {
                    *x=*x-1;
                    *j=*j-35;
                    }
      }
      if(eksi>fark && eksi==0 && fark<0)
      {
                    if(*x<l && dizi[*x+1][*y]!=0)
                    {
                    *x=*x+1;
                    *j=*j+35;
                    }
                    else if(*y==m && dizi[*x][*y+1]!=0)
                    {
                    *y=*y+1;
                    *i=*i+35;
                    }
                    else if(*y==m && dizi[*x][*y-1]!=0)
                    {
                    *y=*y-1;
                    *i=*i-35;
                    }
      }

      return *x,*y,*i,*j;
}
int saldir(int *x,int *y,int *i,int *j)
{
    int fark,eksi;
    fark=*x-l;
    eksi=*y-m;
    if(fark>=eksi && fark>0 && eksi>0)
    {
                if(*x>l && dizi[*x+1][*y]!=0) 
                {
                *x=*x+1;
                *j=*j+35;
                }
                else if(*y>m && dizi[*x][*y+1]!=0)
                {
                *y=*y+1;
                *i=*i+35;
                }
                else if(*y>m && dizi[*x][*y-1]!=0)
                {
                *y=*y-1;
                *i=*i-35;
                }
    }
    if(fark>=eksi && fark==0 && eksi<0)
    {
                if(*y<m && dizi[*x][*y-1])
                {
                *y=*y-1;
                *i=*i-35;
                }
                else if(*x==l && dizi[*x-1][*y]!=0)
                {
                *x=*x-1;
                *j=*j-35;
                }
                else if(*x==l && dizi[*x+1][*y]!=0)
                {
                *x=*x+1;
                *j=*j+35;
                }
    }
    if(fark>=eksi && eksi==0 && fark>0)
    {
                if(*x>l && dizi[*x+1][*y]!=0)
                {
                *x=*x+1;
                *j=*j+35;
                }
                else if(*y==m && dizi[*x][*y-1]!=0)
                {
                *y=*y-1;
                *i=*i-35;
                }
                else if(*y==m && dizi[*x][*y+1]!=0)
                {
                *y=*y+1;
                *i=*i+35;
                }
    }
    if(fark>=eksi && eksi<0 && fark<0)
    {
                if(*y<m && dizi[*x][*y-1])
                {
                *y=*y-1;
                *i=*i-35;
                }
                else if(*x<l && dizi[*x-1][*y]!=0)
                {
                *x=*x-1;
                *j=*j-35;
                }
                else if(*x<l && dizi[*x+1][*y]!=0)
                {
                *x=*x+1;
                *j=*j+35;
                }
    }
    if(fark>=eksi && eksi<0 && fark>0)
    {
                if(*y<m && dizi[*x][*y-1])
                {
                *y=*y-1;
                *i=*i-35;
                }
                else if(*x>l && dizi[*x+1][*y]!=0)
                {
                *x=*x+1;
                *j=*j+35;
                } 
                else if(*x>l && dizi[*x-1][*y]!=0)
                {
                *x=*x-1;
                *j=*j-35;
                }
    }
    if(fark>=eksi && eksi==0 && fark<0)
    {
                if(*x<l && dizi[*x-1][*y]!=0)
                {
                *x=*x-1;
                *j=*j-35;
                }
                else if(*y==m && dizi[*x][*y-1]!=0)
                {
                *y=*y-1;
                *i=*i-35;
                }
                else if(*y==m && dizi[*x][*y+1]!=0)
                {
                *y=*y+1;
                *i=*i+35;
                }
    }


    if(eksi>fark && fark<0 && eksi<0)
    {
                if(*x<l && dizi[*x-1][*y]!=0) 
                {
                *x=*x-1;
                *j=*j-35;
                }
                else if(*y<m && dizi[*x][*y-1]!=0)
                {
                *y=*y-1;
                *i=*i-35;
                }
                else if(*y<m && dizi[*x][*y+1]!=0)
                {
                *y=*y+1;
                *i=*i+35;
                }
    }
    if(eksi>fark && fark>0 && eksi>0)
    {
                if(*y>m && dizi[*x][*y+1]!=0)
                {
                *y=*y+1;
                *i=*i+35;
                }
                else if(*x<l && dizi[*x-1][*y]!=0)
                {
                *x=*x-1;
                *j=*j-35;
                }
                else if(*x>l && dizi[*x+1][*y]!=0)
                {
                *x=*x+1;
                *j=*j+35;
                }
    }
    if(eksi>fark && fark<0 && eksi>0)
    {
                if(*y>m && dizi[*x][*y+1]!=0)
                {
                *y=*y+1;
                *i=*i+35;
                }
                else if(*x<l && dizi[*x-1][*y]!=0)
                {
                *x=*x-1;
                *j=*j-35;
                }
                else if(*x>l && dizi[*x+1][*y]!=0)
                {
                *x=*x+1;
                *j=*j+35;
                }
    }
    if(eksi>fark && fark==0 && eksi>0)
    {
                if(*y>m && dizi[*x][*y+1])
                {
                *y=*y+1;
                *i=*i+35;
                }
                else if(*x==l && dizi[*x-1][*y]!=0)
                {
                *x=*x-1;
                *j=*j-35;
                }
                else if(*x==l && dizi[*x+1][*y]!=0)
                {
                *x=*x+1;
                *j=*j+35;
                }
    }
    if(eksi>fark && eksi==0 && fark<0)
    {
                if(*x<l && dizi[*x-1][*y]!=0)
                {
                *x=*x-1;
                *j=*j-35;
                }
                else if(*y==m && dizi[*x][*y-1]!=0)
                {
                *y=*y-1;
                *i=*i-35;
                }
                else if(*y==m && dizi[*x][*y+1]!=0)
                {
                *y=*y+1;
                *i=*i+35;
                }

    }
    return *x,*y,*i,*j;
}
void kaydet()
{
     initwindow(400,400);
     sprintf(sayi,"%d",score);
     settextstyle(8,0,2);
     outtextxy(150,170,"Adinizi girin:");
     outtextxy(300,300,sayi);
     while(tus!=13) 
     {  
                    for(i=0;tus!=13;i++)
                    {
                    tus=getch();
                    isim[i]=tus;
                    outtextxy(200+i,200,isim);
                    isim[i+1]='\0';
                    }
     }
     fp=fopen("puan.txt","a");
     fprintf(fp,"%s %d\n",isim,score);
   	 fclose(fp);
   	
}
void rekorlar()
{
    char rkr[4][4];
    char tmp1[20];
    int k,j,e,gecici;
    fp=fopen("puan.txt","r");
     while(fscanf(fp,"%s %d\n",(str+i),(puan+i))!=EOF)i++;
     	for(k=0;k<20;k++)
         for(j=0;j<20;j++)
          if(puan[j]<puan[j+1])
          {
                  gecici=puan[j];
                  strcpy(tmp1,&str[j][0]);
                  puan[j]=puan[j+1];
                  strcpy(&str[j][0],&str[j+1][0]);
                  puan[j+1]=gecici;
                  strcpy(&str[j+1][0],tmp1);
          }
    fclose(fp);
    for(e=0;e<5;e++)
    sprintf(rkr[e],"%d",puan[e]);
    outtextxy(100,100,str[0]);
    outtextxy(200,100,rkr[0]);
    outtextxy(100,120,str[1]);
    outtextxy(200,120,rkr[1]);
    outtextxy(100,140,str[2]);
    outtextxy(200,140,rkr[2]);
    outtextxy(100,160,str[3]);
    outtextxy(200,160,rkr[3]);
    outtextxy(100,180,str[4]);
    outtextxy(200,180,rkr[4]);
}
void level()
{
     int x,y;
     cleardevice();
     settextstyle(6,0,1);
     outtextxy(50,50,"Kolay");
     outtextxy(200,50,"Zor");
     while(1)
     { 
     getmouseclick(WM_LBUTTONDOWN,x,y); 
     if(x>50 && x<160 && y>50 && y<70)
                                      {
                                      seviye=0;
                                      oyna();
                                      }
     if(x>200 && x<350 && y>50 && y<70)
                                       {
                                       seviye=1;
                                       oyna();
                                       }
     }
}
