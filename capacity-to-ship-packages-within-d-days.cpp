class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
     int low = *max_element(weights.begin(),weights.end());
     int high = accumulate(weights.begin(), weights.end(), 0); 
     int sum,d; 
     while (high >= low)
     {
        int mid =low + (high-low)/2;
        sum =0,d=1;
        for (auto w : weights)
        {
            if ((sum+w) > mid) d++,sum=0;
            sum += w;
        }
     if(d<=days) high = mid-1;
     else low = mid+1;

     }
     return low;
    }
};