class Solution {
public:
    int dist(string word1, string word2, int n1, int n2, vector<vector<int>>& table) {
        if (n1 == 0)
            return n2;
        if (n2 == 0)
            return n1;
        if (table[n1][n2] != -1)
            return table[n1][n2];
        int result;
        if (word1[n1 - 1] == word2[n2 - 1])
            result = dist(word1, word2, n1 - 1, n2 - 1, table);
        else
            result = min(min(dist(word1, word2, n1 - 1, n2, table) + 1,
                dist(word1, word2, n1, n2 - 1, table) + 1),
                dist(word1, word2, n1 - 1, n2 - 1, table) + 1);
        table[n1][n2] = result;
        return result;
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> table(n1 + 1, vector<int>(n2 + 1, -1));
        int res = dist(word1, word2, n1, n2, table);
        return res;
        /*int table[n1 + 1][n2 + 1];
        for(int i = 0; i <= n1; i++)
        {
            for(int j = 0; j <= n2; j++)
            {
                if(i == 0)
                    table[i][j] = j;
                else if(j == 0)
                    table[i][j] = i;
                else if(word1[i - 1] == word2[j - 1])
                    table[i][j] = table[i-1][j-1];
                else
                    table[i][j] = 1 + min(min(table[i-1][j], table[i][j-1]), table[i-1][j-1]);
            }
        }
        return table[n1][n2];*/
    }

};