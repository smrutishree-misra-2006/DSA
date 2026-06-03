class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {
            int nge = -1;

            for(int j = 0; j < nums2.size(); j++) {
                if(nums2[j] == nums1[i]) {

                    for(int k = j + 1; k < nums2.size(); k++) {
                        if(nums2[k] > nums1[i]) {
                            nge = nums2[k];
                            break;
                        }
                    }

                    break;
                }
            }

            ans.push_back(nge);
        }

        return ans;
    }
};