#include <iostream>
#include <vector>
using namespace std;
int find_max(vector<int> n){
	int max = n[0];
	for(int i = 0 ; i<n.size() ; i++){
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
	for(int l ; l<T ; l++){
		int N,L,H;
		cin>>N>>L>>H;
		longest[l].assign(N,9999);
		longest[l][H] = 0;
		for(int i = 0 ; i <L ; i++){
			int u,v,rope,rug;
			cin>>u>>v>>rope;
			rug = longest[l][u] + rope;
			if(	longest[l][u] == 9999){
				longest[l][u] = -9999;
			}else{
				if(rug < longest[l][v]){
					longest[l][v] = rug;
				}
			}
			
		}
	}
	int max[T];

	vector<int> Q[T];
	
//	for(int i = 0 ; i < T ; i++){
//		for(int j = 0 ; j < longest[i].size() ; j++){
//			cout<<j<<" long >> "<<longest[i][j]<<" ";
//		}cout<<endl;
//	}
	
	for(int i = 0 ; i< T ; i++){
		max[i] = find_max(longest[i]);
	}
	
//	cout<<endl;
//	for(int i = 0 ; i<T;i++){
//		cout<<max[i]<<" ";
//	}cout<<endl;
//	
	for(int i = 0 ; i < T ; i++){
		for(int j = 0 ; j<longest[i].size() ; j++ ){
			if(longest[i][j] == max[i]){
				cout<<j<<" ";
			}
		}cout<<endl;
	}
}
