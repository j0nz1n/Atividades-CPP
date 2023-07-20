#include <iostream>
using namespace std;

struct No {
	int data;
	No* esquerda;
	No* direita;	
};

No* criarNo(int valor) {
    No* newNo = new No;
    newNo->data = valor;
    newNo->direita = NULL;
    newNo->esquerda = NULL;
    return newNo;
}
No* adicionar(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->data) {
        raiz->esquerda = adicionar(raiz->esquerda, valor);
    } else if (valor > raiz->data) {
        raiz->direita = adicionar(raiz->direita, valor);
    }
    return raiz;
}
void exibir(No* raiz) { // Em ordem
    if (raiz != NULL) {
        exibir(raiz->esquerda);
        cout << raiz->data << " ";
        exibir(raiz->direita);
    }
}
No* menorValor(No* no) {
    No* atual = no;
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}
No* deletar(No* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }
    
    if (valor < raiz->data) {
        raiz->esquerda = deletar(raiz->esquerda, valor);
    } else if (valor > raiz->data) {
        raiz->direita = deletar(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            delete raiz;
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            delete raiz;
            return temp;
        }
        
        No* temp = menorValor(raiz->direita);
        raiz->data = temp->data;
        raiz->direita = deletar(raiz->direita, temp->data);
    }
    return raiz;
}

void menu() {
	cout << "Menu" << endl;
    cout << "1 - Adicionar Elemento" << endl;
    cout << "2 - Exibir Elementos" << endl;
    cout << "3 - Remover Elemento" << endl;
    cout << "4 - Sair" << endl;
    cout << "Digite a opcao desejada: ";
}

int main(){
	
	No* raiz = NULL;
    int resp;
    int valor;

    do {
        menu();
        cin >> resp;
        
        switch (resp) {
            case 1:
                cout << "\nDigite o valor a ser adicionado: ";
                cin >> valor;
                raiz = adicionar(raiz, valor);
                break;
            case 2:
                cout << "\nElementos em ordem: ";
                exibir(raiz);
                cout << endl;
                break;
            case 3:
                cout << "\nDigite o valor a ser removido: ";
                cin >> valor;
                raiz = deletar(raiz, valor);
                break;
            default:
                cout << "\nErro. Digite novamente." << endl;
                break;
        }
    } while (resp != 4);
	
	return 0;
}
