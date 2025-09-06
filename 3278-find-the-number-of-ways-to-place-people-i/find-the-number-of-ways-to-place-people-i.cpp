class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int cnt=0,n=points.size();

        for(int i=0;i<n;i++)
        {
            int x1=points[i][0],y1=points[i][1]; // point A
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;

                int x2=points[j][0],y2=points[j][1]; // point B

                if(x1<=x2 && y2<=y1) // A and B form a rectangle
                {
                    bool pointInsideRectangle=false;

                    for(int k=0;k<n;k++)
                    {
                        if(k==i || k==j) continue;

                        int x3=points[k][0],y3=points[k][1]; // point C

                        if(x1<=x3 && x3<=x2 && y2<=y3 && y3<=y1) // pt C lies inside rectangle
                        {
                            pointInsideRectangle=true;
                            break;
                        }
                    }

                    if(!pointInsideRectangle)
                    cnt++;
                }
            }
        }

    return cnt;
    }
};