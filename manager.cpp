#include "colors.h"


void pilka::draw(){
circlefill(bufor,(int)this->posX,(int)this->posY,this->r,white);
}

void pilka::clear(){
circlefill(bufor,(int)this->posX,(int)this->posY,this->r+1,black);     
}
int pilka::zmien_szybkosc(float szybkosc){
 float temp =  rand()%999/1000 + 0.001f;
 this->deltaX =  this->deltaX + szybkosc + (temp);
 this->deltaY =  this->deltaY + szybkosc + (temp);

return 0;
}

void pilka::update(){


if(getpixel(bufor,(int)this->posX,(int)this->posY+this->r) == white){ 
                                             //    Dӣ
      this->deltaY = -this->deltaY;
      this->zmien_szybkosc(0);
}

if(getpixel(bufor,(int)this->posX,(int)this->posY-this->r) == white){  // G�RA
     this->deltaY = -this->deltaY;
     this->zmien_szybkosc(0);
}
if(getpixel(bufor,(int)this->posX-this->r,(int)this->posY) == white){ 
                                             //    lewo
      this->deltaX = -this->deltaX;
      this->zmien_szybkosc(0);
}

if(getpixel(bufor,(int)this->posX+this->r,(int)this->posY) == white){  // prawo
     this->deltaX = -this->deltaX;
     this->zmien_szybkosc(0);
}


this->posX += this->deltaX;
this->posY += this->deltaY;

this->draw();
}

pilka::pilka(){
    if(MESSAGES==true)allegro_message("Tworze pilke0","tworze pilke0");
    this->posX = SCREEN_W/2;
    this->posY = SCREEN_H/2;
    this->r = ball_size; 
    this->speed = 1;
    this->deltaX = this->speed;
    this->deltaY = (this->speed);
}
void pilka::tworze_pilke(){
    if(MESSAGES==true) allegro_message("Tworze pilke1","tworze pilke1");
    this->posX = SCREEN_W/2;
    this->posY = SCREEN_H/2;
    this->r = ball_size; 
    this->speed = 1;
    this->deltaX = this->speed;
    this->deltaY = this->speed;
}


paletka::paletka(){
       
}

void paletka::go_up(){
      this->clear();
     
     if(getpixel(bufor,(int)this->posX,(int)this->posY-1) != white){  // G�RA
          this->posY += -1;
     }
     this->draw();
}
void paletka::go_down(){
      this->clear();
           if(getpixel(bufor,(int)this->posX,(int)this->posY+this->h +1) != white){ 
          this->posY -=-1; /// dol
      }
     this->draw();
     
}
void paletka::update(){
     
     this->draw();


}
void paletka::draw(){

     for(int i = 0; i<this->w;i++)     
  
    fastline(bufor,this->posX+i,this->posY,this->posX+i,this->posY+this->h,white);
}
void paletka::clear(){
     for(int i = 0;i<this->w;i++)     

    fastline(bufor,this->posX,this->posY,this->posX+i,this->posY+this->h,black);
}

void paletka::tworz_paletka(){
this->w = ROCKET_W;
this->h = ROCKET_H;
this->deltaX = 1;
this->deltaY = 1;
if (this->L == true){ this->posX = 20; this->posY = 100;}
if (this->L == false){ this->posX = SCREEN_W-ROCKET_W- 20; this->posY = 100;}
}

gra::gra(){
       this->game_type = 0;
       this->freeze = true;
       this->time = 0;
       Ball.tworze_pilke();

}
void gra::tworze_gre(){
       if(MESSAGES==true) allegro_message("Tworze gre","tworze gre");
    
       this->freeze = true;
       this->time = 0;
       Ball.tworze_pilke();
       P1.tworz_paletka();
       P1.L = true;
       P2.tworz_paletka();
       P2.L = false;
       tablica1.P1 = 0 ;
       
       tablica1.P2 = 0 ;
}
gra::~gra(){

}
void gra::draw_hud(){
     
       hline(bufor,0,5,SCREEN_W,white);
       hline(bufor,0,SCREEN_H-5,SCREEN_W,white);
       vline(bufor,1,0,SCREEN_H, wwhite);    
       vline(bufor,SCREEN_W-1,0,SCREEN_H, wwhite);
       tablica1.rysuj();     
}
int gra::update(){
    
    if(this->freeze == false){
    clear_bitmap(bufor);
    this->draw_hud();
    if(this->game_type == 1) this->pvp();
    if(this->game_type == 2) this->pva();
    if(this->game_type == 3) this->ava();
    this->P1.update();
    this->P2.update();
    this->time ++;

if(getpixel(bufor,(int)Ball.posX-ball_size,(int)Ball.posY) == wwhite){ 
       Ball.tworze_pilke();
       P1.tworz_paletka();
       P1.L = true;
       P2.tworz_paletka();
       P2.L = false;
       
                  tablica1.dodaj(0);                                
                  Ball.tworze_pilke();
                  rest(550);
}

if(getpixel(bufor,(int)Ball.posX+ball_size,(int)Ball.posY) == wwhite){  
       Ball.tworze_pilke();
       P1.tworz_paletka();
       P1.L = true;
       P2.tworz_paletka();
       P2.L = false;
       
                  tablica1.dodaj(1);
                  Ball.tworze_pilke();
                  rest(550);
}
    this->Ball.update();
    blit(bufor,screen,0,0,0,0,width,height);
   
   } return 0;
}
int gra::pvp(){
    
    if(key[KEY_UP]) this->P2.go_up();
    if(key[KEY_DOWN]) this->P2.go_down();
    if(key[KEY_S]) this->P1.go_up();
    if(key[KEY_X]) this->P1.go_down();
    
return 0;    
}

int gra::pva(){
    
    if(key[KEY_UP]) this->P1.go_up();
    if(key[KEY_DOWN]) this->P1.go_down();
    if(Ball.posY < P2.posY+(ROCKET_H/2)) P2.go_up();
    if(Ball.posY > P2.posY+(ROCKET_H/2)) P2.go_down();
return 0;    
}

int gra::ava(){
    
    if(Ball.posY < P2.posY+(ROCKET_H/2)) P2.go_up();
    if(Ball.posY > P2.posY+(ROCKET_H/2)) P2.go_down();
    if(Ball.posY < P1.posY+(ROCKET_H/2)) P1.go_up();
    if(Ball.posY > P1.posY+(ROCKET_H/2)) P1.go_down();
return 0;    
}



void punkty::rysuj(){

          textprintf_ex(bufor, font, SCREEN_W-265,10,cyan,-1, "Gracz 1: %d",this->P1);
          textprintf_ex(bufor, font, SCREEN_W-265,20,cyan,-1, "Gracz 2: %d",this->P2);

}

void punkty::dodaj(int komu){
     if(komu == 0) this->P1++;
     if(komu == 1) this->P2++;
}
