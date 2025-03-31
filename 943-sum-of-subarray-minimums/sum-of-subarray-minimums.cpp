class Solution {
public:
void findPrevSmallerOrEqualElement(vector<int> &arr,vector<int> &psee,int &n)
{
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i]) 
        {
            st.pop(); // keep removing prev greater elements from stack
        }

        psee[i]=(st.empty())? -1:st.top();
        st.push(i);
    }
}
void findNextSmallerElement(vector<int> &arr,vector<int> &nse,int &n)
{
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop(); // keep removing next greater or equal elements from stack
        }

        nse[i]=(st.empty())? n: st.top();
        st.push(i);
    }
}
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(),mod=(int)(1e9+7),sum=0;
        vector<int> psee(n),nse(n); // psee=prevSmallerOrEqualElement, nse=nextSmallerElement
        findPrevSmallerOrEqualElement(arr,psee,n);
        findNextSmallerElement(arr,nse,n);

        for(int i=0;i<n;i++)
        {
            int left=i-psee[i],right=nse[i]-i;
            int contribution=left*right;
            sum=(sum+((long long)contribution*arr[i])%mod)%mod;
        }

        return sum;
    }
};