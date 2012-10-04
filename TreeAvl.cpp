#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class BTree{
    private:
        int data;
        BTree* left;
        BTree* right;

    public:
        BTree *root;
        int height;
        BTree* createNode(int data);
        BTree* getRoot();
        void preOrder(BTree *np);
        void inOrder(BTree* np);
        void buildTree();
        void Insert(int key,BTree *x,BTree *y);
        int setHeight(BTree *node);
        int maxHeight(int a, int b);
        int getHeight(BTree *node);
        int balanceValue(BTree *node);
        void Balance(BTree *node);
        void LeftRotate(BTree *x);
        void RightRotate(BTree *x);
};

void BTree::LeftRotate(BTree *x){
    BTree *y = x->right;
    BTree *xl = x->left;
    BTree *yl = y->left;

    int tmp = x->data;
    x->data = y->data;
    y->data = tmp;

    x->right = x->right->right;
    x->left = y;
    y->left = xl;
    y->right = yl;

    y->height = setHeight(y);
    if(x->right != NULL)
        x->right->height = setHeight(x->right);
    x->height = setHeight(x);

}

void BTree::RightRotate(BTree *x){
    BTree *y = x->left;
    BTree *xr = x->right;
    BTree *yr = y->right;

    int tmp = x->data;
    x->data = y->data;
    y->data = tmp;

    x->left = x->left->left;
    x->right = y;
    y->right = xr;
    y->left = yr;

    y->height = setHeight(y);
    if(x->left != NULL)
        x->left->height = setHeight(x->left);
    x->height = setHeight(x);

}

BTree* BTree::getRoot(){
    return root;
}

BTree* BTree::createNode(int d){
    BTree* np = new BTree();
    np->left = NULL;
    np->right = NULL;
    np->data = d;
    np->height = 1;
}


void BTree::preOrder(BTree *np){
    if(np != NULL){
        cout<<np->data<<" ";
        preOrder(np->left);
        preOrder(np->right);
    }
}

void BTree::inOrder(BTree* np){
    if(np == NULL)
        return ;
    else{
        inOrder(np->left);
        cout<<np->data<<" ";
        inOrder(np->right);
    }
}

int BTree::maxHeight(int a, int b)
{
    return (a > b)? a : b;
}

int BTree::setHeight(BTree *node){
    int ht;
    if(node == NULL)
        return 0;
    else{
        if(node->left == NULL && node->right != NULL)
            return (maxHeight(0, node->right->height)+1);
        if(node->left != NULL && node->right == NULL)
            return (maxHeight(node->left->height,0)+1);
        if(node->left!=NULL && node->right!=NULL)
            return (maxHeight(node->left->height,node->right->height)+1);
        if(node->left == NULL && node->right == NULL)
            return 1;
    }
}

int BTree::getHeight(BTree *node){
    return (maxHeight(node->left->height, node->right->height) + 1);
}

int BTree::balanceValue(BTree *node){
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right != NULL)
        return (0 - node->right->height);
    if(node->left != NULL && node->right == NULL)
        return (node->left->height - 0);
    if(node->left != NULL && node->right!=NULL)
        return (node->left->height - node->right->height);
    return 0;
}

void BTree::Balance(BTree *node){
    int bv = balanceValue(node);
    if( abs(bv) > 1){
        if(bv > 0){
            if( balanceValue(node->left) > 0 ){
                RightRotate(node);
                //cout<<"run\n";
            }
            else{
                LeftRotate(node->left);
                RightRotate(node);
                //cout<<"run\n";
            }
        }
        else if(bv < 0){
            if( balanceValue(node->right) < 0 ){
                LeftRotate(node);
                //cout<<"run\n";
            }
            else{
                RightRotate(node->right);
                LeftRotate(node);
                //cout<<"run\n";
            }
        }
    }
}


void BTree::Insert(int key,BTree *x,BTree *y){

    if(x == NULL){
        if(key < y->data){
            y->left = createNode(key);
        }
        else{
            y->right = createNode(key);
        }
    }
    else if(key < x->data){
        y=x;
        x=x->left;
        Insert(key,x,y);
        y->height = setHeight(y);
        /*cout<<y->height<<endl;
        cout<<balanceValue(y)<<endl;*/
        Balance(y);
    }
    else if(key > x->data){
        y=x;
        x=x->right;
        Insert(key,x,y);
        y->height = setHeight(y);
        /*cout<<"\n"<<y->height;
        cout<<balanceValue(y)<<endl;*/
        Balance(y);
    }
}


void BTree::buildTree(){
    char ch;
    int d,d1;
    cout<<"enter root value: ";
    cin>>d1;
    root = createNode(d1);
    cout<<"enter value to insert : ";
    cin>>d;
    while(true){
        if(d == -999)
            break;
        Insert(d,root,NULL);
        cout<<"Preorder: ";
        preOrder(root);
        cout<<"\nInorder: ";
        inOrder(root);
        cout<<"\nenter value to insert";
        cin>>d;
    }
}

int main(){
    BTree b;
    b.buildTree();
    return 0;
}


