/*
* �˰��� ��ǥ ����
*  - ���� �����ϰ� Ž���ϱ�
*  - �ܼ��� ���. �����͸� ���Ľ�Ų��.
*  - k��°�� ������? ���ʺ��� �ϳ��� ���
*  - k��°�� ū �� ? �����ʺ��� �ϳ��� ���
*/

// ����ȯ�� ������ �����ص帳�ϴ� . vector<int>
// ���� �����ؾ��ϴ� ȯ�ڰ� 1������ �����մϴ�

//Ʈ���� �������� �����ؼ�  ���� ū ���� ã�� ���¸� �����ϸ� ���?

#include <iostream>
#include <vector>
#include <utility> //pair ���
#include <map> //insert {pair -> people d}
#include <algorithm> //sort �Լ�

void EmergencyExample()
{
	std::vector<int> people = { 10,5,7,25,4,27,9 };
	std::vector<int> answer;
	answer.assign(people.size(), 0);
	//? 

	//answer.push_back()//
	std::map<int, int> sheets;

	for (int i = 0; i < people.size(); i++)
	{
		sheets.insert({ people[i],i }); 
	}


	// people �� ���� ����
	std::sort(people.begin(), people.end());

	//answer�� ����ִ� ���� ū ��?
	//int key = sheets.find(answer[answer.size() - 1])->first; //sheets. �� ���ڿ� ����ִ� �ε���
	//sheets �� ����ִ� �ε������� ��ȯ���ּ���
	//answer[key] = 1;

	/*
	* Tree ��� ���� 
	* Tree ������ ������ ���
	* ���̵�� 1. Ʈ���� �����͸� ���� �� ���������� ������ �Ǵ°� �ƴѰ�?
	* ä�� ���� ������ ����Ʈ������ �ϳ��� ��Ģ�� ������ �غ���.
	* Heap : �׿��ִ�. ����Ʈ���� �θ��尡 ���� ū������ �Ѵ�. ���� ���� �ִ� ��尡 ���� ū ��.
	* ���� ���� �ִ� ��尡 ���� ū ��, maxheap
	* ���� �����ִ� ��尡 ���� ���� �� , minheap
	* heapify() - Ʈ���� �ռ����� �������ϴ� �ڵ� �Լ�
	* heapSort() - ������
	*/
	//���� , Ž�� ���� ���

	// �ݺ������

	for (int i = 0; i < people.size(); i++) //7
	{
		auto it = sheets.find(people[people.size() - 1 - i]);
		int index = it->second;
		answer[index] = i + 1;
	}

	std::cout << "[";
	for (int i = 0; i < answer.size(); i++)
	{
	  std::cout<< answer[i] << " ";
	}
	std::cout << "]" << std::endl;
}

int main()
{
	EmergencyExample();
}