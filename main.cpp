#include <iostream>
#include "Tree_Node.h"
#include "BST.h"

int main() {
    vector<int> my_list{5,6,10,2,7};
    BST<int> T1(my_list);
    T1.print_list();
    T1.valid_BST();
    T1.swap_node(6,10);
    cout<<"new tree" << endl;
    T1.print_list();
    T1.valid_BST();
    T1.recover_BST();
    T1.valid_BST();
    T1.print_list();
    return 0;
}
