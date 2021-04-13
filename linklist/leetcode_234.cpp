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
         return new_head.next;  
}  

class Solutions
{
public:
    bool isPalindrome(ListNode* head)
    {
        int count = 0;
        ListNode* pointer1 = head;
        ListNode* pointer2 = NULL;
        if (head->next == NULL)
            return true;
        while (pointer1) {
            pointer1 = pointer1->next;
            count++; 
        }
        int half = count / 2;
        int remainder = count % 2;
        pointer1 = head;
        while (half-1) {
            half--;
            pointer1 = pointer1->next;
        }
        if (remainder==0) {
            pointer2 = pointer1->next;
        }
        else {
            pointer2 = pointer1->next->next;
        }
        pointer1->next = NULL;
        pointer1 = head;
        pointer2 = reverseList(pointer2);
        while (pointer1) {
            if (pointer1->val != pointer2->val)
                return false;
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;
        }
        return true;  
    }
};

struct Question1
{
    ListNode l10;
    ListNode l11;
    ListNode l12;
    ListNode l13;
    Question1 (): l10(1), l11(2), l12(2), l13(1)
    { 
        l10.next = &l11;
        l11.next = &l12;
        l12.next = &l13;
    }
};

struct Question2
{
    ListNode l10;
    ListNode l11;
    ListNode l12;
    ListNode l13;
    ListNode l14;
    ListNode l15;
    ListNode l16;
    Question2 (): l10(1), l11(2), l12(3), l13(4), l14(3), l15(2), l16(1)
    {
        l10.next = &l11;
        l11.next = &l12;
        l12.next = &l13;
        l13.next = &l14;
        l14.next = &l15;
        l15.next = &l16;
    }
};

int main()
{
    Solutions solution;

    Question1 q1;
    cout<<"Q1 :\n";
    print_linklist(q1.l10);
    bool q1_result = solution.isPalindrome(&q1.l10);
    cout<<"yes or no = "<<q1_result<<"\n";

    Question2 q2;
    cout<<"Q2 :\n";
    print_linklist(q2.l10);
    bool q2_result = solution.isPalindrome(&q2.l10);
    cout<<"yes or no = "<<q2_result<<"\n";;
}
