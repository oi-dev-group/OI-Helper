# include <bits/stdc++.h>
using namespace std;
const int N=100010;
struct node 
{
    node *lson,*rson;
    long long x,lazy;
}t[N<<1],*root=&t[0]; //segment tree's node
int tot=0;
int n,m;
long long a[N]; //sequence

void build(node *root,int l,int r) //build a segment tree
{
    if(l==r) //a only-one-node section
    {
        root->x=a[l];
        return;
    }
    int mid=(l+r)>>1; //mid
    root->lson=&t[++tot];
    root->rson=&t[++tot];
    build(root->lson,l,mid) //build lson
    build(root->rson,mid+1,r); //build rson
    root->x=root->lson->x+root->rson->x; //update root->x
    return;
}

void pushdown(node *root,int l,int r) //update x and lazy
{
    int tag=root->lazy;
    if(tag==0) return;
    int mid=(l+r)>>1;
    root->lson->x+=tag*(mid-l+1); //root->lson->x add the tag multi the len(mid-l+1)
    root->rson->x+=tag*(r-mid); //as above.
    root->lson->lazy+=tag; //root->lson->lazy add the tag
    root->rson->lazy+=tag; //as above.
    root->lazy=0; //clear root->lazy.
    return;
}

void update(node *root,int l,int r,int s,int t,int delta) //update
{
    if(l<=s&&t<=r) //completely contains
    {
        root->x+=delta*(t-s+1); //root->x add the delta multi the len(t-s+1)
        root->lazy+=delta; //root->lazy add the delta
        return;
    }
    pushdown(root,s,t); //update
    int mid=(s+t)>>1; //mid
    if(l<=mid) update(root->lson,l,r,s,mid,delta); //[s,mid] contain the [l,r](some)
    if(r>mid)  update(root->rson,l,r,mid+1,t,delta); //as above.
    root->x=root->lson->x+root->rson->x; //update root->x
    return;
}

long long q_sum(node *root,int l,int r,int s,int t) //query.
{
    if(l<=s&&t<=r) 
    {
        return root->x; //completely contains
    }
    pushdown(root,s,t); //update
    int mid=(s+t)>>1; //mid
    long long ans=0;
    if(l<=mid) ans+=q_sum(root->lson,l,r,s,mid); //[s,mid] contain the [l,r](some)
    if(r>mid)  ans+=q_sum(root->rson,l,r,mid+1,t);//as above
    return ans;
}

int main(void) 
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
    }
    build(root,1,n);
    while(m--) 
    {
        int opt,x,y,k;
        scanf("%d",&opt);
        if(opt==1) 
        {
            scanf("%d%d%d",&x,&y,&k);
            update(root,x,y,1,n,k);
        }
        else
        {
            scanf("%d%d",&x,&y);
            printf("%lld\n",q_sum(root,x,y,1,n));
        }
    }
    return 0;
}
//Luogu segment tree 1