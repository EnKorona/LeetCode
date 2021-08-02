//请判断一个链表是否为回文链表。
//
// 示例 1:
//
// 输入: 1->2
//输出: false
//
// 示例 2:
//
// 输入: 1->2->2->1
//输出: true
//
//
// 进阶：
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
// Related Topics 栈 递归 链表 双指针
// 👍 1066 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        stack<int> s;
        ListNode *p = head;
        int count = 0;
        while (p) {
            s.push(p->val);
            p = p->next;
            count++;
        }
        p = head;
        for (int i = 0; i < count / 2; i++) {
            if (p->val != s.top()) {
                return false;
            }
            p = p->next;
            s.pop();
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
