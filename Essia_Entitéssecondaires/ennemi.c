#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <unistd.h>
#include "ennemi.h"
void initialiserennemi(ennemis *ennemi)
{
ennemi->position.x = 200 ;
ennemi->position.y = 275 ;
ennemi->fond1 = IMG_Load("x1.png");
ennemi->fond2 = IMG_Load("x2.png");
ennemi->fonda = IMG_Load("xa.png");
ennemi->fondb = IMG_Load("xb.png");
}

ennemis mouvennemi(ennemis ennemi,int d,SDL_Rect camera,int *q,int *w,int *y)
{
time_t t;
srand((unsigned) time(&t));
int r ;
r = rand();
if((ennemi.position.x<=0||ennemi.position.x>=1000)&&(camera.x>0&&camera.x<7000))
{
if(r%6==0)
{
if(ennemi.position.x<=0)
{
ennemi.position.x=0;
}
if(ennemi.position.x>1000)
{
ennemi.position.x=1000;
}
}
}
r = rand();
if(ennemi.position.x>=0&&ennemi.position.x<=1000)
{
if(*w<10)
{
if(*q==1)
{
if(d==0||camera.x==0||camera.x==6460)
{
ennemi.position.x=ennemi.position.x-10;
return ennemi;
}
if(d==1)
{
ennemi.position.x=ennemi.position.x-20;
}
if(d==2)
{
ennemi.position.x=ennemi.position.x-5;
}
}
if(*q==2)
{
if(d==0||camera.x==0)
{
ennemi.position.x=ennemi.position.x+10;
return ennemi;
}
if(d==1)
{
ennemi.position.x=ennemi.position.x+5;
}
if(d==2)
{
ennemi.position.x=ennemi.position.x+20;
}
}
*w=*w+1;
}
if(*w==10)
{
if(r%2==0)
{
*q=1;
*y=3;
}
if(r%2!=0)
{
*q=2;
*y=1;
}
*w=0;
}
}
return ennemi;
}

int splitennemi(int y)
{

switch(y)
{
case 1:
y=2;
	break;
case 2:
y=1;
	break;
case 3:
y=4;
	break;
case 4:
y=3;
	break;
}	
return y ;
}



void afficherennemi(ennemis ennemi,SDL_Surface *ecran,int y)
{
switch(y)
{
case 1:
SDL_BlitSurface(ennemi.fond1,NULL, ecran,&ennemi.position);
	break ;
case 2:
SDL_BlitSurface(ennemi.fond2,NULL, ecran,&ennemi.position);
	break ;
case 3:
SDL_BlitSurface(ennemi.fonda,NULL, ecran,&ennemi.position);
	break ;
case 4:
SDL_BlitSurface(ennemi.fondb,NULL, ecran,&ennemi.position);
	break ;
}
}


