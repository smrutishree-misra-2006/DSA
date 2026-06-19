class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        stringstream ss1(s1), ss2(s2);
        string word;
        while (ss1 >> word) {
            mp[word]++;
        }
        while (ss2 >> word) {
            mp[word]++;
        }
        vector<string> ans;
        for (auto &p : mp) {
            if (p.second == 1) {
                ans.push_back(p.first);
            }
        }
        return ans;


    }
};