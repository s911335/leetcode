#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {};
};

class Solutions
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* a_pointer = headA;
        ListNode* b_pointer = headB;
        while (a_pointer != b_pointer)
        {
            if (a_pointer != b_pointer)
            {
                if (a_pointer == NULL)
                    a_pointer = headB;
                else
                    a_pointer = a_pointer->next;
                if (b_pointer == NULL)
                    b_pointer = headA;
                else
                    b_pointer = b_pointer->next;
            }
        }
        return a_pointer;
    }
};
struct Question1
{
    ListNode headA;
    ListNode a1;
    ListNode a2;
    ListNode a3;
    ListNode a4;
    ListNode headB;
    ListNode b1;
    ListNode b2;
    Question1 (): headA(4), a1(1), a2(8), a3(4), a4(5), headB(5), b1(6), b2(1)
    {
        headA.next = &a1;
        a1.next = &a2;
        a2.next = &a3;
        a3.next = &a4;
        headB.next = &b1;
        b1.next = &b2;
        b2.next = &a2;
    }
};

struct Question2
{
    ListNode headA;
    ListNode a1;
    ListNode a2;
    ListNode a3;
    ListNode a4;
    ListNode headB;
    Question2 (): headA(1), a1(9), a2(1), a3(2), a4(4), headB(3)
    { 
        headA.next = &a1;
        a1.next = &a2;
        a2.next = &a3;
        a3.next = &a4;
        headB.next = &a3;
    }
};

struct Question3
{
    ListNode headA;
    ListNode a1;
    ListNode a2;
    ListNode headB;
    ListNode b1;
    Question3 (): headA(2), a1(6), a2(4), headB(1), b1(5)
    { 
        headA.next = &a1;
        a1.next = &a2;
        headB.next = &b1;
    }
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
int main()
{
    Question1 q1;
    Question2 q2;
    Question3 q3;
    Solutions solution;
    cout<<"Q1 :\n";
    print_linklist(q1.headA);
    print_linklist(q1.headB);
    ListNode* q1_result = solution.getIntersectionNode(&q1.headA, &q1.headB);
    cout<<"Q1 intersection = "<<q1_result->val<<"\n";
    cout<<"Q2 :\n";
    print_linklist(q2.headA);
    print_linklist(q2.headB);
    ListNode* q2_result = solution.getIntersectionNode(&q2.headA, &q2.headB);
    cout<<"Q2 intersection = "<<q2_result->val<<"\n";
    cout<<"Q3 :\n";
    print_linklist(q3.headA);
    print_linklist(q3.headB);
    ListNode* q3_result = solution.getIntersectionNode(&q3.headA, &q3.headB);
    cout<<"Q3 intersection = "<<q3_result->val<<"\n";
}
