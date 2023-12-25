#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void MainDuplicate(){
	int n,m,u,v;
	cin>>n>>m;
	n++;
	queue<int> Q,S;
	vector<int> G[n];
	int inD[n];
	for(int i = 1 ; i <n ; i++){
		inD[i]=0;
	}
	for(int i = 0 ; i < m ; i++){
		cin>>u>>v;
		G[u].push_back(v);
		inD[v]++;
	}
	for(int i = 1 ; i < n ; i ++){
		if(inD[i] == 0){
			Q.push(i);
		}
	}
	if(Q.empty()){
		cout<<"NO";
	}else{
		while(S.size() != n ){
		int Ou = Q.front();
			Q.pop();
			S.push(Ou);
			for(int i = 0 ; i <G[Ou].size();i++){
				int ii = G[Ou][i];
				inD[ii]--;
				if(inD[ii] == 0){
					Q.push(ii);
				}
				for(int j = 0 ; j<G[ii].size() ; j++){
					if(G[ii][j] == Ou){
						int jj = G[ii][j];
						G[ii].erase(G[ii].begin()+j);
					}
				}
			}
		}
		while(!S.empty()){
			if(S.front() == 0){
				S.pop();
				continue;
			}else{
				cout<<S.front()<<endl;
				S.pop();	
			}
			
		}
	}
	

}

int main(){
	MainDuplicate();
	return 0;
}
