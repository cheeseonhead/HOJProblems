/*
Judge: HOJ
PROG: 50
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
//#define test
using namespace std;

int N,line[65001],a[65001],b[65001],t,pnta,pntb;
bool stat[65001];
char m;

int main()
{
	#ifdef test
	freopen("HOJ_20120224_50.in","r",stdin);
	freopen("HOJ_20120224_50.out","w",stdout);
	#endif
	
	while(~scanf("%d",&N))
	{
		memset(stat,0,sizeof(stat));
		pnta = pntb = 0;
		for(int i=0;i<N;i++)
		{
			int x;
			scanf("%d",&x);
			line[i] = x;
		}
		while(~scanf("%c",&m))
		{
			if(m=='A')
			{
				scanf("%d",&t);
				a[pnta++] = t;
				stat[t] = true;
			}
			else if(m=='B')
			{
				scanf("%d",&t);
				b[pntb++] = t;
				stat[t] = true;
			}
			else if(m=='C')
				break;
		}
		printf("%d",a[pnta-1]);
		for(int i=pnta-2;i>=0;i--)
			printf(" %d",a[i]);
		for(int i=0;i<N;i++)
			if(!stat[line[i]])printf(" %d",line[i]);
		for(int i=0;i<pntb;i++)
			printf(" %d",b[i]);
		puts("");
	}
	return 0;
}
