#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int topdown(int* weight,int* price,int total,int n)
{
	if(n==0)
	{
		return 0;
	}
	if(dp[n][total]!=-1)
	{
		return dp[n][total];
	}
	int currweigh=weight[n-1];
	int currprice=price[n-1];
	int inc=0;
	if(total-currweigh>=0)
	{
		inc=currprice+topdown(weight,price,total-currweigh,n-1);
	}
	int exc=topdown(weight,price,total,n-1);
	int final=max(exc,inc);
	return dp[n][total]=final;
}
int main(int argc, char const *argv[])
{
	int n,w;
	cin>>n>>w;
	int* wrr=new int[n];
	int* price=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>wrr[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>price[i];
	}
	for (int i = 0; i < 100; ++i)
	{
		for(int j=0;j<100;j++)
		{
			dp[i][j]=-1;
		}
	}
	cout<<topdown(wrr,price,w,n)<<endl;
	return 0;
}