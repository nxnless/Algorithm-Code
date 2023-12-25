void PrintG(vector<int> G[] , int n){
		for(int i = 0 ; i < n ; i++){
		cout<<"#"<<i<<" ";
		for(int j = 0 ; j<G[i].size() ; j++ ){
			cout<<G[i][j]<<" ";
		}cout<<endl;
	}
	
}
