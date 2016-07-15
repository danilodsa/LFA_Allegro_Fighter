/* 
 * iNSTALAR: http://www.rafaeltoledo.net/compilando-e-instalando-a-biblioteca-allegro-5-no-ubuntu/
 * 
 * PARA COMPILAR: gcc main.c -o teste -lallegro_image -lallegro 
 * 
 * File:   main.cpp
 * Author: Danilo Alves && Fellipe Eduardo
 *
 * Created on 10 de Julho de 2016, 03:22
 * 
 * 
 * w = PULAR -> ESTADO 5
 * s = ABAIXAR -> ESTADO 2
 * u = SOCO -> ESTADO 3
 * i = CHUTE -> ESTADO 4
 * x = SAIR -> ESTADO 10
 * 
 * 
 */

#include <cstdlib>

using namespace std;
// Inclui o cabeçalho da bibilioteca Allegro 5
#include <allegro5/allegro.h>
 
// Inclui o cabeçalho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
 
int main(void)
{
    // Variável representando a janela principal
    ALLEGRO_DISPLAY *janela = NULL;
 
    // Variável representando a imagem
    ALLEGRO_BITMAP *imagem = NULL;
 
    // Inicializa a Allegro
    al_init();
 
    // Inicializa o add-on para utilização de imagens
    al_init_image_addon();
 
    // Configura a janela
    janela = al_create_display(640, 480);
 
    // Carrega a imagem
    imagem = al_load_bitmap("ninjamegazord.png");
 
    // Desenha a imagem na tela
    al_draw_bitmap(imagem, 0, 0, 0);
 
    // Atualiza a tela
    al_flip_display();
 
    // Segura a execução por 10 segundos
    al_rest(10.0);
 
    // Finaliza a janela quando o estado for o 10 (pressionar esc)
    al_destroy_display(janela);
 
    return 0;
}

