class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long massL = mass;

        for(auto &it: asteroids)
        {
            if((long)it <= massL)
            {
                massL += it;
            }
            else return false;
        }

        return true;
    }
};