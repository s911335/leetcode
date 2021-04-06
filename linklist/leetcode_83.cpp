#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {};
};

void print_linklist(ListNode& head)
{
    cout<<"head ";
    ListNode* pointer = &head;
    while (pointer != NULL)
    {
        cout<<pointer->val<<" -> ";
        pointer = pointer->next;
    }
    cout<<"\n";    
}

class Solutions
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        if (head->val == head->next->val)
        {
            ListNode* pointer = head->next;
            while (pointer->val == head->val)
            {
                if (pointer->next == NULL)
                    return pointer;
                pointer = pointer->next;
            }
            head->next = deleteDuplicates(pointer);
        }
        else
            head->next = deleteDuplicates(head->next);
        return head;   
    }
};

struct Question1
{
    ListNode head;
    ListNode a1;
    ListNode a2;
    Question1 (): head(1), a1(1), a2(2)
    { 
        head.next = &a1;
        a1.next = &a2;
    }
};

struct Question2
{
    ListNode head;
    ListNode a1;
    ListNode a2;
    ListNode a3;
    ListNode a4;
    Question2 (): head(1), a1(1), a2(2), a3(3), a4(3)
    { 
        head.next = &a1;
        a1.next = &a2;
        a2.next = &a3;
        a3.next = &a4;
    }
};

struct Question3
{
    ListNode head;
    ListNode a1;
    ListNode a2;
    Question3 (): head(1), a1(1), a2(1)
    { 
        head.next = &a1;
        a1.next = &a2;
    }
};

int main()
{
    Question1 q1;
    Solutions solution;
    cout<<"Q1 :\n";
    cout<<"head list = ";
    print_linklist(q1.head);
    ListNode* q1_result = solution.deleteDuplicates(&q1.head);
    cout<<"delete duplicates lists = ";
    print_linklist(*q1_result);

    Question2 q2;
    cout<<"Q2 :\n";
    cout<<"head list = ";
    print_linklist(q2.head);
    ListNode* q2_result = solution.deleteDuplicates(&q2.head);
    cout<<"delete duplicates lists = ";
    print_linklist(*q2_result);

    Question3 q3;
    cout<<"Q3 :\n";
    cout<<"head list = ";
    print_linklist(q3.head);
    ListNode* q3_result = solution.deleteDuplicates(&q3.head);
    cout<<"delete duplicates lists = ";
    print_linklist(*q3_result);
}
