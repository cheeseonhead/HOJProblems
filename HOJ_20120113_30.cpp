/*
Judge: HOJ
PROG: 30
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
//#define test
using namespace std;

int dp[100001] = {-2147483647},n,i,LIS,t,L,R,M,p;

int main()
{
	#ifdef test
	freopen("HOJ_20120113_30.in","r",stdin);
	freopen("HOJ_20120113_30.out","w",stdout);
	#endif
	while(~scanf("%d",&n))
	{
		for(i=LIS=0;i<n;i++)
		{
			scanf("%d",&t);
			L=0;R=LIS;
			while(L<=R)
			{
				M=(L+R)/2;
				if(dp[M]<t)
				{
					L=M+1;
					p=M;
				} 
				else R=p=M-1;
			}
			dp[p+1]=t;
			if(p==LIS)LIS++;
		}
		printf("%d\n",n?LIS:1);
	}
	return 0;
}
