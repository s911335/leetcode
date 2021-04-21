#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solutions
{
public:
    vector<int> nextGreaterElement(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> result(n,-1);
        stack<int> st;
        for(int i = 0; i < n * 2; ++i) {
            int num = nums[i % n];
            while(!st.empty() && nums[st.top()] < num) {
                result[st.top()] = num;
                st.pop();
            }
            if (i < n)
                st.push(i);
        }
        return result; 
    }
};

int main()
{
    Solutions solution;
    vector<int> v1 = {1, 2, 3, 4, 3};
    cout<<"Q1 : ";
    for (int i = 0; i < v1.size(); ++i)
        cout<<v1[i]<<", ";
    cout<<"\n";
    vector<int> result = solution.nextGreaterElement(v1);
    cout<<"ans1 : ";
    for (int i = 0; i < result.size(); ++i)
        cout<<result[i]<<", ";
    cout<<"\n";
}
