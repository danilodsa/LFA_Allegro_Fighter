/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define quant_estados 10

#include "automato.h"

using namespace std;

struct af{
    /*vetor que contem os simbolos do alfabeto*/
    string alfabeto;
    
    /*quantidade de estados*/
    int     quant_estado;
    
    /*matriz equivalente ao automato criado*/
    int**   estados;
};

AF* CriaAF(char* alfabeto, int num_estados)
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
    
    return af;
}

void CriaTransicao(AF *af,int e1,char s,int e2)
{
    int     pertence_transicao;
    
    /*retorna a posicao de um caracter na string do alfabeto
     o mesmo e utilizado para definir a coluna de e2*/
    pertence_transicao = af->alfabeto.find(s,0);
    
    af->estados[e1][pertence_transicao] = e2;
}

void Movimenta(AF *af,char comando)
{
    
}