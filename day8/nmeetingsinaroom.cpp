 #include<bits/stdc++.h>
 using namespace std;



// N meetings in one room gfg
int findmax(int s[],int e[],int n)
{
	pair<int,int> a[n+1];
	for(int i=0;i<n;i++)
	{
		a[i].first=e[i];
		a[i].second=i;
	}
	sort(a,a+n);
	vector<int> m;
	m.push_back(a[0].second + 1);
	int time=a[0].first;
	for(int i=1;i<n;i++)
	{
		if(s[a[i].second]>time){
		m.push_back(a[i].second+1);
		time=a[i].first;
		}
	}
	return m.size();
}
int main()
{
	int n,i;cin>>n;
	int s[n],e[n];
	for(i=0;i<n;i++) cin>>s[i];
	for(i=0;i<n;i++) cin>>e[i];
	cout<<findmax(s,e,n);
	return 0;
}

