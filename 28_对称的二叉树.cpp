class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return Score(pRoot,pRoot);
    }
    
    bool Score(TreeNode*p1,TreeNode*p2)
    {
        if(p1==nullptr&&p2==nullptr)
            return true;
        if(p1==nullptr||p2==nullptr)
            return false;
        if(p1->val!=p2->val)
            return false;
        return Score(p1->left,p2->right)&&Score(p1->right,p2->left);
    }

};
