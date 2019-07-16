class Solution {
public:
    void push(int value) {
        m_data.push(value);
        if(m_min.empty()||m_min.top()>value)
            m_min.push(value);
        else
            m_min.push(m_min.top());      //比当前最小值大时，将当前最小值push进来
    }
    void pop() {
        if(!m_data.empty())
        {
            m_data.pop();
            m_min.pop();
        }
    }
    int top() {
            return m_data.top();
    }
    int min() {
            return m_min.top();
    }
    
private:
    stack<int> m_data;
    stack<int> m_min;
};
