/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   automato.h
 * Author: fellipe
 *
 * Created on 17 de Julho de 2016, 01:30
 */

#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <cstdlib>
#include <string.h>
#include <fstream>
#include <string>

struct af{
    /*vetor que contem os simbolos do alfabeto*/
    std::string alfabeto;
    
    /*indica qual e o estado atual*/
    int     atual;
    
    /*quantidade de estados*/
    int     quant_estado;
    int     quant_simbolos;
    
    /*matriz equivalente ao automato criado*/
    int**   estados;
};

typedef struct af AF;

AF* AFCria(std::string alfabeto, int num_estados);

AF* AFCriaa(std::string alfabeto, int num_estados);

void AFcriaTransicao(AF *af,int e1,char s,int e2);

void AFMovimenta(AF *af,char comando);

AF* AFcarregaAutomato(std::string arq_nome);

#endif /* AUTOMATO_H */

