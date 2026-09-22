class Solution {
public:
    int start = 0;
    int maxLen = 1;

    void expand(string &s, int left, int right) {
        int n = s.size();

        while (left >= 0 && right < n && s[left] == s[right]) {
            int len = right - left + 1;

            if (len > maxLen) {
                maxLen = len;
                start = left;
            }

            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();

        if (n <= 1) return s;

        for (int i = 0; i < n; i++) {
            expand(s, i, i);      
            expand(s, i, i + 1);   
        }

        return s.substr(start, maxLen);
    }
};