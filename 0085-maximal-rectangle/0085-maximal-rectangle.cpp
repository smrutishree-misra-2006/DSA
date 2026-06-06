class Solution {
public:
    // Largest Rectangle in Histogram
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxi = max(maxi, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            maxi = max(maxi, heights[element] * (nse - pse - 1));
        }

        return maxi;
    }

    // Maximal Rectangle
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; i++) {

            // Build histogram for current row
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            // Find largest rectangle in current histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};