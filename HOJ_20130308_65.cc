#include <cstdio>

int main()
{
	freopen("HOJ_20130308_65.in","r",stdin);
	int dis[101][101]={},n,m,q,disrd[101][101]={};
	bool rdc[10001]={};
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		if(dis[u][v]>w || !dis[u][v])
		{
			dis[u][v]=dis[v][u]=w;
		}
		for(int j=1;j<=n;j++)
		{	
			if(j==u){dis[u][u]=-1;continue;}
			if(j==v){dis[v][v]=-1;continue;}
			if(dis[u][j]>0 && (dis[u][j]+w<dis[v][j] || !dis[v][j]))
			{	
				dis[v][j]=dis[j][v]=dis[u][j]+w;
			}
		}
		for(int j=1;j<=n;j++)
		{	
			if(j==u){dis[u][u]=-1;continue;}
			if(j==v){dis[v][v]=-1;continue;}
			if(dis[v][j]>0 && (dis[v][j]+w<dis[u][j] || !dis[u][j]))
			{	
				dis[u][j]=dis[j][u]=dis[v][j]+w;
			}
		}
	}

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		printf("dis[%d][%d]=%d\n",i,j,dis[i][j]);
		
	for(int i=1;i<=q;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
//		printf("dis[u][v] = %d w = %d\n",dis[u][v],w);
		if(w<dis[u][v])
		{
			rdc[disrd[u][v]]=0;
			disrd[u][v]=disrd[v][u]=i;
//			printf("disrd[u][v] = %d\n",disrd[u][v]);
			dis[u][v]=dis[v][u]=w;
			rdc[i]=1;
		}
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",rdc[i]);
}