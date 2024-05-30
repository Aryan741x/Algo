#include <bits/stdc++.h>
using namespace std;
long long mode(string s,int i,int j){
    int a=0;
    int b=0;
    for(int k=i;k<=j;++k){
        if(s[k]=='0'){
            a++;
        }
        else{
            b++;
        }
    }
    if(a==b){
        return 2;
    }
    else{
        return 1;
    }
}
int comb(string s){
    int n=s.size();
    int k=0;
    for(int i=0;i<n-1;++i){
        if(s[i]!=s[i+1]){
            k++;
        }
    }
    return k;
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int k=comb(s);
        cout<<mode(s,0,n-1)+((n*(n+1))/2)+((k*(k-1))/2)<<endl;
    }
}
