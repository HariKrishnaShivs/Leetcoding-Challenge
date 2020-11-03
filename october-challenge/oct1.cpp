#include<bits/stdc++.h>
using namespace std;
class RecentCounter {
public:
    deque<int> q;
    int count;
    RecentCounter() {
         count=0;
    }
    
    int ping(int t) {
        while((!q.empty())&&(q.front()<t-3000))
            q.pop_front();
        q.push_back(t);
        count=q.size();
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
