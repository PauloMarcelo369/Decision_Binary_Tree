#include "DecisionTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ArvoreDeDecisao::ArvoreDeDecisao()
{
    inicializar();
}

void ArvoreDeDecisao::inserirNos(Node *node)
{
    /*
        Caso o vector relação doença tiver apenas um elemento,
        esse elemento será o código da doença
        
        dentro função: 
        a variavel id vai reber esse codigo
        o node recebera true para doença(dos os nos são iniciados como false)
        o node recebe aquela doença(vector[id-1])
        o vector relacao doenca sintoma e esvaziado 
        return 
    */
    if (relacaoDoencaESintomas.size() == 1)
    {
        int id = relacaoDoencaESintomas[0];
        node->itsAdisease();
        node->setDisease(Doencas[id-1]);
        relacaoDoencaESintomas.pop_back();
        return;
    }
    /*
        Caso o elem na posição 1 do vector seja 0,
        então checa se o no a esquerda esta vazio, se sim
        então o no é criado.
        retiramos o elemento da posição 1 do vector 
        chamamos a função passando o no para a esquerda
    */
    if (relacaoDoencaESintomas[1] == 0)
    {
        if (node->getLeft() == nullptr) node->setLeft(new Node(nullptr, nullptr));
        relacaoDoencaESintomas.erase(relacaoDoencaESintomas.begin() + 1);
        inserirNos(node->getLeft());
    }
    /*
         posição 1 do vector seja 1,
        então checa se o no a direita esta vazio, se sim
        então o no é criado.
        retiramos o elemento da posição 1 do vector 
        chamamos a função passando o no para a direita
    */
    else
    {
        if (node->getRight() == nullptr) node->setRight(new Node(nullptr, nullptr));
        relacaoDoencaESintomas.erase(relacaoDoencaESintomas.begin() + 1);
        inserirNos(node->getRight());
    }
}

void ArvoreDeDecisao::inicializar()
{
    if (Arvore.is_empty()) // checa se a árvore é vazia
    { 
        Node *root = new Node(nullptr, nullptr); //Cria o no root
        Arvore.setRoot(root);

        ifstream Arquivo("arquivo.txt"); //Arquivo recebe o txt

        if (!Arquivo)
        {
            cerr << "Erro ao abrir o arquivo." << endl;
            return;
        }
        istringstream iss;
        string line;
        Arquivo >> NumeroDeDoencas >> NumeroDeSintomas;
        Arquivo.ignore();
        //Função que coloca as doenças em um vector
        for (int i = 1; i <= NumeroDeDoencas; i++)
        {
            getline(Arquivo, line);
            Doencas.push_back(line);
        }
        //Função que coloca os sintomas em um vector
        for (int i = 0; i < NumeroDeSintomas; i++)
        {
            getline(Arquivo, line);
            Sintomas.push_back(line);
        }
        
        
        while (getline(Arquivo, line))
        {
            istringstream iss2(line);
            int token;
            
            /*
            Coloca cada linha dentro do vector relacao doença sintoma
            E chama a função que constroi as arvores linha por linha, até o fim do
            arquivo
            */
            while (iss2 >> token)
            {
                relacaoDoencaESintomas.push_back(token);
            }
            
            //Chama a função que constroi as arvores 
            inserirNos(Arvore.getRoot());
        }
        Arquivo.close();
    }
}

//função que diz qual é a dença, recebe o no e uma fila de sintomas
void ArvoreDeDecisao::Resultado(Node *node, queue<int> sintomasSofridos)
{
    if (node == nullptr)
    {
        cout << "Nao existe uma doenca com essa combinacao de sintomas!" << endl;
        return;
    }
    //Caso chegue em um no que seja doença e a fila estiver vazia, então
    //serão printadas as doenças correspondentes aqueles sintomas
    if (node->isSickness_() && sintomasSofridos.empty())
    {
        cout << "O paciente sofre de: "<< '\n';
        for(const auto& s : node->getDiseases())
        {
            cout << s << '\n';
        }
        return;
    }
    //Funçãoes que percorrem a arvore até chegar em um no folha(Doença)
    int tag = sintomasSofridos.front(); //leitura do primeiro elemento da fila
    sintomasSofridos.pop();//Retirada
    //Caso seja 0, então a função é chamada novamente indo para a esquerda e passando 
    //a lista se aquele elemento
    if (tag == 0) Resultado(node->getLeft(), sintomasSofridos);
    //Caso contrario
    else Resultado(node->getRight(), sintomasSofridos);
}

//Função que é chamada na main, onde é passada a fila de sintomas
void ArvoreDeDecisao::Diagnostico(queue<int>& q)
{
    Resultado(Arvore.getRoot(), q);
}

int  ArvoreDeDecisao::getNumeroDeDoencas()
{
    return  NumeroDeDoencas;
}
int  ArvoreDeDecisao::getNumeroDeSintomas()
{
    return NumeroDeSintomas;
}

std::vector<std::string> ArvoreDeDecisao::getSintomas()
{
    return Sintomas;
}