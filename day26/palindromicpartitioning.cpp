  int palindromicPartition(string S) {
    if (S.size() < 2) return 0;
    int N = S.size();
    vector<vector<int>> F(N);
    for (auto& f: F) f.resize(N);
    vector<int> G(N, N);
    for (int j = 0; j < N; j++)
        for (int i = j; i >= 0; i--) {
            F[i][j] = S[i]==S[j] && (i+2>j || F[i+1][j-1]);
            if (F[i][j]) G[j] = i ? min(G[j],G[i-1]+1) : 0;
        }
    return G[N-1];
}