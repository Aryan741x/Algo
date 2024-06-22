#include<iostream>
#include<vector>
using namespace std;
void Merge(vector<int>&vec,int start,int mid,int end){
    int leftSize=mid-start+1;
    int rightSize=end-mid;
    vector<int>l(leftSize);
    vector<int>r(rightSize);
    int k=start;
    for(int i=0;i<leftSize;++i){
        l[i]=vec[k];
        k++;
    }
    for(int i=0;i<rightSize;++i){
        r[i]=vec[k];
        k++;
    }
    int left=0;
    int right=0;
    k=start;
    while(left<leftSize&&right<rightSize){
        if(l[left]<r[right]){
            vec[k]=l[left];
            left++;
        }
        else{
            vec[k]=r[right];
            right++;
        }
        k++;
    }
    while(left<leftSize){
        vec[k]=l[left];
        left++;
        k++;
    }
    while(right<rightSize){
        vec[k]=r[right];
        right++;
        k++;
    }
}
void MergeSort(vector<int>&vec,int start,int end){
    if(start>=end)return;
    int mid=start+(end-start)/2;
    MergeSort(vec,start,mid);
    MergeSort(vec,mid+1,end);
    Merge(vec,start,mid,end);
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;++i){
        cin>>vec[i];
    }
    MergeSort(vec,0,n-1);
    for(int i=0;i<n;++i){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
