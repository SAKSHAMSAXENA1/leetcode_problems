class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // stack is monotonic STRICTLY increasing
        stack<int> st; // index

        int n=heights.size(),maxArea=0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                int element=st.top();
                st.pop();
                int nse=i,pse=(!st.empty())? st.top():-1;
                // area of rectangle with popped element as its height
                // area=heigths[element]*(nse-pse-1)

                maxArea=max(maxArea,heights[element]*(nse-pse-1));
            }

            st.push(i);
        }

        // iteration is over, but still there are some elements in stack
        // now consider the rectangles with those elements as their height, one by one
        while(!st.empty())
        {
            int element=st.top();
            st.pop();
            int nse=n,pse=(!st.empty())? st.top():-1;
            
            // area of rectangle with popped element as its height
            // area=heights[element]*(nse-pse-1)

            maxArea=max(maxArea,heights[element]*(nse-pse-1));
        }

        return maxArea;
    }
};