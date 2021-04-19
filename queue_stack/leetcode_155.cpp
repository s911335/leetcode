#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
public:
    stack<int> st;
    stack<int> minst;
    int min;
    void push(int val) {
        if (st.empty())
            min = val;
        else
            min = minst.top();
        if (min > val)
            min = val;
        minst.push(min);
        st.push(val);
    }
    void pop() {
        minst.pop();
        st.pop();
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return minst.top();
    }
    bool empty()
    {
        return st.empty();
    }
    MinStack(){}
    virtual ~MinStack() {}
};

int main(int argc, char *argv[])
{
    MinStack s;
    for (int i = 0; i < 5; i++) {
        s.push(i);
    }
    cout<<"min = "<<s.getMin()<<"\n";
    for (int i = 0; i < 5; i++) {
        if (s.empty())
            cout<<"q is empty\n";
        cout<<s.top()<<", ";
        s.pop();
    }
    cout<<"\n";
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout<<"min = "<<s.getMin()<<"\n";
    s.pop();
    cout<<"min = "<<s.getMin()<<"\n";
}
