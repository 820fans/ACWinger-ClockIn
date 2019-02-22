#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        ListNode root(-1);
        root.next = head;
        for(ListNode *pre=&root, *cur=head;cur;){
            ListNode *next = cur->next;
            bool flag = false;
            while(next && cur->val == next->val) {
                next=next->next;
                flag = true;
            }
            if(flag) cur=next, pre->next = cur;
            else pre=cur, cur=next;
        }
        return root.next;
    }
};