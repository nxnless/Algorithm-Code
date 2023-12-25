#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int m,n;
    cin>>n;
    cin>>m;
    int u,v;
    bool Is_biparti = true;
    vector<bool> pass;
    vector<int> d;
    queue<int> Q;
    vector<int> adj[n+1];
    for(int i = 0 ; i <n+1 ; i++){
        pass.push_back(false);
        d.push_back(-1);
    }
    for(int i = 0 ; i < m ; i++){
        cin>>u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Q.push(u);
    d[u] = 0;


    while(!Q.empty()){
        int U = Q.front();
        int ADJ = adj[U].size();
        for(int i = 0 ; i<ADJ;  i++){
            int V = adj[U][i];
            if(!pass[V]){
                pass[V] = true;
                d[V] = d[U]+1;
                Q.push(V);
            }else if(pass[V]&& d[U] == d[V]){
                    Is_biparti = false;
                    break;
            }
        }
        Q.pop();
    };

    if(Is_biparti){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}
