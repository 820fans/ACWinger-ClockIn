#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        ListNode *p=headA, *q=headB;
        while(p!=q){
            if(p) p=p->next;
            else p = headB;
            if(q) q=q->next;
            else q = headA;
        }
        return p;
        // ListNode *end_cur = headB;
        // while(end_cur->next) end_cur=end_cur->next;
        // end_cur->next = headB;
        // 问题可以转化成一个找环的入口问题
        
        // unordered_set<ListNode*> s;
        // for(ListNode *cur=headB;cur;cur=cur->next) s.insert(cur);
        
        // for(ListNode *cur=headA;cur;cur=cur->next){
        //     if(s.find(cur) != s.end()) return cur;
        // }
        // return NULL;
    }
};