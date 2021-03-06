 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define quant_estados 10

#include "automato.h"

using namespace std;

AF* AFCria(std::string alfabeto, int num_estados)
{
    AF* af;
    
    af = new AF;
        
    af->quant_simbolos = alfabeto.length();
    
    /*grava o alfabeto*/
    af->alfabeto = alfabeto;
    
    /*grava a quantidade de estado*/
    af->quant_estado = num_estados;
    
    /*matriz de estados*/
    /*aloca a linha da matriz, a dimensao da linha e igual a quantidade de 
     simbolos q o alfabeto possui */
    af->estados = (int**) malloc(sizeof(int*)*af->quant_estado);
    int i,j;
    for(i=0;i<af->quant_estado;i++)
    {
        af->estados[i] = (int*) malloc(sizeof(int)*af->alfabeto.size());
    }

    for(i=0;i<af->quant_estado;i++)
    {
        	for(j=0;j<af->quant_simbolos;j++)
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
    
    pertence_transicao = af->alfabeto.find(s);
    
    af->estados[e1][pertence_transicao] = e2;
}

int AFMovimenta(AF *af,char comando)
{
    int     movimento;
    int     prox_estado;
    
    /*movimento recebe a posicao do simbolo no alfabeto*/
    movimento = af->alfabeto.find(comando,0);
    
    /*atualiza o estado inicial*/
    af->atual = af->estados[af->atual][movimento];
    



    return af->atual;
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
        
        af = AFCria(auxStr,auxInt);
        
        while(!arq.eof())
        {
            arq >> auxInt;
            arq >> auxStr;
            arq >> destino;
            
            AFcriaTransicao(af,auxInt,auxStr[0],destino);
        }
        
        return af;
    }
}