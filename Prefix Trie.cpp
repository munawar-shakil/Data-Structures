struct trie{
    int ch[26];
    int en;
};
trie PT[300005];
int sz,k;
void push(char *str)
{
    k=strlen(str);
    int cur=0;
        for(int i=0;i<k;i++)
            {
                if(PT[cur].ch[str[i]-'a']==-1)
                    {
                        PT[cur].ch[str[i]-'a']=++sz;
                        memset(PT[sz].ch,-1,sizeof(PT[sz].ch));
                        PT[sz].en=0;
                    }
                 cur=PT[cur].ch[str[i]-'a'];
            }
            PT[cur].en++;
}
int query(char *str)
{
     int cur=0;
     k=strlen(str);
        for(int i=0;i<k;i++)
            {
                if(PT[cur].ch[str[i]-'a']==-1)
                    {
                       return -1;
                    }
                 cur=PT[cur].ch[str[i]-'a'];
            }
    if(PT[cur].en<=0) return -1;
    return cur;
}
void del(char *str)
{
    //Not yet defined . Can be defined easily with decreasing en of each node.
}
