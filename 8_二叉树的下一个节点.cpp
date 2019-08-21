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
