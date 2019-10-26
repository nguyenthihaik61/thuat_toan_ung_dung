#include<iostream>
using namespace std;
#define MAX 1000000

int N,M;
int a[MAX];
int kq;

void input(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
}

void solve(){
	for(int v=0;v<N;v++){		
		int sum=a[v];
		if(sum<=M){
			kq++;
			for(int j=v+1;j<N;j++){
				sum+=a[j];
				if(sum<=M){
					kq++;
				}else break;
			}
		}
				
		//printf("\nsum=%d\n",sum);
	
					
		
	}
}
int main(){
	kq = 0;
	input();
	solve();
	cout << kq;
	system("pause");
}

