class Solution {
public:
    int countLargestGroup(int n) {
        int cnt=0,maxSum=0;
        unordered_map<int,int> u;

        for(int i=1;i<=n;i++)
        {
            int sum=0,temp=i;
            
            while(temp)
            {
                sum+=temp%10;
                temp/=10;
            }

            u[sum]++;  
        }

        for(auto it:u)
        {
            if(maxSum < it.second)
            {
                cnt=1;
                maxSum=it.second;
            }
            else if(it.second==maxSum) 
                cnt++;
        }

        return cnt;
    }
};