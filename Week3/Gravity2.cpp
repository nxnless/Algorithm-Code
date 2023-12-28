#include <iostream>
#include <vector>
using namespace std;
int find_max(vector<int> n){
	int max = n[0];
	int size = n.size();
	for(int i = 0 ; i<size ; i++){
		if(n[i] > max){
			max = n[i];
		}
	}
	return max;
}

int main(){
	int T;
	cin>>T;
	vector<int> longest[T];
	vector<bool> is_Connect[T];
	for(int j ; j<T ; j++){
		int N,L,H;
		cin>>N>>L>>H;
		is_Connect[j].assign(N,false);
		longest[j].assign(N,9999);
		longest[j][H] = 0;
		is_Connect[j][H] = true;
		for(int i = 0 ; i <L ; i++){
			int u,v,rope,rug;
			cin>>u>>v>>rope;
				if(is_Connect[j][u] = true){
					rug = longest[j][u] + rope;
					if(rug < longest[j][v]){
						longest[j][v] = rug;
					}
				}	
		}
	}
	
	int max[T];
	for(int i = 0 ; i< T ; i++){
		max[i] = find_max(longest[i]);
	}
	
//	for(int i = 0 ; i < T ; i++){
//		for(int j = 0 ; j < longest[i].size() ; j++){
//			cout<<j<<" long >> "<<longest[i][j]<<" ";
//		}cout<<endl;
//	}
	
	for(int i = 0 ; i< T ; i++){
		max[i] = find_max(longest[i]);
	}
	for(int i = 0 ; i < T ; i++){
		for(int j = 0 ; j<longest[i].size() ; j++ ){
			if(longest[i][j] == max[i]){
				cout<<j<<" ";
			}
		}cout<<endl;
	}
	
	return 0;
}
