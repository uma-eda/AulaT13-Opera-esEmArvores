#include <iostream>
#include <iomanip>
#include "Arvore.h"

using namespace std;

int main() {

   node * raiz = NULL;

    raiz = inserirNode(raiz,8);
    raiz = inserirNode(raiz,6);
    raiz = inserirNode(raiz,7);
    raiz = inserirNode(raiz,9);
    raiz = inserirNode(raiz,12);
    raiz = inserirNode(raiz,3);
    raiz = inserirNode(raiz,1);
    raiz = inserirNode(raiz,20);
    raiz = inserirNode(raiz,14);
    raiz = inserirNode(raiz,4);
    raiz = inserirNode(raiz,11);
    raiz = inserirNode(raiz,5);

    cout << "Prefixa : ";
    prefixa(raiz);
    cout << endl << "Infixa : ";
    infixa(raiz);
    cout <<endl<< "Sufixa : ";
    sufixa(raiz);
    cout << endl;

    cout << "Minimo R : "<<retornaMenorR(raiz);
    cout << endl;
    cout << "Minimo I : "<<retornaMenorI(raiz);
    cout << endl;
    cout << "Número de nós : "<<contaNos(raiz);
    cout << endl;
    cout << "Altura : "<<altura(raiz);
    cout << endl <<"-------------------"<<endl;
    imprimeArvore(raiz,0);
    //raiz = removerF(raiz,6);
    raiz = removerC(raiz,6);
    imprimeArvore(raiz,0);

    return 0;
}
