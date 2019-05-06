#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scorilling.h"
void animationright(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso){
SDL_Surface *image1=NULL, *image2=NULL;
image1=IMG_Load("1.png");
image2=IMG_Load("2.png");
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
SDL_BlitSurface(image1,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);

SDL_Delay(150);
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(image2,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);
SDL_Delay(150);
SDL_FreeSurface(image1);
SDL_FreeSurface(image2);

}
void animationleft(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso){
SDL_Surface *image1=NULL, *image2=NULL;
image1=IMG_Load("3.png");
image2=IMG_Load("4.png");
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
SDL_BlitSurface(image1,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);

SDL_Delay(150);
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(image2,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);
SDL_Delay(150);
SDL_FreeSurface(image1);
SDL_FreeSurface(image2);
}

void moving_right(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso){
if  (positionmilieu->x>=516 && positionFond->x<=6000)
            positionFond->x += 25;
        else if (positionmilieu->x<=750) 
            positionmilieu->x +=65;

}

void moving_left(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso){
if (positionmilieu->x<=258 && positionFond->x>=10)
            positionFond->x -= 25;
      else if (positionmilieu->x>=0)
      positionmilieu->x -= 65;

}
void jump(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso){
for(int i=0;i<20;i++){
positionmilieu->y-=10;
            
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(imageDePerso,NULL, ecran, positionmilieu);
    SDL_Flip(ecran);
}}
void gravity(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso,int gravity){
 while(positionmilieu->y<gravity){
positionmilieu->y+=10;
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(imageDePerso,NULL, ecran,positionmilieu);     
    SDL_Flip(ecran);
}}


