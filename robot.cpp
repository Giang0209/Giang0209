#include <iostream>
#include <stack>
#include <vector>
#include <queue>

const int oo = int(1e9);

using namespace std;

int n, m;
int a, b, c, d, r;
int dist[101][101]; // Khoáº£ng cÃ¡ch giá»¯a 2 Ä‘á»‰nh i vÃ  j
int trace[101][101]; // LÆ°u trá»¯ tráº¡ng thÃ¡i thá»i Ä‘iá»ƒm trÆ°á»›c khi 2 robot á»Ÿ vá»‹ trÃ­ i vÃ  j
bool check[101][101] = {false}; // Kiá»ƒm tra xem 2 Ä‘á»‰nh i vÃ  j cÃ³ khoáº£ng cÃ¡ch lá»›n hÆ¡n r hay khÃ´ng vÃ  cÃ³ Ä‘Æ°á»ng Ä‘i tá»« i Ä‘áº¿n j khÃ´ng
stack<int> path; // LÆ°u quÃ¡ trÃ¬nh di chuyá»ƒn cá»§a 2 robot
vector<int> adj[101]; // Danh sÃ¡ch ká»

void Init(){
    // Khá»Ÿi táº¡o dist ban Ä‘áº§u lÃ  oo
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++) {
            if(i==j){
                dist[i][j] = 0;
            } else {
                dist[i][j] = oo;
                dist[j][i] = oo;
            }
        }
    }
    // Khá»Ÿi táº¡o trace lÃ  -1
    // trace lÆ°u giÃ¡ trá»‹ cÃ³ dáº¡ng x1*n + x2
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            trace[i][j] = -1;
        }
    }
}

void readInput(){
//    freopen("robot.txt","r",stdin);
    int x,y,w;
    
    cin>>n>>m;
    Init();
    for(int i=0;i<m;i++) {
        cin>>x>>y>>w;
        dist[x][y] = w;
        dist[y][x] = w;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin>>a>>b>>c>>d;
    cin>>r;
}
// BFS Ä‘á»“ng thá»i tá»« a vÃ  b, hÃ ng Ä‘á»£i lÃ  cáº·p giÃ¡ trá»‹ Ä‘á»‰nh
void BFS(int u, int v) {
    int w;
    check[u][v] = true;
    queue<int> Q;
    Q.push(u*n+v);
    while(!Q.empty()) {
        w = Q.front();
        Q.pop();
        u = w/n;
        v = w%n;
        for(int k : adj[u]){
            if(dist[k][v]>r && check[k][v]==false) {
                check[k][v] = true;
                Q.push(k*n+v);
                trace[k][v] = u*n+v;
                if(k==c && v==d){
                    return;
                }
            }
        }
        for(int k : adj[v]){
            if(dist[u][k]>r && check[u][k]==false) {
                check[u][k] = true;
                Q.push(u*n+k);
                trace[u][k] = u*n+v;
                if(u==c && k==d){
                    return;
                }
            }
        }
    }
}

// Floyd-Warshall
void Floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void traceAndPrint(){
    int x,y,w;
    if(check[c][d]==false)
        cout<<"Khong the"<<endl;
    else {
        x = c;
        y = d;
        while(trace[x][y]!=-1) {
            path.push(x*n + y);
            w = trace[x][y];
            x = w/n;
            y = w%n;
        }
        path.push(x*n + y);
        while(!path.empty()) {
            w = path.top(); path.pop();
            x = w/n;
            y = w%n;
            cout<<x<<" "<<y<<" "<<dist[x][y]<<endl;
        }
    }
}

int main() {
    readInput();
    Floyd();
    BFS(a,b);
    traceAndPrint();
    return 0;
}
