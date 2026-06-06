class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi = 0;
        int element;
        int nse;
        int pse;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                element = st.top(); // we are storing the index
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, heights[element] * (nse - pse - 1));
            }
            st.push(i);//this is the element we get afterwards
         
        }
           while (!st.empty()) {
                element = st.top(); // we are storing the index
                st.pop();
                nse = heights.size() ;
                pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, heights[element] * (nse - pse - 1));
            }
        return maxi;
    }
};