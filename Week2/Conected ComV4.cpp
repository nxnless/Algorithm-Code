#include <iostream>
#include <vector>
using namespace std;

struct record{
	int value;
	struct record *next;
};
typedef struct record node;

	vector<int> pass,pred;
	

node *insert(node *head,int input){
	node *tmp;
	if(head == NULL){
		head = new node;
		head->next = NULL;
		head->value = input;
	}else{
		tmp = new node;
		tmp->value = input;
		tmp->next = head;
		head = tmp;
	}
	return head;
}

void DFS_visit(int u , vector<int> adj[]){
	pass[u]=1;
	
	for(int i = 0 ; i < adj[u].size() ;i++){
		int v = adj[u][i];
		if(pass[v] == 0){
			pred[v] = u;
			DFS_visit(v,adj);
		}
	}
	pass[u] = 1;
}

int main(){
	int m,n;
	cin>>n;
	cin>>m;
	int u,v;
	
	vector<int> adj[n+1];
	for(int i = 0 ; i <n+1 ; i++){

		pass.push_back(0);
		pred.push_back(-1);
	}
	for(int i = 0 ; i < m ; i++){
		cin>>u;
		cin>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int Count = 0;
	for(int i = 1 ; i < n+1 ; i++){
			if(pass[i] == 0){
				DFS_visit(i,adj);
				Count++;
			}
	}		
	cout<<Count;
}
