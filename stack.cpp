#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Stack{
    private:
        struct Node {
            T data;
            Node* next;
            Node(T _data,Node *_next) : data(_data), next(_next){}
        };
        Node* head;

    public:
        Stack(): head(0x0){}
        ~Stack(){
            clean();
        }

    private:
        bool isempty(){
            return head == 0x0;
        }

    public:
        void push(T data){
            Node *tmp = new Node(data, head);
            if(tmp) head = tmp;
        }

        pair<bool , T> pop(){
            if(!isempty()) {
                T element = head->data;
                Node *drop = head;
                head=head->next;
                delete drop;
                return pair(true, element);
            }   return pair(false, NULL);
            cerr << "Warning: Empty Stack" << endl;
        }

        unsigned display(){
            Node *curr = head;
            unsigned length = 0;
            cout << "<";
            while(curr){
                cout << curr->data <<",";
                curr = curr->next;
                length++;
            }   cout << ">" << endl;
            return length;
        }

    protected:
        void clean();
};

template <typename T>
void Stack<T>::clean(){
    Node *curr = head, 
         *prev = 0x0;
    while(curr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
}
