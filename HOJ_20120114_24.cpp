/*
Judge: HOJ
PROG: 24
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
//#define test
#define INF 100
using namespace std;

int dat,m,n,i,j,ans,flag,avis[10],deadn[16],deadid[16][10];

struct Ele{int x,y,r;}bom[16],eny[10];

void dfs(int bomb,int bn,int kill)
{
	int tvis[10] = {};
	if(bn>ans)return;
	int i,j;
	memset(tvis,0,sizeof(tvis));
	for(i=0;i<deadn[bomb];i++)
		if(!avis[deadid[bomb][i]])
		{
			avis[deadid[bomb][i]] = tvis[deadid[bomb][i]] = 1;
			kill++;
		}
	if(kill==n && ans>bn){flag=1;ans=bn;goto reset;}
	for(i=bomb+1;i<m;i++)dfs(i,bn+1,kill);
	reset:;
	for(i=0;i<9;i++)
	if(tvis[i])avis[i]=0;
	return;
}	

int main()
{
	#ifdef test
	freopen("HOJ_20120114_24.in","r",stdin);
	freopen("HOJ_20120114_24.out","w",stdout);
	#endif
	scanf("%d",&dat);
	while(dat--)
	{
		//input & init
		scanf("%d%d",&m,&n);memset(deadn,0,sizeof(deadn));ans = INF;memset(avis,0,sizeof(avis));
		for(i=0;i<m;i++)scanf("%d%d%d",&bom[i].x,&bom[i].y,&bom[i].r);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&eny[i].x,&eny[i].y,&eny[i].r);
			//bombing id
			for(j=0;j<m;j++)
			{
				int disx = bom[j].x-eny[i].x,disy = bom[j].y-eny[i].y,dish = bom[j].r+eny[i].r;
				if(disx*disx + disy*disy <= dish*dish)deadid[j][deadn[j]++] = i;
			}
		}
		//search
		for(i=flag=0;i<m;i++)
			dfs(i,1,0);
		if(!flag)printf("Impossible\n");
		else{printf("%d\n",ans);}
	}
	return 0;
}
