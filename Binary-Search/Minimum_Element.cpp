class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int minimum=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[low]){
                minimum=min(minimum,nums[mid]);
                high=mid-1;
            }
            else{
                minimum=min(minimum,nums[low]);
                low=mid+1;
            }
        }
        return minimum;
    }
};
