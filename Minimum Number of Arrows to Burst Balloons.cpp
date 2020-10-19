#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size();
        if(points.size()==0)
             return 0;
        int val=1;
        int fval=points[0][1];
        for(int i=1;i<n;i++)
        {
            if(points[i][0]>fval)
            {
                val++;
                fval=points[i][1];
            }
            else
            {
                if(points[i][1]<fval)
                    fval=points[i][1];
            }
        }
        return val;
    }
};