class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> indegree;
        unordered_set<string> endProduct(recipes.begin(),recipes.end());
        unordered_set<string> rawMaterials(supplies.begin(),supplies.end());
        vector<string> res;
        queue<string> q; 
        int n=recipes.size();

        for(int i=0;i<n;i++)
        {
            for(auto ingredient:ingredients[i])
            {
                if(indegree.find(ingredient)==indegree.end())
                indegree[ingredient]=0;

                adj[ingredient].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        for(auto it:indegree)
        {
            if(it.second==0 && rawMaterials.find(it.first)!=rawMaterials.end()) 
            q.push(it.first);
        }
        
        while(!q.empty())
        {
            auto item=q.front();
            q.pop();

            if(endProduct.find(item)!=endProduct.end())
            res.push_back(item);

            for(auto neighbour:adj[item])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                q.push(neighbour);
            }
        }

        return res;
    }
};