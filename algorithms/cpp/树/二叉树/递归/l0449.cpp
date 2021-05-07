//序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。 
//
// 设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序
//列化为最初的二叉搜索树。 
//
// 编码的字符串应尽可能紧凑。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [2,1,3]
//输出：[2,1,3]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数范围是 [0, 104] 
// 0 <= Node.val <= 104 
// 题目数据 保证 输入的树是一棵二叉搜索树。 
// 
//
// 
//
// 注意：不要使用类成员/全局/静态变量来存储状态。 你的序列化和反序列化算法应该是无状态的。 
// Related Topics 树 
// 👍 179 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serializeCode;
    string serialize(TreeNode* root) {
        preSerialize(root);
        return serializeCode;
    }
    void preSerialize(TreeNode* root) {
        if (root == NULL) {
            serializeCode += "NULL,";
            return;
        }
        serializeCode += to_string(root -> val) + ',';
        preSerialize(root -> left);
        preSerialize(root -> right);
    }

    // Decodes your encoded data to tree.
    queue<string> q;
    TreeNode* deserialize(string data) {
        int i = 0,j = 0;
        while(i < data.size()) {
            while (data[i] != ',' && i < data.size()) i++;
            string tmp = data.substr(j,i-j);
            q.push(tmp);
            j = ++i;
        }
        return preDeserialize();
    }
    TreeNode* preDeserialize() {
        string t = q.front();
        q.pop();
        if (t == "NULL") return NULL;
        TreeNode* root = new TreeNode(stoi(t));
        root -> left = preDeserialize();
        root -> right = preDeserialize();

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
//leetcode submit region end(Prohibit modification and deletion)
