class Solution {
public:
bool canPerform(int &mid,vector<int> &tasks,vector<int> &workers,int pillsLeft,int &strength)
{
    multiset<int> w(workers.end()-mid,workers.end());

    for(int i=mid-1;i>=0;i--)
    {
        auto curStrongestWorker=--w.end();

        if(*curStrongestWorker>=tasks[i])
        {
            w.erase(curStrongestWorker);
        }
        else if(pillsLeft)
        {
            int minReqStrength=tasks[i]-strength;

            auto weakestWorkerWhoCanPerformThisTask=w.lower_bound(minReqStrength); 
            if(weakestWorkerWhoCanPerformThisTask==w.end()) return false;

            pillsLeft--;
            w.erase(weakestWorkerWhoCanPerformThisTask);
        }
        else // even strongest worker cannot perform this task, no pills left to boost strength
        return false;
    }

    return true;
}
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int l=0,n=tasks.size(),m=workers.size(),h=min(n,m),res=0;

        while(l<=h)
        {
            int mid=(l+h)>>1;

            if(canPerform(mid,tasks,workers,pills,strength))
            {
                res=mid;
                l=mid+1;
            }
            else h=mid-1;
        }

        return res;
    }
};