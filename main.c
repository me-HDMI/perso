#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
int main (int argc, char **argv)
{
int t;
int occ=0;
    SDL_Surface *ecran = NULL;
    SDL_Surface *perso[7] = {NULL};
    SDL_Event event;
SDL_Surface* map;
    SDL_Rect positionperso;
    int i = 0, continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(900, 400, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Animation", NULL);
perso[0] = IMG_Load("s1.png");
perso[1] = IMG_Load("s2.png");
perso[2] = IMG_Load("s3.png");
//map=IMG_Load("background.bmp");

 
    positionperso.x = 0;
    positionperso.y = 260;
     
    SDL_EnableKeyRepeat(100,100);
    while(continuer)
    {
	
        SDL_WaitEvent(&event);
        switch(event.type)
        {

            case SDL_QUIT:
            continuer = 0;
            break;
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_LEFT:
                if(i >= 2)
                i = 0;
                positionperso.x -= 20;
                i++; 
                break;

                case SDLK_RIGHT:
                if(i >= 2)
                i = 0;
                positionperso.x += 20;
                i++;
                break;
                  
                case SDLK_DOWN:
                if(i >= 2)
                i = 0;
                positionperso.y += 20;
                i++;
                break;
             
                case SDLK_UP:
                
                i = 0;

                positionperso.y=positionperso.y-100;

                occ=1; 
                 
                

                break;
          
}

printf("La position en x est %d \n",positionperso.x);
printf("La position en y est %d \n",positionperso.y);


if(positionperso.y>260)
{
positionperso.y=260;
}


if(positionperso.x==880)
{

positionperso.x=0;
positionperso.y=260;
}


SDL_BlitSurface(map,NULL,ecran,NULL); 
SDL_BlitSurface(perso[i], NULL, ecran, &positionperso);
        SDL_Flip(ecran);

if(occ==1)
{
if(positionperso.y<360)
{

SDL_Delay(200);
positionperso.y+=100;
SDL_BlitSurface(map,NULL,ecran,NULL);  
SDL_BlitSurface(perso[i], NULL, ecran, &positionperso);

        SDL_Flip(ecran);

}

occ=0;
}
 
       
}
SDL_BlitSurface(map,NULL,ecran,NULL);  
SDL_BlitSurface(perso[i], NULL, ecran, &positionperso);

        SDL_Flip(ecran);
}


    for(i = 0; i < 3; i++)
    SDL_FreeSurface(perso[i]);
    SDL_FreeSurface(map);
    SDL_Quit();

    return EXIT_SUCCESS;
}
