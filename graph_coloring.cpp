#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int>G[N];

void coloring(int V){
	vector<int>result(V,-1);
	result[0]=0; 

	vector<bool>used(V,false);

	set<int>st;

	for (int u = 1; u < V; u++){
		for (auto it:G[u])	if (result[it] != -1)	used[result[it]] = true;
		
		int color;
		for (color = 0; color < V; color++)			if (used[color] == false)break;

		result[u] = color; 

		st.insert(color);

		for (auto it:G[u])			if (result[it] != -1)	used[result[it]] = false;
	}
	
	cout<<"Vertex\tColour\n";
	for (int u = 0; u < V; u++){
		cout << u << "\t"<< result[u] << endl;
	}
	
	cout<<"\n Minimum colors used: "<<st.size()<<"\n";
}

int main()
{
	cout<<"Enter the number of vertex and edges ";
	int n,m;cin>>n>>m;
	cout<<"Enter the edges: \n";
	for(int i =0;i<m;i++){
		int a,b;cin >>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	coloring(n);

	return 0;
}
