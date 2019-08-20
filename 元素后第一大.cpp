//n个整数的无序数组，找到每个元素后面比它大的第一个数，时间复杂度O（n）

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> findv(vector<int> num)
{
	if (num.empty()) return num;
	vector<int>res(num.size());          //预先分配好容量
	stack<int> s;
	int i = 0;
	while (i<num.size())
	{
		if (s.empty() || num[s.top()] >= num[i])
			s.push(i++);
		else
		{
			res[s.top()] = num[i];
			s.pop();
		}
	}
	while (!s.empty())
	{
		res[s.top()] = INT_MAX;
		s.pop();
	}

	return res;
}

int main()
{
	vector<int> a{ 1,3,5,2,3,4,7,5 };

	vector<int> o = findv(a);

	for (auto c : o)
		cout << c << " ";
	cout << endl;

	system("pause");
}
