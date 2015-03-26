/*
Judge: HOJ
PROG: 2
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <ctime>
//#define test

using namespace std;

int stke[100001],pnt;

struct POINT
{
	int start,end;
}line[100001];

bool cmp(POINT x,POINT y)
{
	return x.start<y.start;
}

int main()
{
	#ifdef test
	freopen("HOJ_20120107_2.in","r",stdin);
	freopen("HOJ_20120107_2.out","w",stdout);
	#endif
	int dat,nn,maxe;scanf("%d",&dat);
	for(int d=0;d<dat;d++)
	{
		scanf("%d",&nn);
		for(int n = 0;n<nn;n++)
		{
			int x,y;
			scanf("%d%d",&line[n].start,&line[n].end);
		}
		sort(line,line+nn,cmp);maxe = pnt = 0;
		stke[pnt++] = line[0].end;
		for(int i=1;i<nn;i++)
		{
			//pop
			while(stke[pnt-1]<line[i].start && pnt)
				pnt--;
			if(pnt && line[i].start<stke[pnt-1])
			{
				//push
				if(line[i].end<stke[pnt-1])
					stke[pnt++] = line[i].end;
				//overlap found
				else
					goto endn;
			}
			else
			{
				stke[pnt++] = line[i].end;
			}
		}
		puts("Y");
		continue;

		endn:;
		puts("N");
	}
	return 0;
}
