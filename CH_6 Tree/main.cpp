/*
* �ڡڡ� Ž���� �ڷᱸ���� �����ؼ� �����غ��� �ڡڡ�
*  - vector      : ����Ž��, ����Ž��
*   - ���� : ����ϴ� �����̳ʰ� ������ �Ǿ� �־�� �Ѵ�.
*    - ��� ���� �����̳��� Ư¡ : ������ ���� �ٷ� ����, ������ ���� ������ �� ��ȿ�����̴�.
*
*  - list		: ������ ���� ������ ��� �� �� �ִ�.
	 - mid index�� ���� target ��
	   - 0 -> mid ���������� Ž�� �� mid ���� ��ȯ�Ѵ�.
		 ��� : ���ͽ�
   ���� : logN�ð��� Ȯ��������, ����ϱ� ���� �ڷᱸ���� �������� �ʴ�.
   ���� �����̳� : set, map // Ʈ�� ������ ������ �Ǿ��ִ�.
*/

/*
*  Tree �ڷᱸ��
*  �����͸� ��� �����ϴ� �����ΰ�?
*  ��� ���·� �����͸� ���� �Ѵ�. Value, ����Ǿ��ִ� Node �ּҸ� �����Ѵ�.
*/

/*
* Tree ��ȸ ���
* 
* ���� ��ȸ pre - order : NLR �д� ���
* ���� ��ȸ in - order  : LNR �д� ���
* ���� ��ȸ post - order :LRN �д� ���
*/

/*
* BST(Binary search Tree) ���� �˻� Ʈ��
*  - �ڱ��ڽŰ� ���� �������� �����ϴ� ��带 ������ �ִ�.
*  - Node �������� ���ʰ� �����ʿ� ���� ���� �� �ִ�.
*  - ���� ���� �������� ū ���� ���������� ������ �ϸ� ��Ģ�������´�.
*  - Ư���� ��Ģ�� ���� Ŭ������ ���� �����͸� ����غ���.
*/

/*
* ���� �����̳� ����� ���� - Ž���� ȿ�������� �ʴ�.
* ���� �����̳� - tree �ڷᱸ��
* bst ���� �˻� �˰������� �ڷᱸ���� ǥ���� ��
* ���� : Ʈ���� �������� ���� �� ��� O(n) �ð���ŭ �ɸ���.
*/

/*
* Ʈ�� �ڷᱸ���� ���
* ��� : 3���� ������ ���� : (��(VALUE), ����, ������ ��� �ּ�) Ʈ���� �⺻ ��Ҹ� �����ϴ� ������ ����
* �θ� ��� : ������ ���� ���� ����� ���
* �ڽ� ��� : �θ� ����� ������ ���� ����� ���
* ��Ʈ ��� : Ʈ���� �ֻ����� �ִ� ���. �θ� ��尡 ����
* ���� ��� : Ư�� ��忡�� ��Ʈ������ ��ο� �ִ� ��� ���
* �ļ� ��� : Ư�� ����� ��� �ڽĵ��� ������ ���� 
* 
* - �˰��� Ʈ�� �ڵ� ���� �� ���Ǵ� ��� - 
*	����(level) : ��Ʈ�� ������ �Ÿ��� ���մϴ�. ��Ʈ�� 0�� ��ȯ�մϴ�.
*   ����        : Ʈ������ ���� ���� ������ ���Ѵ�.
*   ����        : Ư�� ��忡�� ��Ʈ������ �����Դϴ�.
*   ���� Ʈ��   : Ʈ�� ���ο� �ݺ������� �̷������ �ļյ�� ������ �� �ٸ� Ʈ��
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

#pragma region Ʈ�� ��ȸ�ϴ� ���
class Tree
{
public:
	void preOrder(Node* root) //��� ������� �����.
	{
		if (root == nullptr) //��� Ż�� ����
		{
			return;
		}

		std::cout << root->value << "  "; // N�� ����϶�
		preOrder(root->leftNode);                       // L�� �ִ� ��忡 ���� preOrder	����
		preOrder(root->rightNode);                       // R�� �ִ� ��忡 ���� pre0rder	����

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

#pragma region ��� ���� ����
void NodeConnect()
{
	
	Node* root = new Node(4);
	root->leftNode = new Node(2);
	root->leftNode->leftNode = new Node(9);
	root->leftNode->rightNode = new Node(7);
	root->rightNode = new Node(6);
	root->rightNode->leftNode = new Node(1);

	std::cout << " \nƮ���� ���� ��ȸ�� ��� " << std::endl;
	Tree tree;
	tree.preOrder(root);

	std::cout << " \nƮ���� ���� ��ȸ�� ��� " << std::endl;
	tree.InOrder(root);

	std::cout << " \nƮ���� ���� ��ȸ�� ��� " << std::endl;

	tree.postOrder(root);
 }
#pragma endregion

#pragma region ���� BST ����

// root���� ���� �����͸� ����.
// root���� insert ������ ����, ũ�� ������
// ��� �����͸� ���� �� ���� ��ȸ ������� �����͸� ������? - ? ������������ ������ �˴ϴ�.

class BST
{
private:
	Node* root;

	Node* insert(Node* node, int value)
	{
		//�����Ͱ� 0�� �� �� 
		if (node == nullptr)
		{
			return new Node(value);
		}

		// node ������? ���� , ũ�� ������
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

	Node* findMin(Node* node)
	{
		if (node == nullptr || node->leftNode == nullptr)
		{
			return node;
		}
		return findMin(node->leftNode);
	}

	Node* fineMax(Node* node)
	{
		if (node == nullptr || node->rightNode == nullptr)
		{
			return node;
		}
		return fineMax(node->rightNode);
	}

	Node* deleteNode(Node* node, int target) //����, �����͸� ã�� ������ ������ �����
	{
		if (node == nullptr) { return nullptr; }

		if (node->value > target) //���� ���� �̵�
		{
			node->leftNode = deleteNode(node->leftNode, target);
		}
		else if(node->value < target) //������ ���� �̵�
		{
			node->rightNode = deleteNode(node->rightNode, target);
		}
		else             // (node->value = target) <-���� �����͸� ã�� ���
		{
			// ã�Ҵ�, �����ض�.

			/*if (node->rightNode == nullptr && node->leftNode == nullptr);
			if (node->leftNode == nullptr);
			if (node->rightNode == nullptr);*/ // �ؿ���ó�� �ϳ��� ǥ������


			if (node->leftNode == nullptr || node->rightNode == nullptr)
			{
				Node* temp = node->leftNode != nullptr ? node->leftNode : node->rightNode;

				if (temp == nullptr)// �ڽ��� ���� ���
				{
					temp = node; // ����� ���� ��带 �ӽ÷� ����( �������� �޸𸮸� ����Ű�� �ִ�)
					node = nullptr; // ����� ���� ��带 null ����Ű���� ����
					delete temp;   // �ӽú����� �ּҸ� ������
				}
				else
				{
					Node* nodeTodelete = node; //���� ��带 ��� ������ ������ ����,
					node = temp;			   // 1���� �ִ� �ڽ�(temp)�� �������� ��� ��ġ�� �̵�
					delete nodeTodelete;       // �������� ���(nodeTodelete) - �޸𸮸� ����
				}
			}
			else //�ڽ��� ���ΰ��
			{
				//�����ʿ��� ���� ���� ���� ã�ڴ�.
				Node* temp = findMin(node->rightNode);
				node->value = temp->value;
				node->rightNode = deleteNode(node->rightNode, temp->value);
			}
		}
		return node;
	}



	void InOrder(Node* node)
	{
		if (node == nullptr) { return; }
		InOrder(node->leftNode); //L ������
		std::cout << node->value << "  "; //N ������
		InOrder(node->rightNode); //R ������
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

	//���� ������ root�� �д� ���� �ڵ�

	void InOrder()
	{
		InOrder(root);
	}

	void DeleteNode(int value)
	{
		root = deleteNode(root, value);
	}

	void ReturnRoot()
	{
		std::cout << "��Ʈ�� ����� �� : " << root->value << std::endl;
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
	std::cout << "���� �˻� Ʈ�� ������ �Է� ����" << std::endl;
	bst.InOrder();
	bst.insert(9);
	bst.insert(7);
	bst.insert(1);
	std::cout << "���� �˻� Ʈ�� ������ �Է� ����" << std::endl;
	bst.InOrder();
	std::cout << " \n 6. ������ ���� �� ��� " << std::endl;
	bst.DeleteNode(6);
	bst.InOrder();

}