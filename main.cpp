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

using namespace std;
// Inclui o cabeçalho da bibilioteca Allegro 5
#include <allegro5/allegro.h>

// Inclui o cabeçalho do add-on para uso de imagens
#include <allegro5/allegro_image.h>

int main(void)
{
    AF *eta;
    
    eta = AFcarregaAutomato("teste.txt");
    
    int i,j,max;
    
    max = eta->alfabeto.length();
    
    for(i=0;i<eta->quant_estado;i++)
    {
        for(j=0;j<max;j++)
        {
            cout << eta->estados[i][j] << " ";
        }
        cout << "\n";
    }  
}

