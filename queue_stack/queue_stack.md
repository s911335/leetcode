# Queue and Stack

## 232. Implement Queue using Stacks

Implement a first in first out (FIFO) queue using only two stacks. The
implemented queue should support all the functions of a normal queue (push,
peek, pop and empty).

Implement the MyQueue class:
- void push(int x): Pushes element x to the back of the queue.
- int pop(): Removes the element from the front of the queue and returns it.
- int peek(): Returns the element at the front of the queue.
- boolean empty(): Returns true if the queue is empty, false otherwise.

Notes:
- You must use only standard operations of a stack, which means only push to
  top, peek/pop from top, size, and is empty operations are valid.
- Depending on your language, the stack may not be supported natively. You may
  simulate a stack using a list or deque(double-ended queue) as long as you use
  only a stack's standard operations.

### Ex:

1. Input: ["MyQueue", "push", "push", "peek", "pop", "empty"]
   [[], [1], [2], [], [], []].
   Output: [null, null, null, 1, 1, false].

Explanation:
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2]
myQueue.peek(); //return 1
myQueue.pop(); //return 1, queue is [2].
myQueue.empty(); // return false

### Solution:
1. Create input and output stack.
2. For push(x), set input.push(x).
3. For peek(), let input.pop() and push in output stack.
   And return output.top(). 
4. For pop(), do peek() and return output.top(). Next, output.pop().
5. For empty, return input.empty() && output.empty().

## 225. Implement Stack using Queues

Implement a last first out (LIFO) stack using only two queues. The implemented
stack should support all athe functions of a normal queue (push, top, pop and
empty).

Implement the MyStack class:

- void push (int x): Pushed element x to the top of the stack.
- int pop(): Removes the element on the top of the stack and returns it.
- int top(): Returns the element on the top of the stack.
- boolen empty(): Returns true if the stack is empty. false otherwise.

### Ex:

1. Input: ["MyStack", "push", "push", "top", "pop", "empty"]
   [[], [1], [2], [], [], []]
   Output: [null, null, null, 2, 2, false].

Explanation:
MyStack mystack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False

### Solution:

1. Create queue.
2. For push, queue.push(x) and reverse all elements. queue.push(queue.front) 
   and queue.pop() in forloop with the condition queue.size - 1.
3. Due to step 2, queue have become the stack.
4. For pop, queue.pop() and return queue.front().
5. For top, return queue.front.
6. For empty, return queue.empty().

## 155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element
in constant time.

Implement the MinStack class:
- MinStack(): initializes the stack object.
- void push(val): pushes the element val onto the stack.
- void pop(): removes the element on the top of the stack.
- int top(): gets the top elements of the stack.
- int getMin(): retrieves the minimum element in the stack.

### Ex:

Input: ["MinStack", "push", "push", "push", "getMin", "pop", "top", getMin"]
       [[], [-2], [0], [-3], [], [], [], []].
Output: [null, null, null, null, -3, null, 0, -2].

Explanation:
Minstack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3;
minStack.pop();
minStack.top(); //return 0;
minStack.getMin(); //return 2;

### Solution:

1. Create 2 stack for normal stack and minstack.
2. For push operator, let val push into normal stack. Next, let min is first
   element in normal stack. If min is larger than pushing element. let min is 
   equal to pushing element. Finally, push min into min stack.
3. For pop operator, pop element for normal stack and min stack.
4. For get min, return min stack.top().

## 20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and 
']', determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

### Ex:

1. Input: s = '()', Output: true.
2. Input: s = '()[]{}', Output: true.
3. Input: s = '(]', Output: false.
4. Input: s = '([)]', Output: false.
5. Input: s = '{[]}', Output: false.

### Solutions:

1. Create a stack for pushing '(', '{', '['.
2. whileloop with s, if s[i] is equal to '(' or '{' or '[' then push s[i] into 
   the stack. if s[i] is equal to ')' or '}' or ']' then check the stack.top is
   valid with s[i]. If it is not valid, return false.
3. Finally, if the stack is empty, return true, else, return false.

## 739. Daily Temperatures

Given a list of daily temperatures T, return a list such that, for each day in
the input, tells you how many days you would have to wait until a warmer
temperature. If there is no future day for which this is possible, put 0
instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
74], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each
temperature will be an integer in the range [30, 100].

### Ex:

1. Input: [73, 74, 75, 71, 69, 72, 76, 74]
   Output: [1, 1, 4, 2, 1, 1, 0, 0]

### Solution:

1. Create the stack for pushing temperary index of T and result vector which
   size is same as T.
2. To do forloop from 0 to T.size()-1, put index i to the stack in each loop.
3. If the stack is not empty and do whileloop, check that T[i] is larger than
   T[st.top()] is true or not. If it is true, result[st.top] = i - st.top() 
   and remove element of top of the stack. Next, to check next top of the stack.
4. If check that T[i] is larger than T[st.top()] is false, break the whileloop.
5. Finally, return result vector.
