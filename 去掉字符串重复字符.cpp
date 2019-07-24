#include<iostream>
#include<assert.h>
using namespace std;

//时间复杂度O(n2)
void Removedumple(char*str)
{
	if (str == nullptr)return;
	int len = strlen(str);
	if (len < 2) return;
	int tail = 1;
	for (int i = 1; i < len; i++)
	{
		int j;
		for (j = 0; j < tail; j++)             //与已有字符库里的字符比较
			if (str[i] == str[j])break;
		if (j == tail)               
		{
			str[tail] = str[i];                //字符库没有则加入，有则跳过
			tail++;
		}
	}
	str[tail] = '\0';                          //尾部跳过
}

//时间复杂度O(n)

void Removedumple2(char*str)
{
	if (str == nullptr)return;
	int len = strlen(str);
	if (len < 2)return;

	bool charset[256];              //定义伪哈希表映射
	for (int i = 0; i < 256; i++)
		charset[i] = false;
	charset[str[0]] = true;
	int tail = 1;
	for (int i = 1; i < len; i++)
	{
		if (!charset[str[i]])
		{
			str[tail] = str[i];
			tail++;
			charset[str[i]] = true;
		}
	}
	str[tail] = '\0';
}


int main() {
	char a[] = "AABCD";
	char b[] = "CDAA";
	Removedumple2(b);

	cout << b << endl;
	system("pause");
}
