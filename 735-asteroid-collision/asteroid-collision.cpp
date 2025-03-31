class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> res;
        for(auto it:asteroids)
        {
            if(it>0) // asteroid is moving towards right
            st.push(it);
            else // it<0 -> asteroid is moving towards left
            {
                while(!st.empty() && st.top()>0 && st.top()<abs(it))
                {
                    st.pop();
                }

                if(st.empty() || st.top()<0)
                st.push(it);
                else if(st.top()>0 && st.top()==abs(it))
                st.pop();
            }
        }

        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};