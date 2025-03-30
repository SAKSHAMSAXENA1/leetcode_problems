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
        int i=0;
        for(;i<26;i++)
        {
            if(intervals[i].first!=-1) break;
        }

        pair<int,int> last=intervals[i];
        res.push_back(intervals[i].second-intervals[i].first+1);
        i++;

        for(;i<26;i++)
        {
            if(intervals[i].first<last.second) // merging intervals
            {
                last.second=max(last.second,intervals[i].second);
                res.back()=last.second-last.first+1;
            }
            else
            {
                last=intervals[i];
                res.push_back(last.second-last.first+1);
            }
        }

        return res;
    }
};