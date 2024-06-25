#include<iostream>
using namespace std;
//Used when a^b exceeds even long long
long long mod_exp(long long a,long long b,long long M){
    a%=M;
    long long r=1;
    while(b>0){
        if(b&1){
            r=(r*a)%M;
        }
        else{
            a=(a*a)%M;
        }
        b/=2;
    }
    return r;
}
int main(){
    long long a=20;
    long long b=4;
    long long M=1e9+7;
    long long result=mod_exp(a,b,M);
    cout<<result<<endl;
}
