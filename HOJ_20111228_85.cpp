/*
Judge: HOJ
PROG: 85
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
//#define test
using namespace std;

long long int n,maxn,aout,mini,amount;


struct SNAIL
{
	bool operator < (const SNAIL &B)const {if(in==B.in){return out>B.out;}return in>B.in;}
	int in,out;
	SNAIL(){}
}snail[300010];

priority_queue <SNAIL> q;
bool cmp(SNAIL x,SNAIL y)
{
	if(x.out==y.out)return x.in<y.in;
	return x.out<y.out;
}

int main()
{
	#ifdef test
	freopen("HOJ_20111228_85.in","r",stdin);
	freopen("HOJ_20111228_85.out","w",stdout);
	#endif
	scanf("%d",&n);aout = maxn = amount = 0;
	for(int data = 1;data<=n;data++)
		scanf("%d%d",&snail[data].out,&snail[data].in);
	sort(snail+1,snail+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		//printf("%d %d\n",snail[i].out,snail[i].in);
		q.push(snail[i]);
		mini = q.top().in;
		//printf("mini %d\n",mini);
		aout += snail[i].out;
		amount++;
		if(mini*amount>=aout)
		{
			//printf("\taout %d",aout,amount);
			//printf("\tamount %d\n",amount);
			if(maxn < amount)maxn = amount;
		}
		while(amount && mini*amount<aout)
		{
			//printf("\taout %d",aout,amount);
			//printf("\tamount %d\n",amount);
			//printf("\tq.top() out %d in %d\n",q.top().out,q.top().in);
			aout-=q.top().out;
			q.pop();
			amount--;
			if(!amount)break;
			mini = q.top().in;
			//printf("\tmini %d\n",mini);
		}
	}
	printf("%I64d\n",maxn);
	return 0;
}
