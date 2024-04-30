#ifndef NODE_H
#define NODE_H
#include <string>
#include <set>
using namespace std;

class Node {
private:
    int value;  // valor 
    set<string> diseases;
    Node *left;  // ponteiro para filho esquerdo
    Node *right;  // ponteiro para filho direito
    bool isSickness; //Ponteiro para nó doença
    
public:
    /**
     * Construtor que recebe o valor que o nó irá armazenar e os ponteiros para os 
     * filhos esquerdo e direito, respectivamente.
     * */
    Node(Node *l, Node *r);
    
    /**
    Métodos gets e sets dos atributos
    **/
    int getValue();
    Node* getLeft();
    Node* getRight();
    

    void itsAdisease();
    bool isSickness_();
    
    void setLeft(Node* newLeft);
    void setRight(Node* newRight);
    void setDisease(string disease);
    set<string> getDiseases();
};
#endif
