//T.C=log(N)
long long int floorSqrt(long long int x) 
    {
        long long int low=1;
        long long int high=x;
        while(low<=high){
            long long int mid=low+(high-low)/2;
            if(mid*mid>x)high=mid-1;
            else low=mid+1;
        }
        return high;
    }
};

//int square_root = sqrt(number);
