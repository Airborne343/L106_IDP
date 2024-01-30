
//DIJKSTRA

int INF = 999;
int V = 14; 
int source = 1;
int cost[100][100];
int dist[100];
bool visited[100] = {0};
int parent[100];

void setup(){
  Serial.begin(9600);
}


void init() {
    for (int i = 0; i < V; i++) {
        Serial.print("S");
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
        Serial.println( i , " ");
        int parnode = parent[i];

        while (parnode != source) {
            Serial.println(" <- ");
            Serial.print(parnode);
            parnode = parent[parnode];
        }
    }
}

int main(void) {
    Serial.println("Number of vertices:");
    Serial.print(V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            Serial.print(cost[i][j]);
        }
    }
    Serial.println("src node : ");
    Serial.print(source);
    setup();
    init();
    dijkstra();
    display();
}

/*
0     27.2  999   999   999   999   999   999   999   999   999   999   999   999
27.2  0     29.8  999   999   999   100.9 999   999   999   999   999   999   999
999   29.8  0     31.7  68.1  999   999   999   999   999   999   999   999   999
999   999   31.7  0     999   999   999   999   999   999   999   999   999   999
999   999   68.1  999   0     33.7  999   999   82.1  999   999   999   999   999
999   999   999   999   33.7  0     999   999   999   999   999   999   999   999
999   100.9 999   999   999   999   0     33.7  999   82.1  999   999   999   999
999   999   999   999   999   999   33.7  0     999   999   999   999   999   999
999   999   999   999   82.1  999   999   999   0     999   999   999   99.3  176.5
999   999   999   999   999   999   82.1  999   999   0     69.1  999   999   176.5
999   999   999   999   999   999   999   999   999   69.1  0     29.1  30.1  999
999   999   999   999   999   999   999   999   999   999   29.1  0     999   999
999   999   999   999   999   999   999   999   99.3  999   30.1  999   0     74.5
999   999   999   999   999   999   999   999   176.5 176.5 999   999   74.5     0
*/
