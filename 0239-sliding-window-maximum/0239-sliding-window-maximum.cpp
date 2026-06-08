class Solution {
public:
    deque<int> dq;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            // Remove indices outside the window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Start adding results once first window is complete
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};