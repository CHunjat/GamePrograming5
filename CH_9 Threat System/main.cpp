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

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// ���� ������ �ü� ���� ������
// ���� :  10 , 5 , 8 , 7 , 6

class Character
{
private:
	string name;
	vector<int> threatLevel;  // threatLevel { 10,5,8,7,6}


	int currentTurn;

public:
	Character(string name, vector<int> TL) : name(name), threatLevel(TL), currentTurn(0) {}

	int getCurrentThreat()
	{
		if (threatLevel.size() <= currentTurn) // -1�� �����ϸ� ������ �ν��ϼ���
		{
			throw runtime_error("out of range");
		}
		return threatLevel[currentTurn];
	}

	void NextTurn()
	{
		currentTurn++;
	}

	void printStat()
	{
		cout << name << "(���� �������� : " << getCurrentThreat() << ")" << std::endl;
	}

};

class Boss
{
public:
	string name;
	int currentTurn;
	priority_queue<int> threatQueue;
	Boss(string name) : currentTurn(0) {}

	void clear()
	{

		while (!threatQueue.empty())
		{
			threatQueue.pop();
		}
	}

	void UpdataThreatQueue(vector<Character> & party)
	{
		clear();

		for (auto& character : party)
		{
			int threat = character.getCurrentThreat();
			threatQueue.push(threat);
			character.NextTurn();
		}
	}

	int FindMostThreatCharacter(vector<Character>& party)
	{
		//Character* target = nullptr;

		int MostThreatValue = threatQueue.top();
		return MostThreatValue;
	}
};

// maxheap ,minheap
// 1�� �켱���� ť�� �̿��ؼ� �ձ����� �ۼ��غ��ô�.

bool myless(int a, int b)
{
	return a < b;
}

bool myGreater(int a, int b)
{
	return a > b;
}

// k��°�� ���� �� ���ϱ�, k������ ū �� ���ϱ� �켱���� ť�� ����ϸ� ���� ǥ���� �� �ִ�.
// logN �ð����� k��° ���� ���� ã�� �� �ִ� -> (k��° ���� ã�´�, 1:1 ���� N�ð����� �ڵ带 �ۼ��ϸ� �ð��� �ʰ��߽��ϴ�).

class MaxHeap
{
private:
	priority_queue<int, vector<int>, less<int>> pq2;

public:
	MaxHeap() = default;

	void push(int value)
	{
		pq2.push(value);
	}

	bool isempty() const
	{
		return pq2.empty();
	}

	const int& top() const // ����Ǿ��ִ� ���� ���� ���� �����Ѵ�.
	{
		if (isempty())
		{
			throw runtime_error("priorty Queue is empty");
		}
		return pq2.top();
	}

	int pop() //���縦 �� �Ŀ� �ڷᱸ������ ���� 
	{
		if (isempty())
		{
			throw runtime_error("priorty Queue is empty");
		}
		int minValue = pq2.top();
		pq2.pop();
		return minValue;
	}
};

class MinHeap
{
private:
	//1. 
	priority_queue<int, vector<int>, greater<int>> pq;  // �ּҰ��� ���� ���� �ö󰡴� ���� 
	
public:
	MinHeap() = default;

	// push, pop , empty, top (<-=extractMax)
	void push(int value) 
	{
		pq.push(value);
	}

	bool isempty() const
	{
		return pq.empty();
	}

	const int& top() const // ����Ǿ��ִ� ���� ���� ���� �����Ѵ�.
	{
		if (isempty())
		{
			throw runtime_error("priorty Queue is empty");
		}
		return pq.top();
	}

	int pop() //���縦 �� �Ŀ� �ڷᱸ������ ���� 
	{
		if (isempty())
		{
			throw runtime_error("priorty Queue is empty");
		}
		int minValue = pq.top();
		pq.pop();
		return minValue;
	}

};


void findkthExample()
{
	MinHeap myheap;
	MaxHeap myheap2;

	myheap.push(11);
	myheap.push(7);
	myheap.push(5);
	myheap.push(3);
	myheap2.push(11);
	myheap2.push(7);
	myheap2.push(5);
	myheap2.push(3);

	std::cout << "�ּ� ���� ���� ���� �� : " << myheap.top() << std::endl;

	std::cout << "�ּ� ���� ���� ū �� : " << myheap2.top() << std::endl;

	int k = 3;
	// ??
}

void ThreatSystem()
{
	// 1. ���� ĳ������ �������� ����ϼ���.

	Character a("����", { 1,2,3,4,5 });
	Character b("����", { 1,1,1,10,5 });
	Character c("�ü�", { 3,6,3,3,3 });
	Character d("������", { 0,1,6,6,6 });
	Character e("������", { 0,0,10,0,20 });

	std::vector<Character> party;

	party.push_back(a);
	party.push_back(b);
	party.push_back(c);
	party.push_back(d);
	party.push_back(e);

	for (auto& character : party)
	{
		character.printStat();
	}

	// ������ ���� �������� ���� ���ڸ� ������ �غ�����
	Boss boss("ŷ ���");
	boss.UpdataThreatQueue(party);
	int value = boss.FindMostThreatCharacter(party);
	std::cout << "ù��° �Ͽ��� �������� ���� ū ��ġ : " << value << std::endl;



	boss.UpdataThreatQueue(party);
	std::cout << "�ι�° �Ͽ��� �������� ���� ū ��ġ : " << value << std::endl;
	boss.UpdataThreatQueue(party);

	int nextTurnValue = 3;
	int currentThreat = 0;
	for (int i = 0; i < nextTurnValue; i++)
	{
		currentThreat += a.getCurrentThreat();
		a.NextTurn();
	}
	cout << "===������ 3�� �� ������ : "<< currentThreat << std::endl;


}
int main()
{
	findkthExample();
	ThreatSystem();
}