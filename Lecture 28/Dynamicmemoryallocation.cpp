#include<iostream>
using namespace std;
int main(){
    new char;
    char *ptr = new char;
    *ptr  = 'a';
    cout<<*ptr<<endl;
    int *ptr2 = new int[5];
    *ptr2 = 10;
    ptr2[1]=20;
    *(ptr2+2)=30;
    cout<<ptr2[0]<<" "<<ptr2[1]<<" "<<ptr2[2]<<endl;
    int n;
    cin>>n;
    int *ptr3 = new int[n];
    for(int i=0;i<n;i++){
        cin>>ptr3[i];
    }
    for(int i=0;i<n;i++){
        cout<<ptr3[i]<<" ";
    }
    delete []ptr2;
    delete []ptr3;
}