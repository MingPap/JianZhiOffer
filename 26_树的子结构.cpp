#include<iostream>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	bool HasCore(TreeNode* node1, TreeNode* node2)
	{
		if (!node2)
			return true;
		if (!node1)
			return false;
		if (node1->val != node2->val)
			return false;
		return HasCore(node1->left, node2->left) && HasCore(node1->right, node2->right);//递归判断
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{

		bool result = false;
		if (pRoot1&&pRoot2)
		{
			if (pRoot1->val == pRoot2->val)
				result = HasCore(pRoot1, pRoot2);//前序遍历
			if (!result)
				result = HasCore(pRoot1->left, pRoot2);
			if (!result)
				result = HasCore(pRoot1->right, pRoot2);
		}

		return result;
	}
};