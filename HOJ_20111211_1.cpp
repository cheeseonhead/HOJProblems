#include <cstdio>

int main()
{
	int n;
	g:;
	while(~scanf("%d",&n))
	{
		if(!(n%5)){printf("%d\n",n/5);goto g;}
		if(n<=12 && !n%3){printf("%d\n",n/3);goto g;}
		for(int i=1;i<=4;i++)
			if(n-3*i>=0 && !((n-3*i)%5)){printf("%d\n",i+((n-3*i)/5));goto g;}
		puts("This is Kongming's Trap!!!");
	}
}
