class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<vector<int>> intervals(26, vector<int>(2,-1));
        vector<int> res;

        for(int i=0;i<n;i++)
        {
            if(intervals[s[i]-'a'][0]==-1) // this char is seen for the first time
            {
                // update its both first and last indices
                intervals[s[i]-'a'][0]=intervals[s[i]-'a'][1]=i;
            }
            else // this char has been seen previously, so update its last index only
            intervals[s[i]-'a'][1]=i;
        }

        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        int i=0;
        for(;i<26;i++)
        {
            if(intervals[i][0]!=-1) break;
        }
        merged.push_back(intervals[i]);
        i++;

        for(;i<26;i++)
        {
            if(intervals[i][0]<merged.back()[1]) // merging intervals
            merged.back()[1]=max(merged.back()[1],intervals[i][1]);
            else
            merged.push_back(intervals[i]);
        }

        for(auto it:merged)
        {
            res.push_back(it[1]-it[0]+1);
        }

        return res;
    }
};