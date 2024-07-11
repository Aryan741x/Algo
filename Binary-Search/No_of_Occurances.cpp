int count(int nums[], int n, int target) {
    int ans1=-1;
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]>=target){
            ans1=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(ans1>=0 && ans1<n && nums[ans1]!=target)return 0;
    int ans2=-1;
    low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]<=target){
            ans2=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(ans2-ans1+1>n)return 0;
    return ans2-ans1+1;
}
