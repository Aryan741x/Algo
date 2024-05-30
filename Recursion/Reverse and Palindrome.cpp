#include<iostream>
#include<vector>
using namespace std;
void revers(vector<int>&v,int i){
    if(i==v.size()/2)return;
    v[i]=v[i]^v[v.size()-1-i];
    v[v.size()-1-i]=v[i]^v[v.size()-1-i];
    v[i]=v[i]^v[v.size()-1-i];
    revers(v,i+1);
}
bool palindrome(vector<int>&v,int i){
    if(i==v.size()/2)return true;
    if(v[i]!=v[v.size()-1-i])return false;
    return palindrome(v,i+1);
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;++i){
        cin>>vec[i];
    }
    revers(vec,0);
    for(int i=0;i<n;++i){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    if(palindrome(vec,0)){
        cout<<"The Given Array is a Palindrome"<<endl;
    }
    else{
        cout<<"The Given Array is not a Palindrome"<<endl;
    }
}
