class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<pair<int,int>> intervals(26, {-1,-1});
        vector<int> res;

        for(int i=0;i<n;i++)
        {
            if(intervals[s[i]-'a'].first==-1) // this char is seen for the first time
            {
                // update its both first and last indices
                intervals[s[i]-'a'].first=intervals[s[i]-'a'].second=i;
            }
            else // this char has been seen previously, so update its last index only
            intervals[s[i]-'a'].second=i;
        }

        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> merged;
        int i=0;
        for(;i<26;i++)
        {
            if(intervals[i].first!=-1) break;
        }
        merged.push_back(intervals[i]);
        i++;

        for(;i<26;i++)
        {
            if(intervals[i].first<merged.back().second) // merging intervals
            merged.back().second=max(merged.back().second,intervals[i].second);
            else
            merged.push_back(intervals[i]);
        }

        for(auto it:merged)
        {
            res.push_back(it.second-it.first+1);
        }

        return res;
    }
};