#include <iostream>

using namespace std;
struct No {
    int numero;
    No* next;
};

void menu() {
	cout << "================" << endl;
    cout << "Menu Principal" << endl;
    cout << "1 - Pilha" << endl;
    cout << "2 - Fila" << endl;
    cout << "3 - Sair" << endl;
    cout << "================" << endl;
    cout << "Digite a opcao desejada: ";
}

void pilhaMenu() {
	cout << "================" << endl;
    cout << "Menu" << endl;
    cout << "1 - Adicionar Elemento" << endl;
    cout << "2 - Remover Elemento" << endl;
    cout << "3 - Exibir Elementos" << endl;
    cout << "4 - Voltar ao menu Principal" << endl;
    cout << "================" << endl;
    cout << "Digite a opcao desejada: ";
}

void filaMenu() {
	cout << "================" << endl;
    cout << "Menu" << endl;
    cout << "1 - Adicionar Elemento" << endl;
    cout << "2 - Remover Elemento" << endl;
    cout << "3 - Exibir Elementos" << endl;
    cout << "4 - Voltar ao menu Principal" << endl;
    cout << "================" << endl;
    cout << "Digite a opcao desejada: ";
}

int adicionar() {
    int elemento;
    cout << "Digite o elemento a ser adicionado: ";
    cin >> elemento;
    return elemento;
}

void adicionarPilha(No** topo) {
    No* newNo = new No;
    newNo->numero = adicionar();
    newNo->next = *topo;
    *topo = newNo;
    cout << "Elemento adicionado com sucesso!" << endl;
}

void removerPilha(No** topo) {
    if (*topo == NULL) {
        cout << "A pilha esta vazia!" << endl;
        return;
    }
    No* temp = *topo;
    *topo = (*topo)->next;
    delete temp;
    cout << "Elemento removido com sucesso!" << endl;
}

void exibirPilha(No* topo) {
    if (topo == NULL) {
        cout << "A pilha esta vazia!" << endl;
        return;
    }
    cout << "Elementos na pilha: ";
    No* temp = topo;
    while (temp != NULL) {
        cout << temp->numero << " ";
        temp = temp->next;
    }
    cout << endl;
}

void adicionarFila(No** frente, No** fundo) {
    No* newNo = new No;
    newNo->numero = adicionar();
    newNo->next = NULL;
    if (*fundo == NULL) {
        *frente = *fundo = newNo;
    } else {
        (*fundo)->next = newNo;
        *fundo = newNo;
    }
    cout << "Elemento adicionado com sucesso!" << endl;
}

void removerFila(No** frente, No** fundo) {
    if (*frente == NULL) {
        cout << "A fila esta vazia!" << endl;
        return;
    }
    No* temp = *frente;
    *frente = (*frente)->next;
    if (*frente == NULL) {
        *fundo = NULL;
    }
    delete temp;
    cout << "Elemento removido com sucesso!" << endl;
}

void exibirFila(No* frente) {
    if (frente == NULL) {
        cout << "A fila esta vazia!" << endl;
        return;
    }
    cout << "Elementos na fila: ";
    No* temp = frente;
    while (temp != NULL) {
        cout << temp->numero << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int op1, op2;
    No* pilhaTopo = NULL;
    No* filaFrente = NULL;
    No* filaFundo = NULL;

    do {
        menu();
        cin >> op1;
        switch (op1) {
            case 1: {
                system("cls");
                pilhaMenu();
                cin >> op2;
                switch (op2) {
                    case 1: {
                        system("cls");
                        adicionarPilha(&pilhaTopo);
                        break;
                    }
                    case 2: {
                        system("cls");
                        removerPilha(&pilhaTopo);
                        break;
                    }
                    case 3: {
                        system("cls");
                        exibirPilha(pilhaTopo);
                        break;
                    }
                    case 4:
                        system("cls");
                        break;
                    default:
                        cout << "\n\n! OPCAO INVALIDA !\n\n" << endl;
                        break;
                }
                break;
            }
            case 2: {
                system("cls");
                filaMenu();
                cin >> op2;
                switch (op2) {
                    case 1: {
                        system("cls");
                        adicionarFila(&filaFrente, &filaFundo);
                        break;
                    }
                    case 2: {
                        system("cls");
                        removerFila(&filaFrente, &filaFundo);
                        break;
                    }
                    case 3: {
                        system("cls");
                        exibirFila(filaFrente);
                        break;
                    }
                    case 4:
                        system("cls");
                        break;
                    default:
                        cout << "\n\n! OPCAO INVALIDA !\n\n" << endl;
                        break;
                }
                break;
            }
            case 3:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "\n\n! OPCAO INVALIDA !\n\n";
                break;
        }
    } while (op1 != 3);

    while (pilhaTopo != NULL) {
        No* temp = pilhaTopo;
        pilhaTopo = pilhaTopo->next;
        delete temp;
    }

    while (filaFrente != NULL) {
        No* temp = filaFrente;
        filaFrente = filaFrente->next;
        delete temp;
    }

    return 0;
}
