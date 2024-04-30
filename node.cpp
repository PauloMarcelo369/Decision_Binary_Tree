#ifndef NODE_CPP
#define NODE_CPP

#include "node.h"

Node::Node(Node *l, Node *r){
    left = l;
    right = r;
    isSickness = false;
}

int Node::getValue(){
    return this->value;
}


Node* Node::getLeft(){
    return this->left;
}

void Node::setLeft(Node* newLeft){
    this->left = newLeft;
}

Node* Node::getRight(){
    return this->right;
}

void Node::setRight(Node* newRight){
    this->right = newRight;
}


//Nessa função, quando chegamos em um nó folha, ela é chamada
//e setamos aquele nó como um nó doença pro conta do atributo "bool isSickness"
void Node::itsAdisease(){
    isSickness = true;
}

//Retorna True caso sejá um nó folha
bool Node::isSickness_(){
    return isSickness;
}

//Essa função adiciona a doença no nó folha 
void  Node::setDisease(string disease){
    diseases.insert(disease);
}

//Retorna a doença relacionada ao nó folha 
set<string> Node::getDiseases(){
    return diseases;
}

#endif