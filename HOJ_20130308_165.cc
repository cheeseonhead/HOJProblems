#include <cstdio>

int main()
{
//	freopen("HOJ_20130308_165.in","r",stdin);
	char u,v[3];
	while(~scanf("%c",&u))
	{
		v[0] = v[1];
		v[1] = v[2];
		v[2] = u;
	}
	v[0]-='0';
	v[1]-='0';
	v[2]-='0';
	printf("%d\n",(v[0]*100+v[1]*10+v[2])%8);
}