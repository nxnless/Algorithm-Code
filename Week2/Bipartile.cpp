#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<bool> pass;
vector<int> d;
bool BFS(int n, vector<int> adj[] ,int u){
	queue<int> Q;
	Q.push(u);
	d[u] = 0;
	while(!Q.empty()){	
		int U = Q.front();
		Q.pop();
	
		for(int i = 0 ; i<adj[U].size();  i++){
			int V = adj[U][i];
			if(!pass[V]){
				pass[V] = true;
				d[V] = d[U]+1;
				Q.push(V);
			}
			else if(pass[V] == true && d[U] == d[V]){
					return false;
			}
		}
	}
	return true;
}
int main(){
	int m,n;
	cin>>n;
	cin>>m;
	int u,v;
	vector<int> adj[n+1];
	for(int i = 0 ; i < m ; i++){
		cin>>u;
		cin>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0 ; i <n+1 ; i++){
		pass.push_back(false);
		d.push_back(-1);
	
	}
	if(BFS(n,adj,u)){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}
