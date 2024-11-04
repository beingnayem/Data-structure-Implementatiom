#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* Next;
    Node(int data){
        this->data = data;
        this->Next = NULL;
    }

};

class Stack{
private:
    Node* Top;
    int SIZE;

public:
    Stack(){
        Top=NULL;
        SIZE=0;
    }
    
    bool empty(){
        return Top==NULL;
    }

    void push(int val){
        Node* temp = new Node(val);
        temp->Next = Top;
        Top = temp;
        SIZE++;
    }

    void pop(){
        if(empty()){
            cout<<"Stack is empty nothing to delete"<<endl;
            return;
        }
        else{
            Node* deleteNode = Top;
            Top = deleteNode->Next;
            delete deleteNode;
            SIZE--;
        }
    }

    int top(){
        if(empty()){
            throw runtime_error("Stack is empty no top value");
        }
        return Top->data;
    }

    int size(){
        return SIZE;
    }

};


int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    cout<<s.size()<<endl;
    return 0;
}