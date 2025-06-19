/*
* ★★★ 탐색과 자료구조를 연관해서 생각해보기 ★★★
*  - vector      : 선형탐색, 이진탐색
*   - 조건 : 사용하는 컨테이너가 정렬이 되어 있어야 한다.
*    - 사용 중인 컨테이너의 특징 : 임의의 값을 바로 접근, 랜덤한 값을 수정할 때 비효율적이다.
*
*  - list		: 랜덤한 값의 수정을 즉시 할 수 있다.
	 - mid index의 값과 target 비교
	   - 0 -> mid 순차적으로 탐색 후 mid 값을 반환한다.
		 결론 : 벡터써
   단점 : logN시간을 확보했지만, 사용하기 위한 자료구조가 적합하지 않다.
   연관 컨테이너 : set, map // 트리 구조로 구현이 되어있다.
*/

/*
*  Tree 자료구조
*  데이터를 어떻게 저장하는 형태인가?
*  노드 형태로 데이터를 저장 한다. Value, 연결되어있는 Node 주소를 저장한다.
*/

/*
* Tree 순회 방법
* 
* 전위 순회 pre - order : NLR 읽는 방식
* 중위 순회 in - order  : LNR 읽는 방식
* 후위 순회 post - order :LRN 읽는 방식
*/

/*
* BST(Binary search Tree) 이진 검색 트리
*  - 자기자신과 왼쪽 오른쪽을 저장하는 노드를 가지고 있다.
*  - Node 기준으로 왼쪽과 오른쪽에 값을 비교할 수 있다.
*  - 작은 값을 왼쪽으로 큰 값을 오른쪽으로 저장을 하면 규칙성을갖는다.
*  - 특정한 규칙을 갖는 클래스를 만들어서 데이터를 출력해본다.
*/

/*
* 순차 컨테이너 방식의 단점 - 탐색이 효율적이지 않다.
* 연관 컨테이너 - tree 자료구조
* bst 이진 검색 알고리즘으로 자료구조를 표현한 것
* 단점 : 트리가 한쪽으로 편향 될 경우 O(n) 시간만큼 걸린다.
*/
struct Node
{
	int value;
	Node* leftNode;
	Node* rightNode;

	Node(int val) :value(val), leftNode(nullptr), rightNode(nullptr) {}
};

#include <iostream>
#include <vector>

#pragma region 트리 순회하는 방식
class Tree
{
public:
	void preOrder(Node* root) //재귀 방식으로 만든다.
	{
		if (root == nullptr) //재귀 탈출 조건
		{
			return;
		}

		std::cout << root->value << "  "; // N을 출력하라
		preOrder(root->leftNode);                       // L에 있는 노드에 가서 preOrder	실행
		preOrder(root->rightNode);                       // R에 있는 노드에 가서 pre0rder	실행

	}
	void InOrder(Node* root)
	{
		if (root == nullptr) { return; }
		// LNR
		InOrder(root->leftNode);
		std::cout << root->value << "  ";
		InOrder(root->rightNode);


	}
	void postOrder(Node* root)
	{
		if (root == nullptr) { return; }
		//LRN
		InOrder(root->leftNode);
		InOrder(root->rightNode);
		std::cout << root->value << "  ";
	}
};

#pragma rendregion

#pragma region 노드 직접 연결
void NodeConnect()
{
	
	Node* root = new Node(4);
	root->leftNode = new Node(2);
	root->leftNode->leftNode = new Node(9);
	root->leftNode->rightNode = new Node(7);
	root->rightNode = new Node(6);
	root->rightNode->leftNode = new Node(1);

	std::cout << " \n트리를 전위 순회로 출력 " << std::endl;
	Tree tree;
	tree.preOrder(root);

	std::cout << " \n트리를 중위 순회로 출력 " << std::endl;
	tree.InOrder(root);

	std::cout << " \n트리를 후위 순회로 출력 " << std::endl;

	tree.postOrder(root);
 }
#pragma endregion

#pragma region 이진 BST 구현

// root에서 부터 데이터를 삽입.
// root보다 insert 작으면 왼쪽, 크면 오른쪽
// 모든 데이터를 저장 후 중위 순회 방식으로 데이터를 읽으면? - ? 오름차순으로 정렬이 됩니다.

class BST
{
private:
	Node* root;

	Node* insert(Node* node, int value)
	{
		//데이터가 0개 일 떄 
		if (node == nullptr)
		{
			return new Node(value);
		}

		// node 작으면? 왼쪽 , 크면 오른쪽
		if (node->value > value)
		{
			node->leftNode = insert(node->leftNode, value);
		}
		else if (node->value < value)
		{
			node->rightNode = insert(node->rightNode, value);
		}
		return node;
	}
	void InOrder(Node* node)
	{
		if (node == nullptr) { return; }
		InOrder(node->leftNode); //L 데이터
		std::cout << node->value << "  "; //N 데이터
		InOrder(node->rightNode); //R 데이터
	}
public:
	BST()
	{
		root = nullptr;
	}

	void insert(int value)
	{
		root = insert(root,value);
		std::cout << std::endl;
	}

	//중위 순위로 root를 읽는 순위 코드

	void InOrder()
	{
		InOrder(root);
	}

};

#pragma endregion

int main()
{
	NodeConnect();
	BST bst;	
	bst.insert(4);
	bst.insert(2);
	bst.insert(6);
	std::cout << "이진 검색 트리 데이터 입력 예시" << std::endl;
	bst.InOrder();
	bst.insert(9);
	bst.insert(7);
	std::cout << "이진 검색 트리 데이터 입력 예시" << std::endl;
	bst.InOrder();

}