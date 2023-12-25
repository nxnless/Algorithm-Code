#include <iostream>
#include <queue>
using namespace std;
int Found = 0;
struct box{
	int pass,pred,d,f;	
};
typedef struct box Contain;

Contain DFS_visit(int u,Contain Box, queue<int> Q){
	Box.pass=1;
	Box.d = ++Found;
	p = Box.Q;
	while(p){
		int v = p->value;
		if(pass == 0){
			Box.pred = u;
			DFS_visit(v);
		}
		p = p->next;
	}
	Box.pass = 1;
	Box.f =++Found;
	
	return Box;
}


int main(){
	int m,n;
	cin>>n;
	cin>>m;
	int u,v;
	queue<int> a[n+1];
	Contain Box[n+1];

	
	for(int i = 0 ; i < m ; i++){
		cin>>u;
		cin>>v;
		a[u].push(v);
		a[v].push(u);
	}
	int Count = 0;
	for(int i = 0 ; i < n+1 ; i++){
			if(Box[i].pass== 0){
				Box[i] = DFS_visit(i);
				Count++;
			}
	}
	
}
