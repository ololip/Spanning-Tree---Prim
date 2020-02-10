// Drzewa spinajace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Graph
{
	vector<vector<pair<int, int>>> edgeList;
public:
	Graph(int n);
	void addEdge();
	int Prim(int n);
};

ofstream outFile;
ifstream inFile("input.txt");
int main()
{
	int test, n, m;
	char c;

	cout << "Liczba testow: " << endl;
	inFile >> test;

	outFile.open("output.txt");
	for (int i = 0; i < test; i++)
	{
		//cout << "n=#,m=#" << endl;
		inFile >> c;
		inFile >> c;
		inFile >> n;
		inFile >> c;
		inFile >> c;
		inFile >> c;
		inFile >> m;
		Graph graph(n);
		for (int j = 0; j < m; j++)
			graph.addEdge();
		outFile << graph.Prim(n) << endl;
	}
	outFile.close();
}

Graph::Graph(int n)
{
	edgeList.resize(n);
}
void Graph::addEdge()
{
	int u, v, w;
	char c;
	//cout << "{u,v}w" << endl;
	inFile >> c;
	inFile >> u;
	inFile >> c;
	inFile >> v;
	inFile >> c;
	inFile >> w;
	edgeList[u].push_back(make_pair(v, w));
	edgeList[v].push_back(make_pair(u, w));
}
int Graph::Prim(int n)
{
	int sum = 0, min = INT_MAX, u, v, w, edges_visited = 0;
	//vector<vector<pair<int, int>>> edgesT;
	bool* visited = new bool[n];

	for (int i = 0; i < n; i++)
		visited[i] = false;

	for (int i = 0; i < n; i++)
	{
		for (pair<int, int> edge : edgeList[i])
		{
			if (min > edge.second)
			{
				min = edge.second;
				u = i;
				v = edge.first;
				w = edge.second;
			}
		}
	}
	//edgesT[u].push_back(make_pair(v, w));
	visited[u] = true;
	visited[v] = true;
	edges_visited++;
	edges_visited++;
	sum += w;

	while (edges_visited < n)
	{
		min = INT_MAX;

		for (int i = 0; i < n; i++)
		{
			if (visited[i])
			{
				for (pair<int, int> edge : edgeList[i])
				{
					if (min > edge.second && !visited[edge.first])
					{
						min = edge.second;
						u = i;
						v = edge.first;
						w = edge.second;
					}
				}

			}
		}
		//edgesT[u].push_back(make_pair(v, w));
		visited[v] = true;
		edges_visited++;
		sum += w;
	}
	delete[] visited;
	return sum;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
