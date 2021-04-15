#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> input, output;
    void push(int x) {
        input.push(x);
    }
    int pop() {
        peek();
        int ans = output.top();
        output.pop();
        return ans;
    }
    int peek() {
        if (output.empty())
            while (input.size())
            {
                int ans = input.top();
                input.pop();
                output.push(ans);
            }
        return output.top();
    }
    bool empty() {
        return input.empty() && output.empty();
    }
    MyQueue(){}
    virtual ~MyQueue() {}
};

int main(int argc, char *argv[])
{
    MyQueue q;
    for (int i = 0; i < 5; i++) {
        q.push(i);
    }
    for (int i = 0; i < 6; i++) {
        if (q.empty())
            cout<<"q is empty\n";
        cout<<q.pop()<<", ";
    }
    cout<<"\n";
    cout<<"empty = "<<q.empty()<<"\n";
    return 0;
}
