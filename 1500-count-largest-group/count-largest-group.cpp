class Solution {
public:
    int countLargestGroup(int n) {
        int cnt=0,maxSize=0;
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

            if(u[sum]>maxSize)
            {
                maxSize=u[sum]; // update maxSize
                cnt=1; // reset cnt to 1
            }
            else if(u[sum]==maxSize)
            cnt++;
        }

        return cnt;
    }
};