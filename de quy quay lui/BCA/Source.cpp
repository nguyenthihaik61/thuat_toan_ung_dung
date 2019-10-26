#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define max_n 50
#define max_m 10

int n; //number of class
int m;//number of teacher
int sz[max_n];// sz[i] is the number of teacher for course i
int t[max_n][max_m];// t[c][i] the ith teacher can teach coure c
int h[max_n];// h[c] is the number of hours of course c each week
int a[max_n][max_n]; // conflict matrix

int x[max_n];//x[i] is the teacher assigned to course i
int f[max_m];//f[i] is the load of teacher i
int f_best;//best objective value

void input(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++){
		cin >> sz[i];
		for (int j = 0; j< sz[i]; j++) cin >> t[i][j];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
}

int check(int v, int k){
	for (int i = 1; i <= k - 1; i++){
		if (a[i][k] && v == x[i]) return 0;
	}
	return 1;
}
void solution(){
	int max = 0;
	for (int i = 1; i <= m; i++){
		if (max<f[i]) max = f[i];
	}
	if (max<f_best) f_best = max;
}
void TRY(int k){// tim gv V cho mon K
	for (int i = 0; i<sz[k]; i++){
		int v = t[k][i];
		if (check(v, k)){
			x[k] = v;
			f[v] += h[k];
			if (k == n) solution();
			else TRY(k + 1);
			f[v] -= h[k];
		}
	}
}



void solve(){
	f_best = 1000000;
	for (int i = 1; i <= m; i++){
		f[i] = 0;
	}
	TRY(1);
	if (f_best == 1000000) cout << -1;
	else cout << f_best;
}
int main(){
	freopen("input.txt", "r", stdin);
	input();
	solve();
}