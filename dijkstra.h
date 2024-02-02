//DIJKSTRA
int INF = 999;
int V = 14;
int source = 10;
int end = 5;
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
  {999,   999,   999,   999,   999,   999,   999,   999,   177,   177,   999,   999,   75,     0}};
int dist[100];
int path[5];
bool visited[100] = {0};
int parent[100];

void setSourceAndEnd(int s, int e) {
  source = s;
  end = e;}

void initialise_dijkstra() {
  for (int i = 0; i < V; i++) {
    parent[i] = i;
    dist[i] = INF;
  }
  dist[source] = 0;}

int getNearestNode() {
  int minvalue = INF;
  int minnode = 0;
  for (int i = 0; i < V; i++) {
    if (!visited[i] && dist[i] < minvalue) {
      minvalue = dist[i];
      minnode = i;
    }
  }
  return minnode;}

void dijkstra_algorithm() {
  for (int i = 0; i < V; i++) {
    int nearest = getNearestNode();
    visited[nearest] = true;
    for (int adj = 0; adj < V; adj++) {
      if (cost[nearest][adj] != INF && dist[adj] > dist[nearest] + cost[nearest][adj]) {
        dist[adj] = dist[nearest] + cost[nearest][adj];
        parent[adj] = nearest;
      }
    }
  }}

void display() {
  Serial.println("Node:\t\t\tCost :\t\t\tPath:");
  Serial.print(end);
  Serial.print("\t\t\t");
  Serial.print(dist[end]);
  Serial.print("\t\t\t");

  int path[V];
  int pathLength = 0;
  int currentNode = end;

  // Backtrack from end to source to populate the path array
  while (currentNode != source && currentNode != parent[currentNode]) {
    path[pathLength++] = currentNode;
    currentNode = parent[currentNode];
  }
  // Add source node to the path array
  path[pathLength++] = source;
  for (int i = pathLength - 1; i >= 0; i--) {
    Serial.print(path[i]);
    if (i > 0) {
      Serial.print(" -> ");
    }
    }
    Serial.println();
  }

void reset() {
  for (int i = 0; i < V; i++) {
    dist[i] = INF;
    visited[i] = false;
    parent[i] = i;
  }
}

int* dijkstra(){
  initialise_dijkstra();
  dijkstra_algorithm();
  display();
  return path;
}
