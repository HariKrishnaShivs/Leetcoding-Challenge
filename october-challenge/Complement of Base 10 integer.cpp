#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
        int val=0,po=0;
        if(N==0)
             return 1;
        while(N!=0)
        {
            val+=((1-(N%2))*pow(2,po));
            N/=2;
            po++;
        }
        return val;
    }
};