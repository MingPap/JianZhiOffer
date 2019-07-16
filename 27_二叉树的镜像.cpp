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
	void MirrorCore(TreeNode* pnode)
	{
		if (pnode)
		{
			TreeNode* t = pnode->left;
			pnode->left = pnode->right;
			pnode->right = t;
			MirrorCore(pnode->left);
			MirrorCore(pnode->right);
		}
	}
	void Mirror(TreeNode *pRoot) {
		if ((!pRoot) || (!pRoot->left && !pRoot->right))
			return;
		MirrorCore(pRoot);

	}
};