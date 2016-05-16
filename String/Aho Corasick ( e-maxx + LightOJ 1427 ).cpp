//It is not time efficient .
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define fr first
#define sc second
#define  LL   long long
#define inf 1<<29
#define mod 1000000007
#define LSOne(a) (a&(-a))
#define maxL  250010
inline bool cmp(const pii &p, const pii &q) { return (p.fr == q.fr)? p.sc > q.sc : p.fr > q.fr; }
struct node
{
    int next[26];
    bool leaf;
    int p;
    int len;
    char pch;
    int link;
    int go[26];
};
node t[maxL];
int sz;
void init()
{
    t[0].p=t[0].link=-1;
    t[0].len=0;
    memset(t[0].next,-1,sizeof t[0].next);
    memset(t[0].go,-1,sizeof t[0].go);
    sz=1;
}

void add_string(char *str)
{
    int v=0;
    int z=strlen(str);
    for(int i=0;i<z;i++)
    {
        int c=(int)(str[i]-'a');
        if(t[v].next[c] == -1)
        {
            memset(t[sz].next,-1,sizeof(t[sz].next));
            memset(t[sz].go,-1,sizeof(t[sz].go));
            t[sz].link=-1;
            t[sz].p=v;
            t[sz].len=t[v].len+1;
            t[sz].pch=c;
            t[v].next[c]=sz++;
        }
        v=t[v].next[c];
    }
    t[v].leaf=true;
    return ;
}

int go(int v,int c);
int get_link(int v){
    if(t[v].link== -1)
    {
        if(v==0 || t[v].p==0)
            t[v].link=0;
        else
            t[v].link=go(get_link(t[v].p),t[v].pch);
    }
  return t[v].link;
}

int go(int v,int c)
{
    if(t[v].go[c]==-1)
    {
        if(t[v].next[c]!=-1)
            t[v].go[c]=t[v].next[c];
        else
            t[v].go[c]= (v==0)?0:go(get_link(v),c);
    }
    return t[v].go[c];
}

int b[maxL];
pair<int,int> AA[maxL];
char Str[1000005];
int main()
{
    int T,I=1;
    cin>>T;
    int n;
    while(T--)
    {
        printf("Case %d:\n",I++);
        scanf("%d",&n);
        char pattern[n][502];
        init();
        scanf("%s",Str);
        for(int i=0;i<n;i++)
            {
                scanf("%s",pattern[i]);
                add_string(pattern[i]);
            }
    for(int i=0;i<sz;i++)        AA[i]=make_pair(t[i].len,i);
    sort(AA,AA+sz,cmp);
    for(int i=0;i<sz;i++)        b[i]=AA[i].sc;
    for(int i=sz-1;i>=0;i--) get_link(b[i]);
//    for(int  i=0;i<sz;i++)        printf("%d %d\n",i,t[i].link);
    vi ans(sz+1,0);
    int z=strlen(Str);
    int p=0;
    for(int i=0;i<z;i++)
        {
            int c= (int)(Str[i]-'a');
            while(p>0 && t[p].next[c]==-1)
                p=t[p].link;
            if(p==-1) p=0;
            else
            {
                p=t[p].next[c];
                ans[p]++;
            }
        }
   // for(int  i=0;i<sz;i++)        printf("%d %d\n",i,b[i]);
        for(int i=0;i< sz-1;i++)
            ans[t[b[i]].link]+=ans[b[i]];
        for(int i=0;i<n;i++)
        {
            p=0;
            int z1=strlen(pattern[i]);
            for(int j=0;j<z1;j++)
                p=t[p].next[(int)(pattern[i][j]-'a')];
            printf("%d\n",ans[p]);
        }
    }
    return 0;
}
