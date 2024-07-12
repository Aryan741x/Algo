class Solution {
public:
    int result(vector<int>&nums,int low,int high){
        if(low>high)return -1;
        int mid=low+(high-low)/2;
        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])return mid;
        int l=result(nums,mid+1,high);
        int r=result(nums,low,mid-1);
        if(l==-1&&r==-1)return -1;
        else if(l==-1)return r;
        else return l;
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        return result(nums,1,n-2);      
    }
};
