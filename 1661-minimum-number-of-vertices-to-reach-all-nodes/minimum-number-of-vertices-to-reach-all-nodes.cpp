class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indegree(n,false);
        vector<int> res;
        for(auto it:edges)
            indegree[it[1]]=true;

        for(int i=0;i<n;i++)
            if(indegree[i]==false) res.push_back(i);

        return res;
    }
};