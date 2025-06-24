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

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// 전사 마법사 궁수 도적 성직자
// 전사 :  10 , 5 , 8 , 7 , 6

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
		if (threatLevel.size() <= currentTurn) // -1을 리턴하면 에러로 인식하세요
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
		cout << name << "(현재 위협도는 : " << getCurrentThreat() << ")" << std::endl;
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
// 1번 우선순위 큐를 이용해서 합구조를 작성해봅시다.

bool myless(int a, int b)
{
	return a < b;
}

bool myGreater(int a, int b)
{
	return a > b;
}

// k번째로 작은 수 구하기, k번쨰로 큰 수 구하기 우선순위 큐를 사용하면 쉽게 표현할 수 있다.
// logN 시간으로 k번째 작은 수를 찾을 수 있다 -> (k번째 수를 찾는다, 1:1 대응 N시간으로 코드를 작성하면 시간이 초과했습니다).

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

	const int& top() const // 저장되어있는 가장 위의 값을 참조한다.
	{
		if (isempty())
		{
			throw runtime_error("priorty Queue is empty");
		}
		return pq2.top();
	}

	int pop() //복사를 한 후에 자료구조에서 삭제 
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
	priority_queue<int, vector<int>, greater<int>> pq;  // 최소값이 제일 위로 올라가는 형태 
	
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

	const int& top() const // 저장되어있는 가장 위의 값을 참조한다.
	{
		if (isempty())
		{
			throw runtime_error("priorty Queue is empty");
		}
		return pq.top();
	}

	int pop() //복사를 한 후에 자료구조에서 삭제 
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

	std::cout << "최소 힙의 가장 작은 값 : " << myheap.top() << std::endl;

	std::cout << "최소 힙의 가장 큰 값 : " << myheap2.top() << std::endl;

	int k = 3;
	// ??
}

void ThreatSystem()
{
	// 1. 등장 캐릭터의 위협도를 출력하세요.

	Character a("전사", { 1,2,3,4,5 });
	Character b("도적", { 1,1,1,10,5 });
	Character c("궁수", { 3,6,3,3,3 });
	Character d("마법사", { 0,1,6,6,6 });
	Character e("성직자", { 0,0,10,0,20 });

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

	// 보스가 가장 위협도가 높은 숫자를 짓도록 해보세요
	Boss boss("킹 고블린");
	boss.UpdataThreatQueue(party);
	int value = boss.FindMostThreatCharacter(party);
	std::cout << "첫번째 턴에서 위협도가 가장 큰 수치 : " << value << std::endl;



	boss.UpdataThreatQueue(party);
	std::cout << "두번째 턴에서 위협도가 가장 큰 수치 : " << value << std::endl;
	boss.UpdataThreatQueue(party);

	int nextTurnValue = 3;
	int currentThreat = 0;
	for (int i = 0; i < nextTurnValue; i++)
	{
		currentThreat += a.getCurrentThreat();
		a.NextTurn();
	}
	cout << "===전사의 3턴 후 위협도 : "<< currentThreat << std::endl;


}
int main()
{
	findkthExample();
	ThreatSystem();
}