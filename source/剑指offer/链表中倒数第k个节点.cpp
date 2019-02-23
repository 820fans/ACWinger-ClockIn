#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* findKthToTail(ListNode* head, int k) {
        ListNode root(-1), *slow, *fast;
        root.next = head;
        slow=fast=&root;
        while(fast->next && k--) fast=fast->next;
        if(k>0) return NULL;
        while(fast) slow=slow->next, fast=fast->next;
        return slow;
    }
};