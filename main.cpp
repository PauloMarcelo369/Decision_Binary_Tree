/******************
//
// Projeto 2 - Estrutura de Dados UFC
//
// Criação:     04 Jul 2023
// Atualização: 07 Jul 2023
//
// Criado Por:
// PAULO MARCELO CABRAL ARAUJO
// Número de Matrícula [UFC]:536813
//
// MARIO MARTINS ARAGAO
// Número de Matrícula [UFC]: 542056
****************/

#include "DecisionTree.hpp"
#include <iostream>

using namespace std;

//Função para limpar o Terminal
void clear_terminal(){
    printf("\033c");
}

void print_menu();

int main()
{
    ArvoreDeDecisao arvore; //Inicialização da arvore
    
    /*
        Funcionamento da main interativa:
        O usuário recebe um menu de seleção, nele, voce diz se quer iniciar um diagnostico ou sair do programa
        
        Caso  seja iniciado o diagnostico, o programa cria uma fila de respostas, inteiro de resposta e faz suas funções(que serão explicadas abaixo), 
        quando for dado o diagnostico, aparecera novamente a caixa de seleção de modo, caso ele clique em 0  o programa é encerrado.
        Caso contrário o programa refaz os passos do item 1
    */
    
    do
    {
        print_menu();
        int escolha;
        do
        {
            cin >> escolha;
            //Caso o usuario tenha digitado outro número sem ser 0 ou 1, essa
            //função continuará até que o usuario digite uma entrada válida
            if (escolha != 0 && escolha != 1)
            {
                cout << "Please enter only 0 or 1. Please try again:" << '\n';
            }
        } while (escolha != 0 && escolha != 1);
        //Inicio do Diagnostico
        if (escolha == 1)
        {
            clear_terminal();
            queue<int> respostas; //Fila que irá guardar a entrada do usuário
            int resp = 0;
            /*
                For ira printar todos os sintomas e guardara a entrada do usuario
                
                Caso o usuario tenha digitado outro número sem ser 0 ou 1, essa
                função continuará até que o usuario digite uma entrada válida
                
                ao final do for, será chamada a função Diagnostico que passara 
                essa fila de respostas do usuário
            */
            for (int i = 0; i < arvore.getNumeroDeSintomas(); i++)
            {
                cout << "Ask " << i + 1 << ": "
                     << "You are feeling " << arvore.getSintomas()[i] << endl;
                do
                {
                    cin >> resp;
                    if (resp != 0 && resp != 1)
                    {
                        cout << "Please enter only 0 or 1. Please try again: " << '\n';
                    }
                } while (resp != 0 && resp != 1);
                respostas.push(resp);
            }
            arvore.Diagnostico(respostas);
        }
        //Fim do programa
        else if(escolha == 0)
        {
            clear_terminal();
            cout << "program end" << '\n';
            return false;
        }

    } while (true);

    return 0;
}

void print_menu()
{
    cout << "Enter 1 to start diagnostics." << endl;
    cout << "Enter 0 to finish" << endl;
}
