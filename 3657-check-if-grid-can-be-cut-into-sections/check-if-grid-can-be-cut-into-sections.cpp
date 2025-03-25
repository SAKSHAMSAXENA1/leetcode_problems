class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> sortedX,sortedY;
        for(auto it:rectangles)
        {
            sortedX.push_back({it[0],it[2]});
            sortedY.push_back({it[1],it[3]});
        }
        vector<vector<int>> merged;
        int m=rectangles.size(),cutsX=0,cutsY=0;
        auto comp=[&] (pair<int,int> a,pair<int,int> b) {
            if(a.first==b.first) // if both a & b start at same x/y coordinate
            {
                return a.second<b.second; // then a must finish before b in terms of x/y coordinate
            }
            return a.first<b.first; // otherwise a must start before b in terms of x/y coordinate
        };

        /*auto compX=[&] (vector<int> a,vector<int> b) {
            if(a[0]==b[0]) // if both a & b start at same x coordinate
            {
                return a[1]<b[1]; // then a must finish before b in terms of x coordinate
            }
            return a[0]<b[0]; // otherwise a must start before b in terms of x coordinate
        };

        auto compY=[&] (vector<int> a,vector<int> b) {
            if(a[0]==b[0]) // if both a & b start at same y coordinate
            {
                return a[1]<b[1]; // then a must finish before b in terms of y coordinate
            }
            return a[0]<b[0]; // otherwise a must start before b in terms of y coordinate
        };*/

        sort(sortedX.begin(),sortedX.end(),comp);

        pair<int,int> last=sortedX[0];
        for(int i=1;i<m;i++)
        {
            if(sortedX[i].first<last.second)
            last.second=max(last.second,sortedX[i].second);
            else
            {
                cutsX++;
                if(2==cutsX) return true;
                last=sortedX[i];
            }
        }

        sort(sortedY.begin(),sortedY.end(),comp);
        
        last=sortedY[0];
        for(int i=1;i<m;i++)
        {
            if(sortedY[i].first<last.second)
            last.second=max(last.second,sortedY[i].second);
            else
            {
                cutsY++;
                if(2==cutsY) return true;
                last=sortedY[i];
            }
        }

        return false;
    }
};