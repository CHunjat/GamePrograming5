#include <algorithm>
#include "mergesort.h"

void Quicksort(std::vector<int> data, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pivot = start;		//�����̵Ǵ� ��
	int i = start + 1;		// ���ʿ��� ������ ��ġ
	int j = end;			// �����ʿ��� ������ ��ġ
	int temp;				//swap�� ����ϱ� ���� �ӽú���

	while (i <= j)  
	{
		while (i <= end && data[i] >= data[pivot])  // �ǹ����� ū ���� ���� �� �� ���� ã�ƶ�(i�� ���� �������ִ� �ڵ�)  // �������� �ø����� �ε�ȣ �ٲ���
		{
			i++;
		}
		while (j > start && data[j] <= data[pivot]) // �ǹ����� ���� ���� ���� �� �� (j�� ���� �������ִ� �ڵ�) // ����������  �ø������ε�ȣ �ٲ���
		{
			j--;
		}


		// i < j // ���� �ε����� ������ �ε��� ���� ũ��(�����ȴ�)

		if (i > j)
		{
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else //�������� �ʾ��� �� (j�� i�� �ִ� ���� �����ϼ���)
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;

			//std::swap(data[i], data[j]);
		}

		//��� �Լ�

		//quicksort(���� ��Ʈ) quicksort(������ ��Ʈ)
		Quicksort(data, start, j - 1); //����
		Quicksort(data, j + 1, end); //������

	}
}

// sorted 4������ right ������ŭ�� arr���� �����ϴ� �ڵ带 ����� �ϼ��غ�����.

int main()
{
	std::cout << "\n���� ���� �迭 ���� " << std::endl; 

	int arr[6] = { 3 , 2, 5 , 1 , 4 , 8 };
	mergesort(arr, 6, 0, 5);
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << " ";
	}




	//int n;
	//std::cin >> n;

	//std::vector<int> list;
	//list.assign(n, 0); //ũ�⸦ �����Ҽ� �ִ� �Լ�

	//for (int i = 0; i < n; i++)
	//{
	//	std::cin >> list[i];
	//}

	////�߸� ġƮ
	////std::sort(list.begin(), list.end());


	//std::vector<int> nums1 = { 3,5,9,1,2,4,6,8,7,0 };
	//Quicksort(nums1,);
	//for (int num : nums1)
	//{
	//	std::cout << num << " ";
	//}
}