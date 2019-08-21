/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==nullptr)
            return pHead;
        ListNode*p=pHead;
        ListNode*pre=nullptr;
        ListNode*pn=nullptr;
        while(p)
        {
            if(p->next&&p->val==p->next->val)
            {
                pn=p->next;
                while(pn&&pn->val==p->val)//删除p到pn之间的节点
                    pn=pn->next;
                if(p==pHead)            //判断是不是表头
                    pHead=pn;
                else
                    pre->next=pn;
                p=pn;                      //直接跳过p
            }
            else{
                pre=p;
                p=p->next;
            }
        }
        return pHead;
    }
    
    ListNode* deleteDuplication2(ListNode* pHead)
    {
        if(pHead==nullptr)
            return pHead;
        ListNode*p=pHead;
        ListNode*pre=nullptr;

        while(p)
        {
            ListNode* pn=p->next;
            bool needDelete=false;
            if(pn&&p->val==pn->val)
            {
                needDelete=true;
            }
            if(!needDelete)
            {
                pre=p;
                p=pn;
            }
            else{
                int t=p->val;
                ListNode* d=p;
                while(pn&&d->val==t)
                {
                    pn=d->next;            //重新定义pn
                    delete d;
                    d=nullptr;
                    d=pn;
                }
            }
            
            if(!pre)
            {
                pHead=pn;
            }
            else
                pre->next=pn;
            p=pn;

        }
        return pHead;
    }
};
