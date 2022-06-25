//  main.cpp
//  P&D 10: Double linked list deque
//
//  Created by Julia Vister on 26/05/2022.
//

#include <iostream>
#include <stdexcept>

struct Node{
    int value;
    Node *next;
    Node *prev;
    
    Node(int value):
    value(value),
    next(nullptr),
    prev(nullptr){}
};


class Deque{
    Node *head;
    Node *tail;
    
public:
Deque():
    head(nullptr),   //constructor
    tail(nullptr){}
    
    Deque(const Deque& original):head(nullptr),tail(nullptr){  //copy constructor
     /*   if(!original.empty()){
            head=new Node(original.head->value);
            Node *source =original.head->next;
            Node *destination=head;
            
            while(source!=nullptr){
                destination->next=new Node(source->value);
                destination=destination->next;
                source=source->next;
            }
            tail=destination;
        } */
      
        Node *tmp = original.head;
        while (tmp != nullptr) {
            push_front(tmp->value);
            tmp = tmp -> next;
        }
    }
    
    Deque &operator=(Deque cpy){   //assignment operator
        std::swap(cpy.head, head);
        std::swap(cpy.tail, tail);
        return *this;
    }
            

    bool empty()const{
        return (head==nullptr);
    }

int back(){
    if(empty()){
        throw std::runtime_error("empty deque");
    }
    return tail->value;
}

int front(){
    if(empty()){
        throw std::runtime_error("empty deque");
    }
    return head->value;
}

void push_front(int x){
    if(empty()){
        head=new Node(x);
        tail=head;
    }
    else{
        Node *tmp=new Node(x);
        tmp->next = head;
        head->prev=tmp;
        head=tmp;
    }
}

void push_back(int x){
    if(empty()){
        head=new Node(x);
        tail=head;
    }
    else{
        Node *tmp=new Node(x);
        tmp->prev=tail;
        tail->next=tmp;
        tail=tmp;
    }
}

void pop_back(){
    if(empty()){
        throw std::runtime_error("empty deque");
    }
    if(head==tail){
        delete head;
        head=nullptr;
        tail=nullptr;
    }
    else{
    tail=tail->prev;
    delete tail->next;
    tail->next=nullptr;
}
}

void pop_front(){
    if(empty()){
       
    }
    if(head==tail){
        delete head;
        head=nullptr;
        tail=nullptr;
    }
    else{
    head=head->next;
    delete head->prev;
    head->prev=nullptr;
}
}
    
void clear(){
    while(!empty()){
        pop_front();
    }
}

    ~Deque(){
        clear();
    }
};

int main() {
    Deque d;
    d.push_front(2);
    d.push_back(4);
    std::cout<< d.back() << " ";
    std::cout << d.front() << " ";
    d.push_back(8);
    d.push_front(6);
    std::cout << d.front() << " ";
    d.push_back(10);
    std::cout << d.front() << " ";
    d.pop_front();
    
    puts("");
    return 0;
}
