/*
* 0. k��° ���� ã�� ���� ����, delete temp �����ϱ�,
* 1. Heap Ư���� ��Ģ�� ���� �ִ� �ڷᱸ�� ���� �����غ���
* 2. k��° �����ϴ� ���� �� ���� ã�� �� �ִ�. -> ���� ����
*/


// k��° ���� ã��

// 1. vector , array ���� ���� ��Ų �Ŀ� ���� ũ�ų� (����) ���� ã�´�. (���� �˰��� �ð� )
// 2. ��ü ������ n���� ������ n-1 �� �񱳸� �ؾ��Ѵ�.					 (��� ����� ���� Ž���ϴ� ���, ���� Ž��)
// 3. �ð� logN�� �ɸ��� ����� ������?(-> �������� ���� �鸸�� �̻�(ó���ؾ��� �����Ͱ� ������) �� �� ��� �ؾ� �ϳ�?)
// ���࿡ ó���ؾ��� �����Ͱ� ������, (10, 1)



// Tree(���������� �����Ͱ� ����� ��� ȿ���� x)
// 1. ������ �ذ��ϱ� ���� �ϳ��� ��� Ʈ�� ���·� ���������� �ϴ� �����͸� �־�� (Ʈ���� ���ʴ�� �����Ѵ�)
// 2. root �������� ���� ū �� , �Ǵ� ���� ���� ���� �����ϵ��� ��Ģ�� ����,
// ���� ��Ģ�� ���� �ڷᱸ�� ��(Heap) �̶�� ��. maxheap -> ū���� ���� , minheap -> ���� ���� ����

// MaxHeap ������ ���� minHeap �����ϱ�
#include <iostream>
#include <queue>
#include <algorithm>

void priorityQueue() //�켱���� ť
{
	std::priority_queue<int> pq;

	// heap �ڷᱸ���� ������� Ŭ����
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
	* node->value //������ 
	*/

	/*
	* �θ��� �������� ū �༮�� �ٲٸ� �ȵǳ���?
	* heap�� Ư¡�� �����Ͱ� ���� �� heap�� ������ �����ϰ� �ִ� ����
	* ���� ���� �༮�� ��Ģ�� �µ��� �����ϸ� �ȴ�.
	*/

	void heapifyup(Node* node) //���� �߰��� ��� node
	{
		// node �θ� ��带 �����ͷ� ����Ű�� �ִ�. node->parrentNode->value node ->value
		// 
		// while(1�� ���� && 2������)
		// 1. �߰��� ���� �θ� ����� ���� ���ϴ� �ڵ带 �������� ���� �߰��� ��尡 �� Ŭ��
		// 2. ���� �߰��� ����� �θ� ��尡 �����ϸ� ��� �����ϼ���

		// node->par

		while (node->parentnode != nullptr && node->value > node -> parentnode -> value ) //������ �ϱ� ���� ����
		{
			//�˰��� ����� �߰����ش�����, �θ� ���� �ڱ� ��带 swap���ش� (value�� swap)
			// swap�Ŀ� node�� �θ� ���� �������ش�. (�θ� ��带 ����Ű�� �ִ� ���� �����Ѵ�)
			std::swap(node->value, node->parentnode->value);
			node = node->parentnode;
		}
	}

	Node* findLastNode() // ��带 ������ �� ��Ģ1�� ������Ű�� ���ؼ� ���� ������ ��带 ã�´�.
	{
		if (!root) return nullptr; // �����Ͱ� 1���� ���� ��� �����Ű��������
	
		std::queue<Node*> q;
		q.push(root);
		Node* lastNode = nullptr;

		while (!q.empty())
		{ 
			lastNode = q.front();
			q.pop();
			if (lastNode->leftnode) //�׻� ����, left���� right ���� ���� ��� x
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
		//��Ʈ�� �ø� ������ ��带 �� �ڽ� ���(����, ������) �߿��� ū ���� ��ü�Ѵ�.
		//�ڽ� ����, ������ ��庸�� �ڱⰡ �� ũ�ų� , ���̻� �ڽ��� ���������� �ݺ��ض�.
		while (node)
		{
			Node* largest = node; // ���� ��尡 ���� ũ��. (����)

			if (node->leftnode && node->leftnode->value > largest->value)
			{
				largest = node->leftnode;
			}

			if (node->rightnode && node->rightnode->value > largest->value)
			{
				largest = node->rightnode;
			}

			//���ʰ� ������ �߿��� ū ���� �ٲ��.

			if (largest == node) //������ �ȵ����� break;
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

		if (!root) //�����Ͱ� 0���� ��� ���� ���� �����Ͱ� ��Ʈ�� �ȴ�.
		{
			root = newNode;
			size = 1;
			return;
		}

		// ��Ʈ�� ���� �� ���, ��Ģ1�� ���� ������� ��尡 ����� �� �ְ� ������ �ۼ��ϼ���
		// ���ʿ� �����Ͱ� ������ -> ���ʿ� ������ �ֱ�, 
		// ���ʿ� �����Ͱ� ������ -> �����ʿ� ������ �ֱ�

		
		std::queue<Node*> q; //���� ���� �༮�� ó������ FIFO ����
		q.push(root);

		while (!q.empty()) //q�� �������� �ݺ��ϼ���
		{
			Node* currentNode = q.front();
			q.pop();

			if (!currentNode->leftnode) // ���ʿ� �����Ͱ� ������ - > ������ ������ �ֱ�
			{
				currentNode->leftnode = newNode;	//���� ����� ���� �ڽĿ� ���ο� �����͸� �־���.
				newNode->parentnode = currentNode;	//�ڽ��� �θ� �������ش�
				break;
			}

			if (!currentNode->rightnode) // ���ʿ� �����Ͱ� ������ - > ������ ������ �ֱ�
			{
				currentNode->rightnode = newNode; //���� ����� ������ �ڽĿ� ���ο� �����͸� �־���.
				newNode->parentnode = currentNode; //�ڽ��� �θ� �������ش�
				break;
			}

			//root�� ���̻� ����� ��尡 ���� �� ���� �ݺ��ϱ� ���ؼ� ����� ��带 �߰����ִ� ���
			q.push(currentNode->leftnode);
			q.push(currentNode->rightnode);
		}

		size++;
		heapifyup(newNode);
		// ���� �� ����, �� �θ��� ��带 ���ؼ� ū ���� �������� ������
		// heapilyup

	}

	int extractMax() //�ִ밪�� �����϶�. front, pop
	{
		if (!root) return -1; // "-1 �����ϸ� ������ �ִ� �ſ���"

		int maxValue = root->value;

		if (size == 1) // 1���� ���� ��� 1���� ���ְ� �ִ밪�� ��ȯ�Ѵ�.
		{
			delete root;
			root = nullptr;
			size = 0;
			return maxValue;
		}

		// 1. ������ ��带 ã������
		Node* lastnode = findLastNode();
		if (!lastnode) return -2; // if(-1) ������ 0 , (-2) ������ ��带 ã�� �ڵ尡 ������ �����ϴ�. 


		// 2. ������ ��带 root ���� �̵���Ų �� �ٽ� Heap ������ ������ �����ϼ���
		root->value = lastnode->value; // ���� �ؿ� �ִ� ��带 �����״µ� 
		
		//����� ���ؼ� ����Ű�� �ִ� ���� ������ ���
		if (lastnode->parentnode)
		{
			// lastNode ���� root�� �ö����ϱ� ���� lastNode�� �ִ� �ּҸ� nullptr�� �ٲٱ�
			// �θ� ��尡 ������ �θ� ��忡�� ���ʰ� ������ �߿��� ū ���� �θ��� ���� �ø��� �ʹ�.
			if (lastnode->parentnode->leftnode == lastnode)
			{
				lastnode->parentnode->leftnode = nullptr;
			}
			else //������ ��尡 �θ� ����� �����ʿ� �ִ°��
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
		
		// ������ ������ �ڷᱸ���� ���ͷ� ��ȯ�غ�����

		// while queue �ڷ����� ����ؼ� �����͸� Ž���ϴ� ������ �ڵ�

		if (!root) return result;
		std::queue<Node*> q;
		q.push(root);  //rootrk nullptr

		while (!q.empty())
		{
			Node* node = q.front();
			q.pop(); // pop ���ؾ� �����ټ� �ִ� ���߿�
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
* RPG���� , �������̵� , 5����Ƽ , [���� ���� �ü� ������ ������]
* ������ �������� ��ų�� ����� ������ ������ ��׷ΰ� �����մϴ�.
* �� 5���� ���� ���� ���� ������ �켱������ �����ϴ��� ã�� ������ 
* �̋�, ������ Ư�� ������ ������ �� ���� �� ������ ��׷δ� 0���� �ʱ�ȭ�� �˴ϴ�.
*              
* ����    :
* ����    :
* �ü�    :
* ������  :
* ������  : 
* 
* [������ ��ų�� �����ϴ� ����] 
* ����  : ��Ƽ���� ���� ���� �������ΰ�? ���� ���� �� �������ΰ�? <<
* 
* (1) N���� ���� ���� �켱������ �� ���� ū ������ ����Ѵ�.
* (2) Heap �ڷᱸ���� ����ؼ� K��° ����ã��
* 
*  - ������ ������ �������� 1�� ����� ȿ�����̴�.
*  - 2���� ����ؾ��ϴ� ������ ã�ƾ��� �켱 ���� ����� ������ �������� 2�� ����� ȿ��
*/

int main()
{
	MaxHeap mHeap;

	std::cout << "���� ū ���� ã�� Heap ������ �Է�" << std::endl;
	mHeap.insert(7);
	mHeap.insert(3);
	mHeap.insert(5);
	mHeap.insert(11);

	std::cout << "Heap �ڷᱸ���� Ʈ�� ���� ������� ����ϴ� ����" << std::endl;
	std::vector<int> tempV = mHeap.toArray();

	for (auto& data : tempV) //auto�� �ڿ��ִ� �� ���� �ڵ����� ����
	{
		std::cout << data << "  "; 
	}

	std::cout << "���� ū ���� ��ȯ�ϰ� �ٽ� Heap ���� �ϴ� ����" << std::endl;
	int maxValue = mHeap.extractMax(); //1��° ū �� 
    int k = 2;
	int kthValue;
	for (int i = 0; i < k-1; i++)
	{
		kthValue = mHeap.extractMax(); // 2��°�� ū �� kthvalue ����ȴ�
	}

	 //k��°�� ū ���� ã�ƶ�.
	std::cout << " k��°�� ū ���� : " << kthValue << std::endl;
}
