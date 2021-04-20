//给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
//
//
//
// 示例 :
//给定二叉树
//
//           1
//         / \
//        2   3
//       / \
//      4   5
//
//
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
//
//
//
// 注意：两结点之间的路径长度是以它们之间边的数目表示。
// Related Topics 树
// 👍 680 👎 0


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
    int maxDepth = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        getMaxDepth(root);
        return maxDepth;
    }
    void getMaxDepth(TreeNode* root) {
        if (root == NULL) return;
        int depth = getDepth(root -> left) + getDepth(root -> right);
        if (depth > maxDepth) maxDepth = depth;
        getMaxDepth(root -> left);
        getMaxDepth(root -> right);
    }
    int getDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int leftDepth = getDepth(root -> left);
        int rightDepth = getDepth(root -> right);
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
