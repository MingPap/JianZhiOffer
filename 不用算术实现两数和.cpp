//交换两个变量的值

a = a^b;
b = a^b;
a = a^b;


//不用算术实现两个数的加法

int add_no_arithm(int a, int b)
{
	if (b == 0)return a;
	int sum = a^b;                //不管进位求和
	int carry = (a&b) << 1;       //计算每一位的进位

	return add_no_arithm(sum, carry);          //递归计算和
}
