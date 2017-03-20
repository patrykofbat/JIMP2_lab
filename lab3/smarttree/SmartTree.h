//
// Created by patryk on 15.03.17.
//

#ifndef JIMP_EXERCISES_SMARTTREE_H
#define JIMP_EXERCISES_SMARTTREE_H

#include <iostream>
#include <ostream>
#include <string>
#include <memory>
using std::unique_ptr;
using std::make_unique;


namespace datastructures {
    struct SmartTree {
        unique_ptr<SmartTree> left = nullptr;
        unique_ptr<SmartTree> right = nullptr;
        int value;
    };

    unique_ptr<SmartTree> CreateLeaf(int value) {
        unique_ptr<SmartTree> Leaf = make_unique<SmartTree>();
        if (Leaf->left == nullptr && Leaf->right == nullptr)
            Leaf->value = value;
        return Leaf;

    }


    unique_ptr<SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree) {
        if (tree->left == nullptr) {
            tree->left = move(left_subtree);
            tree->left->left = nullptr;
            tree->left->right = nullptr;
        }
            return tree;
    }
        unique_ptr<SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree) {
            if (tree->right == nullptr) {
                tree->right = move(right_subtree);
                tree->right->right = nullptr;
                tree->right->left = nullptr;
            }
                return tree;
        }
    void PrintTreeInOrder(const unique_ptr<SmartTree> &tree, std::ostream *out){
        if(tree == nullptr){
            return;
        }
        else {
            PrintTreeInOrder(tree->left, out);
            *out<<tree->value<<", ";
            PrintTreeInOrder(tree->right, out);
        }

    }


}


#endif //JIMP_EXERCISES_SMARTTREE_H
