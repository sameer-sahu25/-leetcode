class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9LL * num) return "";

        int q = sum / 9;
        int r = sum % 9;

        string ans;

        ans.append(q, '9');

        if (r > 0)
            ans.push_back('0' + r);

        int used = q + (r > 0);

        ans.append(num - used, '0');

        return ans;
    }
};