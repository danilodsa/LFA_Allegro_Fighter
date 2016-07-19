/* 
 * iNSTALAR: http://www.rafaeltoledo.net/compilando-e-instalando-a-biblioteca-allegro-5-no-ubuntu/
 * 
 * PARA COMPILAR: g++ *.cpp -lallegro_image -lallegro
 * 
 * File:   main.cpp
 * Author: Danilo Alves && Fellipe Eduardo
 *
 * Created on 10 de Julho de 2016, 03:22
 * 
 * 
 * w = PULAR -> ESTADO 4
 * s = ABAIXAR -> ESTADO 1
 * u = SOCO -> ESTADO 2
 * i = CHUTE -> ESTADO 3
 * x = SAIR -> ESTADO 9
 * 
 * 
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "automato.h"

 #define slow 0.15
 #define medium 0.1
 #define fast 0.07



using namespace std;
// Inclui o cabeçalho da bibilioteca Allegro 5
#include <allegro5/allegro.h>

// Inclui o cabeçalho do add-on para uso de imagens
#include <allegro5/allegro_image.h>

void entrada();
void background();
char inativo();
void soco();
void chute();
void pula();
void rasteira();
void combo1();
void combo2();

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
bool pressed_keys[ALLEGRO_KEY_MAX];

int main(void)
{
    int  comando, estado;
    int sair = 0;
    AF *af;
    int x;
    
    af = AFcarregaAutomato("automato.txt");
 
    al_init();
    
    janela = al_create_display(709,301);
    al_init_image_addon();
    al_set_target_bitmap(al_get_backbuffer(janela));
    fila_eventos = al_create_event_queue();
    al_install_keyboard();
    ALLEGRO_KEYBOARD_STATE key_state;
    
    entrada();
    while(sair == 0) 
    {   
        comando = inativo();
        
        cout << af->atual;
        estado = AFMovimenta(af, comando);
        
        
        printf(" -> %c %i \n", comando, estado);
        
        switch (estado)
        {
        case 1:
            rasteira();
            break;
        case 2:
            soco();
            break;
        case 3:
            chute();
            break;
        case 4:
            pula();
            break;
        case 5:
            soco();
            break;
        case 6:    
            combo2();
            break;
        case 7:
            chute();
            break;
        case 8:    
            combo1();
            break;
        case 9:
            sair = 1;
            break;
        }

        comando = 0;
        
    }
    
    al_destroy_display(janela);
}

void background()
{
    ALLEGRO_BITMAP* imagem;
    imagem = al_load_bitmap("background.png");
    al_draw_bitmap(imagem, 0, 0, 0);
    al_flip_display();
    
}


char inativo()
{
    int i, comando, sair = 0;
    ALLEGRO_BITMAP* imagem = al_create_bitmap(709,301);
    
    char* inativo[4]= {"inativo_1.png", "inativo_2.png", "inativo_3.png", "inativo_4.png"};
    ALLEGRO_EVENT evento;
     
    
    while(1)
    {
        for(i=0; i<=3; i++)
        {
            
            background();
            imagem = al_load_bitmap(inativo[i]);
            al_draw_bitmap(imagem, 20, 150, 0);
            al_flip_display();
            al_rest(fast);
        }
        
        al_wait_for_event_timed(fila_eventos, &evento, 0.0001);
        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
        al_flush_event_queue(fila_eventos);                 

        
        if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
         {
             switch(evento.keyboard.keycode)
             {
             case ALLEGRO_KEY_W: //Pulo
                 comando = 'w';
                 return comando;
                 break;
             case ALLEGRO_KEY_S: //Abaixar
                 comando = 's';
                 return comando;
                 break;
             case ALLEGRO_KEY_U: //Soco
                 comando = 'u';
                 return comando;
                 break;
             case ALLEGRO_KEY_I: //Chute
                 comando = 'i';
                 return comando;
                 break;
             case ALLEGRO_KEY_ESCAPE:
                 comando = 'x';
                 return comando;
             }
         }
         else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
         {
             return 'x';
         }         
        
    }
     
}

void soco()
{
    int i;
    ALLEGRO_BITMAP* imagem;
    char* soco[2]= {"soca_1.png", "soca_2.png"};

    for(i=0; i<=1; i++)
    {
        background();
        imagem = al_load_bitmap(soco[i]);
        al_draw_bitmap(imagem, 20, 150, 0);
        al_flip_display();
        al_rest(fast);
    }

}

void chute()
{
    int i;
    ALLEGRO_BITMAP* imagem;
    char* chute[5]= {"chute_1.png", "chute_2.png", "chute_3.png", "chute_2.png", "chute_1.png"};
    

    for(i=0; i<=4; i++)
    {
        background();
        imagem = al_load_bitmap(chute[i]);
        al_draw_bitmap(imagem, 20, 130, 0);
        al_flip_display();
        al_rest(fast);
    }

}

void pula()
{
    int i;
    ALLEGRO_BITMAP* imagem;
    char* pula = "pular_1.png";

    for(i=0; i<4; i++)
    {
        background();
        imagem = al_load_bitmap(pula);
        al_draw_bitmap(imagem, 20, 150-i*30, 0);
        al_flip_display();
        al_rest(fast);
    }
    for(i=0; i<4; i++)
    {
        background();
        imagem = al_load_bitmap(pula);
        al_draw_bitmap(imagem, 20, 135+i*10, 0);
        al_flip_display();
        al_rest(fast);
    }


}

void rasteira()
{
    int i;
    ALLEGRO_BITMAP* imagem;
    char* rasteira[3]= {"rasteira_1.png", "rasteira_2.png", "rasteira_1.png"};
    

    for(i=0; i<=2; i++)
    {
        background();
        imagem = al_load_bitmap(rasteira[i]);
        al_draw_bitmap(imagem, 20, 180, 0);
        al_flip_display();
        al_rest(fast);
    }
}

void combo1()
{
    
    
}


void combo2()
{
    
}

void entrada()
{
    int i;
    ALLEGRO_BITMAP* imagem;
    char* entrada[16] = {"gira_1.png", "gira_2.png", "gira_3.png", "gira_1.png", "gira_1.png", "gira_2.png", "gira_3.png", "gira_1.png", "gira_1.png", "gira_2.png", "gira_3.png", "gira_1.png", "gira_1.png", "gira_2.png", "gira_3.png", "gira_1.png"};
    char* pisca1 = "gira_1.png";
    
    for(i=0; i<=15; i++)
    {
        background();
        imagem = al_load_bitmap(pisca1);
        al_draw_bitmap(imagem, 10, 140, 0);
        al_flip_display();
        imagem = al_load_bitmap(pisca1);
        al_draw_bitmap(imagem, 30, 140, 0);
        al_flip_display();
        imagem = al_load_bitmap(entrada[i]);
        al_draw_bitmap(imagem, 20, 140, 0);
        al_flip_display();
        al_rest(fast);
    }    
}