#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Partition(vector<int>&vec,int start,int end){
    int i=start-1;
    int pivot=vec[end];
    for(int j=start;j<end;++j){
        if(vec[j]<pivot){
            swap(vec[i+1],vec[j]);
            i++;
        }
    }
    swap(vec[i+1],vec[end]);
    return i+1;
}
void QuickSort(vector<int>&vec,int start,int end){
    if(start>=end)return;
    int pivotPos=Partition(vec,start,end);
    QuickSort(vec,start,pivotPos-1);
    QuickSort(vec,pivotPos+1,end);
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;++i){
        cin>>vec[i];
    }
    QuickSort(vec,0,n-1);
    for(int i=0;i<n;++i){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
