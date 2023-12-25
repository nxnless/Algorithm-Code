#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void MainDuplicate() {
    int n, m, u, v;
    cin >> n >> m;
    n++;  // Increase size to handle 1-based indexing
    queue<int> Q, S;
    vector<int> G[n];
    vector<int> inD;
    inD.assign(n, 0);

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        inD[v]++;
    }
    for (int i = 1; i < n; i++) {
        if (inD[i] == 0) {
            Q.push(i);
        }
    }

    if (Q.empty()) {
        cout << "NO";
    } else {
        while (!Q.empty()) {
            int Ou = Q.front();
            Q.pop();
            S.push(Ou);
            for (int i = 0; i < G[Ou].size(); i++) {
                int ii = G[Ou][i];
                inD[ii]--;
                if (inD[ii] == 0) {
                    Q.push(ii);
                }
            }
        }
	
	if(S.size() == n-1){
		while (!S.empty()) {
            
            cout << S.front() << endl;
            S.pop();
        }
	}else{
		cout<<"NO";
	}
        
}
}
int main() {
    MainDuplicate();
    return 0;
}

