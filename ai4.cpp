#include<bits/stdc++.h>
#define int long long
using namespace std;
void selection_sort(int arr[],int n){
        for(int i=0;i<n-1;i++){
            int min_number=arr[i];
            int index = i;
            for(int j=i+1;j<=n;j++){
                if(arr[j]<min_number){
                    min_number=arr[j];
                    index = j;
                }
            }
            //cout<<min_number<<" ";
            swap(arr[i],arr[index]);
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }


void prim(unordered_map<int,list<pair<int,int>>>adj,int n,int e){
    vector<int>key(n);
    vector<bool>mst(n);
    vector<int>parent(n);

    for(int i=0;i<n;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<n;i++){
        int mini=INT_MAX;
        int u;
        //find min wali node
        for(int v=0;v<n;v++){
            if(mst[v]==false && key[v]<mini) {
                u=v;
                mini=key[v];
            }
        }
        //mark min node as true;
        mst[u]=true;
        //check its adjacent nodes;
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false and w<key[v] ){
                parent[v]=u;
                key[v]=w;
            }
        }
    }
    cout<<"Edges"<<"  "<<"weight"<<endl;
    int sum=0;
    for(int i=1;i<n;i++) {
        cout<<parent[i]<<" "<<i<<"->"<<key[i]<<endl;
        sum +=key[i];
    }
    cout<<"total weight :"<<sum<<endl;
}
    
    const int N=1e5;
    int parent[N];
    void make(int i){
        parent[i]=i;
    }
    int find(int a){
        if(parent[a]==a) return a;
        return find(parent[a]);
    }
    void Union(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b) parent[b]=a;
    }





//const int N=1e5+9;
const int INF=1e9+9;
vector<pair<int,int>>adj[N];  //(node,wt);
vector<int>vis(N,0);
vector<int>dist(N,INF);
void dikshtra(int source){
    set<pair<int,int>>s;    //(wt,node);
    s.insert({0,source});
    dist[source]=0;
    while(s.size()>0){
        auto node=*s.begin();
        int v=node.second;
        int v_dist=node.first;
        s.erase(node );
        if(vis[v]==1) continue;
        vis[v]=1;
        for(auto child:adj[v]){
            int child_v=child.first;
            int wt=child.second;
            //(new distance < child ka current distance)
            if(dist[v]+wt < dist[child_v]){
                dist[child_v]=dist[v]+wt;
                s.insert({dist[child_v],child_v});
            }
        }
    }
    cout<<endl;
}
signed main()
{

    cout<<"1. selection_sort"<<endl;
    cout<<"2.prims_algorithn"<<endl;
    cout<<"3.krushkal_algorithm"<<endl;
    cout<<"4.dijkstra_algorithm"<<endl;
    cout<<"enter your choice"<<endl;
    int choice;cin>>choice;

    while(true){
    if(choice==1){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    selection_sort(arr,n);
    }

    else if(choice==2){
    int vertices,edge;
    cin>>vertices>>edge;
    vector<pair<pair<int,int>,int>>edges ; //={ {{0, 1}, 2}, {{0, 3}, 6}, {{1, 2}, 3}, {{1, 3}, 8}, {{1, 4}, 5}, {{4, 2}, 7}};

    for(int i=0;i<edge;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edges.push_back({{x,y},z});
    }
    //creates v adj list;
    unordered_map<int,list<pair<int,int>>>adj;

    for(int i=0;i<edge;i++){
        int u=edges[i].first.first;
        int v=edges[i].first.second;
        int w=edges[i].second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    prim(adj,vertices,edge);
    }

    else if(choice==3){
    int n,m;cin>>n>>m;
    vector<pair<int,pair<int,int>>>vpp;
    while(m--){
        int a,b,wt;
        cin>>a>>b>>wt;
        vpp.push_back({wt,{a,b}});
    }
    sort(vpp.begin(),vpp.end());
    for(int i=1;i<=n;i++){
        make(i);
    }
    int total_cost=0;
    cout<<"Edges"<<endl;
    for(auto i:vpp){
        int wt=i.first;
        int x=i.second.first;
        int y=i.second.second;
        if(find(x)==find(y)) continue;
        Union(x,y);
        total_cost +=wt;
        cout<<x<<" "<<y<<endl;
    }
    cout<<"total cost"<<total_cost<<endl;
    }
    else if(choice==4){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        adj[x].push_back({y,wt});
        adj[y].push_back({x,wt});
    }
    dikshtra(0);
    cout<<"nodes"<<" "<<"distance"<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
    }
    else break;
    }
    return 0;
}