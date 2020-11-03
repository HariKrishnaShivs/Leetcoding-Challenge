#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        int n=s.length();
        vector<string> v;
        if(n<=10)
            return v;
        string temp="";
        for(int i=0;i<10;i++)
        {
            temp+=s[i];
        }
        mp.insert({temp,1});
        for(int i=10;i<n;i++)
        {
            temp.erase(temp.begin());
            temp+=s[i];
            mp[temp]++;
        }
        for(auto it:mp)
        {
            if(it.second>1)
             v.push_back(it.first);
        }
        return v;
    }
};