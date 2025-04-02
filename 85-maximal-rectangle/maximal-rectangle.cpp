class Solution {
public:
int largestRectangleInHistogram(vector<int> &heights)
{
    // stack is monotonic STRICTLY increasing
    stack<int> st;
    int n=heights.size(),maxArea=0;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && heights[st.top()]>=heights[i])
        {
            int element=st.top(); 
            st.pop();

            int nse=i,pse=(!st.empty())? st.top():-1;
            // area of rectangle with popped element as its height
            // area=heights[element]*(nse-pse-1)

            maxArea=max(maxArea,heights[element]*(nse-pse-1));
        }

        st.push(i);
    }

    // process rectangles with height as remaining elements of stack
    while(!st.empty())
    {
        int element=st.top();
        st.pop();

        int nse=n,pse=(!st.empty())? st.top():-1;
        maxArea=max(maxArea,heights[element]*(nse-pse-1));
    }

    return maxArea;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<int> heights;
        for(auto it:matrix[0])
        heights.push_back(it-'0');

        int res=largestRectangleInHistogram(heights);

        for(int i=1;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                heights[j]=(matrix[i][j]=='1')? heights[j]+1:0;
            }
            res=max(res,largestRectangleInHistogram(heights));
        }

        return res;

    }
};