#include<iostream>
#include<list>
using namespace std;

class Graph{

    private:
        int v;
        int **edges;
        void DFSutil(int s,bool visit[]);
        void BFSutil(int s,bool visit[]);
    public:
        Graph(int v);
        void buildGraph();
        void BFS(int s);
        void DFS(int s);
};

Graph::Graph(int v){
    this->v = v;
    edges = new int*[v];
    for(int i=0;i<v;i++)
        edges[i] = new int[v];
}

void Graph::DFSutil(int s,bool visit[]){

    visit[s] = true;
    cout<<s<<" ";

    for(int i=0;i<this->v;i++){
            if(edges[s][i] == 1 &&  (!visit[i])){
                DFSutil(i,visit);
            }
        }
}

void Graph::DFS(int s){
    bool *visit = new bool[v];
    for(int i=0;i<v;i++)
        visit[i] = false;
    DFSutil(s,visit);
    cout<<endl;
    for(int i=0;i<v;i++)
        if(!visit[i]){
            DFSutil(i,visit);
        }
}

void Graph::BFSutil(int s,bool visit[]){
    list<int> q;
    q.push_back(s);
    visit[s] = true;
    while(!q.empty()){
        s=q.front();
        cout<<s<<" ";
        q.pop_front();
        for(int i=0;i<this->v;i++){
            if(edges[s][i] == 1 &&  (!visit[i])){
                visit[i] = true;
                q.push_back(i);
            }
        }
    }
}

void Graph::BFS(int s){
    bool *visit = new bool[v];
    for(int i=0;i<v;i++)
        visit[i] = false;
    BFSutil(s,visit);
    cout<<endl;
    for(int i=0;i<v;i++)
        if(!visit[i]){
            BFSutil(i,visit);
        }
}

void Graph::buildGraph(){
    int x,y;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            edges[i][j] = 0;
        }
    }
    while(true){
        cout<<"From: ";
        cin>>x;
        cout<<"To : ";
        cin>>y;
        if(x == -999 || y == -999)
            break;
        else
            edges[x][y] = 1;
    }
}

int main(){
    int s,st;
    cout<<"enter number of vertices: ";
    cin>>s;
    Graph g(s);
    g.buildGraph();
    cout<<"enter source : ";
    cin>>st;
    g.BFS(st);
    cout<<endl;
    g.DFS(st);
    return 0;
}
