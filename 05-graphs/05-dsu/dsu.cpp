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
    
    
};