/*
Judge: HOJ
PROG: 34
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
//#define test
using namespace std;

int N,x,height,stk[250000],pnt,ans;

int main()
{
	#ifdef test
	freopen("HOJ_20120119_34.in","r",stdin);
	freopen("HOJ_20120119_34.out","w",stdout);
	#endif
	while(~scanf("%d",&N))
	{
		pnt=ans=0;
		for(int data=0;data<N;data++)
		{
			scanf("%d%d",&x,&height);
			while(height<stk[pnt-1])pnt--;
			if(height>stk[pnt-1])
			{
				stk[pnt++]=height;
				ans++;
			}
		}
		printf("%d",ans);
	}
	return 0;
}
