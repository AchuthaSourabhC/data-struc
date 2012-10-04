#include<iostream>
using namespace std;

class Node{
    private:
    int data;
    Node* next;

    public:
    Node* createNode(int d);
    void buildList(Node* np);
    Node* find(Node* np ,int pos);
    void insert(Node* np,Node* newNode,int pos);
    void remove(Node* np,int pos);
    void makeEmpty(Node* np);
    void printList(Node* np);
}*first,*last,*tmp,*p;


Node* Node::createNode(int d){
   Node* np = new Node();
   np->data = d;
   np->next = NULL;
   return np;
}

void Node::buildList(Node* np){

    if(first == NULL)
        first=last=np;

    else{
        last->next = np;
        last = np;
    }
}

Node* Node::find(Node* np,int pos){
    for(int i = 0;i<pos;i++ ){
        if(i == pos-2){
            return np;
        }
        np=np->next;
    }
}

void Node::insert(Node* np,Node* newNode,int pos){
    Node* t= new Node();

    if(pos == 1){
        t=first;
        first=newNode;
        newNode->next = t;
        return ;
    }
    np = find(np,pos);

    if(np->next == NULL){
        last->next = newNode;
        last = newNode;
        return ;
    }
    else{
        t = np->next;
        np->next = newNode;
        newNode->next = t;
        return ;
    }
}

void Node::remove(Node* np,int pos){
    Node* t = new Node();

    if(first == NULL)
        cout<<"underflow";

    if(pos == 1){
        t=first;
        first=first->next;
        delete t;
        return ;
    }

    np = find(np,pos);

    if(np->next->next == NULL){
        delete np->next;
        np->next = NULL;
        return ;
    }
    else{
        t = np->next->next;
        delete np->next;
        np->next=t;
        return ;
    }
}

void Node::makeEmpty(Node* np){
    Node* t = new Node();
    while(np != NULL){
        t=np;
        np=np->next;
        first = np;
        delete t;
    }
}

void Node::printList(Node* np){
    while(np != NULL){
        cout<<" "<<np->data<<"->";
        np = np->next;
    }
}

int main(){

    int data,nd,pos1,pos2;
    char ch = 'y';
    Node n;

    while(ch == 'y' || ch == 'Y'){
        cout<<"\nEnter data for new node: ";
        cin>>data;
        p = n.createNode(data);
        n.buildList(p);
        cout<<"\nDo u want to add new element(y/n): ";
        cin>>ch;
    }
    n.printList(first);
    cout<<"\nEnter Value and position of new node: ";
    cin>>nd>>pos1;
    p = n.createNode(nd);
    n.insert(first,p,pos1);
    n.printList(first);
    cout<<"\nEnter positon of node to remove: ";
    cin>>pos2;
    n.remove(first,pos2);
    n.printList(first);
    cout<<"\n list empty";
    n.makeEmpty(first);
    n.printList(first);
    return 0;
}

