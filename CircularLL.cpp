#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node{
public:    
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    } 
};

void print(Node* &tail){
    Node* temp=tail;
    if(tail==NULL){
        cout<<"empty list"<<endl;
        return;
        }
    
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail !=temp);
    cout<<endl;
}

void insertNode(Node* &tail, int element, int d){
    if(tail==NULL){
        Node* newNode = new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
      Node* curr=tail;
      while(curr->data!=element){
          curr=curr->next;
      }  
      Node* temp= new Node(d);
      temp->next=curr->next;
      curr->next=temp;
    }
}

void deletion(Node* &tail, int element){

    if(tail==NULL){
        cout<<"empty list"<<endl;
        return;
        }
    else{
    Node* prev = tail;
    Node* curr=prev->next;
    while(curr->data!=element){
          prev=curr;
          curr=curr->next;
      } 
      prev->next=curr->next;
      //list=1 element
      if(curr=prev){
          tail=NULL;
      }

      // list>=2 elements
      else if(tail==curr){
          tail=prev;
      }
      curr->next=NULL;
    }
}

int main(){
    Node* tail=NULL;
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 8);
    print(tail);

    insertNode(tail, 5, 13);
    print(tail);

    deletion(tail, 5);
    print(tail);

    deletion(tail, 3);
    print(tail);

    deletion(tail, 13);
    print(tail);
    return 0;
}