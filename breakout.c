#include<SDL2/SDL.h>		
#include<SDL2/SDL_image.h>		
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ballPos(){

    int k = rand() % 515;

    if (k > 60){

        return k;

    }

    ballPos();
    
}


int pointin(int x, int y, SDL_Rect rect){

    if ( x > rect.x && y > rect.y && x < rect.x + rect.w && y < rect.y + rect.h){
     
        return 1;   
        
    }
    return 0;

}


int colision(SDL_Rect r1, SDL_Rect r2){

    if ((pointin(r1.x, r1.y, r2) == 1) || 
       (pointin(r1.x + r1.w, r1.y, r2) == 1) || 
       (pointin(r1.x, r1.y + r1.h, r2) == 1) || 
       (pointin(r1.x + r1.w, r1.y + r1.h, r2) == 1)){
        
            return 1;

        }

    return 0;   
}


struct Blocks{

    int x;
    int y; 
    int h;
    int w;
    int a;

};



int main (int argc, char* args[])
{
	int i = 0, x = 0, y = 0;
    srand(time(NULL));

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
	SDL_Texture* img = IMG_LoadTexture(renderer, "brasil.png");
	SDL_Texture* back = IMG_LoadTexture(renderer, "fundo.jpg");
	SDL_Texture* gwin = IMG_LoadTexture(renderer, "WIN.jpg");
	SDL_Texture* gover = IMG_LoadTexture(renderer, "over.jpg");
	SDL_Texture* urna = IMG_LoadTexture(renderer, "urna.png");
	SDL_Texture* base = IMG_LoadTexture(renderer, "base.jpg");
	SDL_Texture* bola = IMG_LoadTexture(renderer, "cabeca.png");

	int a = 342,b = 464, f = 70, v=80;
    int posicao;

    posicao = ballPos();

    SDL_Rect ball;

    ball.x = posicao;
    ball.y = 180;
    ball.h = 20;
    ball.w = 20;

	SDL_Rect rack;

	rack.x = a;
	rack.y = b;
	rack.h = 20;
	rack.w = 80;

	int bricks = 5;   
    unsigned int cTime = 0 , lTime = 0; 
    int velX = 5, velY = 5;

    /* ALL BLOCKS DEFINITION*/ 


    SDL_Rect bloco[40];

    struct Blocks blocks[40];

    for (i=2, x=5 , y= 10; i<7; i++, x+=85){

        if (x > 650){
            x = 5;
            y += 30;
        }

        blocks[i].x = x;
        blocks[i].y = y; 
        blocks[i].h = 25;
        blocks[i].w = 80;
        blocks[i].a = 1;    

    }

    for (i=2; i<7; i++){
 
        bloco[i].x = blocks[i].x;
        bloco[i].y = blocks[i].y;
        bloco[i].h = blocks[i].h;
        bloco[i].w = blocks[i].w; 

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
                            if (rack.x < 605)
            					rack.x += 8;
                            break; 
	        			case SDLK_LEFT:
                            if (rack.x > 0)
            					rack.x -= 8;
	        				break;
                   
	        		}
        		}
    
        }

        if (ball.x > 661 || ball.x < 1){
            
            velX = -velX;
                    
        } 
        
        else if (ball.y > 455 || ball.y < 10){
            velY = -velY;
        }
        //int colision(int aY, int bY, int aX, int bX, int aH, int bH,  int aW, int bW) a = ball b=rack
        if (colision(ball,rack) == 1){
            velY = -velY;
        }
        if (ball.y + 20 >= 480){
        
            break;            

        }

        if (bricks == 0) break;


        ball.x += velX;

        for (i=2; i<7; i++){

            if (blocks[i].a == 1){

                if (colision(ball, bloco[i]) == 1){
                    bricks -= 1;
                    velY = -velY;
                    blocks[i].a = 0;
                    break;
                }


            }
        }



        ball.y += velY;
    

		SDL_RenderFillRect(renderer, NULL);			
   		SDL_RenderCopy(renderer, back, NULL, NULL);                       
		//SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
		SDL_RenderFillRect(renderer, &ball);
		SDL_RenderCopy(renderer, bola, NULL, &ball); 

		SDL_RenderFillRect(renderer, &rack);
        SDL_RenderCopy(renderer, base, NULL, &rack); 
        


       for (i=2; i<7 ; i++){
 
            if (blocks[i].a == 1){
                SDL_RenderFillRect(renderer, &bloco[i]);    
        		SDL_RenderCopy(renderer, urna, NULL, &bloco[i]);                       
            } 
            
        }


		SDL_RenderPresent(renderer);
	}

    SDL_Rect fim = {0, 0, 685, 480};
    if (bricks != 0)
     	SDL_RenderCopy(renderer, gover, NULL, &fim);                       
    else if (bricks == 0)
        SDL_RenderCopy(renderer, gwin, NULL, &fim);                       


    SDL_RenderPresent(renderer);

    SDL_Delay(5000);

//	FIN
	SDL_DestroyTexture(img);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
} 
