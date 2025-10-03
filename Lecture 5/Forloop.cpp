#include<iostream>
using namespace std;
int main(){
    int n,b;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << i <<endl;
    }
    int a = 1;
    for(;;)
    {
        if (a<=n)
        {
            cout<<a<<endl;
        }
        else
        {
            break;
        }
        a++;
    }
}