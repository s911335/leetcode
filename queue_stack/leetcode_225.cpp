#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    queue<int> que;
    void push(int x) {
        que.push(x);
        for(int i = 0; i < que.size()- 1; i++)
        {
            que.push(que.front());
            que.pop();
        }
    }
    int pop() {
        int ans = que.front();
        que.pop();
        return ans;
    }
    int peek() {
        return que.front();
    }
    bool empty() {
        return que.empty();
    }
    MyStack(){}
    virtual ~MyStack() {}
};

int main(int argc, char *argv[])
{
    MyStack s;
    for (int i = 0; i < 5; i++) {
        s.push(i);
    }
    for (int i = 0; i < 6; i++) {
        if (s.empty())
            cout<<"q is empty\n";
        cout<<s.pop()<<", ";
    }
}
