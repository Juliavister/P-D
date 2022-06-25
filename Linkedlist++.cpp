//  main.cpp
//  P&D: Double linked list iteration
//
//  Created by Julia Vister on 02/06/2022.

#include <iostream>

struct Node{
    int value;
    Node *next;
    Node *prev;
    
    explicit Node(int v):
    value(v),
    next(nullptr),
    prev(nullptr)
    {}
};

class Doublelinkedlist
{
    Node *head;
    Node *tail;
public:
    Doublelinkedlist():
    head(nullptr),
    tail(nullptr)
    {}
    
    Node *begin(){
        return head;
    }
    
    Node *end(){
        return tail;
    }
    
    Doublelinkedlist(const Doublelinkedlist& original):head(nullptr),tail(nullptr){ //copy constructor
        Node *tmp = original.head;
        while (tmp != nullptr) {
            push_front(tmp->value);
            tmp = tmp -> next;
        }
    }
    
    Doublelinkedlist &operator=(Doublelinkedlist cpy){   //assignment operation
        std::swap(cpy.head, head);
        std::swap(cpy.tail, tail);
        return *this;
    }
    
    bool empty(){
        return head==nullptr;
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
            throw std::runtime_error("empty list");
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
            throw std::runtime_error("empty list");
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
    
    
    ~Doublelinkedlist(){
        clear();
    }
    
    //Add a remove method that takes a Node * as an argument. The method needs to remove the element, and change head or tail (or both) pointers accordingly, if it is necessary to do so.
    void remove(Node *n){
        if(n==head){
            pop_front();
        }
        if(n==tail){
            pop_back();
        }
        n->prev->next= n->next;
        n->next->prev =n->prev;
    }
    
    //Add an insert_before method, that takes an integer value and a Node * as arguments. The method needs to insert a new Node with the given value before the Node, whose pointer given as an argument. If the pointer is a nullptr, insert it at the back of the double-linked list.
    void insert_before(Node *n, int v){
        if(n==nullptr){
            push_back(v);
        }
        if(n==head){
            push_front(v);
        }
        Node *new_node = new Node(v);
        new_node->next =n;
        new_node->prev= n->prev;
        n->prev->next=new_node;
        n->prev=new_node;
    }
    
    Node *find(Node *from, Node *up_to, int value) //iteration
    {
        if(from!=nullptr){
            while(from!=up_to){
                if(from->value==value){
                    break;
                }
                from=from->next;
            }
        }
        return from;
    }
    
    Node *find(int value){
        return find(head, nullptr, value);
    }
    
    //sets the value of all elements between the two pointers to value provided as the third argument.
    void fill(Node *from, Node *up_to, int value){
        if(from!=nullptr){ // if(from==nullptr){from=head}
            while(from!=up_to){
                from->value=value;
                from=from->next;
                
            }
        }
    }
    
    //that works like std::fill_n: set the values of n elements starting at from to v.
    void fill_n(Node *from, int n, int v){
        if(from!=nullptr){
            while(n--){
                from->value=v;
                from=from->next;
                
            }
        }
    }
    
    //Implement an iota method, that works like std::iota.
    void iota(Node *from, Node *up_to, int n){
        if(from==nullptr){
            from=head;
        }
        while(from!=nullptr){
            from->value= n++;
            from= from->next;
        }
    }
    
    //Implement a reverse method, that reverses the list (so a list 1->2->3 should become 3->2->1)
    void reverse(Node *head, Node *tail){  //miip i dont understand this
        Node *n=head;
        while(head!=nullptr){
            Node *next=n->next;
            head->next=n->prev;
            n->prev=next;
            n=next;
        }
        std::swap(head,tail);
    }
    
    //Implement an insert_sorted method. Assume that the collection is sorted in the ascending order (if it is not, we do not guarantee that the method will work properly). First, find the correct spot for a number (similar to find, but find first Node that You encounter that has a value larger than the number we wish to insert). Secondly, insert a new Node before the found Node.
    void insert_sorted(int x)
    {
        Node *n=head;
        while(n !=nullptr)
        {
            if(n->value > x)
            {
                insert_before(n,x);
                break;
            }
            n=n->next;
        }
    }
};

int main() {
    Doublelinkedlist d;
    d.push_front(2);
    std::cout << d.front() << " ";
    d.push_back(4);
    std::cout<< d.back() << " \n";
    d.push_back(8);
    std::cout<< d.back() << " ";
    d.push_front(6);
    std::cout << d.front() << " \n";
    d.push_back(10);
    std::cout<< d.back() << " ";
    d.push_front(12);
    std::cout << d.front() << " \n";
    d.pop_front();
    std::cout << d.front() << " ";
    d.pop_back();
    std::cout<< d.back() << " ";
    
    puts("");
    

    return 0;
}
