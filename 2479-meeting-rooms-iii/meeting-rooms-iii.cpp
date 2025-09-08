class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<>> usedRooms; // {time,room}
        priority_queue<int,vector<int>,greater<>> freeRooms;
        vector<int> freq(n,0);
        int maxFreq=0,mostUsedRoom=-1;

        for(int i=0;i<n;i++) 
        freeRooms.push(i);

        sort(meetings.begin(),meetings.end());

        for(auto it: meetings)
        {
            int start=it[0],end=it[1];

            // pop all those rooms which become availabe before or at start of this meeting
            while(!usedRooms.empty() && usedRooms.top().first <= (long)start)
            {
                freeRooms.push(usedRooms.top().second);
                usedRooms.pop();
            }

            // if some room is already available when this meeting starts
            // meeting starts and ends at its original start time and end time, respectively
            if(!freeRooms.empty())
            {
                int roomToUse=freeRooms.top();
                freeRooms.pop();

                usedRooms.push({end,roomToUse});
                freq[roomToUse]++;
            }
            else // no room available at the original start time of meeting => delay
            {
                auto [availabilityTime,roomToUse]=usedRooms.top();
                usedRooms.pop();

                int meetingDuration=end-start;
                usedRooms.push({availabilityTime+meetingDuration,roomToUse});
                freq[roomToUse]++;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(freq[i] > maxFreq)
            {
                maxFreq=freq[i];
                mostUsedRoom=i;
            }
        }

        return mostUsedRoom;
    }
};