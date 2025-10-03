#include<iostream>
using namespace std;
int power(int a,int b){
    int ans = 1;
    for(int i=1;i<=b;i++){
        ans = ans*a;
    }
    return ans;
}
int main(){
    int n,m;
    cin >> n >> m;
    cout << power(n,m);
}
//Time Complexity O(b)