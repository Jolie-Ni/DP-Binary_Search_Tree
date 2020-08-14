//
// Created by Nan Ni on 2020-08-14.
//

#ifndef DP_BINARY_SEARCH_TREE_TREE_NODE_H
#define DP_BINARY_SEARCH_TREE_TREE_NODE_H
#include <string>
using namespace std;

template<class T>
class Tree_Node {
private:
    T val;
    Tree_Node<T>* left;
    Tree_Node<T>* right;

public:
    //default constructor
    Tree_Node(){
        val = NULL;
        left = nullptr;
        right = nullptr;
    }

    //second constructor
    Tree_Node(T value){
        val = value;
        left = nullptr;
        right = nullptr;
    }

    //copy constructor
    Tree_Node(Tree_Node<T> &TN){
        val = TN.val;
    }

    //get val
    T get_val(){
        return val;
    }

    //set val
    void set_val(T value){
        val = value;
    }

    //get left
    Tree_Node<T>* get_left(){
        return left;
    }

    //set left
    void set_left(Tree_Node<T>* lf){
        left = lf;
    }

    //get right
    Tree_Node<T>* get_right(){
        return right;
    }

    ~Tree_Node<T>(){

    }

    //set right
    void set_right(Tree_Node<T>* rt){
        right = rt;
    }

    //operator overload for int
    bool operator > (Tree_Node<int> &T2){
        return (val > T2.get_val());
    }

    //operator overload for string
    bool operator > (Tree_Node<string> &T2){
        if(val.compare(T2.get_val()) > 0 ){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator < (Tree_Node<int> &T2){
        return (val < T2.get_val());
    }

    bool operator < (Tree_Node<string> &T2){
        if(val.compare(T2.get_val()) < 0){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator == (Tree_Node<int> &T2){
        return (val == T2.get_val());
    }

    bool operator == (Tree_Node<string> & T2){
        if(val.compare(T2.get_val()) == 0){
            return true;
        }
        else{
            return false;
        }
    }


};


#endif //DP_BINARY_SEARCH_TREE_TREE_NODE_H
