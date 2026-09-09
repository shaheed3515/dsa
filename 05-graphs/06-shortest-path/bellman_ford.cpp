//Bellman-Algorithm

for(int count=1;count<=n-1;count++){
    for(vector<int> & edge : edges){
        int u=edge[0];
        int v=edge[1];
        int d=edge[2];
        if(res[u]!=INT_MAX && res[u]+d<res[v]){
            res[v]=res[u]+d;
        }
    }
}