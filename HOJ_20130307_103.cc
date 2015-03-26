#include<cstdio>

int main()
{
//	freopen("HOJ_20130307_103.in","r",stdin);
	int k,n,m;
	scanf("%d",&k);
	while(k)
	{
		scanf("%d %d",&n,&m);k--;
		if(!(m%2))m--;
		if(m==n)m-=2;
		for(int i=m;i>0&&n>0;i-=2)
		{
			if(n<i){i=n+(n%2)-1;}
//			printf("n=%d i=%d\n",n,i);
			if(n-i==2)continue;
			n-=i;
		}
		if(n==0)printf("YES\n");
		else printf("NO\n");
	}
}