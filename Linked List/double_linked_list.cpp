#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* Next;
    Node* prev;

    Node(int val){
        data=val;
        Next=NULL;
        prev=NULL;
    }
};

class DoubleLinkedList{
private:
    Node* head;

public:
    DoubleLinkedList(){
        head=NULL;
    }

    bool empty(){
        return head==NULL;
    }

    void insertAthead(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        newNode->Next = head;
        head->prev = newNode;
        head = newNode;
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
        temp->Next = newNode;
        newNode->prev = temp;
    }

    void insertByPos(int pos, int val){
        if(pos<0){
            cout<<"Position Underflow\n";
            return;
        }
        if(pos==0){
            insertAthead(val);
            return;
        }
        Node* temp = head;
        int cnt=0;
        while(temp && cnt<pos-1){
            temp = temp->Next;
            cnt++;
        }
        if(temp==NULL){
            cout<<"Position Overflow\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->Next = temp->Next;
        newNode->prev = temp;
        temp->Next = newNode;
        if(newNode->Next != NULL) newNode->Next->prev = newNode;
    }

    void insertByvalue(int target, int val){
        if(head->data==target){
            insertAthead(val);
            return;
        }
        Node* temp = head;
        while(temp->Next->Next && target!=temp->Next->data){
            temp = temp->Next;
        }
        if(temp->Next->Next==NULL && target!=temp->Next->data){
            cout<<"No value matched with "<<target<<endl;
            return;
        }
        Node* newNode = new Node(val);
        newNode->Next = temp->Next;
        newNode->prev = temp;
        temp->Next = newNode;
        if(newNode->Next!=NULL) newNode->Next->prev = newNode;
    }

    void deleteAthead(){
        if(empty()){
            cout<<"List is empty nothing to delete\n";
            return;
        }
        if(head->Next==NULL){
            Node* deleteNode = head;
            head = NULL;
            delete deleteNode;
            return;
        }
        Node* deleteNode = head;
        head->Next->prev = NULL;
        head = deleteNode->Next;
        delete deleteNode;
    }

    void deleteAttail(){
        if(empty()){
            cout<<"List is empty nothing to delete\n";
            return;
        }
        if(head->Next==NULL){
            deleteAthead();
            return;
        }
        Node* temp = head;
        while(temp->Next){
            temp = temp->Next;
        }
        Node* deleteNode = temp;
        deleteNode->prev->Next=NULL;
        delete deleteNode;
    }

    void deleteBypos(int pos){
        if(empty()){
            cout<<"List is empty nothing to delete\n";
            return;
        }
        if(pos<0){
            cout<<"Position Underflow\n";
            return;
        }
        if(pos==0){
            deleteAthead();
            return;
        }
        int cnt=0;
        Node* temp = head;
        while(temp->Next && cnt<pos-1){
            temp = temp->Next;
            cnt++;
        }
        if(temp->Next==NULL && pos-1>cnt){
            cout<<"Position Overflow\n";
            return;
        }

        if(temp->Next->Next==NULL && cnt==pos-1){
            deleteAttail();
            return;
        }

        Node* deleteNode = temp->Next;
        temp->Next = deleteNode->Next;
        deleteNode->Next->prev = temp;
        delete deleteNode;
    }

    void deleteByvalue(int target){
        if(empty()){
            cout<<"List is empty nothing to delete\n";
            return;
        }
        if(head->data==target){
            deleteAthead();
            return;
        }
        Node* temp = head;
        while(temp->Next->Next && temp->Next->data!=target){
            temp = temp->Next;
        }
        if(temp->Next->Next==NULL && temp->Next->data==target){
            deleteAttail();
            return;
        }
        if(temp->Next->Next==NULL && temp->Next->data!=target){
            cout<<"No value matched with "<<target<<endl;
            return;
        }
        Node* deleteNode = temp->Next;
        temp->Next = deleteNode->Next;
        deleteNode->Next->prev = temp;
        delete deleteNode;
    }

    void reverseList(){
        if(!empty()){
            Node* cur = head;
            Node* temp = NULL;
            while(cur->Next!=NULL){
                temp = cur->Next;
                cur->Next = cur->prev;
                cur->prev = temp;
                cur = cur->prev;
            }
            if(temp){
                head = temp->prev;
            }  
        }
    }

    int size(){
        if(empty()) return 0;
        int cnt=0;
        Node* temp = head;
        while(temp){
            temp = temp->Next;
            cnt++;
        }
        return cnt;
    }

    void clear(){
        if(head!=NULL){
            int n = size();
            for(int i=0; i<n; i++){
                deleteAttail();
            }
        }
    }

    void vectorTOdoubleLinkedlist(vector<int> v){
        for(int i=0; i<v.size(); i++){
            insertAttail(v[i]);
        }
    }

    void displayForward(){
        if(empty()){
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

    void displayBackward(){
        if(empty()){
            cout<<"List is Empty\n";
            return;
        }
        Node* temp=head;
        while(temp->Next!=NULL){
            temp=temp->Next;
        }
        while(temp){
            cout<<temp->data;
            if(temp->prev!=NULL)    cout<<" --> ";
            temp=temp->prev;
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

    DoubleLinkedList dll;

    dll.insertAttail(10);
    dll.insertAttail(20);
    dll.insertAttail(30);
    dll.insertAttail(40);
    dll.insertAttail(50);
    // dll.insertByPos(5, 9);
    // dll.insertByvalue(2, 9);
    // dll.deleteAthead();
    // dll.deleteAttail();
    // dll.deleteBypos(3);
    // dll.deleteByvalue(30);

    // cout<<dll.size()<<endl;
    // dll.clear();
    // cout<<dll.size()<<endl;
    // dll.vectorTOdoubleLinkedlist(v);
    dll.reverseList();
    dll.displayForward();
    // dll.displayBackward();

    return 0;
}