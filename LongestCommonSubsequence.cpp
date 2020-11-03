#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int lcs(string a,string b,int i,int j)
{
	if(i=a.length() or j=b.length())
	{
		return 0;
	}
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	if(a[i]==b[j])
	{
		dp[i][j]=lcs(a,b,i+1,j+1)+1;
	}
	else
	{
		dp[i][j]=max(lcs(a,b,i,j+1),lcs(a,b,i+1,j));
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	string a,b;
	cin>>a>>b;
	for(int i=0;i<a.length();i++)
	{
		for(int j=0;j<b.length();j++)
		{
			dp[i][j]=-1;
		}
	}
	cout<<lcs(a,b,0,0)<<endl;
	return 0;
}