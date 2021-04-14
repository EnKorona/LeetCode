//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
// 本题中，一棵高度平衡二叉树定义为：
//
//
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//
//
//
//
// 示例 1：
//
//
//输入：root = [3,9,20,null,null,15,7]
//输出：true
//
//
// 示例 2：
//
//
//输入：root = [1,2,2,3,3,null,null,4,4]
//输出：false
//
//
// 示例 3：
//
//
//输入：root = []
//输出：true
//
//
//
//
// 提示：
//
//
// 树中的节点数在范围 [0, 5000] 内
// -104 <= Node.val <= 104
//
// Related Topics 树 深度优先搜索 递归
// 👍 661 👎 0


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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int leftDepth = getDepth(root -> left);
        int rightDepth = getDepth(root -> right);
        if (leftDepth - rightDepth >1 || leftDepth - rightDepth < -1) return false;
        return isBalanced(root -> left) && isBalanced(root -> right);
    }
    int getDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int leftDepth = getDepth(root -> left);
        int rightDepth = getDepth(root -> right);
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
