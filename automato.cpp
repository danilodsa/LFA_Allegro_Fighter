/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define quant_estados 10

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>

#include "automato.h"

using namespace std;

struct af{
    /*vetor que contem os simbolos do alfabeto*/
    string alfabeto;
    
    /*indica qual e o estado atual*/
    int     atual;
    
    /*quantidade de estados*/
    int     quant_estado;
    
    /*matriz equivalente ao automato criado*/
    int**   estados;
};

AF* AFCria(char* alfabeto, int num_estados)
{
    AF* af;

    /*grava o alfabeto*/
    af->alfabeto = alfabeto;
    
    /*grava a quantidade de estado*/
    af->quant_estado = num_estados;
    
    /*matriz de estados*/
    /*aloca a linha da matriz, a dimensao da linha e igual a quantidade de 
     simbolos q o alfabeto possui */
    af->estados = (int**) malloc(sizeof(int*)*af->alfabeto.size());
    int i,j;
    for(i=0;i<af->quant_estado;i++)
    {
        af->estados[i] = (int*) malloc(sizeof(int)*af->quant_estado);
        for(j=0;j<af->quant_estado;j++)
        {
            /*estados podem ser identificados por zero, logo a matriz
             e incializada com -1*/
            af->estados[i][j] = -1;
        }
    }
    
    /*define o estado inicial como o atual no momento em que retorna o
     automato*/
    af->atual = 0;
    
    return af;
}

void AFcriaTransicao(AF *af,int e1,char s,int e2)
{
    int     pertence_transicao;
    
    /*retorna a posicao de um caracter na string do alfabeto
     o mesmo e utilizado para definir a coluna de e2*/
    pertence_transicao = af->alfabeto.find(s,0);
    
    af->estados[e1][pertence_transicao] = e2;
}

void AFMovimenta(AF *af,char comando)
{
    int     movimento;
    int     prox_estado;
    
    /*movimento recebe a posicao do simbolo no alfabeto*/
    movimento = af->alfabeto.find(comando,0);
    
    /*atualiza o estado inicial*/
    af->atual = af->estados[af->atual][movimento];
    
    /*recebe o identificador do proximo estado*/
    prox_estado = af->estados[af->atual][movimento];
    
    /*executa a rotina do estado especificado*/
    switch(prox_estado)
    {
        case 0:
            break;
        case 1:
            Rasteira();
            break;
        case 2:
            Soca();
            break;
        case 3:
            Chuta();
            break;
        case 4:
            Pula();
            break;
        case 5:
            Soca();
            break;
        case 6:
        //Combo_2();
            break;
        case 7:
            Chuta();
            break;
        case 8:
        //Combo_1();
            break;
        case 9:
            /*SAI DO PROGRAMA*/
            exit(0);
            break;
    }
}

AF* AFcarregaAutomato(char* arq_nome)
{
    ifstream    arq;
    
    arq.open(arq_nome,ios::in);
    
    if(arq)
    {
        string      auxStr;
        int         auxInt;
        int         destino;
        AF          *af;

        arq >> auxStr;        
        arq >> auxInt;
        
        char*       temp = new char[auxStr.length()];
        
        strcpy(temp,auxStr.c_str());
        
        af = AFCria(temp,auxInt);
        
        while(!arq.eof())
        {
            arq >> auxInt;
            arq >> auxStr;
            arq >> destino;
            
            AFcriaTransicao(af,auxInt,auxStr[0],destino);
        }
    }
}