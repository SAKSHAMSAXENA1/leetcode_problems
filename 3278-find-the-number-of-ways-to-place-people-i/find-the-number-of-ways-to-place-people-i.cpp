class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size(),cnt=0;

        auto comp=[&](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]) // same x-coord
            return a[1] > b[1]; // higher y-coord first

            // x-coord diff
            return a[0] < b[0]; // lower x-coord first
        };

        sort(points.begin(),points.end(),comp);

        for(int i=0;i<n;i++)
        {
            int x1=points[i][0],y1=points[i][1]; // point A

            int yMax=INT_MIN;
            for(int j=i+1;j<n;j++)
            {
                int x2=points[j][0],y2=points[j][1]; // point B

                // x1<=x2 automatically since points is sorted

                if(y2 <= y1) // A & B form a rectangle
                {
                    if(yMax < y2) // no pt inside rectangle made by A and B
                    {
                        cnt++;
                        yMax=y2;
                    }
                }
            }
        }

        return cnt;
    }
};