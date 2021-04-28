//给你一个二叉树的根结点，请你找出出现次数最多的子树元素和。一个结点的「子树元素和」定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
//
// 你需要返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
//
//
//
// 示例 1：
//输入:
//
//   5
// /  \
//2   -3
//
//
// 返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。
//
// 示例 2：
//输入：
//
//   5
// /  \
//2   -5
//
//
// 返回 [2]，只有 2 出现两次，-5 只出现 1 次。
//
//
//
// 提示： 假设任意子树元素和均可以用 32 位有符号整数表示。
// Related Topics 树 哈希表
// 👍 108 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
    map<int,int> m;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        preFindFrequentTreeSum(root);
        int max = 0;
        vector<int> ans;
        for(auto it = m.begin();it != m.end();it++) {
            if (it -> second > max) max = it -> second;
        }
        for(auto it = m.begin();it != m.end();it++) {
            if (it -> second == max) ans.push_back(it -> first);
        }
        return ans;
    }
    void preFindFrequentTreeSum(TreeNode* root) {
        if (root == NULL) return;
        int sum = getSumOfTree(root);
        m[sum]++;
        preFindFrequentTreeSum(root -> left);
        preFindFrequentTreeSum(root -> right);
    }
    int getSumOfTree(TreeNode* root) {
        if (root == NULL) return 0;
        return root -> val + getSumOfTree(root -> left) + getSumOfTree(root -> right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
