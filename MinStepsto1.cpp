#include <bits/stdc++.h>
using namespace std;
int recursive(int n)
{
	if(n==1)
	{
		return 0;
	}
	int minstepsby3=INT_MAX,minstepsby2=INT_MAX,minstepsby1=INT_MAX;
	if(n%3==0)
		minstepsby3=recursive(n/3);
	if(n%2==0)
		minstepsby2=recursive(n/2);
	minstepsby1=recursive(n-1);
	int mini=1+min(minstepsby1,min(minstepsby2,minstepsby3));
	return mini;
}
int topdown(int* dp,int n)
{
	if(n==1)
	{
		return 0;
	}
	if(dp[n]!=0)
	{
		return dp[n];
	}
	int minstepsby3=INT_MAX,minstepsby2=INT_MAX,minstepsby1=INT_MAX;
	if(n%3==0)
		minstepsby3=topdown(dp,n/3);
	if(n%2==0)
		minstepsby2=topdown(dp,n/2);
	minstepsby1=topdown(dp,n-1);
	int mini=1+min(minstepsby1,min(minstepsby2,minstepsby3));
	dp[n]=mini;
	return mini;
}
int bottomup(int n)
{
	int* dp=new int[n];
	memset(dp,0,sizeof(dp));
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	for(int i=4;i<=n;i++)
	{
		int div3=INT_MAX,div2=INT_MAX,minstepsby1=INT_MAX;
		if(i%3==0)
			div3=dp[i/3];
		if(i%2==0)
			div2=dp[i/2];
		minstepsby1=dp[i-1];
		dp[i]=1+min(minstepsby1,min(div2,div3));
	}
	return dp[n];
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int* dp=new int[n];
	memset(dp,0,sizeof(dp));
	cout<<recursive(n)<<endl;
	cout<<topdown(dp,n)<<endl;
	cout<<bottomup(n)<<endl;
	return 0;
}