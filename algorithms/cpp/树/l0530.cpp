//给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
//
//
//
// 示例：
//
// 输入：
//
//   1
//    \
//     3
//    /
//   2
//
//输出：
//1
//
//解释：
//最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
//
//
//
//
// 提示：
//
//
// 树中至少有 2 个节点。
// 本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
//相同
//
// Related Topics 树
// 👍 248 👎 0


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
    const int MAX_VALUE = 99999999;
    int ans = MAX_VALUE;
    int getMinimumDifference(TreeNode* root) {
        preGetMininum(root);
        return ans;
    }
    void preGetMininum(TreeNode* root) {
        if (root == NULL) return;
        int tmp = getMininum(root);
        if (tmp < ans) ans = tmp;
        preGetMininum(root -> left);
        preGetMininum(root -> right);
    }
    int getMininum(TreeNode* root) {
        int min = MAX_VALUE;
        int leftMin = MAX_VALUE;
        int rightMin = MAX_VALUE;
        if (root == NULL) return min;
        TreeNode* left = root -> left;
        if (left != NULL) {
            while (left -> right != NULL) {
                left = left -> right;
            }
            int tmp = root -> val - left -> val;
            leftMin = tmp > 0 ? tmp : -tmp;
        }
        TreeNode* right = root -> right;
        if (right != NULL) {
            while (right -> left != NULL) {
                right = right -> left;
            }
            int tmp = root -> val - right -> val;
            rightMin = tmp > 0 ? tmp : -tmp;
        }
        min = leftMin < rightMin ? leftMin : rightMin;
        return min;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
