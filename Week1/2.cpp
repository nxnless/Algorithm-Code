#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool Si_Sort(pair<int,int> a , pair<int , int > b)
{	
	return a.first < b.first;
}

int main(){
	int n;
	
	cin>>n;
	
	int F , S ;
	vector <pair<int,int> > J;
	
	//Input
	for(int i = 0 ; i < n ; i++){
		cin>> S;
		cin>> F;
		
		J.push_back(make_pair(S,F));
	}
	sort(J.begin() , J.end() , Si_Sort);
	
	int end = J[n-1].second, font = J[n-1].first;
	int aim = J[n-1].first;
	int shot = 1;
	for(int i = n-1 ; i >= 0 ; i--){
		if(J[i].second >= aim){
			font = J[i].first;
		}else{
			shot++;
			aim = J[i].first; 
		}
	}
	
	cout<<shot;
	

}
