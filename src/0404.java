//计算给定二叉树的所有左叶子之和。
//
// 示例：
//
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
//
//
// Related Topics 树
// 👍 276 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        int left = 0;
        int right = 0;
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            return 0;
        }
        if (root.left != null) {
            left = sum(root.left, true);
        }
        if (root.right != null) {
            right = sum(root.right, false);
        }
        return left + right;
    }
    private int sum(TreeNode root, boolean flag) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null && flag == true) {
            return root.val;
        }
        return sum(root.left, true) + sum(root.right, false);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
