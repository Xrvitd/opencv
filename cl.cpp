#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
int n,m,k=0;
int a[1001][1001],sum[10010],jd[1001],zdg[1001];
bool v[1001][1001]={0};
int fx[9]={0,1,1,-1,-1,1,-1,0,0};
int fy[9]={0,0,1,1,0,-1,-1,1,-1};
inline int get_num()
{
int num = 0;
char c;
bool flag = false;
while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
if (c == '-') flag = true;
else num = c - '0';
while (isdigit(c = getchar()))
num = num * 10 + c - '0';
return (flag ? -1 : 1) * num;
}
void bl(int x,int y)
{
	//cout<<x<<" "<<y<<endl;
	a[x][y]=k;
	sum[k]++;
	for(int i=1;i<=8;i++)
	{
		int tx=x+fx[i],ty=fy[i]+y;
		if(tx>0&&tx<=n&&ty>0&&ty<=m&&!v[tx][ty]&&a[tx][ty]==255)
		{
			v[tx][ty]=1;
			bl(tx,ty);
		}
	}
	
}
int main()
{
    freopen("out.txt","r",stdin);
	freopen("/webdata/ans.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=get_num();
		}
	}
	
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==255&&!v[i][j])
			{
				k++;
				v[i][j]=1;
				bl(i,j);
			}
		}
	}
	
	
	
	int max=0,now=0;
	for(int i=1;i<=k;i++)
	{
		if(sum[i]>max)
		{
			max=sum[i];
			now=i;
		}
	}
	int zgd,zdd=n;
	bool zgv=0,zdv=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==now)
			a[i][j]=1;
			else
			a[i][j]=0;
			
			if(a[i][j]==1&&zgv==0)
			{
				zgv=1;
				zgd=i;
			}
			
		}
	}
	
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/ 
	
	int maxx=0,fih=n;
	bool vq=0;
	for(int i=1;i<=(n+fih)/2;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if(a[i][j]!=a[i][j-1])
			{
				jd[i]++;
				if(!vq)
				{
					vq=1;
					fih=i;
				}
			}
		}
		zdg[jd[i]]++;
       // cout<<jd[i]<<"\n"; 
		if(jd[i]>maxx)
		{
			maxx=jd[i];
		}
	}
	for(int i=maxx;i>=1;i--)
	{
		if(zdg[i]!=0)
		{
			
			if((i%2==0&&zdg[i]>=((150-fih+1)/15)))
			{
				cout<<i/2;
				break; 
			}
			
		}
	}
	
  
}

