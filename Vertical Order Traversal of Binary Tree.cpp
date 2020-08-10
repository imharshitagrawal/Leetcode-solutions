/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findMinMaxX(TreeNode* root, int& min, int& max, int hd)
    {
        if (!root)
            return;
        if (hd < min) min = hd;
        else if (hd > max) max = hd;
        findMinMaxX(root->left, min, max, hd - 1);
        findMinMaxX(root->right, min, max, hd + 1);
    }
    void findMinMaxY(TreeNode* root, int& min, int& max, int hd)
    {
        if (!root)
            return;
        if (hd < min) min = hd;
        else if (hd > max) max = hd;
        findMinMaxY(root->left, min, max, hd - 1);
        findMinMaxY(root->right, min, max, hd - 1);
    }
    void givenCord(TreeNode* root, int i, int j, int hd1, int hd2, vector<int>& v)
    {
        if (!root)
            return;
        if (i == hd1 && j == hd2)
            v.push_back(root->val);
        givenCord(root->left, i, j, hd1 - 1, hd2 - 1, v);
        givenCord(root->right, i, j, hd1 + 1, hd2 - 1, v);
    }
    void fillMap(TreeNode* root, int hd1, int hd2, map<int, vector<pair<int, int>>>& mp)
    {
        if (!root)
            return;
        mp[hd1].push_back({ hd2, root->val });
        fillMap(root->left, hd1 - 1, hd2 - 1, mp);
        fillMap(root->right, hd1 + 1, hd2 - 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        /*int min_x = 0, max_x = 0;
        int min_y = 0, max_y = 0;
        findMinMaxX(root, min_x, max_x, 0);
        findMinMaxY(root, min_y, max_y, 0);
        vector<vector<int>> result;
        for(int i = min_x; i <= max_x; i++)
        {
            vector<int> vec;
            for(int j = max_y; j >= min_y; j--)
            {
                vector<int> v;
                givenCord(root, i,j,0, 0, v);
                sort(v.begin(), v.end());
                for(int i = 0; i < v.size(); i++)
                    vec.push_back(v[i]);
            }
            result.push_back(vec);
        }
        return result;*/
        vector<vector<int>> result;
        map<int, vector<pair<int, int>>> mp;
        fillMap(root, 0, 0, mp);
        for (auto itr : mp)
        {
            vector<int> vec;
            sort(itr.second.begin(), itr.second.end(), [&](auto& a, auto& b) {
                if (a.first == b.first)
                    return a.second < b.second;
                return a.first > b.first;
                });
            for (int i = 0; i < itr.second.size(); i++)
                vec.push_back(itr.second[i].second);
            result.push_back(vec);
        }


        return result;
    }

};