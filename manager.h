#include <time.h>


#define DEBUG true
#define WINDOWED true
#define MESSAGES false
#define height 200
#define width 200
#define ball_size 50
#define ROCKET_H 30
#define ROCKET_W 3
BITMAP *bufor;


class pilka {
      public:
      
      void draw();
      void update();
      void clear();
      pilka();
      void tworze_pilke();
      float deltaX;
      float deltaY;
      int zmien_szybkosc(float szybkosc);
      float posX;
      float posY;
              
     private:
              int speed;
              int r;
};      


class paletka{
       public:
              int temp;
              bool L;
              int posX;
              int posY;
              void update();
              paletka();
              void go_down();
              void go_up();
              void tworz_paletka();
       private:
               int deltaX;
               int deltaY;
               int speed;
               int h,w;
        
               void draw();
               void clear();
        
};
class punkty{
      public:
             int P1;
             int P2;
             void rysuj();     
             void dodaj(int komu);
};



class gra{
      public:
             bool freeze;
             int time;
             pilka Ball;
             paletka P1,P2;
             punkty tablica1;
             int game_type;
             int update();
             gra();
             void tworze_gre();
             ~gra();
      private:
              void draw_hud();
              int ava();    // game_type 0 i 3;
              int pvp();    // game_type 1;
              int pva();    // game_type 2;
              

};

