pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int low=0,high=n-1;
    pair<int,int>p;
    sort(arr,arr+n);
    //Code For Floor
    int ans1=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]<=x){
            ans1=arr[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    low=0;
    high=n-1;
    //Code for Ceil
    int ans2=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=x){
            ans2=arr[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    p=make_pair(ans1,ans2);
    return p;
}
