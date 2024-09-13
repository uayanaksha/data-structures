#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Queue{
    private:
        struct Node {
            T data;
            Node* next;
            Node(T _data,Node *_next) : data(_data), next(_next){}
        };
        Node *head, *tail;

    public:
        Queue(): head(nullptr), tail(nullptr){}
        ~Queue(){
            clean();
        }

    private:
        bool isempty(){
            return tail == nullptr;
        }

    public:
        void enque(T data){
            Node *ptr = new Node(data, head);
            if(isempty()){
                head = tail = ptr;
            }   else {
                tail->next = ptr;
                tail = ptr;
            }
        }

        pair<bool , T> deque(){
            T element = 0;
            if(!isempty()) {
                element = head->data;
                Node *drop = head;
                if(head == tail){
                    head = tail = nullptr;
                }   else{
                    head = head->next;
                }   delete drop;
            }
            return pair<bool, T>( !isempty() , element);
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
void Queue<T>::clean(){
    Node *curr = head, 
         *prev = 0x0;
    while(curr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
}
