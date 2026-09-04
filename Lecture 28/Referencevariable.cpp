#include<iostream>
using namespace std;
void update(int &n){
    n++;
}
int &update2(int n){
    int &ans = n;
    n++;
    ans++;
    return ans;
}
int *update3(int n){
    int *p = &n;
    (*p)++;
    n++;
    return p;
}
int main(){
    int i=5;
    int &j = i;
    cout<<i<<" "<<j<<endl;
    cout<<&i<<" "<<&j<<endl;
    update(i);
    cout<<i<<endl;
    cout<<update2(i)<<endl;
    cout<<i<<endl;
    cout<<&i<<endl;
    cout<<update3(i)<<" "<<*update3(i)<<endl;
    cout<<i<<endl;
}