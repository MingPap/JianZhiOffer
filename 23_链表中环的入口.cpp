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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==nullptr)
            return pHead;
        ListNode* pS=pHead;
        ListNode* pF=pHead;
        bool Isa=false;
        while(pF->next!=nullptr)
        {
            pS=pS->next;
            pF=pF->next->next;
            if(pS==pF)
            {
                Isa=true;
                break;
            }
        }
        
        if(!Isa)
            return nullptr;
        else
        {
            pS=pHead;
            while(pS!=pF)
            {
                pS=pS->next;
                pF=pF->next;
            }
            return pS;
        }
        
    }
};
