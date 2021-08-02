struct segTree
{
    int size;
    vll table;
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        table.assign(2 * size, INF);
    }
 
    void build(vll &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < sz(a))
            {
                table[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        table[x] = min(table[2 * x + 1],table[2 * x + 2]);
    }
 
    void build(vll &a)
    {
        build(a, 0, 0, size);
    }
 
    void set(int index, int value, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            table[x] = value;
            return;
        }
        int m = (lx + rx) / 2;
        if (index < m)
        {
            set(index, value, 2 * x + 1, lx, m);
        }
        else
        {
            set(index, value, 2 * x + 2, m, rx);
        }
        table[x] = min(table[2 * x + 1],table[2 * x + 2]);
    }
 
    void set(int index, int value)
    {
        set(index, value, 0, 0, size);
    }
 
    ll query(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return INF;
        if (lx >= l && rx <= r)
            return table[x];
        int m = (lx + rx) / 2;
        ll q1 = query(l, r, 2 * x + 1, lx, m);
        ll q2 = query(l, r, 2 * x + 2, m, rx);
        return min(q1,q2);
    }
 
    ll query(int l, int r)
    {
        return query(l, r, 0, 0, size);
    }
};
