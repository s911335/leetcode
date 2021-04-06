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
    ListNode* reverseList(ListNode* head)
    {
        if (head == NULL)
            return head;
        ListNode new_head(-1);
        ListNode* pointer = head;
        while (pointer != NULL)
        {
            if (new_head.next == NULL)
            {
                new_head.next = pointer;
                pointer = pointer->next;
                new_head.next->next = NULL;
            }
            else
            {
                ListNode* record = new_head.next;
                new_head.next = pointer;
                pointer = pointer->next;
                new_head.next->next = record;
            }
        }
        print_linklist(*new_head.next);
        return new_head.next;
    }
};

struct Question1
{
    ListNode headA;
    ListNode a1;
    ListNode a2;
    ListNode a3;
    ListNode a4;
    Question1 (): headA(1), a1(2), a2(3), a3(4), a4(5)
    { 
        headA.next = &a1;
        a1.next = &a2;
        a2.next = &a3;
        a3.next = &a4;
    }
};

struct Question2
{
    ListNode headA;
    ListNode a1;
    Question2 (): headA(1), a1(2)
    { 
        headA.next = &a1;
    }
};

int main()
{
    Question1 q1;
    Question2 q2;
    Solutions solution;
    cout<<"Q1 :\n";
    print_linklist(q1.headA);
    ListNode* q1_result = solution.reverseList(&q1.headA);
    cout<<"Q1 reverse = ";
    print_linklist(*q1_result);
}
