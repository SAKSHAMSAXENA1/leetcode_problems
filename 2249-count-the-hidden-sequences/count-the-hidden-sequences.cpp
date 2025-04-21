#define ll long long
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll offset=0,maxNetOffset=LLONG_MIN,minNetOffset=LLONG_MAX;
        ll maxStartingVal,minStartingVal;

        for(auto it:differences)
        {
            offset+=it;
            maxNetOffset=max(maxNetOffset,offset);
            minNetOffset=min(minNetOffset,offset);
        }

        maxStartingVal=min(upper-maxNetOffset,(ll)upper);
        minStartingVal=max(lower-minNetOffset,(ll)lower);

        if(maxStartingVal<minStartingVal) return 0;

        return maxStartingVal-minStartingVal+1;
    }
};