#include <iostream>
#include "Tree_Node.h"
#include "BST.h"

int main() {
    vector<int> my_list{5,6,10,2,7};
    BST<int> T1(my_list);
    T1.print_tree();
    T1.delete_node(2);
    T1.delete_node(6);
    T1.delete_node(7);
    T1.delete_node(10);
    T1.delete_node(5);

    cout<<"new tree" << endl;
    T1.print_tree();
    return 0;
}
