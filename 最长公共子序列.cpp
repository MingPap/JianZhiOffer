#include<iostream>
#include<algorithm>
using namespace std;

const int n = 100;
int dp[n][n];

int LCS(const char*str1, const char*str2)
{
	if (str1 == nullptr || str2 == nullptr)
		return 0;
	int s1 = strlen(str1);
	int s2 = strlen(str2);
	for (int i = 0; i < s1; i++)
		dp[0][i] = 0;
	for (int j = 0; j < s2; j++)
		dp[j][0] = 0;

	for(int i=1;i<=s1;i++)
		for (int j = 1; j <= s2; j++)
		{
			if (str1[i] == str2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	return dp[s1][s2];

}


int main()
{
	char s1[] = "ABCBDAB";
	char s2[] = "BDCABA";

	cout << LCS(s1, s2) << endl;
	system("pause");
}