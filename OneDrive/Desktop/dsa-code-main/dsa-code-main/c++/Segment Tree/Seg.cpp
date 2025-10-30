//Sum of query(SEGMENT TREE)

#include<iostream>
using namespace std;

int a[20],seg[4*20];

//To build the segment tree
void build(int ind,int low,int high)
{
    if(low==high)
    {
        seg[ind]=a[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

int query(int ind,int low,int high,int l,int r)
{
    if(low>=l && high<=r)   //Query inside range
        return seg[ind];
    if(high<l || low>r)     //Query outside range
        return 0;           //use INT_MIX->max  INT_MAX->min  product->1
    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);
    return left+right;
}

//To update single index
void update(int ind,int low,int high,int i,int val)
{
    if(low==high)
    {
        seg[ind]=val;
        return;
    }
    int mid=(low+high)/2;
    if(i<=mid)
        update(2*ind+1,low,mid,i,val);
    else
        update(2*ind+2,mid+1,high,i,val);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

int main()
{
    int n;
    cout<<"Enter array size:"<<endl;
    cin>>n;
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    build(0,0,n-1); //to build the segment tree
    int q;
    cout<<"Enter query:"<<endl;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<"SUM from the query ("<<l<<"-"<<r<<") is: "<<query(0,0,n-1,l,r)<<endl;
        int x,val;
        cout<<"Enter the index and value to update :"<<endl;
        cin>>x>>val;
        update(0,0,n-1,x,val);
        cout<<"Sum after updatetion: "<<query(0,0,n-1,l,r)<<endl;
    }
    return 0;
}
