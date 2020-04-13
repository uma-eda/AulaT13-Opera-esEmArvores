//
// Created by Filipe Quintal on 13/04/2020.
//

#ifndef AULA13PARTE1_ARVORE_H
#define AULA13PARTE1_ARVORE_H

struct node {
    int valor;
    node * esquerda;
    node * direita;
};

node * novoNode(int valor);
node * inserirNode(node * raiz, int valor);
void prefixa(node * raiz);
void infixa(node * raiz);
void sufixa(node * raiz);
int retornaMenorR(node * raiz);
int retornaMenorI(node * raiz);
int contaNos(node * raiz);
int altura(node * raiz);
void imprimeArvore(node * raiz, int nivel);

#endif //AULA13PARTE1_ARVORE_H
