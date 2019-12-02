#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#define MAX_N 100001
using namespace std;
int N, M;
int s, t;
int p[MAX_N], d[MAX_N];
vector<int> A[MAX_N], W[MAX_N], Fixed, NonFixed;

void input()
{
	
	cin >> N >> M;
	int u, v, w;
	for (int i = 1; i <= N; i++)
	{
		d[i] = 10000000;
	}
	
	for (int i = 1; i <=M ; i++)
	{
		cin >> u >> v >> w;
		//if (u == s) d[v] = w;
		A[u].push_back(v);
		W[u].push_back(w);
	
	}
	cin >> s >> t;
	for (int i = 0; i < W[s].size(); i++)
	{
		d[A[s][i]] = W[s][i];
	}
	
	d[s] = 0;
	for (int i = 1; i <= N; i++)
	{
		
		p[i] = s;
		if (i != s)
			NonFixed.push_back(i);
	}
}
void init()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		d[i] = 10000000;
		p[i] = s;
		if(i!=s) 
			NonFixed.push_back(i);
	}
}
void solve()
{
	
	input();
	int minu = 0, dminu = 0;
	while (!NonFixed.empty())
	{
		minu = 0;
		for (int i = 1; i < NonFixed.size(); i++)
		{
			if (d[NonFixed[i]] < d[NonFixed[minu]])
			{
				minu = i;

			}
		}
		
		dminu = d[NonFixed[minu]];
	
		int nodeminu = NonFixed[minu];
		Fixed.push_back(NonFixed[minu]);
		NonFixed.erase((NonFixed.begin()+minu));
	

		for (int i = 0; i < NonFixed.size(); i++)
		{
			for (int j = 0; j < A[nodeminu].size(); j++)
			{
				if (A[nodeminu][j] == NonFixed[i])
				{
					if (d[NonFixed[i]] > d[nodeminu] + W[nodeminu][j])
					{
						
						d[NonFixed[i]] = d[nodeminu] + W[nodeminu][j];
						p[NonFixed[i]] = nodeminu;
					
						
					}
					break;
				}
			}
			
		}
	}
}
int main()
{

	freopen("input.txt", "r", stdin);
	solve();
	cout << "t=" << t << endl;
	cout << d[t] << endl;
	return 0;
}