//给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一
//个。
//
// 更正式地说，root.val = min(root.left.val, root.right.val) 总成立。
//
// 给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
//
//
//
// 示例 1：
//
//
//输入：root = [2,2,5,null,null,5,7]
//输出：5
//解释：最小的值是 2 ，第二小的值是 5 。
//
//
// 示例 2：
//
//
//输入：root = [2,2,2]
//输出：-1
//解释：最小的值是 2, 但是不存在第二小的值。
//
//
//
//
// 提示：
//
//
// 树中节点数目在范围 [1, 25] 内
// 1 <= Node.val <= 231 - 1
// 对于树中每个节点 root.val == min(root.left.val, root.right.val)
//
// Related Topics 树
// 👍 133 👎 0


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
    // 由题意，根节点一定是最小值，所以找到除根节点外的最小的值即可
    public int findSecondMinimumValue(TreeNode root) {
        findSecondMin(root, root.val);
        if (flag == true) {
            return -1;
        }
        return secMin;
    }

    // 把最大值设置为Integer范围内的最大值，但是有可能出现子树中最大值为此值的情况，所以再设置一个标志位，记录子树中是否存在不等于根节点的值
    int secMin = Integer.MAX_VALUE;
    Boolean flag = true;

    private void findSecondMin(TreeNode root, int min) {
        if (root == null) {
            return;
        }
        if (root.val != min) {
            flag = false;
            if (root.val < secMin) {
                secMin = root.val;
            }
        }
        findSecondMin(root.left, min);
        findSecondMin(root.right, min);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
