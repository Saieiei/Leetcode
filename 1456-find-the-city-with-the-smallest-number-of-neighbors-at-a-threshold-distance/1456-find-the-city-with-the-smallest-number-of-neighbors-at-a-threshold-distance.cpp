class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    // Step 1: Initialize the distance matrix with a large value (infinity)
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Step 2: Distance from a city to itself is 0
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    // Step 3: Set initial distances based on the edges
    for (const auto& edge : edges) {
        int from = edge[0], to = edge[1], weight = edge[2];
        dist[from][to] = weight;
        dist[to][from] = weight;
    }

    // Step 4: Apply the Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Step 5: Count reachable cities within the distance threshold
    int minReachable = INT_MAX, resultCity = -1;
    for (int i = 0; i < n; ++i) {
        int reachable = 0;
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] <= distanceThreshold) {
                ++reachable;
            }
        }
        if (reachable <= minReachable) {
            minReachable = reachable;
            resultCity = i;
        }
    }

    return resultCity;
}
};