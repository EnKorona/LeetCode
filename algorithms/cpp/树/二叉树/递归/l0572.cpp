//给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看
//做它自身的一棵子树。
//
// 示例 1:
//给定的树 s:
//
//
//     3
//    / \
//   4   5
//  / \
// 1   2
//
//
// 给定的树 t：
//
//
//   4
//  / \
// 1   2
//
//
// 返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
//
// 示例 2:
//给定的树 s：
//
//
//     3
//    / \
//   4   5
//  / \
// 1   2
//    /
//   0
//
//
// 给定的树 t：
//
//
//   4
//  / \
// 1   2
//
//
// 返回 false。
// Related Topics 树
// 👍 487 👎 0


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
    bool flag = false;
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) return false;
        preIsSubtree(s,t);
        return flag;
    }
    // 遍历比较s的每棵子树与t，判断是否相同
    void preIsSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) return;
        if (s -> val == t -> val) {
            bool tmp = judgeSameTree(s,t);
            if (tmp == true) {
                flag = true;
                return;
            }
        }
        preIsSubtree(s -> left,t);
        preIsSubtree(s -> right,t);
    }
    // 对传入的两棵树判断是否相同
    bool judgeSameTree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s != NULL && t == NULL) return false;
        if (s == NULL && t != NULL) return false;
        return (s -> val == t -> val && judgeSameTree(s-> left,t -> left) && judgeSameTree(s -> right,t -> right));
    }
};
//leetcode submit region end(Prohibit modification and deletion)
