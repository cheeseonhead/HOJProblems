/*
Judge: HOJ
PROG: 34
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define test
using namespace std;

int brd[20][20],n,x,y,b,ans;

int main()
{
	#ifdef test
	freopen("HOJ_20120119_34.in","r",stdin);
	freopen("HOJ_20120119_34.out","w",stdout);
	#endif
	while(~scanf("%d",&n))
	{
		ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&x,&y,&b);
			brd[x][y] = b;
			ans++;
		}
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&x,&y,&b);
			ans+=(brd[x][y]==b)?-1:1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
