#include <bits/stdc++.h>
using namespace std;
class Trav
{
private:
    int total;
    list<int> *ADJ_List;

public:
    Trav(int total)
    {
        this->total = total;
        ADJ_List = new list<int>[total];
    }
    // undirected edges
    void addEdge(int source, int dest)
    {
        ADJ_List[source].push_back(dest);
        ADJ_List[dest].push_back(source);
    }
    void BFS(int start)
    {
        // set all visited to False
        vector<bool> visited(total, false);
        list<int> Q;
        // set start node to true
        visited[start] = true;
        // push it to Q
        Q.push_back(start);

        list<int>::iterator i;
        while (!(Q.empty()))
        {
            start = Q.front();
            cout << "- - -" << endl;
            cout << "  " << start << " " << endl;
            cout << "- - -" << endl;
            Q.pop_front();

            for (i = ADJ_List[start].begin(); i != ADJ_List[start].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    Q.push_back(*i);
                }
            }
        }
    }
    ~Trav()
    {
        delete[] ADJ_List;
    }
};
int main()
{
    Trav graph(7);
    // undirected graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 5);
    graph.addEdge(1, 4);
    graph.addEdge(1, 5);
    graph.addEdge(2, 6);
    graph.addEdge(3, 6);
    // bfs from 0
    graph.BFS(0);
    return 0;
}