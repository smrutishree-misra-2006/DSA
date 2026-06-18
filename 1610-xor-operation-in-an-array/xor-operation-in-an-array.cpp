class Solution {
public:
    int xorOperation(int n, int start) {
        int nums[n];int xorr = 0;
        for(int i = 0 ;i < n ;i++){
            int ele = start + 2 * i;
            xorr = xorr ^ ele;
        }
        return xorr;
    }
};