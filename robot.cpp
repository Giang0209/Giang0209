#include <bits/stdc++.h>
using namespace std;

long int Vertices, Edges;
long int stA, stB, endA, endB, maxDist;
vector<vector<long long>> distanceMatrix;
vector<vector<pair<long int, long int>*>> parentMatrix;
vector<vector<long int>> adjacencyList;
vector<pair<long int, long int>> pathResult;

void bfs() {
    queue<pair<long int, long int>> q;
    
    if (distanceMatrix[stA][stB] > maxDist) {
        q.push(make_pair(stA, stB));
        parentMatrix[stA][stB] = new pair<long int, long int>(-1, -1);
    }

    while (!q.empty()) {
        int currentA = q.front().first;
        int currentB = q.front().second;
        q.pop();

        for (long int neighborA : adjacencyList[currentA]) {
            if (parentMatrix[neighborA][currentB] == nullptr && distanceMatrix[neighborA][currentB] > maxDist) {
                q.push(make_pair(neighborA, currentB));
                parentMatrix[neighborA][currentB] = new pair<long int, long int>(currentA, currentB);
            }
        }

        for (long int neighborB : adjacencyList[currentB]) {
            if (parentMatrix[currentA][neighborB] == nullptr && distanceMatrix[currentA][neighborB] > maxDist) {
                q.push(make_pair(currentA, neighborB));
                parentMatrix[currentA][neighborB] = new pair<long int, long int>(currentA, currentB);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> Vertices >> Edges;

    distanceMatrix.resize(Vertices, vector<long long>(Vertices, 0));
    parentMatrix.resize(Vertices, vector<pair<long int, long int>*>(Vertices, nullptr));
    adjacencyList.resize(Vertices);

    for (long int i = 0; i < Vertices; i++) {
        for (long int j = 0; j < Vertices; j++) {
            parentMatrix[i][j] = nullptr;
            if (i == j) 
                distanceMatrix[i][j] = 0;
            else 
                distanceMatrix[i][j] = 1e18;
        }
    }

    for (long int i = 0; i < Edges; i++) {
        long int vertexX, vertexY, weight;
        cin >> vertexX >> vertexY >> weight;
        adjacencyList[vertexX].push_back(vertexY);
        adjacencyList[vertexY].push_back(vertexX);
        distanceMatrix[vertexX][vertexY] = distanceMatrix[vertexY][vertexX] = weight;
    }

    for (long int k = 0; k < Vertices; k++) {
        for (long int i = 0; i < Vertices; i++) {
            for (long int j = 0; j < Vertices; j++) {
                distanceMatrix[i][j] = min(distanceMatrix[i][j], distanceMatrix[i][k] + distanceMatrix[k][j]);
            }
        }
    }

    cin >> stA >> stB >> endA >> endB >> maxDist;
    bfs();

    if (parentMatrix[endA][endB] == nullptr) {
        cout << "KhÃ´ng thá»ƒ!" << endl;
    } else {
        long int currentA = endA;
        long int currentB = endB;
        while (currentA != stA || currentB != stB) {
            pathResult.push_back(make_pair(currentA, currentB));
            pair<long int, long int>* prev = parentMatrix[currentA][currentB];
            currentA = prev->first;
            currentB = prev->second;
        }

        pathResult.push_back(make_pair(stA, stB));
        for (long int i = pathResult.size() - 1; i >= 0; i--) {
            cout << pathResult[i].first  << " " << pathResult[i].second << endl;
        }
    }

    return 0;
}
