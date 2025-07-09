class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        int events=startTime.size();

        freeTime.push_back(startTime[0]);

        for(int i=0;i<events-1;i++)
        freeTime.push_back(startTime[i+1]-endTime[i]);

        freeTime.push_back(eventTime-endTime[events-1]);

        // k shifts => k+1 free times will add

        int n=events+1,l=0,r=0,sum=0,maxSum=0;

        while(r<n)
        {
            sum+=freeTime[r]; // (acquire)

            // while condn of probm is false, i.e window has more than k+1 elements,
            // keep shrinking it
            if(r-l+1 > k+1)
            {
                sum-=freeTime[l]; // (release)
                l++; // shrink the window (release)
            }

            // now cond of probm is satisfied, i.e. window has <=k+1 elements
            // so update the res
            maxSum=max(maxSum,sum);
            r++; // expand the window (acquire)
        }

        return maxSum;
    }
};