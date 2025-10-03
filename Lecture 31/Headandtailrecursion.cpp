#include<iostream>
using namespace std;
void tail_recursive_print(int n){  //prints n to 1
    if(n==0){
        return ;
    }
    cout<<n<<endl;
    tail_recursive_print(n-1);
}
void head_recursive_print(int n){ //prints 1 to n
    if(n==0){
        return ;
    }
    head_recursive_print(n-1);
    cout<<n<<endl;
}
int main(){
    int n;
    cin>>n;
    tail_recursive_print(n);
    head_recursive_print(n);
}