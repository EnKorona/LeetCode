//给定一个二叉树，检查它是否是镜像对称的。
//
//
//
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//
//     1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//
//
//
//
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
//
//     1
//   / \
//  2   2
//   \   \
//   3    3
//
//
//
//
// 进阶：
//
// 你可以运用递归和迭代两种方法解决这个问题吗？
// Related Topics 树 深度优先搜索 广度优先搜索
// 👍 1207 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    // 明确这个函数的功能:判断这棵树是否为对称二叉树
    public boolean isSymmetric(TreeNode root) {
        return check(root, root);
    }

    // 根据需要，构造一个函数，判断对称位置的子树是否为对称的
    public boolean check(TreeNode p, TreeNode q) {
        // 判断两个子树是否对称：两棵子树根节点值相等，左侧树的左子树与右侧树的右子树也需要满足子树对称的要求，左侧树右子树与右侧树左子树亦同
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null) {
            return false;
        }
        // 先序遍历左侧树的每个节点，每个节点对应的右侧树都构成对称二叉树，则整棵树就是对称二叉树
        return p.val == q.val && check(p.left, q.right) && check(p.right, q.left);
    }
}

//leetcode submit region end(Prohibit modification and deletion)
