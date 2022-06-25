//  main.cpp
//  P&D 9. Linked list Queue
//
//  Created by Julia Vister on 25/05/2022.

#include <iostream>
#include <stdexcept>

struct Node {
    int value;
    Node *next;
    
    Node(int _value,Node *_next=nullptr):
    value(_value),
    next(_next)
    {}
};

class Queue{
    Node *head;
    Node *tail;
    
public:
    Queue():
    head(nullptr),
    tail(nullptr)
    {}
    
    bool empty()const {
        return (head==nullptr);
    }
    
    void push(int x){   //inserting values
        if(empty()){
            head=new Node(x);
            tail=head;
        }
        else{
            tail->next=new Node(x);
            tail=tail->next;
        }
    }
    
    int front(){   //showing value
        if(empty()){
            throw std::runtime_error("Cannot front value from empty queue!");
        }
        return head->value;
    }
    
    void pop(){  //removing values
        if(empty()){
            throw std::runtime_error("Cannot remove from empty queue!");
        }
        Node *tmp=head;
        head=head->next;
        delete tmp;
    }
    
    void clear(){
        while(!empty()){
            Node *tmp=head;
            head=head->next;
            delete tmp;
        }
    }
    ~Queue() {  //destructor
        clear();
    }
    
    Queue(const Queue& original):head(nullptr){  //copy constructor
        if(!original.empty()){
            head=new Node(original.head->value);
            Node *source =original.head->next;
            Node *destination=head;
            
            while(source!=nullptr){
                destination->next=new Node(source->value);
                destination=destination->next;
                source=source->next;
            }
            tail=destination;
        }
    }
    
     void extend(const Queue& original){ //copies from another queue
        Node *tmp=original.head;
        while(tmp !=nullptr){
            push(tmp->value);
            tmp=tmp->next;
        }
    }
    
    Queue &operator=(Queue cpy){   //assignment operator
        std::swap(cpy.head, head);
        std::swap(cpy.tail, tail);
        return *this;
    }
    
    Queue merge(Queue &original, Queue &other){ //produces a third queue
        Queue Result;
        }
    while(!orginal.empty() && !other.empty()){
        if(original.push() < other.push()){
            original.pop();
            result.push(original.front());
        }
        else if(other.push()> original.push())
        {
            other.pop();
            result.push(other.push);
        }
        return Result;
    }
    
};

int main() {
    Queue q;
    q.push(5);
    std::cout<< q.front() <<std::endl;
    q.pop();
    q.push(10);
    std::cout<< q.front() <<std::endl;
    q.pop();
    q.push(15);
    std::cout<< q.front() <<std::endl;
    q.pop();
    q.push(20);
    std::cout<< q.front() <<std::endl;
    puts("");
  
    Queue w;
    w.push(25);
    w.push(30);
    w.push(35);
    w.push(40);

    

    std::cout << "Successfull linked list Queue!" <<std::endl;
    return 0;
}
