#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;
class Rough_Dun
{
public:
    //Source -> Destination -> list of (RoadName, Distance)
    unordered_map<string,unordered_map<string,vector<pair<string,int>>>>adj;
    void addEdge(string u,string v,string roadName,int distance,bool direction)
    {
        //Direction=0 --> undirected graph
        //Direction=1 --> directed graph
        //Store Multiple roads between two Places
        adj[u][v].push_back({roadName,distance});
        if(direction==0)
            adj[v][u].push_back({roadName,distance});
    }
    void printAdjList(string p,string d)
    {
        if(adj.find(p)!=adj.end() && adj[p].find(d)!=adj[p].end())
        {
            cout<<"Pickup location: "<<p<<endl;
            cout<<"Destination: "<<d<<endl;
            cout<<"Available roads are:\n";
            for(auto i: adj[p][d])
                cout<<" - "<<i.first<<" ( "<<i.second<<" km )\n";
        }
        else
            cout<<"No direct roads found. "<<endl;
        /*for(auto &i:adj)        // i is from
        {
            cout<<i.first<<"----> ";
            for(auto &j:i.second)  // j is to
            {
                cout<<j.first<<" via: ";
                for (auto &k:j.second)  //k is road
                    cout<<"[ "<<k.first<<" , "<<k.second<<" km ]    ";
            }
            cout<<endl;
        }*/
    }
};

int main()
{
    /*int n,m;
    cout<<"Enter no of places:"<<endl;
    cin>>n;*/
    int m;
    cout<<"Enter number of roads:"<<endl;
    cin>>m;
    Rough_Dun g;
    for(int i=0;i<m;i++)
    {
        string u,v,road;
        int distance;
        cout<<"Enter Road(Pickup,Destination, roadName,Distance):"<<endl;
        cin>>u>>v>>road>>distance;
        g.addEdge(u,v,road,distance,0);
    }
    /*cout<<"Map is as follows :"<<endl;
    g.printAdjList();*/

    string pickup,destination;
    cout<<"\nEnter Pickup Location:"<<endl;
    cin>> pickup;
    cout<<"Enter destination:"<<endl;
    cin>>destination;

    cout<<"\n--- Route Information----\n";
    g.printAdjList(pickup,destination);
    return 0;
}