class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size(),res=INT_MAX;
        vector<vector<bool>> userToLang(m+1,vector<bool>(n+1,false));

        for(int i=0;i<m;i++)
        {
            for(auto it:languages[i])
            userToLang[i+1][it]=true;
        }

        for(int lang=1;lang<=n;lang++)
        {
            vector<bool> teach(m+1,false);
            for(auto it:friendships)
            {
                int u=it[0],v=it[1];
                bool canTalk=false;

                for(int commonLang=1;commonLang<=n;commonLang++)
                {
                    if(userToLang[v][commonLang] && userToLang[u][commonLang])
                    {
                        canTalk=true;
                        break;
                    }
                }

                if(!canTalk)
                {
                    if(userToLang[u][lang]==false)
                    teach[u]=true;

                    if(userToLang[v][lang]==false)
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