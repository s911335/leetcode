# LinkList

## 160. Intersection of Two Linked Lists

Given the heads of two singly linked-lists headA and headB, return the node
at which the list interset. If the two linked lists have no intersection
at all, return null.

Ex1: intersecVal = 8, list A = [4, 1, 8, 4, 5], list B = [5, 6, 1, 8, 4, 5],
     skipA = 2. skipB = 3.
     Output: intersected at '8'.
Ex2: intersecVal = 2, list A = [1, 9, 1, 2, 4], list B = [3, 2, 4],
     skipA = 3, skipB = 1.
     Output: intersected at '2'.
Ex3: intersecVal = 0, list A = [2, 6, 4], list B = [1, 5].
     skipA = 3. skipB = 2.
     Output: No intersection.

Solution:
1. Due to list A = a + c and list B = b + c, c is overlapping area. Therefore,
   we need to loop the interval with a + b + c and can get a intersection.
2. Set a_pointer = headA pointer, b_pointer = headB pointer. And to do whileloop
   with the condition that a_pointer is not equal to b_pointer.
3. If a_pointer is not NULL, a_pointer = pointer of next a_pointer. 
   If a_pointer = NULL, let a_pointer = headB pointer for each loop.
4. If b_pointer is not NULL, b_pointer = pointer of next a_pointer. 
   If b_pointer = NULL, let b_pointer = headA pointer for each loop.
5. After whileloop, return a_pointer or b_pointer.

## 206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the
reversed list.

Ex1: Input: head = [1, 2, 3, 4, 5];
     Output: [5, 4, 3, 2, 1].
Ex2: Input: head = [1, 2]
     Output: [2, 1]
Ex3: Input: head = []
     Output: []
