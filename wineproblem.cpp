#include <bits/stdc++.h>
using namespace std;
int rec(int* arr,int year,int start,int end)
{
	if(start>end)
	{
		return 0;
	}
	int startinc= (arr[start]*year) + rec(arr,year+1,start+1,end);
	int endinc= (arr[end]*year) + rec(arr,year+1,start,end-1);
	return max(startinc,endinc);
}
int dp[100][100];
int topdown(int* arr,int year,int start,int end)
{
	if(start>end)
	{
		return 0;
	}
	if(dp[start][end]!=-1)
	{
		return dp[start][end];
	}
	int startinc= (arr[start]*year) + rec(arr,year+1,start+1,end);
	int endinc= (arr[end]*year) + rec(arr,year+1,start,end-1);
	dp[start][end]=max(startinc,endinc);
	return dp[start][end];
}
int bottomup(int* arr,int n)
{
	int year=n;
	int dp[100][100]={0};

	for (int i = 0; i < n; ++i)
	{
		dp[i][i]=year*arr[i];
	}
	year--;

	for(int win=2;win<=n;win++)
	{
		int start=0,end=n-win;

		while(start<=end)
		{
			int startofwin=start;
			int endofwin=start+win-1;
			int sellstart=(arr[startofwin]*year)+dp[startofwin+1][endofwin];
			int sellend=(arr[endofwin]*year)+dp[startofwin][endofwin-1];
			dp[startofwin][endofwin]=max(sellend,sellstart);
			start++;
		}
		year--;
	}
	return dp[0][n-1];
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int* arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	for (int i = 0; i < 100; ++i)
	{
		for(int j = 0; j < 100; ++j)
		{
			dp[i][j]=-1;
		}
	}
	cout<<rec(arr,1,0,n-1)<<endl;
	cout<<topdown(arr,1,0,n-1)<<endl;
	cout<<bottomup(arr,n)<<endl;
	return 0;
}