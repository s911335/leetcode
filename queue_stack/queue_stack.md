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
