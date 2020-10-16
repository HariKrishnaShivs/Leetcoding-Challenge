class Solution {
public:
    bool bs(vector<int> v,int target)
    {
        int low=0,high=v.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(v[mid]==target)
                return true;
            else if(v[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0)
         return false;
        int m=matrix[0].size();
         if(m==0)
             return false;
        for(int i=0;i<n;i++)
        {
            if((matrix[i][0]<=target)&&(matrix[i][m-1]>=target))
            {
               return bs(matrix[i],target);
            }
        }
        return false;
    }
};