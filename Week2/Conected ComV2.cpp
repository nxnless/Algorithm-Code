#include <iostream>
using namespace std;

struct record{
	int value;
	struct record *next;
};
typedef struct record node;

	int Found = 0;

	int pass[1000000],pred[1000000],d[1000000],f[1000000];
	node *adj[100000];


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

void DFS_visit(int u){
	pass[u]=1;
	d[u] = ++Found;
	node *p = adj[u];
	while(p){
		int v = p->value;
		if(pass[v] == 0){
			pred[v] = u;
			DFS_visit(v);
		}
		p = p->next;
	}
	pass[u] = 1;
	f[u] =++Found;
}

int main(){
	int m,n;
	cin>>n;
	cin>>m;
	int u,v;
	
	for(int i = 0 ; i <n+1 ; i++){
		adj[i] = NULL;
		pass[i] = 0 ;
		pred[i] = d[i] = f[i] = -1;
	}
	for(int i = 0 ; i < m ; i++){
		cin>>u;
		cin>>v;
		adj[u] = insert(adj[u] , v);
		adj[v] = insert(adj[v] , u);
	}
	int Count = 0;
	for(int i = 1 ; i < n+1 ; i++){
			if(pass[i] == 0){
				DFS_visit(i);
				Count++;
			}
	}		
	cout<<Count;
}
