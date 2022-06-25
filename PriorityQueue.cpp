//  main.cpp
//  P&D: Priority Queue
//
//  Created by Julia Vister on 03/06/2022.
// Priority queue as a linked list:

#include <iostream>
#include <stdexcept>
#include <queue>
#include <string>


struct Customer{
    int priority;
   std::string name;
    
};
struct Node{
    Node *next;
    Node *prev;
    Customer value;

    Node(Customer value): value(value),next(nullptr),prev(nullptr) {}
    
   /* Node(Customer _value,Node *_next=nullptr,Node *prev=nullptr):
    value(_value),
    next(_next)
    {} */
};

class Priorityqueue{
    Node *head;
    Node *tail;
    
public:
    Priorityqueue():
    head(nullptr),
    tail(nullptr)
    {}
    
    Node *begin(){
        return head;
    }
    
    bool empty(){
        return head==nullptr;
    }
    
    void insert_before(Node *n, Customer value){
        if(n==nullptr){
            push(value);
        }
        if(n==head){
            push(value);
        }
    }

    void Insert(Customer value){ 
        Node *new_node =new Node(value);
        new_node->value=value;
        new_node->next=nullptr;
        if(head==nullptr){
            head=new_node;
            return;
        }
        else{
            new_node->next=head;
            head=new_node;
        }
    }
    
    void push(Customer value){
        Node *tmp = new Node(value);
        if(head==nullptr){
            head=tmp;
            tail=head;
            return;
        }
        
        tmp->next=head;
        head=tmp;
    
        while(tmp->next!=nullptr){
            
            if(tmp->value.priority > tmp->next->value.priority){
            std::swap(tmp->value, tmp->next->value);
            }
            else
            {
                return;
            }
            tmp=tmp->next;
    }
    }
        
    void pop(){
        if(empty()){
            throw std::runtime_error("Cannot remove from empty queue!");
        }
        Node *tmp=head;
        head=head->next;
        delete tmp;
    }
    
        
   Customer front(){
        if(empty()){
            throw std::runtime_error("Cannot front value from empty queue!");
        }
        return head->value;  //returning customer
    }
               
               
 void clear(){
        while(!empty()){
            pop();
        }
    }
               
    ~Priorityqueue() {
        clear();
    }
    
    Priorityqueue(const Priorityqueue& original):head(nullptr){
        Node *tmp = original.head;
        while (tmp != nullptr) {
            push(tmp->value);
            tmp = tmp -> next;
        }
    }
    
    Priorityqueue &operator=(Priorityqueue cpy){
        std::swap(cpy.head, head);
        return *this;
    }
 

    void print(){
        Node *tmp=head;
        while(tmp!=nullptr){
            std::cout<< tmp->value.priority << " ";
            std::cout<< tmp->value.name << " ";
            tmp=tmp->next;
            
        }
        std::cout<<std::endl;
        
    }
    
};


int main() {
    Priorityqueue q;
    Customer V;
    V.priority=10;
    V.name="Julia";
    
    Customer H;
    H.name="Dorsa";
    H.priority=8;
    
    Customer G;
    G.name="Piotr";
    G.priority=20;
    
    
    q.push(V);
    q.push(H);
    q.push(G);
    
    G.name="Piotr2";
    G.priority=9;
    q.push(G);
    
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    
 
    std::cout << "\nIT RAN! ";
    return 0;
}
