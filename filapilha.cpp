#include <iostream>
#include <stack>
#include <queue>
#include<cstdlib>
using namespace std;

//Criando as fun��es para exibir os menus.
void exibirMenuPrincipal() {
    cout << "Menu Principal" << endl;
    cout << "1 - Pilha" << endl;
    cout << "2 - Fila" << endl;
    cout << "3 - Sair" << endl;
    cout << "Digite a opcao desejada: " <<endl;
}

void exibirMenuPilha() {
    cout << "Menu Pilha" << endl;
    cout << "1 - Adicionar Elemento" << endl;
    cout << "2 - Remover Elemento" << endl;
    cout << "3 - Exibir Elementos da Pilha" << endl;
    cout << "4 - Voltar ao Menu Principal" << endl;
    cout << "Digite a opcao desejada: " << endl;
}

void exibirMenuFila() {
    cout << "Menu Fila" << endl;
    cout << "1 - Adicionar Elemento" << endl;
    cout << "2 - Remover Elemento" << endl;
    cout << "3 - Exibir Elementos da Fila" << endl;
    cout << "4 - Voltar ao Menu Principal" << endl;
    cout << "Digite a opcao desejada: " << endl;
}

/*Aqui que a magia acontece, � criada uma vari�vel para armazenar a op��o digitada pelo usu�rio, logo antes de uma sequ�ncia
de switch case, incluindo os dois menus dentro do switch case principal. Os conceitos de FIFO e LIFO s�o aplicados no momento
da remo��o de algum elemento.*/
int main() {
    int opcao;
    stack<int> pilha;
    queue<int> fila;

    do {
    	system("cls");
        exibirMenuPrincipal();
        cin >> opcao;
        switch (opcao) {
            case 1:
            	system("cls");
                exibirMenuPilha();
                cin >> opcao;

                switch (opcao) {
                    case 1: {
                    	system("cls");
                        int elemento;
                        cout << "Digite o elemento a ser adicionado: ";
                        cin >> elemento;
                        pilha.push(elemento);
                        cout << "Elemento adicionado com sucesso!" << endl;
                        system("cls");
                        break;
                    }
                    case 2:
                    	system("cls");
                        if (!pilha.empty()) {
                            pilha.pop();
                            cout << "Elemento removido com sucesso!" << endl;
                            system("cls");
                        } else {
                            cout << "A pilha est� vazia!" << endl;
                        }
                        break;
                    case 3:
                    	system("cls");
                        if (!pilha.empty()) {
                            stack<int> temp = pilha;

                            cout << "Elementos na pilha: ";
                            while (!temp.empty()) {
                                cout << temp.top() << " ";
                                temp.pop();
                            }
                            cout << endl;
                        } else {
                            cout << "A pilha est� vazia!" << endl;
                        }
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Op��o inv�lida!" << endl;
                        break;
                }
                break;
            case 2:
            	system("cls");
                exibirMenuFila();
                cin >> opcao;
                switch (opcao) {
                    case 1: {
                    	system("cls");
                        int elemento;
                        cout << "Digite o elemento a ser adicionado: ";
                        cin >> elemento;
                        fila.push(elemento);
                        cout << "Elemento adicionado com sucesso!" << endl;
                        system("cls");
                        break;
                    }
                    case 2:
                    	system("cls");
                        if (!fila.empty()) {
                            fila.pop();
                            cout << "Elemento removido com sucesso!" << endl;
                        } else {
                            cout << "A fila est� vazia!" << endl;
                        }
                        break;
                    case 3:
                    	system("cls");
                        if (!fila.empty()) {
                            queue<int> temp = fila;

                            cout << "Elementos na fila: ";
                            while (!temp.empty()) {
                                cout << temp.front() << " ";
                                temp.pop();
                            }
                            cout << endl;
                        } else {
                            cout << "A fila est� vazia!" << endl;
                        }
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Op��o inv�lida!" << endl;
                        break;
                }
                break;
            case 3:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Op��o inv�lida!" << endl;
                break;
        }
    } while (opcao != 3);

    return 0;
}

//Acrescentei o comando "system("cls")" para limpar a tela e ficar mais f�cil de enxergar.
