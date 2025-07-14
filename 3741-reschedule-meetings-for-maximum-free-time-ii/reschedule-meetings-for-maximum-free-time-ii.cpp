class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size(),noOfGaps=n+1,maxi=0; // n=noOfMeetings
        vector<int> gaps;
        gaps.push_back(startTime[0]);

        for(int i=0;i<n-1;i++)
        gaps.push_back(startTime[i+1]-endTime[i]);

        gaps.push_back(eventTime-endTime[n-1]);

        vector<int> largestLeft(noOfGaps),largestRight(noOfGaps);

        for(int i=noOfGaps-2;i>=0;i--)
        largestRight[i]=max(gaps[i+1],largestRight[i+1]);

        for(int i=1;i<noOfGaps;i++)
        largestLeft[i]=max(gaps[i-1],largestLeft[i-1]);

        for(int i=0;i<n;i++)
        {
            int meetingLength=endTime[i]-startTime[i];

            // if any gap on the left or right is big enough to accommodate current meeting
            // G[i-1] G[i] M[i] G[i+1] G[i+2]
            if(max(largestLeft[i],largestRight[i+1])>=meetingLength)
            {
                // out of order shifting of the current meeting
                maxi=max(maxi,gaps[i]+meetingLength+gaps[i+1]);
            }

            // inorder shifting of the current meeting
            maxi=max(maxi,gaps[i]+gaps[i+1]);
        }

        return maxi;

    }
};