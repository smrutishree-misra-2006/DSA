class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> freq;

        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }

        int score = 0;
        for (auto it : freq) {
            score += it.first * it.second;
        }

        return score;
    }
};