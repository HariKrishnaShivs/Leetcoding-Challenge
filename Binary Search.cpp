#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            //cout<<mid<<" "<<nums[mid]<<endl;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                right=mid-1;
            else
                left=mid+1;
            //cout<<left<<" "<<right<<endl;
        }
        return -1;
    }
};