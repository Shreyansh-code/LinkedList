#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    
};

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLen(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
}

int insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head-> prev = temp;
    head=temp;
}

int insertAtTail(Node*tail, int d){
    Node* temp = new Node(d);
    temp->prev = tail;
    tail->next = temp;
    tail=temp;
}

void insertAtpos(Node* &head,Node* &tail, int pos, int d){
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
       insertAtTail(tail, d);
       return;
       }

    Node* newNodeinsert = new Node(d);
    newNodeinsert->next=temp->next;
    temp->next->prev=newNodeinsert;
    temp-> next=newNodeinsert;
    newNodeinsert->prev=temp;
    
}

void deleteion(Node* &head, int pos){
    
    if(pos==1){
        Node* temp=head;
        head=temp->next;
        temp->next->prev=NULL;
        temp->next=NULL;
        return;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;
        int count =1;
        while(count<pos){
            count ++;
            prev=curr;
            curr=curr->next;
    }
    
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
    }
}


int main(){
    Node* node1= new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtHead(head, 32);
    print(head);

    insertAtHead(head, 13);
    print(head);

    insertAtTail(tail, 19);
    print(head);

    insertAtpos(head, tail, 3, 76);
    print(head);

    insertAtpos(head, tail, 6, 76);
    print(head);

    insertAtpos(head, tail, 1, 76);
    print(head);

    deleteion(head, 1);
    print(head);

    deleteion(head, 3);
    print(head);

    deleteion(head, 4);
    print(head);
    
    return 0;
}