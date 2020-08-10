class Solution {
public:
    int table[][len];
    memset(table, 0, sizeof(table));
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.length();
        int n = text2.length();

        if (m == 0 || n == 0)
            return 0;
        if (text1[m - 1] == text2[n - 1])
            return 1 + longestCommonSubsequence(text1.substr(0, m - 1), text2.substr(0, n - 1));
        else
            return max(longestCommonSubsequence(text1.substr(0, m), text2.substr(0, n - 1)),
                longestCommonSubsequence(text1.substr(0, m - 1), text2.substr(0, n)));

    }
};