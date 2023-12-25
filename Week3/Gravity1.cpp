#include <iostream>
#include <vector>
using namespace std;
struct hellTree{
	vector<int> value;
	int Hgt;
	struct hellTree *left;
	struct hellTree *Right;
};

typedef struct hellTree node;

vector<int> H_PtC;
int hh;
node *insert(node *tree , int parent ,int input , int height , node *pa){

	if(tree == NULL){
		tree = new node;
		tree->value.push_back(input);
		tree->Hgt = height;
		tree->left = NULL;
		tree->Right = NULL;
		tree->P = NULL;
	}else{
		if(height > tree->Hgt){
			hh = tree->Hgt+height;
			if(hh < H_PtC[input]){
				H_PtC[input] = hh;
			}
			tree->Right = insert(tree->Right , parent , input , height);
		}else{
			hh = tree->Hgt+height;
			if(hh < H_PtC[input]){
				H_PtC[input] = hh;
			}
			tree->left = insert(tree->left , parent , input , height);
		}
	}
}  

int main(){
	int T,N,E,H;
	cin>>T;
	int u,v,height;
	node *tree[T];

	for(int O = 0 ; O < T ; O++){
		tree[O] =NULL;
		N>>E>>H;
		H_PtC.assign(N,0);
		insert(tree[O] , H , H , 0 );
		for(int i = 0 ; i < E ; i++){
			hh = 0;
			cin>>u>>v>>height;
			tree[O] = insert(tree[O] , u, v , height);
		}
	}
}
