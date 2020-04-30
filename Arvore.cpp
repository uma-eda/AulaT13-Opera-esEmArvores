//
// Created by Filipe Quintal on 13/04/2020.
//
#include "Arvore.h"
#include <iostream>
#include <iomanip>
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


node * removerF(node * raiz, int num){
    node * no_remover = raiz;
    node * anterior = NULL;
    while(no_remover!=NULL){
        if(no_remover->valor == num){
            cout << "Encontrei o nó !!"<<endl;
            return removerF(raiz,no_remover,anterior);
        }else if(num < no_remover->valor){
            anterior = no_remover;
            no_remover = no_remover->esquerda;
        }else{
            anterior = no_remover;
            no_remover = no_remover->direita;
        }
    }
    return raiz;
}

node * removerF( node * raiz, node * no, node * ant){
    //o nó a remover é a raiz
    if(ant == NULL){
        //a arvore é apenas a raiz
        if(no->esquerda == NULL & no->direita==NULL)
            raiz = NULL; //se só tenho a raiz depois de remover fica a NULL
        else if(raiz->direita == NULL) // só tenho valores à esquerda
            raiz = raiz->esquerda;      // a raiz passa a ser o que estava a direita
        else if(raiz->esquerda == NULL)  // só tenho valores à direita
            raiz = raiz->direita;       // a raiz passa a ser o que estava a direita
        else{                       //tenho valores à esquerda e direita
            // tenho valores a esq e dir da raiz, vou fazer a remoção por fusão
            node * aux = no->esquerda;   //sub arvore esquerda
            while(aux->direita!=NULL)   // o mais a direita possível
                aux = aux->direita;

            aux->direita = no->direita;  // colocar a sub arvore direita do nó a remover
            //à direita do no mais à direita da sub arvoer
            //esquerda
            raiz = no->esquerda;    // saltar o nó a remover
        }
    }else{ // remover qqer nó que não é a raiz
        if(no->direita == NULL){        //o no a remover n tem filhos à direita
            if(ant->valor > no->valor) // o nó a remover está a esq ou direita do
                ant->esquerda = no->esquerda;             // anterior
            else
                ant->direita = no->esquerda;
        }else if(no->esquerda == NULL){  //o no a remover n tem filhos à esq
            if(ant->valor > no->valor)
                ant->esquerda = no->direita;
            else
                ant->direita = no->direita;
        }else{
            //remoção por fusão
            node * temp = no->esquerda;
            while(temp->direita!=NULL)
                temp = temp->direita;

            temp->direita = no->direita;
            if(ant->valor>no->valor)
                ant->esquerda = no->esquerda;
            else
                ant->direita = no->esquerda;
        }
    }
    delete no;
    return raiz;
}
int retornaMenor(node * raiz){

    node * aux = raiz;

    while(aux->esquerda !=NULL)
        aux = aux->esquerda;

    return aux->valor;

}

node * removerC(node * root, int num) {
    node * no = root;
    node * prev = NULL;
    while (no != NULL) {
        if (num == no->valor) {
            return root = removerC(root, no, prev);
        }
        else if (num <no->valor) {
            prev = no;
            no = no->esquerda;
        }
        else {
            prev = no;
            no = no->direita;
        }

    }
    return root;
}
node * removerC(node * root, node * no, node * prev) {
    //removing the root
    if (prev == NULL) {
        if (no->esquerda == NULL && no->direita == NULL)
            root = NULL;
        else if (no->esquerda != NULL && no->direita == NULL)
            root = no->esquerda;
        else if (no->esquerda == NULL && no->direita != NULL)
            root = no->direita;
        else {
            //copy step
            node * temp = no->esquerda;
            prev = root;
            while (temp->direita != NULL) {
                prev = temp;
                temp = temp->direita;
            }
            swap(temp->valor, root->valor);
            if (prev->valor > root->valor || prev == root)
                prev->esquerda = temp->esquerda;
            else
                prev->direita = temp->esquerda;
        }
    }
    else { // any other node
        if (no->esquerda == NULL && no->direita == NULL) {
            if (prev->valor > no->valor)
                prev->esquerda = NULL;
            else
                prev->direita = NULL;
        }
        else if (no->esquerda == NULL && no->direita!=NULL) {
            if (prev->valor > no->valor)
                prev->esquerda = no->direita;
            else
                prev->direita = no->direita;
        }
        else if (no->esquerda != NULL && no->direita == NULL) {
            if (prev->valor > no->valor)
                prev->esquerda = no->esquerda;
            else
                prev->esquerda = no->esquerda;
        }
        else { // copy step
            node * temp = no->esquerda;
            prev = no;
            while (temp->direita != NULL) {
                prev = temp;
                temp = temp->direita;
            }
            swap(temp->valor, no->valor);
            if (prev->valor > no->valor || prev == no)
                prev->esquerda = temp->esquerda;
            else
                prev->direita = temp->esquerda;

            no = temp;
        }
    }
    delete no;
    return root;
}