class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
     int m = mat.size(),n = mat[0].size();
     int low = 0, high = n-1;
     while (high >= low)
     {
        int mid = low + (high - low)/2;
        int maxRow = 0;
        for (int i = 1;i < m;i++)
        {
            if (mat[maxRow][mid]<mat[i][mid])
            {
                maxRow = i;
            }
        }
        int left = (mid-1)>=0?mat[maxRow][mid-1]:-1;
        int right = (mid+1)<n?mat[maxRow][mid+1]:-1;
        if (mat[maxRow][mid]>left && mat[maxRow][mid]>right) 
        return {maxRow,mid};
        else if (mat[maxRow][mid]<right) low = mid+1;
        else high = mid-1;
     }
     return {-1,-1};
    }
};