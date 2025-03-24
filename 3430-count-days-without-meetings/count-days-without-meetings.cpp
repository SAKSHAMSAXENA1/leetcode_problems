class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // merge intervals
        sort(meetings.begin(),meetings.end());
        vector<vector<int>> merged;
        merged.push_back(meetings[0]);
        int i=1,n=meetings.size(),meetingDays=0;

        for(;i<n;i++)
        {
            if(meetings[i][0]<=merged.back()[1])
            merged.back()[1]=max(merged.back()[1],meetings[i][1]);
            else merged.push_back(meetings[i]);
        }

        for(auto it:merged)
        {
            meetingDays+=it[1]-it[0]+1;
        }

        return days-meetingDays;
    }
};