//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//
//
// push(x) —— 将元素 x 推入栈中。
// pop() —— 删除栈顶的元素。
// top() —— 获取栈顶元素。
// getMin() —— 检索栈中的最小元素。
//
//
//
//
// 示例:
//
// 输入：
//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]
//
//输出：
//[null,null,null,null,-3,null,0,-2]
//
//解释：
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 -2.
//
//
//
//
// 提示：
//
//
// pop、top 和 getMin 操作总是在 非空栈 上调用。
//
// Related Topics 栈 设计
// 👍 974 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class MinStack {
    // 辅助栈的作用其实就是按入栈顺序筛选出递减顺序的数字。每当入主栈的时候，如果当前值小于目前栈顶元素(当前出现过的最小值)，就堂堂正正入栈，如果比当前的大，就假装进栈了，实际不做任何操作
    // 出栈的时候也一样，当主栈中的元素出栈的时候，去看看辅助栈里有没有这个元素，有的话堂堂正正出栈，没有的话就假装出栈了，留在栈头的就是当前主栈里出现的最小的元素
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {

    }

    void push(int x) {
        x_stack.push(x);
        if (min_stack.empty() || x <= min_stack.top()) {
            min_stack.push(x);
        }
    }

    void pop() {
        if (x_stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        x_stack.pop();
    }

    int top() {
        return x_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//leetcode submit region end(Prohibit modification and deletion)
