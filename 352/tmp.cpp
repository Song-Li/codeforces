#include <bits/stdc++.h>
/*#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
 */
using namespace std;
#define Riep(n) for(int i=1;i<=n;i++)
#define Riop(n) for(int i=0;i<n;i++)
#define Rjep(n) for(int j=1;j<=n;j++)
#define Rjop(n) for(int j=0;j<n;j++)
#define mst(ss,b) memset(ss,b,sizeof(ss));
typedef long long LL;
const LL mod=1e9+7;
const double PI=acos(-1.0);
const int inf=0x3f3f3f3f;
const int N=1e5+25;
double fun(double xx,double yy,double fx,double fy)
{
    return sqrt((xx-fx)*(xx-fx)+(yy-fy)*(yy-fy));
}
double ax,ay,bx,by,tx,ty,x[N],y[N],dis[N],disa[N],disb[N];
int n;
int main()
{
    scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&tx,&ty);
    scanf("%d",&n);
    double ans=0;
    Riep(n)
    {
        scanf("%lf%lf",&x[i],&y[i]);
        dis[i]=fun(x[i],y[i],tx,ty);
        disa[i]=fun(x[i],y[i],ax,ay);
        disb[i]=fun(x[i],y[i],bx,by);
        ans+=2*dis[i];
    }
    disa[0]=0;
    disb[0]=0;
    dis[0]=0;
    double mmina=999999999999999,mminb=99999999999999,s=ans;
    double sea,seb;
    int posa=0,posb=0;
    for(int i=1;i<=n;i++)
    {
        if(disa[i]-dis[i]<mmina)
        {
            sea = mmina;
            mmina=disa[i]-dis[i];
            posa=i;
        }
        if(disb[i]-dis[i]<mminb)
        {
            seb = mminb;
            mminb=disb[i]-dis[i];
            posb=i;
        }
    }
    if(mmina<0&&mminb<0)
    {
        if(posa==posb)
        {
            for(int i=0;i<=n;i++)
            {
                if(i!=posa)
                    s=min(s,ans+mmina-dis[i]+disb[i]);
            }
            for(int i=0;i<=n;i++)
            {
                if(i!=posb)
                    s=min(s,ans+mmina-dis[i]+disa[i]), cout << disa[i] - dis[i] << endl;
            }
            cout << mminb << ' ' << dis[posb] - disb[posb] << endl;
            cout << sea << ' ' << seb << endl;
        }
        else
        {
            s=ans+mmina+mminb;
        }
    }
    else
    {
        if(mmina<mminb)
        {
            s=ans-dis[posa]+disa[posa];
        }
        else
        {
            s=ans-dis[posb]+disb[posb];
        }
    }
    printf("%.10lf\n",s);
    return 0;
}
