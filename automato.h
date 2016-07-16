/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   automato.h
 * Author: fellipe
 *
 * Created on 14 de Julho de 2016, 14:28
 */

#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <cstdlib>
#include <string>
#include "anima.h"

/*estrutura gravadora do automato*/
typedef struct af AF;

AF* AFcarregaAutomato(char* arq_nome);

AF* AFCria(char* alfabeto, int num_estados);
        
void CriaTransicao(AF *af,int e1,char s,int e2);

void Movimenta(AF *af,char comando);

#endif /* AUTOMATO_H */