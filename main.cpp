
#include "manager.h"

int game_time=0;
bool game_just_started;
void init();
void deinit();
void menu();
void debug();
gra Game1;

	
int main() {
    
    srand((unsigned)time(NULL));
    init();
    
    game_just_started = true;
	menu();
	Game1.tworze_gre();
	game_just_started = false;
	Game1.freeze = false;
	
	while (!key[KEY_A]) {
     
     if(key[KEY_ESC]) { Game1.freeze = true; menu(); }
     
     if(DEBUG == true) debug();
	 
     // rest(1);
      if(Game1.freeze == false && game_just_started == false) Game1.update();
     
    
    }

	deinit();
	exit(0);
	return 0;
}
END_OF_MAIN()








void debug(){

          game_time++;
          rectfill(screen,SCREEN_W-165,3,SCREEN_W-35,20,black);
          textprintf_ex(screen, font, SCREEN_W-135,10,red,-1, "Time: %d",game_time);
          textprintf_ex(screen, font, SCREEN_W-135,20,red,-1, "Type: %d",Game1.game_type);
          textprintf_ex(screen, font, SCREEN_W-135,30,red,-1, "Freeze: %d",Game1.freeze);
          textprintf_ex(screen, font, SCREEN_W-135,40,red,-1, "GJS: %d",game_just_started);
          textprintf_ex(screen, font, SCREEN_W-135,50,red,-1, "Game Time: %d",Game1.time);
          textprintf_ex(screen, font, SCREEN_W-165,60,red,-1, "DX:DY %3f:%3f",Game1.Ball.deltaX,Game1.Ball.deltaY);
          //textprintf_ex(screen, font, SCREEN_W-135,70,red,-1, "%d",Game1.time);
          //rest(10);
          if(game_time >= 100) game_time = 0;
      
      
}





void menu(){
     start_menu:
 clear_bitmap(screen);
 textprintf_ex(screen, font, SCREEN_W/2-50, (SCREEN_H/2-50), makecol(255, 100, 200),
                    -1, "Ping Pong by Marcin Œwierkocki");
 textprintf_ex(screen, font, SCREEN_W/2-35, (SCREEN_H/2)-40, makecol(255, 100, 200),
                    -1, "Typ Gry:");
 textprintf_ex(screen, font, SCREEN_W/2-35, (SCREEN_H/2)-30, makecol(255, 100, 200),
                    -1, "1. pvp"); 
 textprintf_ex(screen, font, SCREEN_W/2-35, (SCREEN_H/2)-20, makecol(255, 100, 200),
                    -1, "2. pva");
 textprintf_ex(screen, font, SCREEN_W/2-35, (SCREEN_H/2)-10, makecol(255, 100, 200),
                    -1, "q: wyjscie");
 textout_ex(screen, font, "v1.0.0 przez Marcin Swierkocki 2008", SCREEN_W-400, SCREEN_H-10, makecol(0, 0, 255), -1);                    
    clear_keybuf();
    if(DEBUG == true) debug();	
    do{
     if(DEBUG == true) debug();	
     clear_keybuf();
     val = readkey();
        switch(((val & 0xff))){
            case '1' :{
                  clear_bitmap(screen);
                  textout_ex(screen, font, "Player Vs Player", SCREEN_W /2-50, SCREEN_H/2-20, makecol(244, 255, 0), -1);
                  textout_ex(screen, font, "Sterowanie: X I S i strzalki ", SCREEN_W /2-50, SCREEN_H/2-10, makecol(244, 255, 0), -1);
                  rest(1250);
                  clear_bitmap(screen);
                  Game1.tworze_gre();
                  Game1.game_type = 1;
                  Game1.freeze = false;       
                  game_just_started = false;
                  game_time = 0;
                                goto end_menu;
                  }
            break;
            case '2' :{
                  clear_bitmap(screen);
                  textout_ex(screen, font, "Player Vs AI", SCREEN_W /2-50, SCREEN_H/2-20, makecol(244, 255, 0), -1);
                  rest(750);
                  clear_bitmap(screen);
                  Game1.tworze_gre();
                  Game1.freeze = false;               
                  Game1.game_type = 2;
                  game_just_started = false;
                  game_time = 0;
                  goto end_menu;
                  }
            break;
            case '3' :{
                  clear_bitmap(screen);
                  textout_ex(screen, font,"3 tryb gry", SCREEN_W /2-50, SCREEN_H/2-20, makecol(244, 255, 0), -1);
                  rest(750);
                  clear_bitmap(screen);
                  clear_bitmap(screen);
                  Game1.tworze_gre();
                  Game1.freeze = false;               
                  Game1.game_type = 3;
                  game_just_started = false;
                  game_time = 0;
                  goto end_menu;
                  }
            break;
            case 'q' : exit(0);
            break;
            default : 
            break;
        };
        
    }while(!key[KEY_ESC]);
    end_menu:
    if(game_just_started == 1) goto start_menu;
    if(game_just_started == 0) Game1.freeze= false;
    rest(400);
    clear_bitmap(screen);
}


void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 8;
	set_color_depth(depth);
	if (WINDOWED == false) res = set_gfx_mode(GFX_AUTODETECT, width, height, 0, 0);
	if (WINDOWED == true) res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, width, height, 0, 0);
	
    if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}
    if (is_windowed_mode()) {
         /* Windowed mode stuff. */
      } else {
         /* Fullscreen mode stuff. */
      }
    bufor = create_bitmap(width,height);
    
    if(!bufor){
    set_gfx_mode(GFX_TEXT,0,0,0,0);
    allegro_message("Nie Moge utworzyc bufora!");
    exit(-1);
    }
	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() {
     destroy_bitmap(bufor);
 textout_ex(screen, font, "KONIEC PROGRAMU", 30, 10, makecol(244, 0, 0), -1);
	clear_keybuf();
	/* add other deinitializations here */
}
