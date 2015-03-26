/*
Judge: HOJ
PROG: 29
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
//#define test
using namespace std;

char c;
int ary[1000001],n,p,q,x,y,ans,val,low;

int main()
{
	#ifdef test
	freopen("HOJ_20120411_29.in","r",stdin);
	freopen("HOJ_20120411_29.out","w",stdout);
	#endif
	
	//intput
	while(~scanf("%d %d %d %d %d ",&n,&p,&q,&x,&y))
	{
	
		//init
		ans = low = 0;val = p;
		
		//ary
		for(int i=0;i<n;i++)
		{
			c=getchar();
			switch(c)
			{
				case '+':ary[i]=1;break;
				case '-':ary[i]=-1;break;
			}
			val+=ary[i];
			if(low>val)low = val;
		}
		
		//algor
		if(val>=q)
		{
			int t = n-1;
			while(low<0)
			{
				low+=ary[t--];
				ans+=y;
			}
			ans+=((val-q)/2)*x;
		}
		else if(val<q)
		{
			ans+=((q-val)/2)*x;
			low+=q-val;
			int t = n-1;
			while(low<0)
			{
				low+=ary[t--];
				ans+=y;
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
