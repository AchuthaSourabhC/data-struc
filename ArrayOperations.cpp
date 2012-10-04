#include<iostream>

using namespace std;


int main(){

    int a[20],i,n=0,k,p,p2,k3,p3;

    for(i=0;i<20;i++){
        a[i] == NULL;
    }
    //Reading input
    cout<<"enter size of input \n";
    cin>>n;
    cout<<"enter elements\n";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    //inserting elements
    cout<<"Enter the element to insert\n";
    cin>>k;
    cout<<"enter position\n";
    cin>>p;

    for(i=n-1;i>=p;i--){
        a[i+1]=a[i];
    }
    a[p] = k;
    n=n+1;
    for(i=0;i<n;i++){
        cout<<a[i];
    }

    //deleting elements
    cout<<"enter position of element to delete\n";
    cin>>p2;
    a[p2] = 0;

    //updating
    cout<<"Enter the element to update\n";
    cin>>k3;
    cout<<"enter position\n";
    cin>>p3;

    a[p3]=k3;

    for(i=0;i<n;i++){
        cout<<a[i];
    }

    //finding
    int k4,c=0;
    cout<<"Enter the element to find\n";
    cin>>k4;
    for(i=0;i<n;i++){
        if(a[i] == k4){
            c=1;
            break;
        }
    }
    if(c ==1)
        cout<<"Found at index: "<<i;
    else
        cout<<"not found";


    return 0;
}
