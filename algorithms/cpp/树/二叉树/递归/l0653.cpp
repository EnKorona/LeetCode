//给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
//
// 案例 1:
//
//
//输入:
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 9
//
//输出: True
//
//
//
//
// 案例 2:
//
//
//输入:
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 28
//
//输出: False
//
//
//
// Related Topics 树
// 👍 239 👎 0


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
// 下面的解为啥不行
class Solution {
public:
    bool ans = false;
    bool findTarget(TreeNode* root, int k) {
        preFindTarget(root,k);
        return ans;
    }
    // 此方法的含义是先序遍历一遍树，看看是否能找到某个节点的根节点值对应的另一个值
    void preFindTarget(TreeNode* root, TreeNode* subRoot, int k) {
        if (root == NULL) return;
        findExistTarget(root, k - subRoot -> val);
        preFindTarget(root, root -> left, k);
        preFindTarget(root, root -> right, k);

    }
    // 在root树中寻找是否有值为target的节点
    void findExistTarget(TreeNode* root, int target) {
        if (root == NULL) return;
        if (root -> val == target && target != root -> val) {
            ans = true;
            return;
        }
        if (root -> val > target) {
            findExistTarget(root -> left, target);
        }
        if (root -> val < target) {
            findExistTarget(root -> right, target);
        }
    }
};

// 这个解答可以，你就像一个不会用工具的猴子
class Solution2 {
public:
    set<int> s;
    bool ans = false;
    bool findTarget(TreeNode* root, int k) {
        preFindTarget(root, k);
        return ans;
    }
    void preFindTarget(TreeNode* root, int k) {
        if (root == NULL) return;
        for (auto it = s.begin(); it != s.end(); it++) {
            if (*it + root -> val == k) {
                ans = true;
                return;
            }
        }
        s.insert(root -> val);
        preFindTarget(root -> left, k);
        preFindTarget(root -> right, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
