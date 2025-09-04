class Solution {
public:
int f(int i,vector<int> &pge,vector<int> &nge,vector<int> &dp)
{
   if(dp[i]!=-1) return dp[i];

   int maxi=0;
   for(int nbr=pge[i];nbr<=nge[i];nbr++)
   {
    if(nbr==i) continue;

    maxi=max(maxi,f(nbr,pge,nge,dp));
   }
   /*if(pge[i] < i)
   prev=f(pge[i],arr,pge,nge);
   
   if(i < nge[i])
   next=f(nge[i],arr,pge,nge));

   return 1+max(prev,next);*/

   return dp[i]=1+maxi;
}
    int maxJumps(vector<int>& arr, int d) {
     int n=arr.size(),maxi=0;
     vector<int> nge(n),pge(n),dp(n,-1);
     stack<int> st;
     for(int i=n-1;i>=0;i--)
     {
        while(!st.empty() && arr[st.top()] < arr[i])
        st.pop();

        nge[i]=min((st.empty()) ?  n-1 : st.top()-1,i+d);

        st.push(i);
     }   

     st=stack<int>();
     for(int i=0;i<n;i++)
     {
        while(!st.empty() && arr[st.top()] < arr[i])
        st.pop();

        pge[i]=max((st.empty()) ?  0 : st.top()+1,i-d);

        st.push(i);
     } 

     for(int i=0;i<n;i++)
     {
        maxi=max(maxi,f(i,pge,nge,dp));
     }
     

     return maxi;
    }
};