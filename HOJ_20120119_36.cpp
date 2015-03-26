/*
Judge: HOJ
PROG: 36
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define test
#define R 20
#define C 19
using namespace std;

int stk1[362],brd1[20][20];
int bd1,bd2,r,c,b,ans;

int main()
{
	#ifdef test
	freopen("HOJ_20120119_36.in","r",stdin);
	freopen("HOJ_20120119_36.out","w",stdout);
	#endif
	while(~scanf("%d",&bd1))
	{
		ans=0;
		//input first board
		for(int i=0;i<bd1;i++)
		{
			scanf("%d%d%d",&r,&c,&b);
//			printf("BD1#%d   r c b \n\t\t%d %d %d\n",i,r,c,b);
			stk1[i]=r*R + c;
			brd1[r][c]=b?1:-1;
		}
		//input seconde board
		scanf("%d",&bd2);
		for(int i=0;i<bd2;i++)
		{
			scanf("%d%d%d",&r,&c,&b);
			
			//white as -1 black as 1
			b=b?1:-1;
			
//			printf("BD2#%d   r c b \n\t\t%d %d %d\n",i,r,c,b);
//			printf("\tbrd1[%d][%d] %d b %d\n",r,c,brd1[r][c],b);
			
			//find difference between boards
			ans+=(brd1[r][c]>b)?brd1[r][c]-b:b-brd1[r][c];
			
//			printf("\tans %d\n",ans);

			//init that point on first board
			brd1[r][c]=0;
		}
		//check first board
		for(int i=0;i<bd1;i++)
		{
			
//			printf("%d %d %d\n",stk1[i]/R,stk1[i]%R,brd1[stk1[i]/R][stk1[i]%R]);

			//if not 0 then +1
			ans+=(brd1[stk1[i]/R][stk1[i]%R])?1:0;
			//init point
			brd1[stk1[i]/R][stk1[i]%R]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
