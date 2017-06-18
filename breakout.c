#include<SDL2/SDL.h>		
#include<SDL2/SDL_image.h>		
#include<assert.h>
#include<stdio.h>

//int colision()



int main (int argc, char* args[])
{

	//INI
	
	int error = SDL_Init(SDL_INIT_EVERYTHING);
	assert(error == 0);

	//WINDOW	
    SDL_Window* window = SDL_CreateWindow("Jogo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         685, 480, SDL_WINDOW_SHOWN);;
	assert(window != NULL);
	//RENDERER
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	assert(renderer != NULL);
	//EVENT
	SDL_Event Event;
	//TEXTURE   
	SDL_Texture* img = IMG_LoadTexture(renderer, "/home/brunofreire/Documentos/Reativos/brasil.png");

	int a = 605,b = 464, f = 70, v=80;
    float l = 2;

    SDL_Rect ball = {80,230,20,20};

	SDL_Rect rack;

	rack.x = a;
	rack.y = b;
	rack.h = 16;
	rack.w = 80;

	int R = 0 , G = 0, B = 0;   
    unsigned int cTime = 0 , lTime = 0; 
    int velX = 15, velY = 15;

    /* ALL BLOCKS DEFINITION */


    SDL_Rect bloco[40];

    for (int i=0, x=5 , y= 10; i<40; i++, x+=85){
 

        if (x > 650){
            x = 5;
            y += 30;
        }

        bloco[i].x = x;
        bloco[i].y = y; 
        bloco[i].h = 25;
        bloco[i].w = 80; 


    }

//	EXE


	    while (1){
		    while (SDL_PollEvent(&Event) == 0);

		    if (Event.type == SDL_QUIT){
			    break;
            
            }else{
                if (Event.type == SDL_KEYDOWN){	

	        		switch (Event.key.keysym.sym){

	        			case SDLK_RIGHT:
                            if (rack.x < a)
            					rack.x += 10;
                            break; 
	        			case SDLK_LEFT:
                            if (rack.x > 0)
            					rack.x -= 10;
	        				break;
                   
	        		}
        		}
    
        }

        if (ball.x > 661 || ball.x < 1){
            
            velX = -velX;
                    
        } 
        
        if (ball.y > 455 || ball.y < 10){
            velY = -velY;
        }
        
        ball.x += velX;
        ball.y += velY;
    

		SDL_SetRenderDrawColor(renderer, 0x12, 0x37, 0x60, 0x00);
		SDL_RenderFillRect(renderer, NULL);			

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderFillRect(renderer, &rack);
        

        for (int i=0; i<40 ; i++){
            if (i < 8)
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            else if (i < 16)
                SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
            else if (i < 24)
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
            else if (i < 32)
                SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
            else if (i < 40)
                SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

            SDL_RenderFillRect(renderer, &bloco[i]);
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderFillRect(renderer, &ball);			

		SDL_RenderCopy(renderer, img, NULL, &ball); 

		SDL_RenderPresent(renderer);

	}


//	FIN
	SDL_DestroyTexture(img);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}   
