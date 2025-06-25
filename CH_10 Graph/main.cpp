/*
*  1.정렬 (데이터 순서대로 나열)
*  2.탐색 (데이터의 수정 및 삭제)
* 
*  - vector 정렬 시키고 이진 탐색 
*  - Tree 자료 구조, 이진 검색 트리
*  - Heap ( 우선순위 큐 priority_queue)
* 
*  - Graph 탐색.
*/

/*
*  그래프가 무엇인가?
*  - 점(vertex)과 간선(edge)로 표현한 자료구조이다.
*  - <기준> 
*  1. 방향(Direction) 이 존재하는 
*  2. 순환(cycle) 이 
*  3. 가중치 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

/*
*  그래프를 Matrix로 표현했을 때
*   
* 
* 
*/

/*
* 
* 프로그래밍으로 그래프를 표현할 수 있게 되었습니다.
* 연결되어 있는 그래프를 탐색을 하는 방법?
* [1] 깊이 우선 탐색 
* [2] 너비 우선 탐색
*/

/*
* 게임 속에서 점과 선으로 연결되어 있는 이미지를 하나 찾아보세요.
* 점과 선을 그래프로 표현하는 것을 아무 주제나 선택해보세요 실행해보세요
*/

class Graph
{
private:
	int V; //점의 갯수 
	vector<vector<int>> adj;

	vector<bool> visited;				// 한번 지나간 길은 봤다(들렀다) 저장해주는 자료구조

	void DFS(int v)
	{
		// v방문, visited = true
		visited[v] = true; 
		cout << v << "  "; 

		for (auto& i : adj[v])
		{
			// adj B,C,D ("B) ->DFS 실행. 재귀 방식
			if(visited[i] == false) //만약게 방문을 했다면 DFS 실행하지 마세요
			DFS(i);    // DFS(B) -> DFS(C) -> DFS(D)
		}
	}

	void DFSIter(int v)
	{
		//방문한 점은 ture 변환
		//재귀함수 방식을 사용하지 않고 반복문 사용해서 표현해보세요
		stack<int> stack;
		visited[v] = true;
		stack.push(v);
		while (!stack.empty())
		{
			int cvertex = stack.top();
			stack.pop();

			// stack : 데이터를 삽입 후 가장 마지막에 들어온 데이터를 먼저 실행하라.
			// 반복문, 역순 데이터를 실행하게 만들어 준다.

			if (visited[cvertex] == false)
			{
				visited[cvertex] == true;
				cout << v << " ";
			}

			//이웃노드
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
	//생성자, 점의 갯수, 2차원 배열을 v의 갯수만큼 모두 0으로 초기화
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
			std::cout << "정점 " << i << " 의 인접한 리스트 : " << endl;
			for (auto& elem : adj[i])
			{
				cout << " -> " << elem;
			}
			cout << endl;
		}
	}

	void DFSTraverse(int startV)
	{
		// 방문한 경험을 리셋시킨다. 
		fill(visited.begin(), visited.end(), false);

		cout << "DFS 탐색 결과 (시작 지점 : " << startV << ")";
		DFS(startV);
		cout << endl;
	}

	void DFSIterTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);

		cout << "DFS Iterative 방식 탐색 결과 ( 시작지점 : " << startV << ")";
	}
	

};

class GraphMatrix
{
private:
	int V;
	vector<vector<int>>adj;

public:
	GraphMatrix(int v) : V(v), adj(v, vector<int>(v, 0)) {} // v * v 2차원 배열을 0으로 초기화

	void addEdge(int u, int v)
	{
		adj[u][v] = 1;  // 단방향 하나
		adj[v][u] = 1;  // 쌍방향 추가
	}

	void PrintGraph()
	{
		cout << "인접 행렬" << endl;
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