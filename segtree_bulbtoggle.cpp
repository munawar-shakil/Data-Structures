class St{
    public:
vi  toggle;
vi on;
void Pro(int at,int L,int R)
{
    int mid= (L+R)/2;
    int left=at*2;
    int right=at*2 +1;
    toggle[at]=0;
    toggle[left] ^=1;
    toggle[right] ^=1;
    on[left]=mid-L+1 -on[left];
    on[right]=R-mid -on[right];
}
void update(int at,int L,int R,int l,int r)
{
    if(r<L   || R<l) return ;
    if(l<=L && R<=r){
        toggle[at]^=1;
        on[at]=R-L+1-on[at];
        return ;
    }
    if(toggle[at]) Pro(at,L,R);
    int mid=(L+R)/2;
    update(at*2,L,mid,l,r);
    update(at*2    +1,mid+1,R,l,r);
    on[at]=on[at *2] +on[at*2  +1];
    return ;
}

int query(int at,int L,int R,int l,int r)
{
    if(r<L || R< l) return 0;
    if(l <=L && R<=r) return on[at];
    if(toggle[at]) Pro(at,L,R);
    int mid=(L+R)/2;
    int x=query(at*2,L,mid,l,r);
    int y=query(at*2    +1,mid+1,R,l,r);
    //on[at]=on[at *2] +on[at*2  +1];
    return x+y;
}
 St(int a)
{
   toggle.assign(4*a +1,0);
   on.assign(4*a +1,0);
}
};
