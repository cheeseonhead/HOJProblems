#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int main()
{
    long long int n,m;
    scanf("%I64d%I64d",&n,&m);
        if(n==1 || m==1){printf("%I64d.00\n",2*n*m-2);return 0;}
        printf("%I64d",n*m);
        if(n%2&&m%2)
            puts(".41");
        else
            puts(".00");
    return 0;
}
