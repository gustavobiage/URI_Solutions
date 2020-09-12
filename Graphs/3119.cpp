#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <vector>

#define INF 222222222222222

using namespace std;

int f, c, t;
int a, b, w;
long long int dist[10001];
vector<int> adj[10001];
vector<int> w_[10001];
long long int total;

void dijkstra(int s) {
    int u, v;
    for (v = 1; v <= c; v++) {
        dist[v] = INF;
    }
    dist[s] = 0;
    
    priority_queue<pair<long long int,int> > pq;
    pq.push(make_pair(dist[s],s));
    
    while (!pq.empty()) {
        u = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < adj[u].size(); i++) {
            v = adj[u][i];
            w = w_[u][i];
            
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(-dist[v],v));
            }
        }
    }
}

int main() {

    while (scanf("%d ", &f) != EOF) {
        total = 0;
        while (f--) {
            scanf("%d %d ", &c, &t);
            for (int i = 0; i <= c; i++) {
                adj[i].clear();
                w_[i].clear();
            }
            for (int i = 0; i < t; i++) {
                scanf("%d %d %d", &a, &b, &w);
                w_[a].push_back(w);
                adj[a].push_back(b);
            }
            dijkstra(1);
            total = total + dist[c];
        }
        printf("%Ld\n", total);
    }
        
    return 0;
}

