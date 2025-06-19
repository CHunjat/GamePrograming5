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
	std::cout << "���� �˻� Ʈ�� ������ �Է� ����" << std::endl;
	bst.InOrder();

}