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
}*head,*tmp,*p;


Node* Node::createNode(int d){
   Node* np = new Node();
   np->data = d;
   np->next = NULL;
   return np;
}

void Node::buildList(Node* np){
    Node* t = new Node();
    if(head == NULL){
        head = np;
        np->next = head;
    }
    else{
        t = head;
        while(t->next != head){
            t = t->next;
        }
        t->next = np;
        np->next = head;
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
        t = head;
        while(t->next != head){
            t = t->next;
        }
        t->next = newNode;
        newNode->next = head;
        head = newNode;
        return ;
    }
    np = find(np,pos);

    if(np->next == head){
        np->next = newNode;
        newNode->next = head;
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
    Node* tmp = new Node();

    if(head == NULL)
        cout<<"underflow";

    if(pos == 1){
        t=head;
        tmp = head;
        while(tmp->next != head){
            tmp = tmp->next;
        }
        head = head->next;
        tmp->next = head;
        delete t;

        return ;
    }

    np = find(np,pos);

    if(np->next->next == NULL){
        t=np->next;
        delete t;
        np->next = head;
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
    np=head->next;
    while(true){
        t=np;
        if(np->next == head){
            delete t;
            delete head;
            return;
        }
        np=np->next;
        delete t;
    }
}

void Node::printList(Node* np){
    while(true){
        cout<<" "<<np->data<<"->";
        if(np->next == head){
            return;
        }
        np = np->next;
    }
}

int main(){
    head = NULL;
    int data,nd,pos1,pos2;
    char ch = 'y';
    Node n;

    while(ch == 'y' || ch == 'Y'){
        cout<<"\nEnter data for new node: ";
        cin>>data;
        p = n.createNode(data);
        n.buildList(p);
        n.printList(head);
        cout<<"\nDo u want to add new element(y/n): ";
        cin>>ch;
    }
    ch = 'y';
    while(ch == 'y' || ch == 'Y'){
        cout<<"\nEnter Value and position of new node: ";
        cin>>nd>>pos1;
        p = n.createNode(nd);
        n.insert(head,p,pos1);
        n.printList(head);
        cout<<"\nDo u want to insert an element(y/n): ";
        cin>>ch;
    }
    ch = 'y';
    while(ch == 'y' || ch == 'Y'){
        cout<<"\nEnter positon of node to remove: ";
        cin>>pos2;
        n.remove(head,pos2);
        n.printList(head);
        cout<<"\nDo u want to remove an element(y/n): ";
        cin>>ch;
    }
    //cout<<"\n list empty";
   /*n.makeEmpty(head);
    n.printList(head);*/
    return 0;
}
