#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > fans;
    void func(vector<int> candidates,vector<int>& v,int target,int prsum,int ind)
    {
        if(prsum==target)
        {
            fans.push_back(v);
            return;
        }
        if((ind>=candidates.size())||(prsum>target))
        {
            return ;
        }

        if(prsum+candidates[ind]<=target)
        {
            v.push_back(candidates[ind]);
            func(candidates,v,target,prsum+candidates[ind],ind);
            v.pop_back();
        }
                func(candidates,v,target,prsum,ind+1);
        return ;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        int prsum=0,ind=0;
        func(candidates,v,target,prsum,ind);
        return fans;
    }
};
