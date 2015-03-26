/*
Judge: HOJ
PROG: 2
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <ctime>
#define test

using namespace std;

//map <long long int,long long int> end,line;
//map <long long int,long long int> ::iterator it,dt,kt;
int stk[100001],pnt;

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
	int dat,nn;scanf("%d",&dat);
	for(int d=0;d<dat;d++)
	{
		scanf("%d",&nn);
		for(int n = 0;n<nn;n++)
		{
			scanf("%d%d",&line[n].start,&line[n].end);
		}
		puts("Y");
	}
	return 0;
}
