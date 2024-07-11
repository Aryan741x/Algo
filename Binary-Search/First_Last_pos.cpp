vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>res;
    int ans=-1;
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(ans>=0 && ans<nums.size() && nums[ans]!=target)ans=-1;
    res.push_back(ans);
    ans=-1;
    low=0,high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]<=target){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(ans>=0 && ans<nums.size() && nums[ans]!=target)ans=-1;
    res.push_back(ans);
    return res;
}
