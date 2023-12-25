//Nonthakan Pimsan
//6530300287

// 	print 1 7 -1 2 7 -1 5 -1 4 -1 5 -1 -1 7 -1 -1 -1
		
		
		/*
		0 1 7 -1 
		1 2 7 -1 
		2 5  -1 
		3 4 -1 
		4 5 -1 
		5 -1 
		6 7 
		7 -1 
		8 -1 
		9 -1
		*/
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

typedef struct suapha Suit;

int Found = 0;
int pass[9],pred[9],d[9],f[9];
node *adj[9];

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


node *createStack(){
	node *S;
	S = new node;
	if(S == NULL){
		cout<<"Out of space!!!"<<endl;//if non Space to reserve in memorie will print this massage
	}
	S->next = NULL;
	return S;
}

void push(node *S, int input){
	node *tmp;
	tmp = new node;
	if(S==NULL || tmp == NULL){
		if(S == NULL){
			cout<<"Non space to reserve stack"<<endl;
		}
		if(tmp == NULL){
			cout<<"Non space to reserve new data"<<endl;
		}
	}
	else{
		tmp->value = input;
		tmp->next = S->next; //Push move like insert only font in linked list 
		//but first node is non value and REAL first node is node->next
		//S->next like head
		S->next = tmp;	
	}
}

bool isEmpty(node *S){
	return S->next ==NULL;
}

void pop(node *S){
	node *tmpDelete;
	if(isEmpty(S)){
		cout<<"Stack is empty"<<endl;
	}else{
		tmpDelete = S->next;
		S->next = S->next->next;
		delete tmpDelete;
	}
}

int top(node *S){
	return	S->next->value;
}


void menu(){
	cout<<"===========MENU=========="<<
	endl<<"1) Insert Graph"<<
	endl<<"2) DFS"<<
	endl<<"3) Exit"<<
	endl<<"Please choose >";
}

void printl(struct record *head){
	struct record *p;
	p = head;
	while(p){
		cout<<p->value<<" ";
		p = p->next;
	}
}

void printAr9(int a[9]){
	for(int i = 0 ; i<9 ; i++){
		cout<< a[i] <<" ";
	}
}

int Top(node *head){
	return head->value;
}
node *S = createStack();
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

void ReverseStack(node *SOri,node *SNew){
	
	while(SOri->next != NULL){//Reverse
		push(SNew , top(SOri));
		pop(SOri);
	}

}
//DFS _ sort by f[u]
void printTG(node *S){
	//   	1 7 -1 2 7 -1 5 7 -1 4 -1 5 -1 -1 7 -1 -1 -1
	
	string suit[9] = {"Undershort","Pant","Belt","Shirt","Tie","Jacket","Socks","Shoes","Watch"};
	node *SN = createStack();
	int max = 18;
	int i =0;
 
	do{
		if(d[i]==max){
			max--;
			i=-1;
		}else if(f[i]==max){
			push(S,i);
			max--;
			i=-1;
		}
		i++;
	}while(max!=0);
	ReverseStack(S,SN);
	while(!isEmpty(SN)){
		cout<<suit[top(SN)]<<" ";
		pop(SN);
	}cout<<endl;
}

int main(){
	// 	print 1 7 -1 2 7 -1 5 7 -1 4 -1 5 -1 -1 7 -1 -1 -1
	struct boxed Box;

	int input;
	int select;
	for(int i = 0 ; i < 9 ; i++){
		pass[i] = 0 ;
		pred[i] = d[i] = f[i] = -1;
	}
	
	do{
		menu();
		cin>>select;
		switch(select){
			case 1:
				for(int i = 0 ; i<9 ; i++){	
					Box.hh = NULL;
					Box.tt = NULL;
					cout<<"Enter #"<<i<<" : ";
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
				break;
			case 2:
				int u;
				int treeCount = 0;
				cout<<"Input source vertex : ";
				cin >> u ;
				DFS_visit(u);
				treeCount++;
				for(int i = 0 ; i < 9 ; i++){
					if(pass[i]== 0){
						DFS_visit(i);
						treeCount++;
					}
				}
				
				cout<<"Trees = "<<treeCount<<endl;
				cout<<"d : ";
			
				printAr9(d);
				cout<<endl;
				
				cout<<"f : ";
				printAr9(f);
				cout<<endl;

				cout<<"pred : ";
				printAr9(pred);
				cout<<endl;
	
				printTG(S);
				break;
		}
	}while(select != 5);
}
