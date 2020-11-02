#include <bits/stdc++.h>
using namespace std;
int recursion(int n)
{
	if(n==0 or n==1)
	{
		return n;
	}
	int fib=recursion(n-1)+recursion(n-2);
	return fib;
}
int topdown(int*dp,int n)
{
	if(n==0 or n==1)
	{
		dp[n]=n;
		return n;
	}
	if(dp[n]!=0)
	{
		return dp[n];
	}
	int fib=topdown(dp,n-1)+topdown(dp,n-2);
	return dp[n]=fib;
}
int bottomup(int n)
{
	int* dp=new int[n];
	memset(dp,0,sizeof(dp));
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int* dp=new int[n];
	memset(dp,0,sizeof(dp));
	cout<<recursion(n)<<endl;
	cout<<topdown(dp,n)<<endl;
	cout<<bottomup(n)<<endl;
	return 0;
}