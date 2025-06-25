/*
*  1.���� (������ ������� ����)
*  2.Ž�� (�������� ���� �� ����)
* 
*  - vector ���� ��Ű�� ���� Ž�� 
*  - Tree �ڷ� ����, ���� �˻� Ʈ��
*  - Heap ( �켱���� ť priority_queue)
* 
*  - Graph Ž��.
*/

/*
*  �׷����� �����ΰ�?
*  - ��(vertex)�� ����(edge)�� ǥ���� �ڷᱸ���̴�.
*  - <����> 
*  1. ����(Direction) �� �����ϴ� 
*  2. ��ȯ(cycle) �� 
*  3. ����ġ 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

/*
*  �׷����� Matrix�� ǥ������ ��
*   
* 
* 
*/

/*
* 
* ���α׷������� �׷����� ǥ���� �� �ְ� �Ǿ����ϴ�.
* ����Ǿ� �ִ� �׷����� Ž���� �ϴ� ���?
* [1] ���� �켱 Ž�� 
* [2] �ʺ� �켱 Ž��
*/

/*
* ���� �ӿ��� ���� ������ ����Ǿ� �ִ� �̹����� �ϳ� ã�ƺ�����.
* ���� ���� �׷����� ǥ���ϴ� ���� �ƹ� ������ �����غ����� �����غ�����
*/

class Graph
{
private:
	int V; //���� ���� 
	vector<vector<int>> adj;

	vector<bool> visited;				// �ѹ� ������ ���� �ô�(�鷶��) �������ִ� �ڷᱸ��

	void DFS(int v)
	{
		// v�湮, visited = true
		visited[v] = true; 
		cout << v << "  "; 

		for (auto& i : adj[v])
		{
			// adj B,C,D ("B) ->DFS ����. ��� ���
			if(visited[i] == false) //����� �湮�� �ߴٸ� DFS �������� ������
			DFS(i);    // DFS(B) -> DFS(C) -> DFS(D)
		}
	}

	void DFSIter(int v)
	{
		//�湮�� ���� ture ��ȯ
		//����Լ� ����� ������� �ʰ� �ݺ��� ����ؼ� ǥ���غ�����
		stack<int> stack;
		visited[v] = true;
		stack.push(v);
		while (!stack.empty())
		{
			int cvertex = stack.top();
			stack.pop();

			// stack : �����͸� ���� �� ���� �������� ���� �����͸� ���� �����϶�.
			// �ݺ���, ���� �����͸� �����ϰ� ����� �ش�.

			if (visited[cvertex] == false)
			{
				visited[cvertex] == true;
				cout << v << " ";
			}

			//�̿����
			for (int i = adj[cvertex].size() - 1; i >= 0; i--)
			{
				int neighbor = adj[cvertex][i];
				if (!visited[neighbor] == false)
				{
					stack.push(neighbor);
				}
			}
		}
	}

public:
	//������, ���� ����, 2���� �迭�� v�� ������ŭ ��� 0���� �ʱ�ȭ
	Graph(int vertices) : V(vertices)
	{
		adj.resize(V);
		visited.resize(V, false);
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void PrintGraph()
	{
		for (int i = 0; i < V; i++)
		{
			std::cout << "���� " << i << " �� ������ ����Ʈ : " << endl;
			for (auto& elem : adj[i])
			{
				cout << " -> " << elem;
			}
			cout << endl;
		}
	}

	void DFSTraverse(int startV)
	{
		// �湮�� ������ ���½�Ų��. 
		fill(visited.begin(), visited.end(), false);

		cout << "DFS Ž�� ��� (���� ���� : " << startV << ")";
		DFS(startV);
		cout << endl;
	}

	void DFSIterTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);

		cout << "DFS Iterative ��� Ž�� ��� ( �������� : " << startV << ")";
	}
	

};

class GraphMatrix
{
private:
	int V;
	vector<vector<int>>adj;

public:
	GraphMatrix(int v) : V(v), adj(v, vector<int>(v, 0)) {} // v * v 2���� �迭�� 0���� �ʱ�ȭ

	void addEdge(int u, int v)
	{
		adj[u][v] = 1;  // �ܹ��� �ϳ�
		adj[v][u] = 1;  // �ֹ��� �߰�
	}

	void PrintGraph()
	{
		cout << "���� ���" << endl;
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				cout << adj[i][j] << "  "; 
			}
			cout << endl;
		}
	}
};

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.DFSTraverse(3);
	g.DFSIterTraverse(0);
	g.PrintGraph();


	GraphMatrix gn(4);

	gn.addEdge(0, 1);
	gn.addEdge(0, 2);
	gn.addEdge(0, 3);
	gn.addEdge(1, 2);
	gn.addEdge(1, 3);

	gn.PrintGraph();
}