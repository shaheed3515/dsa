class Solution
{
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        if (parent[x] == x)
        {
            return parent[x] = x;
        }
        return parent[x] = find(parent[x]);
    }
    void uniondsu(int x, int y)
    {
        int xp = find(x);
        int yp = find(y);
        if (xp == yp)
            return;
        if (rank[xp] > rank[yp])
        {
            parent[yp] = xp;
        }
        else if (rank[yp] > rank[xp])
        {
            parent[xp] = yp;
        }
        else
        {
            rank[xp]++;
            parent[yp] = xp;
        }

        return;
    }
    int kruskal(vector<vector<int>> &edges)
    {
        int mindis = 0;
        for (auto it : edges)
        {
            if (find(it[0]) != find(it[1]))
            {
                uniondsu(it[0], it[1]);
                mindis += it[2];
            }
        }
        return mindis;
    }
    int spanningTree(int n, vector<vector<int>> &edges)
    {
        // code here

        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        sort(edges.begin(), edges.end(), [](vector<int> &v1, vector<int> &v2)
             { return v1[2] < v2[2]; });

        return kruskal(edges);
    }
};