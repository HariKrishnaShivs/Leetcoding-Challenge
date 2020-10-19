#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(vector<int> A,vector<int> B)
    {
        int val=A[0],f=1,s=0,n=A.size();
        for(int i=1;i<n;i++)
        {
            if((A[i]==val)&&(B[i]==val))
                continue;
            else if(A[i]==val)
            {
                f++;
            }
            else if(B[i]==val)
            {
                s++;
            }
            else
                return -1;
        }
        return min(f,s);
    }
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if((A.size()!=B.size())||(A.size()==0))
            return 0;
        int x=func(A,B);
        int y=func(B,A);
       if(x==-1)
        return y;
        if(y==-1)
            return x;
        return min(x,y);
    }
};