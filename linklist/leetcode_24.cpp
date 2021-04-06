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
    ListNode* swapPairs(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* n1 = head;
        ListNode* n3 = head->next->next;
        head = head->next;
        head->next = n1;
        head->next->next = swapPairs(n3);
        return head;   
    }
};

struct Question1
{
    ListNode head;
    ListNode a1;
    ListNode a2;
    ListNode a3;
    Question1 (): head(1), a1(2), a2(3), a3(4)
    { 
        head.next = &a1;
        a1.next = &a2;
        a2.next = &a3;
    }
};

struct Question2
{
    ListNode head;
    Question2 (): head(1) {}
};

int main()
{
    Question1 q1;
    Solutions solution;
    cout<<"Q1 :\n";
    cout<<"head list = ";
    print_linklist(q1.head);
    ListNode* q1_result = solution.swapPairs(&q1.head);
    cout<<"lists = ";
    print_linklist(*q1_result);

    Question2 q2;
    cout<<"Q3 :\n";
    cout<<"head list = ";
    print_linklist(q2.head);
    ListNode* q2_result = solution.swapPairs(&q2.head);
    cout<<"ists = ";
    print_linklist(*q2_result);
}
