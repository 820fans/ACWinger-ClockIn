#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasSubtree(TreeNode* pA, TreeNode* pB) {
        if(!pB || !pA) return false;
        // if(!pB) return false;
        // return dfs(pA, pB);
        if(isSame(pA, pB)) return true;
        return hasSubtree(pA->left, pB) || hasSubtree(pA->right, pB);
    }
    
    bool isSame(TreeNode* pA, TreeNode* pB){
        if(!pB) return true;
        if(!pA || pA->val != pB->val) return false;
        return isSame(pA->left, pB->left) && isSame(pA->right, pB->right);
    }
    
    bool dfs(TreeNode* pA, TreeNode* pB) {
        if(!pB && !pA) return true;
        if(!pB) return true;
        if(!pA) return false;
        bool f = pA->val == pB->val;
        return hasSubtree(pA->left, pB) || hasSubtree(pA->right, pB) || (f &&
            dfs(pA->left, pB->left) && 
            dfs(pA->right, pB->right));
    }
};