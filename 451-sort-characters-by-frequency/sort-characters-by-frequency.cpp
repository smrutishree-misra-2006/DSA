class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        for (char ch : s)
            mp[ch]++;

        vector<pair<int, char>> v;

        for (auto it : mp) {
            v.push_back({it.second, it.first});
        }

        sort(v.rbegin(), v.rend());

        string ans = "";

        for (auto it : v) {

            int freq = it.first;
            char ch = it.second;

            while (freq--) {
                ans += ch;
            }
        }

        return ans;
    }
};