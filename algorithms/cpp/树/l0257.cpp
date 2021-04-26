//给定一个二叉树，返回所有从根节点到叶子节点的路径。
//
// 说明: 叶子节点是指没有子节点的节点。
//
// 示例:
//
// 输入:
//
//   1
// /   \
//2     3
// \
//  5
//
//输出: ["1->2->5", "1->3"]
//
//解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
// Related Topics 树 深度优先搜索
// 👍 486 👎 0


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
    vector<string> strList;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return strList;
        string s;
        binaryTree(root,s);
        return strList;
    }
    void binaryTree(TreeNode* root,string val) {
        if (root == NULL) return;
        if (val.length() == 0) {
            val = to_string(root -> val);
        } else {
            val = val + "->" + to_string(root -> val);
        }
        if (root -> left == NULL && root -> right == NULL) {
            strList.push_back(val);
        }
        binaryTree(root -> left,val);
        binaryTree(root -> right,val);
        return;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
