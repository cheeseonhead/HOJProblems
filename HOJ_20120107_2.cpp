/*
Judge: HOJ
PROG: 2
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define test

using namespace std;

map <long long int,long long int> mymap;
map <long long int,long long int> ::iterator it,dt;

void print()
{
	while(it!=mymap.end())
	{
		printf("%d %d\n",it->first,it->second);
		it++;
	}
	puts("---------------");
}

int main()
{
	#ifdef test
	freopen("HOJ_20120107_2.in","r",stdin);
	freopen("HOJ_20120107_2.out","w",stdout);
	#endif
	int data,nn;
	scanf("%d",&data);
	for(int d = 0;d<data;d++)
	{
		scanf("%d",&nn);
		for(int n = 0;n<nn;n++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			mymap[x] = y;
		}
		it = mymap.begin();
		for(int i=0;i<nn-1;i++)
		{
			dt = it;dt++;
			while(dt!=mymap.end()&&dt->first < it->second)
			{ 
				//printf("it fir %d sec %d\ndt first %d sec %d\n",it->first,it->second,dt->first,dt->second);
				if(dt->second > it->second)
				{
					goto endn;
				}
				dt++;
			}
			it++;
		}
		puts("Y");
		continue;
		endn:;
		puts("N");
		mymap.clear();
	}
	return 0;
}
