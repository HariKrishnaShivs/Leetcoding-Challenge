#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        int n=A.length(),m=B.length();
        if(n!=m)
         return false;
        int l=0;
        char f=' ',s=' ';
        for(int i=0;i<n;i++)
        {
            if(A[i]!=B[i])
            {
                if(f==' ')
                {
                    f=A[i];
                    s=B[i];
                }
                else
                {
                    if(!((f==B[i])&&(s==A[i])))
                    {
                       return false;
                    }
                }
                l++;
            }
        }
        if(l==2)
            return true;
        if(l==0)
        {
            set<char> s;
            for(int i=0;i<n;i++)
            {
                if(s.find(A[i])!=s.end())
                    return true;
                s.insert(A[i]);
            }
        }
          return false;
    }
};