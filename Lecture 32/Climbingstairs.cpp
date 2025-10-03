#include<iostream>
using namespace std;
int climbing_stairs(int n){
    if(n<0){
        return 0;
    }
    else if(n==0){
        return 1;
    }
    else{
        return (climbing_stairs(n-1)+climbing_stairs(n-2));
    }
}
int main(){
    int n;
    cin >>n;
    cout<<climbing_stairs(n)<<endl;
}