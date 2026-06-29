class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        if (numerator == 0)
            return "0";

        string ans;

        // Handle negative sign
        if ((numerator < 0) ^ (denominator < 0))
            ans += "-";

        // Use long long to avoid overflow
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // Integer part
        ans += to_string(num / den);

        long long rem = num % den;

        if (rem == 0)
            return ans;

        ans += ".";

        // remainder -> position in answer string
        unordered_map<long long, int> mp;

        while (rem != 0) {

            // If remainder repeats, recurring decimal starts
            if (mp.count(rem)) {
                ans.insert(mp[rem], "(");
                ans += ")";
                break;
            }

            // Store the current position of this remainder
            mp[rem] = ans.size();

            rem *= 10;

            ans += to_string(rem / den);

            rem %= den;
        }

        return ans;
    }
};