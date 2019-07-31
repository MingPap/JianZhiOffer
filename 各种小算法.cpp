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


//写一个接受可变参数的函数实现多个数相加

int add(int num,...)
{
	int sum=0;
	int index=0;
	int*p=(int*)&num+1;                          //获取形参地址方式
	for(;index<num;index++)
		sum+=*p++;
	return sum;
}

//或者initializer_list


//求最大公约数

int func(int m,int n)
{
	if(m%n==0)
		return n;
	else
		return func(n,m%n);
}
