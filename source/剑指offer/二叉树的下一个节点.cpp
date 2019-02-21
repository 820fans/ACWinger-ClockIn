#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *father;
    TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *father;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res=NULL;
    TreeNode* inorderSuccessor(TreeNode* p) {
        dfs(p);
        return res;
    }
    
    void dfs(TreeNode* root){
        if(root->right){
            // right child's leftmost child
            TreeNode* temp = root->right;
            while(temp->left) temp=temp->left;
            res = temp;
        }
        else{
            // find up
            while(root->father && root->father->right==root){
                root = root->father;
            }
            TreeNode *fa = root->father;
            if(fa && fa->left==root) res = fa;
        }
    }
};
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // void inorder(TreeNode* root, TreeNode* &val){
    //     if(root->right){
    //         TreeNode *node = root->right;
    //         while(node->left) node = node->left;
    //         val = node;
    //     }
    //     else{
    //         while(root->father && root->father->right == root) {
    //             root = root->father;
    //         }
    //         TreeNode* father = root->father;
    //         if(father && father->left == root) val = father;
            
    //     }
    // }
};