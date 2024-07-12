class Solution {
public:
    int result(vector<int>&nums,int low,int high){
        if(low>high)return -1;
        int mid=low+(high-low)/2;
        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])return mid;
        int l=result(nums,mid+1,high);
        if(l!=-1)return l;
        int r=result(nums,low,mid-1);
        if(r!=-1)return r;
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        return result(nums,1,n-2);      
    }
};
