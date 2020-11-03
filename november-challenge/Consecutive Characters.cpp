#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPower(string s) {
        int ml=0,l=1;
        if(s.length()==0)
            return 0;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==s[i-1])
            {
                l++;
            }
            else
            {
                ml=max(ml,l);
                l=1;
            }
        }
        ml=max(ml,l);
        return ml;
    }
};