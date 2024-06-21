#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool Sub(int n,vector<int>vec,queue<int>s,int i,int sum,int k){
    if(i==n){
        if(sum==k){
            while(!s.empty()){
                cout<<s.front()<<" ";
                s.pop();
            }
            cout<<endl;
            return true;
        }
        return false;
    }
    if(Sub(n,vec,s,i+1,sum,k)==true)return true;
    s.push(vec[i]);
    if(Sub(n,vec,s,i+1,sum+vec[i],k)==true)return true;
    return false;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>vec(n);
    for(int i=0;i<n;++i){
        cin>>vec[i];
    }
    queue<int>s;
    bool r=Sub(n,vec,s,0,0,k);
    if(!r){
        cout<<"No Such SubSequence Possible here."<<endl;
    }
    else{
        cout<<"SubSequence Founded."<<endl;
    }
}
