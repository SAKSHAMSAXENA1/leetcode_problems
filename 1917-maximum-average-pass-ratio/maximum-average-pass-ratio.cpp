class Solution {
public:
double calcGain(int n,int d)
{
    return (n+1.0)/(d+1.0)-(n*1.0)/d;
}
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> pq; // {gain,{num,den}}
        double total=0.0;

        for(auto it:classes)
            pq.push({calcGain(it[0],it[1]),{it[0],it[1]}});

        while(extraStudents--)
        {
            auto it=pq.top();
            pq.pop();

            int newNum=it.second.first+1,newDen=it.second.second+1;
            pq.push({calcGain(newNum,newDen),{newNum,newDen}});
        }

        while(!pq.empty())
        {
            total+=pq.top().second.first*1.0/pq.top().second.second;
            pq.pop();
        }

        return total/classes.size();
    }
};