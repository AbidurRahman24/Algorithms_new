vector<int> path;
    int current = d;
    while(current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    cout<<endl;
    for(int node:path)
    {
        cout<<node<<" ";
    }