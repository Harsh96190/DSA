class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int low = 1;
       int high = *max_element(nums.begin(),nums.end()); 
        int sum,result;
       while (high>=low)
       {
        int mid = low+(high-low)/2;
         sum=0;
         for (auto num:nums)
         {
            sum += (num+mid-1)/mid;
         }
        if(sum<=threshold){
            result = mid;
            high = mid-1;
        }
        else low = mid+1;
       }
       return result;
    }
};