#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *Next;

    Node(int val){
        data=val;
        Next=NULL;
    }
};


class Queue{

private:
    Node* head;
    Node* tail;

public:

    Queue(){
        head=NULL;
        tail=NULL;
    }
    
    bool empty(){
        return head==NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }

        tail->Next = newNode;
        tail = newNode;
    }

    void pop(){
        if(empty()){
            cout<<"Queue is empty nothing to delete\n";
            return;
        }
        Node* deleteNode = head;
        head = deleteNode->Next;
        delete deleteNode;
    }

    int front(){
        if(empty()){
            throw runtime_error("Queue is empty");
        }
        return head->data;
    }

    int back(){
        if(empty()){
            throw runtime_error("Queue is empty");
        }
        return tail->data;
    }

    int size(){
        if(head==NULL){
            return 0;
        }
        Node* temp = head;
        int cnt=0;
        while(temp){
            temp=temp->Next;
            cnt++;
        }
        return cnt;
    }

    void clear(){
        if(head!=NULL){
            int n = size();
            for(int i=0; i<n; i++){
                pop();
            }
        }
    }

    void display(){
        if(empty()){
            cout<<"Queue is empty\n";
            return;
        }
        Node* temp = head;
        while(temp){
            cout<<temp->data;
            if(temp->Next!=NULL)    cout<<" --> ";
            temp=temp->Next;
        }
        cout<<endl;
    }

};


int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    cout<<q.size()<<endl;
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Back: "<<q.back()<<endl;
    cout<<q.empty()<<endl;
    q.clear();
    cout<<q.empty()<<endl;
    q.display();
    return 0;
}