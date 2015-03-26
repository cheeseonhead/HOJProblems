/*
Judge: HOJ
PROG: 31
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
//#define test
using namespace std;

int ary[3001][3001],N,M,n[3001],m[3001],i,j;

int main()
{
	#ifdef test
	freopen("HOJ_20120113_31.in","r",stdin);
	freopen("HOJ_20120113_31.out","w",stdout);
	#endif
	while(~scanf("%d%d",&N,&M))
	{
		memset(ary,0,sizeof(ary));
		for(i=1;i<=N;i++)scanf("%d",&n[i]);
		for(i=1;i<=M;i++)scanf("%d",&m[i]);
		for(i=1;i<=N;i++)
			for(j=1;j<=M;j++)
				if(n[i]!=m[j])ary[i][j] = (ary[i-1][j]>ary[i][j-1])?ary[i-1][j]:ary[i][j-1];
				else ary[i][j] = ary[i-1][j-1]+1;
		printf("%d\n",ary[N][M]);
	}
	return 0;
}
