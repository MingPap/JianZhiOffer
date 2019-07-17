class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()!=popV.size())
            return false;
        int len=pushV.size();
        int i=0,j=0;                   //创建序列索引
        stack<int> data;
        data.push(pushV[0]);
        while(i<len&&j<len)
        {
            if(data.top()!=popV[j])
                data.push(pushV[++i]);           //如果正在压入的序列元素与弹出序列不相同，则将该元素压入栈
            else{
                data.pop();                      
                j++;
            }
        }
        if(data.empty())                         //栈空证明验证合格
            return true;
        return false;
    }
};
