class Solution {
public:
    static bool func(vector<int> a,vector<int> b)
    {
        if(a[0]==b[0])
             return a[1]>=b[1];
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),func);
        priority_queue<int> q;
        int val=0,n=intervals.size();
        for(int i=0;i<n;i++)
        {
            if(i==0)
                q.push(intervals[i][1]);
            else
            {
                if(intervals[i][1]<=q.top())
                {
                    val++;
                }
                q.push(intervals[i][1]);
            }
        }
        //cout<<val<<endl;
        return (n-val);
    }
};
