#include <bits/stdc++.h>
using namespace std;
template<typename T = int>
class BST{
    private:
        struct Node {
            T data;
            Node *left, *right;
            Node(T _data) : data(_data), left(nullptr), right(nullptr) {}
        };
        Node *root;

    public:
        BST(){
            root = nullptr;
        }
        ~BST(){
            clean(root);
        }

    protected:
        void clean(Node *root){
            if(!root) return;
            clean(root->left);
            clean(root->right);
            delete root;
        }

    public:
        void insert(T data){
            Node **curr = &root;
            Node* newnode = new Node(data);
            while(*curr){
                curr = data < (*curr)->data ? &((*curr)->left) : &((*curr)->right);
            }
            *curr = newnode;
        }

        void remove(T target){
            deletenode(&root, target);
        }

        bool search(T target){
            Node *curr = root;
            while (curr) {
                if(target == curr->data) return true;
                else if (target < curr->data) curr = curr->left;
                else curr = curr->right;
            }   return false;
        }

        void traversal(unsigned order){
            cout << "<";
            switch (order) {
                case 0: cout << "PREORDER: ";
                        preorder_r(root);
                        break;
                case 1: cout << "INORDER: ";
                        inorder_r(root);
                        break;
                case 2: cout << "POSTORDER: ";
                        postorder_r(root);
                        break;
                default: cout << "<0:PREORDER,1:INORDER,2:POSTORDER";
            }
            cout << ">" << endl;
        }

    private:
        void deletenode(Node**, T);
        static int minval(Node *node){
            int minval = node->data;
            while (node->left) {
                minval = node->left->data;
                node = node->left;            
            }   return minval;
        }

    private:
        void preorder_r(Node*);
        void inorder_r(Node*);
        void postorder_r(Node*);
};

template<typename T>
void BST<T>::preorder_r(Node *node){
    if(!node)return;
    cout << node->data << ",";
    preorder_r(node->left);
    preorder_r(node->right);
}

template<typename T>
void BST<T>::inorder_r(Node *node){
    if(!node)return;
    inorder_r(node->left);
    cout << node->data << ",";
    inorder_r(node->right);
}

template<typename T>
void BST<T>::postorder_r(Node *node){
    if(!node)return;
    postorder_r(node->left);
    postorder_r(node->right);
    cout << node->data << ",";
}

template <typename T>
void BST<T>::deletenode(Node **root, T target){
    Node **node = root;
    Node *drop;
    while(node){
        if(target < (*node)->data){
            node = &((*node)->left);
        } else if(target > (*node)->data){
            node = &((*node)->right);
        } else {
            Node *drop = *node;
            if((*node)->left == nullptr) {
                *node = (*node)->right;
                delete drop;
                break;
            }   else if((*node)->right == nullptr) {
                *node = (*node)->left;
                delete drop;
                break;
            }
            (*node)->data = minval((*node)->right);
            deletenode(&((*node)->right), (*node)->data);
            break;
        }
    }
}
