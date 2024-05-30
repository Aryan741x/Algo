#include<iostream>
#include<vector>
using namespace std;
void Subsequence(int i,vector<int>v,int n,vector<int>emp){
    if(i>=n){
        for(int i=0;i<emp.size();++i){
            cout<<emp[i]<<" ";
        }
        cout<<endl;
        return;
    }
    emp.push_back(v[i]);
    Subsequence(i+1,v,n,emp);
    emp.pop_back();
    Subsequence(i+1,v,n,emp);
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    vector<int>emp;
    Subsequence(0,v,n,emp);
}
