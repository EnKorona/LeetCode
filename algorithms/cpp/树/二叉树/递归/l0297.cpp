//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方
//式重构得到原数据。
//
// 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串
//反序列化为原始的树结构。
//
// 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的
//方法解决这个问题。
//
//
//
// 示例 1：
//
//
//输入：root = [1,2,3,null,null,4,5]
//输出：[1,2,3,null,null,4,5]
//
//
// 示例 2：
//
//
//输入：root = []
//输出：[]
//
//
// 示例 3：
//
//
//输入：root = [1]
//输出：[1]
//
//
// 示例 4：
//
//
//输入：root = [1,2]
//输出：[1,2]
//
//
//
//
// 提示：
//
//
// 树中结点数在范围 [0, 104] 内
// -1000 <= Node.val <= 1000
//
// Related Topics 树 设计
// 👍 552 👎 0


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
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)
