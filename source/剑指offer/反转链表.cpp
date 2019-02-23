#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    // 递归版本
    ListNode* reverseListRecursive(ListNode* head) {
        if(!head || !(head->next)) return head;
        
        ListNode *node=reverseListRecursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }

    // 非递归版本1
    ListNode* reverseList1(ListNode* head) {
        ListNode root(-1), *temp=NULL;
        root.next=head;
        while(head){
            ListNode *next = head->next;
            root.next = head;
            head->next= temp;
            temp = head;
            head = next;
        }
        return root.next;
    }
    
    // 非递归版本2
    ListNode* reverseList2(ListNode* head) {
        ListNode root(-1);
        while(head){
            ListNode *next = head->next;
            head->next= root.next;
            root.next = head;
            head = next;
        }
        return root.next;
    }
};