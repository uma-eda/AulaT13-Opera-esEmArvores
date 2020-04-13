//
// Created by Filipe Quintal on 13/04/2020.
//
#include "Arvore.h"
#include <iostream>
using namespace std;

node * novoNode(int valor){
    node * novo = new node;
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

node * inserirNode(node * raiz, int v){
    if(raiz == NULL)
        return novoNode(v);
    else if(v < raiz->valor){
        raiz->esquerda =  inserirNode(raiz->esquerda,v);
    }else{
        raiz->direita = inserirNode(raiz->direita,v);
    }
    return raiz;
}

void prefixa(node * raiz){
    //condição de paragem
    if(raiz==NULL)
        return;
    //travessia prefixa
    cout << raiz->valor << " | ";
    prefixa(raiz->esquerda);
    prefixa(raiz->direita);

}

void infixa(node * raiz){
    //condição de paragem
    if(raiz==NULL)
        return;
    //travessia infixa
    infixa(raiz->esquerda);
    cout << raiz->valor << " | ";
    infixa(raiz->direita);
}

void sufixa(node * raiz){
    //condição de paragem
    if(raiz==NULL)
        return;
    //travessia sufixa
    sufixa(raiz->esquerda);
    sufixa(raiz->direita);
    cout << raiz->valor << " | ";

}

int retornaMenorR(node * raiz){

    if(raiz==NULL) // árvore vazia
        return -1;

    if(raiz->esquerda == NULL)
        return raiz->valor;

    return retornaMenorR(raiz->esquerda);

}

int retornaMenorI(node * raiz){
    node * aux =  raiz;

    while(aux->esquerda != NULL)
        aux = aux->esquerda;

    return aux->valor;
}

int contaNos(node * raiz){
    if(raiz==NULL)
        return 0;
    else{
        return 1 + contaNos(raiz->esquerda) + contaNos(raiz->direita); //1+1+1+1+1+1+1+1+1+1
    }
}

int altura(node * raiz){

    if(raiz == NULL)
        return 0;

    int alt_e = altura(raiz->esquerda);
    int alt_d = altura(raiz->direita);

    if(alt_e>alt_d)
        return alt_e+1;
    else
        return alt_d+1;
}

void imprimeArvore(node  * raiz, int nivel){

    if(raiz == NULL){
        cout << endl;
        return;
    }
    imprimeArvore(raiz->direita, nivel+1);

    for(int i=0;i<nivel;i++)
        cout << "\t";

    cout << raiz->valor << endl;

    imprimeArvore(raiz->esquerda, nivel+1);

}