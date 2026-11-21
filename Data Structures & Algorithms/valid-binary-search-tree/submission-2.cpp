/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:  // optimized- recursive range validation

    bool validate(TreeNode* root, long long low, long long high){

        if(root == nullptr){
            return true;
        }

        if(root->val <= low || root->val >= high){
            return false;
        }

        bool leftvalid = validate(root->left, low, root->val);
        bool rightvalid = validate(root->right, root->val, high);

        return leftvalid && rightvalid;
    }

    bool isValidBST(TreeNode* root) {

        return validate(root, LLONG_MIN, LLONG_MAX);
        
    }
};
