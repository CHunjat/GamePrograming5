#include <algorithm>
#include "mergesort.h"

void Quicksort(std::vector<int> data, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pivot = start;		//기준이되는 값
	int i = start + 1;		// 왼쪽에서 변경할 위치
	int j = end;			// 오른쪽에서 변경할 위치
	int temp;				//swap을 사용하기 위한 임시변수

	while (i <= j)  
	{
		while (i <= end && data[i] >= data[pivot])  // 피벗보다 큰 값을 만날 때 그 값을 찾아라(i의 값을 변경해주는 코드)  // 내림차순 올림차순 부등호 바꾸자
		{
			i++;
		}
		while (j > start && data[j] <= data[pivot]) // 피벗보다 작은 값을 만날 때 그 (j의 값을 변경해주는 코드) // 내림차순은  올림차순부등호 바꾸자
		{
			j--;
		}


		// i < j // 왼쪽 인덱스가 오른쪽 인덱스 보다 크면(엇갈렸다)

		if (i > j)
		{
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else //엇갈리지 않았을 때 (j와 i에 있는 값을 변경하세요)
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;

			//std::swap(data[i], data[j]);
		}

		//재귀 함수

		//quicksort(왼쪽 파트) quicksort(오른쪽 파트)
		Quicksort(data, start, j - 1); //왼쪽
		Quicksort(data, j + 1, end); //오른쪽

	}
}

// sorted 4번으로 right 갯수만큼을 arr값에 복사하는 코드를 만들어 완성해보세요.

int main()
{
	std::cout << "\n병합 정렬 배열 버전 " << std::endl; 

	int arr[6] = { 3 , 2, 5 , 1 , 4 , 8 };
	mergesort(arr, 6, 0, 5);
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << " ";
	}




	//int n;
	//std::cin >> n;

	//std::vector<int> list;
	//list.assign(n, 0); //크기를 배정할수 있는 함수

	//for (int i = 0; i < n; i++)
	//{
	//	std::cin >> list[i];
	//}

	////야매 치트
	////std::sort(list.begin(), list.end());


	//std::vector<int> nums1 = { 3,5,9,1,2,4,6,8,7,0 };
	//Quicksort(nums1,);
	//for (int num : nums1)
	//{
	//	std::cout << num << " ";
	//}
}