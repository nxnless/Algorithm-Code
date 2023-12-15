#include <iostream>
using namespace std;
struct record{
	int value;
	struct record *next;
};
typedef struct record node;

struct boxed{
	node *hh;
	node *tt;
};
int time = 0;
int pass[8],pred[8],d[8],f[8];
node *adj[8];

struct boxed insert(boxed Box , int input){
	node *head = Box.hh;
	node *tail = Box.tt;

	if(head == NULL && tail ==NULL){
		head = new node;
		head->value = input;
		head->next = NULL;
		tail = head;
	}else{	
		node *tmp;
		tmp = new node;
		tmp->value = input;
		tmp->next = NULL;
		tail->next = tmp;
		tail = tmp;
	}
	Box.hh = head;
	Box.tt = tail;
	return Box;
}

void DFS_visit(int u){
	pass[u]=1;
	d[u] = ++time;
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
	f[u] =++time;
}

int main(){
	int max = 16;
	int b[8];
	struct boxed Box;
	node *link = NULL;
	int re;
	node *p;
	int treeCount = 0;
	int input;
	int select;
	int Mat[8][8];
	int tranMat[8][8];
		int	min = 0;
	int a[8];
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j<8 ; j++){
			Mat[i][j] = 0;
		}
	}
	for(int i = 0 ; i < 8 ; i++){
		pass[i] = 0 ;
		pred[i] = d[i] = f[i] = -1;
	}
	
	for(int i = 0 ; i<8 ; i++){	
			Box.hh = NULL;
			Box.tt = NULL;
				do{
					cin >> input;
							if(input == -1){
								break;
							}else{
								Box = insert(Box,input);
							}
						
						}while(input != -1);
					adj[i] = Box.hh;
				}
	
}
