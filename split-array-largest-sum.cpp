class Solution {
public:

    int SubArr_count(vector<int>& nums,int mid){
        int sum=0,count = 1;
        for(auto num:nums){
        if ((sum + num)>mid)
        {
            count++;
            sum = 0;
        }
        sum+=num;
        }
        return count;
    } 

    int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0),count;
    while(high>low)
    {
        int mid = low +(high-low)/2;
        
       count = SubArr_count(nums,mid);

       if (count>k) low = mid+1;
       else high = mid;

    }
    return low;
    }
};