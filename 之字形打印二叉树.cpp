/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(!pRoot)
            return res;
        
        queue<TreeNode*> q;
        q.push(pRoot);
        bool even=false;                     //定义了一个开关
        while(!q.empty())
        {
            vector<int> path;
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* p=q.front();
                path.push_back(p->val);
                q.pop();
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            if(even)
                std::reverse(path.begin(),path.end());            //翻转
            res.push_back(path);                      
            even=!even;
        }
        
        return res;
    }
    
};

//另一种方法利用两个栈
