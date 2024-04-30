#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include <iostream>
#include "binarytree.h"
using namespace std;

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::BinaryTree(int value) {
    root = new Node(nullptr, nullptr);
}

BinaryTree::BinaryTree(BinaryTree& l, BinaryTree& r) {
    root = new Node(l.getRoot(), r.getRoot());
    //As duas árvores ficarão vazias, pois os nós raizes delas serão filhas da árvore criada
    l.setRoot(nullptr);
    r.setRoot(nullptr);
}

Node* BinaryTree::getRoot(){
    return root;
}
    
void BinaryTree::setRoot(Node* newRoot){
    root = newRoot;
}

//Implementei uma função recursiva para liberar os nós de forma recursiva
void clear_rec(Node* node) {
    if(node != nullptr) {
        clear_rec(node->getLeft());
        clear_rec(node->getRight());
        delete node;
    }
}


void BinaryTree::clear() {
    clear_rec(root);
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    clear();
}

bool BinaryTree::is_empty() {
    return root == nullptr;
}

void print_values_rec(Node *node) {
    if(node != nullptr) {
        cout << node->getValue() << " ";
        print_values_rec(node->getLeft());
        print_values_rec(node->getRight());
    }
}

void BinaryTree::print_values() {
    print_values_rec(root);
    cout << endl;
}

bool BinaryTree::is_leaf() {
    return !is_empty() && root->getLeft() == nullptr && root->getRight() == nullptr;
}

bool contains_rec(Node* node, int value) {
    if(node == nullptr) 
        return false; // subárvore vazia
    else 
        return node->getValue() == value ||
               contains_rec(node->getLeft(), value) ||
               contains_rec(node->getRight(), value);
}

bool BinaryTree::contains(int value) {
    return contains_rec(root, value);
}

#endif