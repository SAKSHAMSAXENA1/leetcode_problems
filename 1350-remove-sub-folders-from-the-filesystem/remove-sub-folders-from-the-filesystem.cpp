class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> folders;
        sort(folder.begin(),folder.end());

        for(auto it:folder)
        {
            string path="";
            bool isSubfolder=false;

            for(auto c:it)
            {
                if(c=='/' && path.size()!=0)
                {
                    if(folders.find(path)!=folders.end())
                    {
                        isSubfolder=true;
                        break;
                    }
                }

                path.push_back(c);
            }

            if(isSubfolder==false) folders.insert(path);
        }

        vector<string> res;

        for(auto it:folders) res.push_back(it);

        return res;
    }
};