#include<iostream>
using namespace std;
void increment(int n){
    n++;
   cout<<"n is: "<<n<<endl;;
   return; 
}
int main(){
    int n;
    cin>>n;
    increment(n);
    cout<<"n is "<<n;
}