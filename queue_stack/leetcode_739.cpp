#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solutions
{
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        stack<int> st;
        vector<int> result(T.size(), 0);
        for (int i = 0; i < T.size(); ++i) {
            while (!st.empty()) {
                if (T[st.top()] < T[i]) {
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                else
                    break;
            }
            st.push(i);
        }
        return result; 
    }
};

int main()
{
    Solutions solution;
    vector<int> v1 = {73, 74, 75, 71, 69, 72, 76, 73};
    cout<<"Q1 : ";
    for (int i = 0; i < v1.size(); ++i)
        cout<<v1[i]<<", ";
    cout<<"\n";
    vector<int> result = solution.dailyTemperatures(v1);
    cout<<"ans1 : ";
    for (int i = 0; i < result.size(); ++i)
        cout<<result[i]<<", ";
    cout<<"\n";
}
