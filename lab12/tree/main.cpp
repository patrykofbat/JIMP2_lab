//
// Created by Patryk on 01.06.2017.
//


#include "Tree.h"

using namespace tree;

int main(){
    Tree<int> tree;
    tree.Insert(8);
    tree.Insert(5);
    tree.Insert(7);
    std::cout<<tree.Size();
    std::cout<<tree.Depth();




    return 0;

}
