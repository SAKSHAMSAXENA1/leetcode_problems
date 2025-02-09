class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int m=elements.size();
        unordered_map<int,int> elementsToIndex;
        vector<int> res;

        for(int i=m-1;i>=0;i--)
        elementsToIndex[elements[i]]=i;

        for(auto it: groups)
        {
            int mini=INT_MAX;
            for(int j=1;j*j<=it;j++)
            {
                if(it%j==0)
                {
                    if(elementsToIndex.find(j)!=elementsToIndex.end())
                    mini=min(mini,elementsToIndex[j]);

                    if(j!=it/j && elementsToIndex.find(it/j)!=elementsToIndex.end())
                    mini=min(mini,elementsToIndex[it/j]);
                }
            }

            if(mini==INT_MAX) res.push_back(-1);
            else res.push_back(mini);
        }

        return res;
    }
};