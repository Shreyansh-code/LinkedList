#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data=data;
        this -> next = NULL;
    }
};
// insert at Head
void insertAtHead(Node* &head, int d){
    //first create a new node
    Node* temp = new Node(d);
    //insert at head
    temp -> next = head;
    head = temp;
}

//insert at tail
void insertAttail(Node* &tail, int d){
    //first create a new node
    Node* temp = new Node(d);
    //insert at head
    tail-> next = temp;
    tail = temp;
}

//insert at given pos
void insertAtPos(Node* &head,Node* &tail,int pos, int d){
    if(pos==1){
       insertAtHead(head, d);
       return; 
    }
    Node* temp = head;
    int count =1;

    while(count<pos-1){
        count ++;
        temp=temp->next;
    }
    if(temp->next==NULL){
       insertAttail(tail, d);
       return;
    }

    Node* newNodeinsert = new Node(d);
    newNodeinsert-> next=temp-> next;
    temp->next=newNodeinsert;
}


//deletion at given pos
void deleteion(Node* &head, int pos){
    Node* temp = head;
    Node* curr = head;
    int count =1;
    if(pos==1){
        head=temp->next;
        return;
    }
    else{
    while(count<pos){
        count ++;
        temp=curr;
        curr=curr->next;
    }

    if(curr->next==NULL){
        temp->next=curr->next;
        return;
    }
    temp->next=curr->next;
    curr->next=NULL;
    }
}


void printLL(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<< temp-> data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}




int main(){
// create first node
Node* node1 = new Node(10);

//head pointed to node1
Node* head = node1;

// tail pointed to node1
Node* tail = node1;

//insert at head a new node
insertAttail(tail, 20);
insertAttail(tail, 15);
insertAtPos(head,tail, 4, 34);
//print
printLL(head);
cout<<endl;
deleteion(head,1);
printLL(head);



    return 0;
}
