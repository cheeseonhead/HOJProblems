/*
Judge: HOJ
PROG: 8
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define test
#define INF 2147483647
using namespace std;
 
int maxid,n;
 
int main()
{
    #ifdef test
    freopen("HOJ_20120114_8.in","r",stdin);
    freopen("HOJ_20120114_8.out","w",stdout);
    #endif
    while(~scanf("%d",&n))
    {
        maxid=0;
        bool b[300001] = {1};
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if(b[x+1]&&x<n){if(maxid<x)maxid=x;}
            b[x] = 1;
        }
        printf("%d\n",maxid);
    }
    return 0;
}
