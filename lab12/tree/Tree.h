//
// Created by Patryk on 01.06.2017.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H


#include <iostream>
#include <ostream>
#include <math.h>
#include <cmath>


namespace tree {
    template<class T>
    class Node {
    public:
        Node *left;
        Node *right;
        T value;

        Node(T value) : value(value) {
            left = nullptr;
            right = nullptr;

        }
        ~Node(){
            delete this->left;
            delete this->right;
        }

    };


    template<class T>
    class Tree {
    public:
        Node<T> *root;
        int size = 0;


        Tree(T initial_value) {
            this->root = new Node<T>(initial_value);
            size++;
        }

        Tree() {
            this->root = nullptr;

        }
        ~Tree(){
            delete this->root;
        }

        void insert_helper(T object, Node<T> *root_prim) {
            if (root_prim->value >= object) {
                if (!root_prim->left) {
                    root_prim->left = new Node<T>(object);
                    size++;
                }
                else
                    insert_helper(object, root_prim->left);
            } else {
                if (!root_prim->right) {
                    root_prim->right = new Node<T>(object);
                    size++;
                }
                else
                    insert_helper(object, root_prim->right);
            }

        }


        void Insert(T object) {
            if (!root) {
                this->root = new Node<T>(object);
                size++;
            }
            else
                insert_helper(object, root);
        }

        void Inorder(Node<T> *root){
                if(root){
                    Inorder(root->left);
                    std::cout<<root->value;
                    Inorder(root->right);
                }
        }

        int Size(){
            return this->size;
        }

        double Depth(){
            return std::floor(log2(size))+1;
        }

        double Value(){
            return this->root->value;
        }


    };
}


#endif //JIMP_EXERCISES_TREE_H
