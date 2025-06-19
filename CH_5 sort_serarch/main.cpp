#include <iostream>
#include <vector>

/*
* 정렬을 다양한 방법으로 직접 구현.
* 왜 정렬을 해야하는가?
* 새로운 아이템(ITEM) 컨테이너 추가될 때, 
  정렬 되어 있는 상태로 저장이되는 경우가 있다.
*/

/*
* 탐색? : 컨테이너 안에 데이터가 있는지 없는지 찾는다.
* 탐색을 프로그래밍 코드로 한번 구현해보자.
* (1) 앞에서 부터 데이터를 비교해서 있는지 없는지 확인
*     - 선형 탐색 방법 (LINEAR SEARCH)
* (2) 이진 탐색 (binary search)
*     - 컨테이너가 정렬 되어 있을 때 중앙 값을 기준으로 데이터를 나누어서 찾는 방법.
*/

/*
* 선형 탐색의 경우에는 최선의 경우(best case) O(1) , 최악의 경우 n 시간이 걸림
* 평균 O(n)의 시간이 걸린다. 데이터의 갯수가 백만을 넘어가면 비효율적이다.
* 분할 정복 알고리즘 : 범위를 나누어서 작은 범위를 해결하는 방식으로 문제를 푼다.+
*/

#include <utility>

/*
* std::pair<int , 클래스이름> 
* std::pair<int, std::string>
* 
* std::vector<std::pair<int, std::string>> data;
* //pair타입 선언하는 방법
* data.push_back({0, "AAS"})
* //해당하는 인덱스가 있다면 그 인덱스에 저장되어 있는 문자를 출력하는 코드만들기.
* 
* // 유저의 id에 유저가 가진 벙보를 저장합니다. 서버에 유저의 ID를 기준으로 해당 유저의 정보를 
*    검색하는 기능을 구현해보세요
*/

/*
* ★★★ 탐색과 자료구조를 연관해서 생각해보기 ★★★
*  - vector      : 선형탐색, 이진탐색
*   - 조건 : 사용하는 컨테이너가 정렬이 되어 있어야 한다.
*    - 사용 중인 컨테이너의 특징 : 임의의 값을 바로 접근, 랜덤한 값을 수정할 때 비효율적이다.
* 
*  - list		: 랜덤한 값의 수정을 즉시 할 수 있다. 
     - mid index의 값과 target 비교
	   - 0 -> mid 순차적으로 탐색 후 mid 값을 반환한다.
	     결론 : 벡터써라

   단점 : logN시간을 확보했지만, 사용하기 위한 자료구조가 적합하지 않다.
   연관 컨테이너 : set, map // 트리 구조로 구현이 되어있다.
*/

template<typename T1,typename T2>
struct mypair
{
	int first;
	int second;
	// 페어끼리 복사, 이동, 연산자 오버로딩..... 등등
};

class Item
{
	int price;
	bool operator<(const Item& other)
	{
		return price < other.price;
	}
};



void LinearSearch(int arr[], int n , int target)
{
	// 전체 개수를 반복해서
	// target과 같은 데이터가 존재하면

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == target)
		{
			std::cout << "해당하는 데이터 :  " << target << "를 찾았습니다" << std::endl;
			break; 
		}
		 std::cout << "데이터를 찾지 못했습니다." << std::endl;
	}
}

void LinearSearch(std::vector<int> arr, int target)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == target)
		{
			std::cout << "해당하는 데이터 :  " << target << "를 찾았습니다" << std::endl;
			break;
		}
		std::cout << "데이터를 찾지 못했습니다." << std::endl;
	}
}

// iterator 방식으로 구현한 이진 탐색입니다.


void BinarySearch(int arr[], int n, int target)
{
	// int mid = (left + right) / 2 - 20억 +20억
	// int mid = left +(right -left) / 2 왼쪽 오른쪽  거리 /2 더해준다

	// i 왼쪽 arr[left] arr[right]
	int i = 0;
	// j 오른쪽
	int j = n - 1;

	while (i <= j) // 왼쪽과 오른쪽
	{
		// mid 의 값이 바껴야하기때문에 while 안쪽 // 루프 돌때마다 중앙값은 변경해준다.
		int mid = i + (j - i) / 2;

		// 현재 mid의 값과 target을 비교해보세요
		
		if (arr[mid] == target)						//target 찾은경우
		{
			std::cout << "해당하는 데이터 :  " << target << "를 찾았습니다" << std::endl;
			return;
		}
		else if (arr[mid] > target) 				//target이 작은경우
		{
			j = mid - 1; // mid의 기준으로 어떻게 j를 바꾸면 될까?

		}
		else										//target이 큰 경우
		{
			i = mid + 1; //왼쪽 i가 mid의 기준으로 어떻게 바뀌면 될까?
		}
	}
	std::cout << "데이터를 찾지 못했습니다" << std::endl;
}

// 재귀 함수 방식으로 구현한 이진 탐색
void BinarySearchByRecursive(int arr[], int n, int target, int left, int right)
{
	//재귀 함수를 탈출할 수 있는 조건

	if (left > right)
	{
		std::cout << "데이터를 찾지 못했습니다" << std::endl;
		return;
	}


	//중앙값 호출
	int mid = left + (right - left) / 2;
	//자기자신의 함수를 호출
	if (arr[mid]==target)
	{
		std::cout << "해당하는 데이터 :  " << target << "를 찾았습니다" << std::endl;
		return;
	}
	else if (arr[mid] > target) //왼쪽 (right = mid -1)
	{
		BinarySearchByRecursive(arr, n, target, left, mid -1);
	}
	else  //오른쪽 (left = mid + 1)
	{
		BinarySearchByRecursive(arr, n, target,mid+1,right);
	}

}

void Example()
{
	// pair 데이터 하나를 표현하는 방식 key, value 값을 구분해서 저장하는 방식
	// 연산자 오버로딩, 클래스 비교 재정의.
	// 유저의 ID - "고유한 숫자정보"

	std::vector<std::pair<int, std::string>> data; //3번째 버전
	data.push_back({ 0,"aaa" });
	data.push_back({ 1,"bbb" });
	data.push_back({ 2,"ccc" });
	data.push_back({ 3,"ddd" });
	data.push_back({ 4,"eee" });

	std::pair<int, std::string> a = { 1,"aaa" }; //1번째 버전

	std::make_pair(1, "aaa");				     //2번째 버전

	// 선형 탐색, 이진 탐색을 사용해서 결과값을 찾으세요

	//타입이 다르기 때문에 해당하는 타입으로 다시 만들어 줘야한다.

	std::vector<int> temp;
	for (int i = 0; i < data.size(); i++)
	{
		temp.push_back(data[i].first); //여기서 first int 값을 가리킴 첫번재꺼 두번째꺼 등등
	}
	LinearSearch(temp, 4); //이 코드의 경우는 말그대로 "4"만 찾으니 4가 존재한다면?
	std::cout << "데이터가 존재합니다 : (" << data[4].second << ")" << std::endl;  // 세컨드값을 출력을하라!

}

bool UserDataSearch(std::vector<std::pair<int, std::string>>data, int userID)
{
	//탐색 함수랑 + Pair 클래스 중복해서 코드를 표현할 수 있는가?
	//선형 탐색
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].first == userID)
		{
			std::cout << "닉네임 : " << data[i].second << std::endl;
			return true;
		}
	}
	std::cout << "유저 아이디에 해당하는 데이터가 없습니다" << std::endl;
	return false;
}

int main()
{
	std::cout << "유저 아이디로 닉네임 검색하기 예제" << std::endl;
	std::vector < std::pair<int, std::string>> data3;
	data3.push_back({ 0,"aaa" }); data3.push_back({ 1,"bbb" });
	data3.push_back({ 2,"ccc" }); data3.push_back({ 3,"ddd" });
	if (UserDataSearch(data3, 3)) //해당하는 유저 아이디가 존재한다면
	{
		data3[3].second = "eee";
		//무엇을 해야 할까? data3[3] -> 변경하는 코드를 작성할 수있다.
		//닉네임은 변경하세요 // 비밀번호를 입력하고 해당 닉네임으로 로그인 한다.
	}

	std::cout << "\n배열로 구현한 선형 탐색" << std::endl;
	int arr[5] = { 0,5,2,4,9 };
	LinearSearch(arr, 5, 2);

	std::cout << "\n 벡터로 구현한 선형 탐색" << std::endl;
	std::vector<int> data = { 0,5,2,4,9 };
	LinearSearch(data, 2);

	std::cout << "\n배열로 구현한 이진 탐색" << std::endl;
	int arr2[5] = { 0,2,4,5,9 };
	BinarySearch(arr2, 5, 2);

	std::cout << "\n배열로 구현한 재귀 방식의 이진 탐색" << std::endl;
	int arr3[5] = { 0,2,4,5,9 };
	BinarySearchByRecursive(arr3, 5, 2, 0, 4);

	std::cout << "\n 벡터로 구현한 이진 탐색" << std::endl;

}
