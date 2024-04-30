#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int min(int a,int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}
//Recursive code
/*int f(vector<int>&dp,int index,int k){
    if(index==0){
        return 0;
    }
    int jump=1e9;
    for(int i=1;i<=k;++i){
        if(index>=i){
            int j=f(dp,index-i,k)+abs(dp[index]-dp[index-i]);
            jump=min(jump,j);
        }
    }
    return jump;
}
*/
//Dp code (Memoization)
int f(vector<int>&dp,vector<int>&val,int index,int k){
    if(index==0)return 0;
    int jump=1e9;
    for(int i=1;i<=k;++i){
        if(index>=i){
            int j;
            if(dp[index-i]!=-1){
                j=dp[index-i]+abs(val[index]-val[index-i]);
            }
            else{
                j=f(dp,val,index-i,k)+abs(val[index]-val[index-i]);
            }
            jump=min(jump,j);
        }
    }
    dp[index]=jump;
    return jump;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>val(n);
    vector<int>dp(n,-1);
    for(int i=0;i<n;++i){
        cin>>val[i];
    }
    cout<<f(dp,val,n-1,k)<<endl;
}
