#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#include "scorilling.h"
int main()
{

SDL_Surface * ecran=NULL, *imageDeFond=NULL,*imageDePerso=NULL;
int mvmspeed=50;
int x=0,i;
int gravit=230;
    SDL_Rect positionFond ,positionmilieu;
    positionFond.x = 0;
    positionFond.y = 0;
    positionFond.h =1000;
    positionFond.w =800;
    positionmilieu.x = 200/2 - 50 / 2;
    positionmilieu.y = 230 ;
     SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800,1200, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("SCROLLING", NULL);
    imageDeFond = IMG_Load("backg.jpg");
    imageDePerso = IMG_Load("5.png");
  
  
 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s",Mix_GetError());
    }
    Mix_Music *musique;
    Mix_AllocateChannels(20);
    musique = Mix_LoadMUS("musique.mp3");
    Mix_PlayMusic(musique, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);
    int continuer = 1;
    SDL_Event event;
    SDL_EnableKeyRepeat(10, 10);
 SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
  SDL_BlitSurface(imageDePerso,NULL, ecran, &positionmilieu);
  SDL_Flip(ecran);
    while (continuer)
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
            case SDLK_RIGHT: 

      moving_right(&positionmilieu,&positionFond,imageDeFond,ecran,imageDePerso);
animationright(&positionmilieu,&positionFond,imageDeFond,ecran,imageDePerso);
                break;
            case SDLK_LEFT:

            	moving_left(&positionmilieu,&positionFond,imageDeFond,ecran,imageDePerso);
animationleft(&positionmilieu,&positionFond,imageDeFond,ecran,imageDePerso);
                break;
case SDLK_UP:
jump(&positionmilieu,&positionFond,imageDeFond,ecran,imageDePerso);

                break;
case SDLK_DOWN:
gravit=250;
break;
        }
        break;  
   }

gravity(&positionmilieu,&positionFond,imageDeFond,ecran,imageDePerso,gravit);     

        }

   SDL_FreeSurface(imageDeFond); 
   SDL_Quit();
    return EXIT_SUCCESS;
}
