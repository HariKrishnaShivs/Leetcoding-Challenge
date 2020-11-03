class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> q;
        int n=asteroids.size();
        vector<int> negatives;
        for(int i=0;i<n;i++)
        {
            if(asteroids[i]>0)
            {
                q.push_back(i);
            }
            else
            {
                while((!q.empty())&&(asteroids[q.back()]<abs(asteroids[i])))
                {
                    q.pop_back();
                }
                if(q.empty())
                {
                    negatives.push_back(i);
                }
                else if(asteroids[q.back()]==abs(asteroids[i]))
                    q.pop_back();
            }
          }
        while(!q.empty())
        {
              negatives.push_back(q.front());
              q.pop_front();
        }
        sort(negatives.begin(),negatives.end());
        for(int i=0;i<negatives.size();i++)
        {
            //cout<<negatives[i]<<endl;
            negatives[i]=asteroids[negatives[i]];
        }
        return negatives;
    }
};