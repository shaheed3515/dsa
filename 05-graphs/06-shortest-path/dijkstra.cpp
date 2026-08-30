class Solution {
    public:
        void dijkstra(vector<vector<pair<int,int>>>& adj,vector<int>& res,int& src){
            priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,src});
            /*
            set<pair<int,int>> s;
            s.insert({0,src});
            */
            res[src]=0;
            while(!pq.empty()){
                pair<int,int> t=pq.top();
                int d=t.first;
                int v=t.second;
                pq.pop();
                /*
                pair<int,int> it=*s.begin(); // begin() is a iterator so dereference it.
                int d=it.first;
                int v=it.second;
                s.erase(it);
                */
                if(d>res[v]) continue; //if the initial moving dist is geater than in res it waste to take that path
                for( pair<int,int>& x : adj[v]){
                    int dis=x.first;
                    int edge=x.second;
                    if(dis+d<res[edge]){
                        /*
                        if(res[edge]!=INT_MAX){
                            s.erase({res[edge],edge});
                        }
                        */
                        res[edge]=dis+d;
                        pq.push({dis+d,edge});
                        /*
                        s.insert({dis+d,edge});
                        */
                    }
                }
            }
            return ;
        }
        vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
          // Code here
            vector<vector<pair<int,int>>> adj(n);
            for(vector<int>& it : edges){
                int u=it[0];
                int v=it[1];
                int dis=it[2];
                adj[u].push_back({dis,v});
                adj[v].push_back({dis,u});
            }
            vector<int> res(n,INT_MAX);
          
            dijkstra(adj,res,src);
            return res;
        }
};