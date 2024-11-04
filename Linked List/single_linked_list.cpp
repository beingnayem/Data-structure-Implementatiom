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

class LinkedList{
private:
    Node* head;

public:
    LinkedList(){
        head=NULL;
    }

    void insertAthead(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        newNode->Next=head;
        head=newNode;
    }

    void insertAttail(int val){
        Node* newNode = new Node(val);

        if(head==NULL){
            head=newNode;
            return;
        }
        Node* temp = head;
        while(temp->Next!=NULL){
            temp=temp->Next;
        }
        temp->Next=newNode;
    }

    void insertBypos(int pos, int val){
        if(pos<0){
            cout<<"Position Underflow\n";
            return;
        }
        if(pos==0){
            Node* newNode = new Node(val);
            insertAthead(val);
            return;
        }
        int cnt=0;
        Node* temp = head;
        while(temp && cnt<pos-1){
            temp = temp->Next;
            cnt++;
        }
        if( temp==NULL){
            cout<<"Position Overflow\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->Next = temp->Next;
        temp->Next=newNode;
    }

    void insertByvalue(int target, int val){
        if(head->data==target){
            Node* newNode = new Node(val);
            insertAthead(val);
            return;
        }
        Node* temp=head;
        while(temp->Next && temp->Next->data!=target){
            temp=temp->Next;
        }
        if(temp->Next==NULL){
            cout<<"In linked list no value matched with "<<target<<endl;
            return;
        }
        Node* newNode = new Node(val);
        newNode->Next = temp->Next;
        temp->Next = newNode;
    }

    void deleteAthead(){
        if(head==NULL){
            cout<<"List is empty nothing to delete\n";
            return;
        }
        else if(head->Next==NULL){
            Node* nodeDelete = head;
            head=NULL;
            delete nodeDelete;
            return;
        }
        else{
            Node* nodeDelete=head;
            head = nodeDelete->Next;
            delete nodeDelete;
            return;
        }
    }

    void deleteAttail(){
        if(head==NULL){
            cout<<"List is empty nothing to delete\n";
            return;
        }
        else if(head->Next==NULL){
            Node* nodeDelete = head;
            head=NULL;
            delete nodeDelete;
            return;
        }
        else{
            Node* temp = head;
            while(temp->Next->Next!=NULL){
                temp=temp->Next;
            }
            Node* nodeDelete = temp->Next;
            temp->Next=NULL;
            delete nodeDelete;
        }
    }

    void deleteBypos(int pos){
        if(pos<0){
            cout<<"Position Underflow\n";
            return;
        }
        if(head==NULL){
            cout<<"List is empty Nothing to delete\n";
        }
        if(pos==0){
            deleteAthead();
            return;
        }
        int cnt=0;
        Node* temp=head;
        while(temp->Next!=NULL && cnt<pos-1){
            temp = temp->Next;
            cnt++;
        }
        if(temp->Next==NULL && pos-1>=cnt){
            cout<<"Position Overflow\n";
            return;
        }
        else if(temp->Next->Next==NULL && cnt==pos-1){
            deleteAttail();
            return;
        }
        else{
            Node* deleteNode = temp->Next;
            temp->Next = deleteNode->Next;
            delete deleteNode;
        }
    }

    void deleteByvalue(int val){
        if(head==NULL){
            cout<<"List is empty nothing to delete\n";
        }
        if(head->data==val){
            deleteAthead();
            return;
        }
        Node* temp=head;
        while(temp->Next->Next!=NULL && temp->Next->data!=val){
            temp = temp->Next;
        }
        if(temp->Next->Next==NULL && temp->Next->data==val){
            deleteAttail();
            return;
        }
        if(temp->Next->Next==NULL && temp->Next->data!=val){
            cout<<"No value matched with "<<val<<endl;
        }
        Node* deleteNode = temp->Next;
        temp->Next = deleteNode->Next;
        delete deleteNode;
    }

    void reverseList(){
        Node* pre = NULL;
        Node* cur = head;
        Node* next = NULL;
        while(cur){
            next = cur->Next;
            cur->Next=pre;
            pre = cur;
            cur=next;
        }
        head=pre;
    }

    int size(){
        if(head==NULL)  return 0;
        Node* temp=head;
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
                deleteAthead();
            }
        }
    }

    void vectorToLinkedlist(vector<int> v){
        for(int i=0; i<v.size(); i++){
            insertAttail(v[i]);
        }
    }

    void display(){
        if(head==NULL){
            cout<<"List is Empty\n";
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

    // vector<int> v;

    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);


    LinkedList list;

    list.insertAttail(5);
    list.insertAttail(4);
    list.insertAttail(3);
    list.insertAttail(2);
    list.insertAttail(1);
    // list.insertBypos(3, 9);
    // list.insertByvalue(1, 11);
    // list.deleteAthead();
    // list.deleteAttail();
    // list.deleteBypos(-1);
    // list.deleteByvalue(9);
    // list.reverseList();
    // cout<<list.size()<<endl;
    // list.clear();
    // cout<<list.size()<<endl;
    // list.vectorToLinkedlist(v);
    list.display();

    return 0;
}