void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        make_set(i);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }
    int ans = 0; // no of sets
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        s.insert(find_set(i));
    }
    ans = (int) s.size();
    cout << ans << '\n';
    return 0;
}
