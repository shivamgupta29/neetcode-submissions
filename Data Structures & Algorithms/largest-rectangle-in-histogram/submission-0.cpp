class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = heights[st.top()]; 
                st.pop();
                int pse = !st.empty() ? st.top() : -1;
                int nse = i;
                maxArea = max(maxArea, element*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int e = heights[st.top()];
            st.pop();
            int nse = heights.size();
            int pse = !st.empty() ? st.top(): -1;
            maxArea = max(maxArea, e*(nse-pse-1));
        }
        return maxArea;
    }
};
