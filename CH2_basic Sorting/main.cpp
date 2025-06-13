#include <iostream>
#include <vector>
#include <algorithm>

/*
* nums �迭���� �׽�Ʈ ���̽��� ���´�.
* nums vector �� 1,3,5,7,9..... ������ ������ ���´�
* �� ���ڸ� �������� �����غ����� �� ������ ���� answer�� ������ �غ�����
* �����غ�����
*/

/*
* �ڵ带 ���� �� �ִ� = �� ���� �˰��� �ڵ尡 �����Ѵ�
* �ð� ���⵵, ���� ���⵵
* �ּ� : �ڵ尡 ������ ������ ���� ����ϴ� �ڵ�
* �ð��� ������ �׸�ŭ ������ ������
* �ð��� ������ ������ �� ����ϴ� ��찡 ����
*/

/*
*  O(1), (log n) ,(n), (n^2)
*  n�� ũ��      1    10     100     1000     1,000,000
*  O(1)          1     1       1       1          1       
   O(log n)      0    1        2       3          6
   O(n)          1    10     100     1000     1,000,000
   ���� : ��κ��� �˰��� ������ �׽�Ʈ ���̽��� ������ ���� ��츦 ����
*/

/*
* �ð� ���⵵�ε� �� ���� �ð��� ���ϴ� ���� �ƴ϶� ���� Ƚ���� ���ұ��?
*  - ȯ�濡 ���� ��� ���� �޶�����.
*  - ���� Ƚ���� ������ ���� ���� ū ������ �񱳸� ����.
*  - O(n) ��� ǥ���
*/

#pragma region �ð� ���⵵ ����ϱ�

void Test1()
{
	//1 ~ 5 ������ ���ڸ� ���� ���� ���� ����ϼ���.  // int Ÿ�� sum�� �� 0�� �Ҵ�. ���� 1��
	int sum = 0; 

	int n = 0; 
	std::cin >> n; //ũ�Ⱑ �������� ����

	for (int i = 1; i < 6; i++)
	{
		sum += i;  //5�� ����
	}

	// 38 �ڵ��� ���� Ƚ�� : n + 3�� 

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			sum += i * j;  // 5�� 2�� 
		}
	}

	// 45 �ڵ��� ���� Ƚ�� : n^2 + n + 3

}




#pragma endregion







std::vector<int> solution(std::vector<int> nums)
{
	std::vector<int> answer;
	std::sort(nums.begin(), nums.end()); //STL�� �����Ǿ� �ִ� ������ ����ϰڴ�.
	answer = nums;
	return answer;
}

//���� �Ǿ����� �ʴ� ���ڸ� �迭�� �޾ƿͼ� �� ���� �����ϴ� �Լ��� ����� ������.

// ���� ����, ���� ����, ���� ����

#pragma region ���� ����
//������ ���������� �ð��� �����ɸ��� ����
void bubblesort(int arr[], int n)
{	// ����Ŭ�� ��� ���ƾ� �ϴ°�?
	
	for (int i = 0; i < n; i++) //n - 1 �� ����Ŭ�� Ƚ��
	{
		for (int j = 0; j < n - i - 1; j++)  //j,i 3���� ǥ���Ϸ��� ��� �ؾ��ұ�?
		{
			//swap �ڵ带 ���� ����

			if (arr[j] > arr[j + 1]) //���� ���� ���� ������ ũ�� ���� �����ϼ���
			{
				//swap�� �����ϼ���
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " "; 
	}
	// ����Ŭ ���� ������ �ؾ��ϴ°�?
	// 1. �迭 ��ҳ��� �񱳸� �Ѵ�.



}

//vector. size()

// �ð� ���⵵ : 0(N^2)
// �ּ�, �־�, ���
// �������� :   �ּ�(O(n)) , �־�(O(n^2)), ��� (O(n^2))

void bubblesort(std::vector<int> nums)
{
	int n = nums.size();

	for (int i = 0; i < n - 1; i++)// �ڽŰ��� �� x
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				std::swap(nums[j], nums[j + 1]);
			}
		}
	}
	for (int n : nums)
	{
		std::cout << n << " ";
	}
	
}



#pragma endregion

#pragma region ���� ����

// ���� ���� ���� ����
// �Ǿտ� ������ ������� �����Ѵ�.
// ����Ŭ ���� ���� ���� ���� ����� ��ġ�� ã�ƾ� �մϴ�.

void SelectionSort(int arr[], int n)
{
	// ��� ����Ŭ? �ڱ��ڽ� �����
	for (int i = 0; i < n-1; i++)
	{
		int min_idx = i;


		for (int j = i+1 ; j < n ; j++)
		{
			// arr[min+index} arr[j] ������ �ʰ� �ּҰ�
			if (arr[min_idx] < arr[j])
			{
				min_idx = j;
			}
		}

		if (i != min_idx)
		{
			std::swap(arr[i], arr[min_idx]);
		}
	}

	// arr[j]�� ����,. ���� ���� ��(Index) arr[min]

	// swap arr[��] arr[min]

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "  ";
	}
}

void SelectionSort(std::vector<int> nums)
{
	int n = nums.size();
}


// �ð� ���⵵ : O(n^2) O(n)

#pragma endregion

#pragma region ���� ����
#pragma endregion




void Execute()
{
	std::vector<int> nums = { 1,5,4,3,2 };
	auto v = solution(nums);

	for (auto& elem : v)
	{
		std::cout << elem << "  ";
	}
}

int main()
{
	//Execute();
	std::cout << " ���� ���� �ڵ� ���� " << std::endl;
	int arr[5] = { 3,1,2,6,9 };
	bubblesort(arr, 5);
	std::cout << " ���� ���� �ڵ� ����2 " << std::endl;
	std::vector<int> nums = { 5,1,2,7,3 };
	bubblesort(nums);
	
	std::cout << "\n���� ���� �ڵ� ����" << std::endl;
	int arr2[5] = { 3,1,2,6,9 };
	SelectionSort(arr2, 5);

}