#include<iostream>
using namespace std;
int sqrt(int n){
    int l=0,u=n;
    int ans;
    while(l<=u){
        int mid = l+((u-l)/2);
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid<n){
            ans = mid;
            l=mid+1;
        }
        else{
            u=mid-1;
        }
    }
    return ans;
}
double precise_sqrt(int n,int precision){
    double ans = sqrt(n);
    double factor=1;
    for(int i=0;i<precision;i++){
        factor/=10;
        while(((ans+factor)*(ans+factor))<n){
            ans+=factor;
        }
    }
    return ans;
}
int main(){
    int n;cin>>n;
    int p;cin>>p;
    cout<<sqrt(n)<<endl;
    cout<<precise_sqrt(n,p)<<endl;
}