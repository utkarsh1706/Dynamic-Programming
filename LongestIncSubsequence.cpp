#include <bits/stdc++.h>
using namespace std;
int lic(int* arr,int n)
{
	if(n==0 or n==1)
	{
		return n;
	}
	int* dp=new int[n];
	for(int i=0;i<n;i++)
	{
	    dp[i]=1;
	}
	int maxlength=INT_MIN;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		maxlength=max(maxlength,dp[i]);
	}
	return maxlength;
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
	cout<<lic(arr,n)<<endl;
	return 0;
}