#include<iostream>
#include<algorithm>

using namespace std;
struct dp2{
	int x,y;
	int index;
	int r;
	bool operator<(dp2& a){ 	//This operator is crucial
		if(x!=a.x)return x<a.x;
		return y>a.y;
	}
};
dp2 MergeArr[10005];
dp2 OriArr[10005];
void Merge(int f,int m,int l)
{
	int id1=f,id2=m+1;
	int d=0,top=0;
	while(id1<=m && id2<=l)
	{
		if(OriArr[id1].y<OriArr[id2].y)
		{
			MergeArr[top++]=OriArr[id1++];
			d++;
		}
		else
		{
			MergeArr[top++]=OriArr[id2++];
			MergeArr[top-1].r+=d;
		}
	}
	while(id1<=m)MergeArr[top++]=OriArr[id1++];
	while(id2<=l)MergeArr[top++]=OriArr[id2++],MergeArr[top-1].r+=d;
	
	for(int i=0;i<top;i++)//the merge result must back to OriArr 
	{
		OriArr[f++]=MergeArr[i];
	}
}
void Ranking(const int f, const int l)
{
	if(f>=l)return;
	int m=(f+l)/2;
	Ranking(f,m);
	Ranking(m+1,l);
	Merge(f,m,l);
}
int main()
{
	int n;
	int o[10005];
	while(cin>>n)
	{
		for(int i=0;i<10005;i++)
		OriArr[i].r=0;
		for(int i=0;i<n;i++)
	{
		cin>>OriArr[i].x>>OriArr[i].y;
		OriArr[i].index=i;
	}
	sort(OriArr,OriArr+n);
	Ranking(0,n-1);
	for(int i=0;i<n;i++)
		o[OriArr[i].index]=OriArr[i].r;//crucial
		
	for(int i=0;i<n;i++)
		cout<<o[i]<<endl;
	}
	return 0;
}
