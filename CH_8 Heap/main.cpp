/*
* 0. k번째 문제 찾기 오류 수정, delete temp 삭제하기,
* 1. Heap 특정한 규칙을 갖고 있는 자료구조 직접 구현해보기
* 2. k번째 존재하는 수를 더 빨리 찾을 수 있다. -> 게임 예제
*/


// k번째 숫자 찾기

// 1. vector , array 숫자 정렬 시킨 후에 가장 크거나 (작은) 수를 찾는다. (정렬 알고리즘 시간 )
// 2. 전체 갯수가 n개가 있으면 n-1 번 비교를 해야한다.					 (모든 경우의 수를 탐색하는 방법, 완전 탐색)
// 3. 시간 logN이 걸리는 방법이 없을까?(-> 데이터의 수가 백만개 이상(처리해야할 데이터가 많으면) 일 떄 어떻게 해야 하나?)
// 만약에 처리해야할 데이터가 적으면, (10, 1)



// Tree(편항적으로 데이터가 저장될 경우 효율적 x)
// 1. 단점을 해결하기 위한 하나의 방법 트리 형태로 균형잡히게 일단 데이터를 넣어보자 (트리를 차례대로 저장한다)
// 2. root 방향으로 가장 큰 수 , 또는 가장 작은 수를 저장하도록 규칙을 설정,
// 위의 규칙을 갖는 자료구조 힙(Heap) 이라고 함. maxheap -> 큰숫자 위로 , minheap -> 작은 숫자 위로

// MaxHeap 구현을 보고 minHeap 구현하기
#include <iostream>
#include <queue>
#include <algorithm>

void priorityQueue() //우선순위 큐
{
	std::priority_queue<int> pq;

	// heap 자료구조로 만들어진 클래스
}

class MaxHeap
{
private:
	struct Node
	{
		int value;
		Node* leftnode;
		Node* rightnode;
		Node* parentnode;

		Node(int val) : value(val), leftnode(nullptr), rightnode(nullptr), parentnode(nullptr) {}
	};

	Node* root;
	int size;

	/* 
	* (*node).value
	* node->value //역참조 
	*/

	/*
	* 부모노드 기준으로 큰 녀석을 바꾸면 안되나요?
	* heap의 특징은 데이터가 들어올 때 heap의 성질을 만족하고 있다 가정
	* 새로 들어온 녀석만 규칙에 맞도록 수정하면 된다.
	*/

	void heapifyup(Node* node) //새로 추가된 노드 node
	{
		// node 부모 노드를 포인터로 가리키고 있다. node->parrentNode->value node ->value
		// 
		// while(1번 조건 && 2번조건)
		// 1. 추가된 노드와 부모 노드의 값을 비교하는 코드를 만들어보세요 새로 추가된 노드가 더 클때
		// 2. 새로 추가된 노드의 부모 노드가 존재하면 계속 실행하세요

		// node->par

		while (node->parentnode != nullptr && node->value > node -> parentnode -> value ) //변경을 하기 위한 조건
		{
			//알고리즘 헤더를 추가해준다음에, 부모 노드와 자기 노드를 swap해준다 (value를 swap)
			// swap후에 node를 부모 노드와 변경해준다. (부모 노드를 가리키고 있는 것을 변경한다)
			std::swap(node->value, node->parentnode->value);
			node = node->parentnode;
		}
	}

	Node* findLastNode() // 노드를 삭제할 때 규칙1을 만족시키기 위해서 가장 마지막 노드를 찾는다.
	{
		if (!root) return nullptr; // 데이터가 1개도 없는 경우 실행시키지마세요
	
		std::queue<Node*> q;
		q.push(root);
		Node* lastNode = nullptr;

		while (!q.empty())
		{ 
			lastNode = q.front();
			q.pop();
			if (lastNode->leftnode) //항상 왼쪽, left부터 right 부터 먼저 사용 x
			{
				q.push(lastNode->leftnode);
			}
			if (lastNode->rightnode) 
			{
				q.push(lastNode->rightnode);
			}
		}

		return lastNode;
	}

	void heapifydown(Node* node)
	{
		//루트에 올린 마지막 노드를 그 자식 노드(왼쪽, 오른쪽) 중에서 큰 값과 교체한다.
		//자식 왼쪽, 오른쪽 노드보다 자기가 더 크거나 , 더이상 자식이 없을떄까지 반복해라.
		while (node)
		{
			Node* largest = node; // 현재 노드가 제일 크다. (가정)

			if (node->leftnode && node->leftnode->value > largest->value)
			{
				largest = node->leftnode;
			}

			if (node->rightnode && node->rightnode->value > largest->value)
			{
				largest = node->rightnode;
			}

			//왼쪽과 오른쪽 중에서 큰 수로 바뀐다.

			if (largest == node) //변경이 안됐으면 break;
			{
				break;
			}

			std::swap(node->value, largest->value);
			node = largest;

		}
	}

	void deleteNode(Node* node)
	{
		if (!node) return;

		deleteNode(node->leftnode);
		deleteNode(node->rightnode);
		delete node;
	}

public:

	MaxHeap() :  root(nullptr), size(0) {}

	void insert(int value)
	{
		Node* newNode = new Node(value);

		if (!root) //데이터가 0개일 경우 새로 들어온 데이터가 루트가 된다.
		{
			root = newNode;
			size = 1;
			return;
		}

		// 루트가 존재 할 경우, 규칙1을 따라서 순서대로 노드가 저장될 수 있게 조건을 작성하세요
		// 왼쪽에 데이터가 없으면 -> 왼쪽에 데이터 넣기, 
		// 왼쪽에 데이터가 있으면 -> 오른쪽에 데이터 넣기

		
		std::queue<Node*> q; //먼저 들어온 녀석을 처리해줘 FIFO 구조
		q.push(root);

		while (!q.empty()) //q가 있을때만 반복하세요
		{
			Node* currentNode = q.front();
			q.pop();

			if (!currentNode->leftnode) // 왼쪽에 데이터가 없으면 - > 왼족에 데이터 넣기
			{
				currentNode->leftnode = newNode;	//현재 노드의 왼쪽 자식에 새로운 데이터를 넣었다.
				newNode->parentnode = currentNode;	//자식의 부모를 설정해준다
				break;
			}

			if (!currentNode->rightnode) // 왼쪽에 데이터가 없으면 - > 왼족에 데이터 넣기
			{
				currentNode->rightnode = newNode; //현재 노드의 오른쪽 자식에 새로운 데이터를 넣었다.
				newNode->parentnode = currentNode; //자식의 부모를 설정해준다
				break;
			}

			//root에 더이상 연결된 노드가 없을 때 까지 반복하기 위해서 연결된 노드를 추가해주는 노드
			q.push(currentNode->leftnode);
			q.push(currentNode->rightnode);
		}

		size++;
		heapifyup(newNode);
		// 현재 들어간 노드와, 그 부모의 노드를 비교해서 큰 수를 위쪽으로 보내라
		// heapilyup

	}

	int extractMax() //최대값을 제거하라. front, pop
	{
		if (!root) return -1; // "-1 리턴하면 에러가 있는 거에여"

		int maxValue = root->value;

		if (size == 1) // 1개만 있을 경우 1개를 없애고 최대값을 변환한다.
		{
			delete root;
			root = nullptr;
			size = 0;
			return maxValue;
		}

		// 1. 마지막 노드를 찾으세요
		Node* lastnode = findLastNode();
		if (!lastnode) return -2; // if(-1) 갯수가 0 , (-2) 마지막 노드를 찾는 코드가 에러가 있읍니다. 


		// 2. 마지막 노드를 root 노드로 이동시킨 후 다시 Heap 성질을 갖도록 정리하세요
		root->value = lastnode->value; // 제일 밑에 있는 노드를 가리켰는데 
		
		//지우기 위해서 가리키고 있는 가장 마지막 노드
		if (lastnode->parentnode)
		{
			// lastNode 값은 root로 올라갔으니까 현재 lastNode에 있는 주소를 nullptr로 바꾸기
			// 부모 노드가 있으면 부모 노드에서 왼쪽과 오른쪽 중에서 큰 수를 부모노드 위로 올리고 싶다.
			if (lastnode->parentnode->leftnode == lastnode)
			{
				lastnode->parentnode->leftnode = nullptr;
			}
			else //마지막 노드가 부모 노드의 오른쪽에 있는경우
			{
				lastnode->parentnode->rightnode = nullptr;
			}
		}
		delete lastnode;
		heapifydown(root);    //

		return maxValue;
	}

	std::vector<int> toArray()
	{
		std::vector<int> result;
		
		// 힙으로 저장한 자료구조를 벡터로 변환해보세요

		// while queue 자료형을 사용해서 데이터를 탐색하는 형태의 코드

		if (!root) return result;
		std::queue<Node*> q;
		q.push(root);  //rootrk nullptr

		while (!q.empty())
		{
			Node* node = q.front();
			q.pop(); // pop 을해야 지워줄수 있다 나중에
			result.push_back(node->value);

			if (node->leftnode)
			{
				q.push(node->leftnode);
			}

			if (node->rightnode)
			{
				q.push(node->rightnode);
			}

		}

		return result;
	}
};

/*
* RPG게임 , 보스레이드 , 5인파티 , [전사 도적 궁수 마법사 성직자]
* 각각의 직업들은 스킬을 사용할 때마다 보스의 어그로가 증가합니다.
* 총 5번의 보스 공격 마다 누구를 우선적으로 공격하는지 찾는 로직을 
* 이떄, 보스가 특정 직업을 공격할 때 마다 그 직업의 어그로는 0으로 초기화가 됩니다.
*              
* 전사    :
* 도적    :
* 궁수    :
* 마법사  :
* 성직자  : 
* 
* [보스의 스킬을 결정하는 로직] 
* 보스  : 파티에서 누가 가장 위협적인가? 누가 가장 덜 위협적인가? <<
* 
* (1) N개의 직업 마다 우선순위를 비교 가장 큰 순위를 출력한다.
* (2) Heap 자료구조를 사용해서 K번째 순위찾기
* 
*  - 갯수가 적으면 적을수록 1번 방식이 효율적이다.
*  - 2번을 사용해야하는 보스가 찾아야할 우선 순위 대상이 많으면 많을수록 2번 방식이 효율
*/

int main()
{
	MaxHeap mHeap;

	std::cout << "가장 큰 수를 찾는 Heap 데이터 입력" << std::endl;
	mHeap.insert(7);
	mHeap.insert(3);
	mHeap.insert(5);
	mHeap.insert(11);

	std::cout << "Heap 자료구조의 트리 저장 순서대로 출력하는 예제" << std::endl;
	std::vector<int> tempV = mHeap.toArray();

	for (auto& data : tempV) //auto는 뒤에있는 거 보고 자동으로 해줌
	{
		std::cout << data << "  "; 
	}

	std::cout << "가장 큰 수를 반환하고 다시 Heap 정렬 하는 예제" << std::endl;
	int maxValue = mHeap.extractMax(); //1번째 큰 수 
    int k = 2;
	int kthValue;
	for (int i = 0; i < k-1; i++)
	{
		kthValue = mHeap.extractMax(); // 2번째로 큰 수 kthvalue 저장된다
	}

	 //k번째로 큰 수를 찾아라.
	std::cout << " k번째로 큰 수는 : " << kthValue << std::endl;
}
