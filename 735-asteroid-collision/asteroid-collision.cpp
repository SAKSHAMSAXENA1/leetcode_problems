class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for(auto it:asteroids)
        {
            if(it>0) res.push_back(it); // asteroid moving towards right
            else // asteroid moving towards left
            {
                while(res.size() && res.back()>0 && res.back()<abs(it))
                {
                    res.pop_back();
                }

                if(res.size()==0 || res.back()<0)
                {
                    res.push_back(it);
                }
                else if(res.size() && res.back()==abs(it))
                {
                    res.pop_back();
                }
            }
        }

        return res;
    }
};