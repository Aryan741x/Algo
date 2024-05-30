#include<iostream>
using namespace std;
int Fibonacci(int n){
    if(n<=1)return n;
    else{
        int k=Fibonacci(n-1)+Fibonacci(n-2);
        return k;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cout<<Fibonacci(i)<<" ";
    }
}
