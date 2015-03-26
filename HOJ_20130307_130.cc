#include <cstdio>

int findPlace(int *cowsee,int height,int cowcnt)
{
	int i;
	for(i=1;i<=cowcnt;i++)
	{
		if(height>=cowsee[i])break;
	}
	return i;
}

int main()
{
//	freopen("HOJ_20130307_130.in","r",stdin);
	int n,cow[80000 + 10],cowcnt=0,cowsee[80000 + 10];
	long long int ans=0;
	scanf("%d",&n);
	cow[0]=1000000001;
	for(int i=1;i<=n;i++)scanf("%d",&cow[i]);
	for(int i=1;i<=n;i++)
	{
		ans+=cowcnt;
		if(cow[i]<cow[i-1]){cowcnt++;cowsee[cowcnt]=cow[i];}
		else
		{
			int p = findPlace(cowsee,cow[i],cowcnt);
			cowcnt=p; cowsee[cowcnt] = cow[i];
		}
//		printf("%d\n",cowcnt);
	}
	printf("%llu\n",ans);
}