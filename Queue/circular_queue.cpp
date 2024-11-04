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
    int SIZE;

public:
    Queue(){
        head=NULL;
        tail=NULL;
        SIZE=0;
    }

    bool empty(){
        return head==NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->Next=head;
            SIZE++;
            return;
        }
        tail->Next = newNode;
        tail = newNode;
        tail->Next=head;
        SIZE++;
    }

    void pop(){
        if(empty()){
            cout<<"Queue is empty nothing to delete\n";
            return;
        }
        if(head==tail){
            Node* deleteNode = head;
            head=tail=NULL;
            delete deleteNode;
            SIZE--;
            return;
        }
        Node* deleteNode = head;
        head = deleteNode->Next;
        delete deleteNode;
        tail->Next=head;
        SIZE--;
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
        return SIZE;
    }

    void display(){
        if(empty()){
            cout<<"Queue is empty\n";
            return;
        }
        Node* temp = head;
        do{
            cout<<temp->data<<" ";
            temp=temp->Next;
        }
        while(temp!=head);
        cout<<endl;
    }

    void clear(){
        if(head!=NULL){
            int n = size();
            for(int i=0; i<n; i++){
                pop();
            }
        }
    }


};

int main(){

    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.clear();
    q.display();
    cout<<q.size()<<endl;


    return 0;
}