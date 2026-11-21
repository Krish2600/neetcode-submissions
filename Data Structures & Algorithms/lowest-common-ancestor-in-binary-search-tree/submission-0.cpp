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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> bfs;

        parent[root] = nullptr;
        bfs.push(root);

        while(!parent.count(p) || !parent.count(q)){

            TreeNode* node = bfs.front();
            bfs.pop();

            if(node->left != nullptr){
                parent[node->left] = node;
                bfs.push(node->left);
            }

            if(node->right != nullptr){
                parent[node->right] = node;
                bfs.push(node->right);
            }
        }

        unordered_set<TreeNode*> ancestors;

        while(p != nullptr){
            ancestors.insert(p);
            p = parent[p];
        }

        while(!ancestors.count(q)){
            q = parent[q];
        }

        return q;



        
    }
};
