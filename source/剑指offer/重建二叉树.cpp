#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m=preorder.size();
        int n=inorder.size();
        TreeNode* root = build(preorder, inorder, 0, n-1);
        return root;
    }
    
    int p=0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r){
        if(p>=preorder.size() || l>r) return NULL;
        
        int val = preorder[p++];
        TreeNode* node = new TreeNode(val);
        int pos=l;
        while(pos<=r && inorder[pos]!=val) pos++;
        if(l<pos) node->left = build(preorder, inorder, l, pos-1);
        if(pos<r) node->right = build(preorder, inorder, pos+1, r);
        return node;
    }
    
    
    // TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& p, int l, int r) {
    //     if(p>= preorder.size() || l>r) return NULL;  // null node
    //     int val = preorder[p];
        
    //     TreeNode* node = new TreeNode(val);
    //     p++;
    //     // find val in inorder between l,r, get its index
    //     int pos=l;
    //     while(pos <= r && inorder[pos] != val) pos++;
        
    //     // left node is in l,pos-1. while right node is in pos+1,r
    //     if(l<pos) node->left = build(preorder, inorder, p, l, pos-1);
    //     if(r>pos) node->right = build(preorder, inorder, p, pos+1, r);
        
    //     return node;
    // }
};