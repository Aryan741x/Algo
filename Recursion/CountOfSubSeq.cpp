#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int Sub(int n,vector<int>vec,int i,int sum,int k){
    if(sum>k)return 0;
    if(i==n){
        if(sum==k){
            return 1;
        }
        return 0;
    }
    int l=Sub(n,vec,i+1,sum,k);
    int r=Sub(n,vec,i+1,sum+vec[i],k);
    return l+r;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>vec(n);
    for(int i=0;i<n;++i){
        cin>>vec[i];
    }
    cout<<Sub(n,vec,0,0,k)<<endl;
}
