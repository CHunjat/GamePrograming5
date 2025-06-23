/*
* 알고리즘 대표 문제
*  - 수를 정렬하고 탐색하기
*  - 단순한 방법. 데이터를 정렬시킨다.
*  - k번째로 작은수? 왼쪽부터 하나씩 출력
*  - k번째로 큰 수 ? 오른쪽부터 하나씩 출력
*/

// 응급환자 순서를 제공해드립니다 . vector<int>
// 먼저 진료해야하는 환자가 1번부터 시작합니다

//트리에 저장방식을 응용해서  가장 큰 수를 찾는 형태를 구현하면 어떨까?

#include <iostream>
#include <vector>
#include <utility> //pair 사용
#include <map> //insert {pair -> people d}
#include <algorithm> //sort 함수

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


	// people 의 값을 정렬
	std::sort(people.begin(), people.end());

	//answer에 들어있는 가장 큰 수?
	//int key = sheets.find(answer[answer.size() - 1])->first; //sheets. 각 숙자에 들어있는 인덱스
	//sheets 에 들어있는 인덱스값을 반환해주세요
	//answer[key] = 1;

	/*
	* Tree 노드 삭제 
	* Tree 균형이 안잡힌 경우
	* 아이디어 1. 트리에 데이터를 넣을 때 균형잡히게 넣으면 되는거 아닌가?
	* 채워 넣은 다음에 서브트리들이 하나의 규칙을 갖도록 해보자.
	* Heap : 쌓여있다. 서브트리의 부모노드가 가장 큰수여야 한다. 가장 위에 있는 노드가 가장 큰 수.
	* 가장 위에 있는 노드가 가장 큰 수, maxheap
	* 가장 위에있는 노드가 가장 작은 수 , minheap
	* heapify() - 트리를 합순서로 재정렬하는 코드 함수
	* heapSort() - 힙정렬
	*/
	//정렬 , 탐색 같이 사용

	// 반복문사용

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