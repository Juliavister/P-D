//
//  main.cpp
//  P&D: EXAM 08.06.22
//
//  Created by Julia Vister on 08/06/2022.
//

#include <iostream>
#include <stdexcept>
#include <stack>

struct nm {
    int n;
    int m;
};
class Stack{
    int elements;
    int capacity;
    nm  *mem;

public:
    Stack():
    capacity(10),
    mem(new nm[capacity]),
    elements(0)
    {}
    
    bool empty(){
        return elements==0;
    }
    
    void push(int x, int y){  //push the pair n,m on the stack
        if(capacity==elements)
        {
            nm *tmp = new nm[capacity *2];
            for(int i=0;i<capacity;i++)
            {
                tmp[i]=mem[i];
            }
            delete [] mem;
            mem = tmp;
            capacity *= 2;
        }
        nm a;
        a.n=x;
        a.m=y;
        mem[elements] = a;
        elements ++;
    }
    
    nm top(){  //returns topmost pair
        if(empty())
        {
            throw std::runtime_error("Cannot return value from empty stack!");
        }
        return mem[elements -1];
    }
    
    void pop(){  //removes pair
        if(empty())
        {
            throw std::runtime_error("Cannot remove value from empty stack!");
        }
        elements--;
    }
    
    ~Stack() {
        delete[]mem;
    }
    
    int fun(int n, int m)
    {
     int sum=0;
        push(n, m);
        while(!empty()){
            nm T = top();
            pop();
            int x=T.n;
            int y=T.m;
            if(x==0 || y==0)
            {
                sum=sum+1;
            }
            else{
            push(x-1, y);
            push(x, y-1);
            }
        }
        return sum;
    }
    
    Stack &operator=(Stack cpy){
        capacity=cpy.capacity;
        elements=cpy.elements;
        std::swap(mem, cpy.mem);
        return *this;
    }
    
    Stack(const Stack& original):
    capacity(original.capacity),
    elements(original.elements),
    mem(new nm[capacity])
    {
        for(int i=0;i<elements;i++){
            mem[i]=original.mem[i];
        }
    }
};


int main() {
    Stack S;
    Stack T;
    std::cout << "Test: it runs!";
    std::cout << S.fun(0,0) << std::endl;
    std::cout << T.fun(1,1) << std::endl;
    std::cout << T.fun(3,4) << std::endl;
    std::cout << T.fun(2,6) << std::endl;
    std::cout << S.fun(12,14) << std::endl;
    return 0;
}
