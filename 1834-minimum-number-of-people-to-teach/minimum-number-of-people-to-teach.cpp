class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size(),res=INT_MAX;
        vector<unordered_set<int>> userToLang(m+1);

        for(int i=0;i<m;i++)
        {
            for(auto it:languages[i])
            userToLang[i+1].insert(it);
        }

        for(int lang=1;lang<=n;lang++)
        {
            vector<bool> teach(m+1,false);
            for(auto it:friendships)
            {
                int u=it[0],v=it[1];
                bool canTalk=false;

                for(auto commonLang: userToLang[u])
                {
                    if(userToLang[v].find(commonLang)!=userToLang[v].end())
                    {
                        canTalk=true;
                        break;
                    }
                }

                if(!canTalk)
                {
                    if(userToLang[u].find(lang)==userToLang[u].end())
                    teach[u]=true;

                    if(userToLang[v].find(lang)==userToLang[v].end())
                    teach[v]=true;
                }
            }

            int cnt=0;
            for(auto it:teach)
            cnt+=it;

            res=min(res,cnt);
        }

        return res; 
    }
};