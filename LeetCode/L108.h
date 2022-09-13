#pragma once
#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
}TreeNode;

class L108
{
public:
    static void insertTree(TreeNode* node, int val) {
        while (true) {
            if (val < node->val) {
                if (node->left) {
                    node = node->left;
                }
                else {
                    TreeNode* newN = new TreeNode(val);
                    node->left = newN;
                    return;
                }
            }
            else if (node->val < val) {
                if (node->right) {
                    node = node->right;
                }
                else {
                    TreeNode* newN = new TreeNode(val);
                    node->right = newN;
                    return;
                }
            }
        }
    }

    static TreeNode* sortedArrayToBST(vector<int>& nums) {
        int rt = nums.size() / 2;

        TreeNode* root = new TreeNode(nums[rt]);

        for (int i = 0; i < rt; i++) {
            insertTree(root, nums[i]);
        }
        for (int i = rt + 1; i < nums.size(); i++) {
            insertTree(root, nums[i]);
        }

        return root;
    }
};

