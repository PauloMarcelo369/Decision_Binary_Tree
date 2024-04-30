#include <vector>
#include <string>
#include "binarytree.h"
#include <queue>

class ArvoreDeDecisao
{
private:
    BinaryTree Arvore;
    void inserirNos(Node *node);
    void inicializar();
    void Resultado(Node *node, queue<int> sintomasSofridos);
    int NumeroDeDoencas;
    int NumeroDeSintomas;
    std::vector<std::string> Doencas;
    std::vector<std::string> Sintomas;
    std::vector<int> relacaoDoencaESintomas;

public:
    
    ArvoreDeDecisao();
    void Diagnostico(queue<int>& q);
    int getNumeroDeDoencas();
    int getNumeroDeSintomas();
    std::vector<std::string> getSintomas();
};