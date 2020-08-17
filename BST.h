//
// Created by Nan Ni on 2020-08-14.
// for future could have save a log file recording the process of constructing tree
// including detail of what is being added and what is being deleted and how

#ifndef DP_BINARY_SEARCH_TREE_BST_H
#define DP_BINARY_SEARCH_TREE_BST_H
#define LEFT -1
#define RIGHT 1
#define ROOT 0
#define INSERT 10
#define DELETE -10
#include "Tree_Node.h"
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

template <class T>
class BST {

private:
    Tree_Node<T>* root;
    vector<int> path;
public:
    //default constructor
    BST();

    //second constructor
    BST(vector<T> list);

    //copy constructor
    BST(BST<T> &Tree);

    //get root
    Tree_Node<T>* get_root();

    //set root
    void set_root(Tree_Node<T>* rt);

    //get path
    void print_path();

    //insert leaf
    void insert_node(T val);

    //delete leaf
    void delete_node(T val);

    //clear all
    void clear_all();

    //print in-order
    void print_list();

    //print tree shape
    void print_tree();

    //balance tree
    void balance_tree();


    //destructor
    ~BST<T>();
};

//copy helper
template<class T>
Tree_Node<T>* cpy_helper(Tree_Node<T>* root);

template<class T>
//clear helper
Tree_Node<T>* clear_helper(Tree_Node<T>* root);

template<class T>
//delete node helper
Tree_Node<T>* delete_node_helper(Tree_Node<T>* root);

template<class T>
Tree_Node<T>* rightMin(Tree_Node<T>* root);

template<class T>
Tree_Node<T>* leftMax(Tree_Node<T>* root);

template<class T>
BST<T>::BST(){
    root = nullptr;
}

template<class T>
BST<T>::BST(vector<T> list){
    for(typename vector<T>::iterator itr = list.begin(); itr != list.end(); itr++){
        insert_node(*itr);
    }
}

template<class T>
BST<T>::BST(BST<T> &Tree){

    root = cpy_helper(Tree.root);

}

template<class T>
Tree_Node<T>* cpy_helper(Tree_Node<T>* root){
    if(root == nullptr){
        return nullptr;
    }
    else{
        Tree_Node<T>* new_node = new Tree_Node<T>(root->get_val());
        new_node->set_left(cpy_helper(root->get_left()));
        new_node->set_right(cpy_helper(root->get_right()));
        return new_node;
    }
}

template<class T>
Tree_Node<T>* BST<T>::get_root(){
    return root;
}

template<class T>
void BST<T>::set_root(Tree_Node<T> *rt) {
    root = rt;
}

template<class T>
void BST<T>::print_path(){
    for(vector<int>::iterator itr = path.begin();itr != path.end();itr++){
        if(*itr == -1){
            cout << "-1 ";
        }
        else if(*itr == 0){
            cout << "0 ";
        }
        else if(*itr == 1){
            cout << "1 ";
        }
        else if(*itr == 10){
            cout << "INSERT ";
        }
        else if(*itr == -10){
            cout << "DELETE ";
        }
        else{
            cout << "UNDEFINED ";
        }
         cout << ",";
    }
}

template<class T>
//insert leaf
//path indicating the sequential path of insertion, -1 indicating go left, 1 indicating go right
void BST<T>::insert_node(T val){
    Tree_Node<T>* ptr = root;
    Tree_Node<T>* new_node = new Tree_Node<T>(val);
    Tree_Node<T>* lf = nullptr;
    Tree_Node<T>* rt = nullptr;
    if(ptr == nullptr){
        root = new_node;
    }
    else{
        while(ptr != nullptr){
            //go left
            if((*new_node) < (*ptr)){
                lf = ptr;
                ptr = ptr->get_left();
                path.push_back(LEFT);
            }
                //go right
            else if((*new_node) > (*ptr)){
                rt = ptr;
                ptr = ptr->get_right();
                path.push_back(RIGHT);
            }
            else{
                cout << "node already exist" << endl;
                path.push_back(ROOT);
                return;
            }
        }

        //when reached bottom from left
        if(*(path.end()-1) == LEFT){
            lf->set_left(new_node);
        }//from right
        else{
            rt->set_right(new_node);
        }

        path.push_back(INSERT);

    }
}


template<class T>
//delete leaf
void BST<T>::delete_node(T val){
    //find node to be deleted
    Tree_Node<T>* target = new Tree_Node<T>(val);
    root = delete_node_helper(root,target);
}


template<class T>
//clear all
void BST<T>::clear_all(){
    root = clear_helper(root);
    if(root == nullptr){
       cout << "root is null" << endl;
    }
}

template<class T>
//print in-order
void BST<T>::print_list(){

}

template<class T>
//print tree shape
void BST<T>::print_tree(){
    vector<T> tree;
    queue<Tree_Node<T>*> nodes;
    if(root == nullptr){
        cout << "tree is empty" << endl;
        return;
    }
    else{
        nodes.push(root);
    }
    while(!nodes.empty()){
        Tree_Node<T>* ptr = nodes.front();
        if(ptr->get_left() != nullptr){
            nodes.push(ptr->get_left());
        }

        if(ptr->get_right() != nullptr){
            nodes.push(ptr->get_right());
        }
        
        tree.push_back(ptr->get_val());
        nodes.pop();
    }
    for(typename vector<T>::iterator itr = tree.begin();itr != tree.end();itr++){
        cout << *itr << endl;
    }
}

template<class T>
//balance tree
void BST<T>::balance_tree(){

}

template<class T>
Tree_Node<T>* clear_helper(Tree_Node<T>* root){
    if(root == nullptr){
        return nullptr;
    }
    else{
        root->set_left(clear_helper(root->get_left()));
        root->set_right(clear_helper(root->get_right()));
        delete root;
        return nullptr;
    }
}


template<class T>
Tree_Node<T>* delete_node_helper(Tree_Node<T>* root,Tree_Node<T>* target){
    if(root == nullptr){
        return nullptr;
    }
    else{
        root->set_left(delete_node_helper(root->get_left(),target));
        root->set_right(delete_node_helper(root->get_right(),target));
        //found to delete
        if((*target) == (*root)){
            if(root->get_left() == nullptr && root->get_right() == nullptr) {
                //leaf
                delete root;
                return nullptr;
            }
            else if(root->get_left() == nullptr){
                Tree_Node<T>* RM = rightMin(root);
                T temp = root->get_val();
                root->set_val(RM->get_val());
                RM->set_val(temp);
                return delete_node_helper(root,RM);
            }
            else{
                Tree_Node<T>* LM = leftMax(root);
                T temp = root->get_val();
                root->set_val(LM->get_val());
                LM->set_val(temp);
                return delete_node_helper(root,LM);
            }
        }
        else{
            return root;
        }
    }

}

template<class T>
Tree_Node<T>* rightMin(Tree_Node<T>* root){
    Tree_Node<T>* rt = root->get_right();
    while(root->get_left() != nullptr){
        rt = rt->get_left();
    }
    return rt;
}

template<class T>
Tree_Node<T>* leftMax(Tree_Node<T>* root){
    Tree_Node<T>* rt = root->get_left();
    while(root->get_right() != nullptr){
        rt = rt->get_right();
    }
    return rt;
}

//destructor
template<class T>
BST<T>::~BST(){

}


#endif //DP_BINARY_SEARCH_TREE_BST_H
