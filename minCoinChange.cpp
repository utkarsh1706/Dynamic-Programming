#include <bits/stdc++.h>
using namespace std;
int recursive(int n,int k,int* arr)
{
	if(k==0)
	{
		return 0;
	}
	int ans=INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if(k-arr[i]>=0)
		{
			int maxi=1+recursive(n,k-arr[i],arr);
			ans=min(maxi,ans);
		}
	}
	return ans;
}
int topdown(int n,int k,int* arr,int* dp)
{
	if(k==0)
	{
		return 0;
	}
	if(dp[k]!=0)
	{
		return dp[k];
	}
	int ans=INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if(k-arr[i]>=0)
		{
			int maxi=1+topdown(n,k-arr[i],arr,dp);
			ans=min(maxi,ans);
		}
	}
	return dp[k]=ans;
}
int bottomup(int n,int k,int* arr)
{
	int* dp=new int[n];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=k;i++)
	{
		dp[i]=INT_MAX;
		for(int j=0;j<n;j++)
		{
			if(i-arr[j]>=0)
			{
				int maxi=1+dp[i-arr[j]];
				dp[i]=min(dp[i],maxi);
			}
		}
	}
	return dp[k];
}
int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	int* arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cout<<recursive(n,k,arr)<<endl;
	cout<<topdown(n,k,arr,dp)<<endl;
	cout<<bottomup(n,k,arr)<<endl;
	return 0;
}