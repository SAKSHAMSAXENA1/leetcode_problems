class Solution {
public:
    int findLucky(vector<int>& arr) {
        int res=-1;
        unordered_map<int,int> u;

        for(auto it:arr)
        u[it]++;

        for(auto it:u)
        {
            if(it.first==it.second && it.first>res) res=it.first;
        }

        return res;
    }
};