class Solution {
public:
    long long int Time(vector<int>&piles,int mid){
        long long int ans=0;
        for(int i=0;i<piles.size();++i){
            if(piles[i]%mid==0)ans+=(piles[i]/mid);
            else ans+=((piles[i]/mid)+1);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int max_value=0;
        for(int i=0;i<piles.size();++i){
            if(max_value<piles[i])max_value=piles[i];
        }
        int low=1,high=max_value;
        long long int ans=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long int t_time=Time(piles,mid);
            if(t_time>h)low=mid+1;
            else{
                if(ans>mid)ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};
