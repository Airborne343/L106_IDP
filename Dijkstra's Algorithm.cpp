//DIJKSTRA

int INF = 999;
int V = 14;
int source = 0;
int cost[14][14] = {
  {0,     27,    999,   999,   999,   999,   999,   999,   999,   999,   999,   999,   999,   999},
  {27,    0,     30,    999,   999,   999,   101,   999,   999,   999,   999,   999,   999,   999},
  {999,   30,    0,     32,    68,    999,   999,   999,   999,   999,   999,   999,   999,   999},
  {999,   999,   32,    0,     999,   999,   999,   999,   999,   999,   999,   999,   999,   999},
  {999,   999,   68,    999,   0,     34,    999,   999,   82,    999,   999,   999,   999,   999},
  {999,   999,   999,   999,   34,    0,     999,   999,   999,   999,   999,   999,   999,   999},
  {999,   101,   999,   999,   999,   999,   0,     34,    999,   82,    999,   999,   999,   999},
  {999,   999,   999,   999,   999,   999,   34,    0,     999,   999,   999,   999,   999,   999},
  {999,   999,   999,   999,   82,    999,   999,   999,   0,     999,   999,   999,   99,    177},
  {999,   999,   999,   999,   999,   999,   82,    999,   999,   0,     69,    999,   999,   177},
  {999,   999,   999,   999,   999,   999,   999,   999,   999,   69,    0,     29,    30,    999},
  {999,   999,   999,   999,   999,   999,   999,   999,   999,   999,   29,    0,     999,   999},
  {999,   999,   999,   999,   999,   999,   999,   999,   99,    999,   30,    999,   0,     75},
  {999,   999,   999,   999,   999,   999,   999,   999,   177,   177,   999,   999,   75,     0}
};
int dist[100];
bool visited[100] = {0};
int parent[100];

void setup() {
  Serial.begin(115200);
  Serial.println("Number of vertices:");
  Serial.print(V);
  Serial.println("src node : ");
  Serial.print(source);
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      Serial.print(cost[i][j]);
  }
 }
  init();
  dijkstra();
  display();
}

void init() {
  for (int i = 0; i < V; i++) {
    parent[i] = i;
    dist[i] = INF;
  }
  dist[source] = 0;
}

int getNearestNode() {
  int minvalue = INF;
  int minnode = 0;
  for (int i = 0; i < V; i++) {
    if (!visited[i] && dist[i] < minvalue) {
      minvalue = dist[i];
      minnode = i;
    }
  }
  return minnode;
}

void dijkstra() {
  for (int i = 0; i < V; i++) {
    int nearest = getNearestNode();
    visited[nearest] = true;
    for (int adj = 0; adj < V; adj++) {
      if (cost[nearest][adj] != INF && dist[adj] > dist[nearest] + cost[nearest][adj]) {
        dist[adj] = dist[nearest] + cost[nearest][adj];
        parent[adj] = nearest;
      }
    }
  }
}

void display() {
    Serial.println("Node:\t\t\tCost :\t\t\tPath");
    for (int i = 0; i < V; i++) {
        Serial.println(i);
        Serial.print("\t\t\t");
        Serial.print(dist[i]);
        Serial.print("\t\t\t");
        int parnode = parent[i];
        Serial.println(parnode);
     }
 }

int main(void) {
  setup();
}
