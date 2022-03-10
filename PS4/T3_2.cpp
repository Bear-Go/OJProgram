/* code below is writen one year ago */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,V,i,j;
LL c[41],v[41];
struct plan
{
    LL sumc,sumv;
};
vector<plan> a,b,aa,bb;
void dfs(LL num,LL sumc,LL sumv,LL total,LL model)
{
    if(num==total)
    {
        struct plan x_plan={sumc,sumv};
        if(sumc<=V)
        {
            if(model==1)
                a.push_back(x_plan);
            if(model==2)
                b.push_back(x_plan);
        }
        sumc+=c[num];
        if(sumc<=V)
        {
            struct plan y_plan={sumc,sumv+v[num]};
            if(model==1)
                a.push_back(y_plan);
            if(model==2)
                b.push_back(y_plan);
        }
        return;
    }
    dfs(num+1,sumc,sumv,total,model);
    dfs(num+1,sumc+c[num],sumv+v[num],total,model);
}

bool comp(const plan &x,const plan &y)
{
    if(x.sumv!=y.sumv)
        return x.sumv>y.sumv;
    else
        return x.sumc<y.sumc;
}

bool compans(const plan &x,const plan &y)
{
    return x.sumc>y.sumc;
}

int main()
{

    cin>>n>>V;
    for(i=1;i<=n;++i)
        cin>>c[i]>>v[i];
    if(n<=20)
    {
        dfs(1,0,0,n,1);
        sort(a.begin(),a.end(),comp);
        LL len=a.size();
        aa.push_back(a[0]);
        for(i=1,j=0;i<len;++i)
            if(a[i].sumc<aa[j].sumc)
            {
                aa.push_back(a[i]);
                ++j;
            }
        cout<<aa[0].sumv<<endl;
    }
    else
    {
        dfs(1,0,0,20,1);
        sort(a.begin(),a.end(),comp);
        LL lena=a.size();
        aa.push_back(a[0]);
        for(i=1,j=0;i<lena;++i)
            if(a[i].sumc<aa[j].sumc)
            {
                aa.push_back(a[i]);
                ++j;
            }

        dfs(21,0,0,n,2);
        sort(b.begin(),b.end(),comp);
        LL lenb=b.size();
        bb.push_back(b[0]);
        for(i=1,j=0;i<lenb;++i)
            if(b[i].sumc<bb[j].sumc)
            {
                bb.push_back(b[i]);
                ++j;
            }
        LL len=bb.size();
        for(i=0;i<len;++i)
        {
            struct plan xy_plan={V-bb[i].sumc,0};
            LL loc=lower_bound(aa.begin(),aa.end(),xy_plan,compans)-aa.begin();
            bb[i].sumc+=aa[loc].sumc;
            bb[i].sumv+=aa[loc].sumv;
        }
        sort(bb.begin(),bb.end(),comp);
        cout<<bb[0].sumv<<endl;
    }
}