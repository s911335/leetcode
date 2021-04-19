#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solutions
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int i = 0;
        while(i < s.size()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {
                if (st.empty())
                    return false;
                if (s[i] == ')') {
                    if (st.top() == '(') 
                        st.pop();
                    else
                        return false;
                }
                if (s[i] == ']') {
                    if (st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
                if (s[i] == '}') {
                    if (st.top() == '{')
                        st.pop();
                    else
                        return false;
                }
            }
            ++i;
            if (st.empty())
                return true;
            else
                return false;
        }
        return true;   
    }
};

int main()
{
    Solutions solution;
    string s1 = "()";
    cout<<"Q1 :"<<s1<<" is ";
    if (solution.isValid(s1))
        cout<<"true\n";
    else
        cout<<"false\n";

    string s2 = "()[]{}";
    cout<<"Q2 :"<<s2<<" is ";
    if (solution.isValid(s2))
        cout<<"true\n";
    else
        cout<<"false\n";
    
    string s3 = "(]";
    cout<<"Q3 :"<<s3<<" is ";
    if (solution.isValid(s3))
        cout<<"true\n";
    else
        cout<<"false\n";
    
    string s4 = "([)]";
    cout<<"Q4 :"<<s4<<" is ";
    if (solution.isValid(s4))
        cout<<"true\n";
    else
        cout<<"false\n";
    
    string s5 = "{[]}";
    cout<<"Q5 :"<<s5<<" is ";
    if (solution.isValid(s5))
        cout<<"true\n";
    else
        cout<<"false\n";
    
}
