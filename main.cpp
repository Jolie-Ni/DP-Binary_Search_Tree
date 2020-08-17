#include <iostream>
#include "Tree_Node.h"
#include "BST.h"

int main() {
    vector<int> my_list{5,6,10,2,7};
    BST<int> T1(my_list);
    T1.print_tree();
    T1.delete_node(10);
    cout<<"new tree" << endl;
    T1.print_tree();
    return 0;
}
