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

/*estrutura gravadora do automato*/
typedef struct af AF;

/*Gera uma estrutura do tipo AF, com uma matriz vazia e um char com o alfabeto*/
AF* CriaAF(char* alfabeto, int num_estados);

/*insere uma transicao na matriz do automato*/
void CriaTransicao(AF *af,int e1,char s,int e2);

/*move entre as transicoes do automato de acordo com o comando especeficado*/
void Movimenta(AF *af,char comando);

#endif /* AUTOMATO_H */