#pragma once

/*
* ��� �ڵ带 �����غ��� ������? 
*/

/*
* ���� ����
* �ٽ� ���� : �ϴ� ������, 1���� �ɶ� ����
*/


/*
* ������ = mergesort
* ��ģ�� = merge
*/

/*
*  ���� ���� 
*  ���� : ���ĵǾ� �������� ������
*  ���� : n�� ũ�Ⱑ ũ�� Ŭ ���� ��ȿ�����̴�
*  100�� ������ ������ ���ĵǾ� �ִ� ������ ������ ����ϸ� �����̴�.
* 
*  �� ����
*  ���� :���������� ���� ����Ѵ�. stL sort
*		 ��κ��� ��쿡 n logn �ð��� �����Ѵ�.
*  ���� : worst case�� O(n^2)
*  ������ �� sort. pivot - �� ����, �˰��� �߰�
* 
* ���� ����
* ���� : ��������� NlogN �ð��� �����Ѵ�.
* ���� : sorted ������ ���� �迭�� ����ϱ� ������, �߰����� �޸𸮸� ����Ѵ�.
* 
* ���� ���� ��� �˰��� ��� �߰��ؼ� sort(begin(), end()) ; ���� �� 
*/

#include <iostream>
#include <vector>

void merge(int arr[], int n, int left, int mid, int right)
{
	// 1. ���ĵ� �����͸� ���� ������ �迭 ������ �����մϴ�. (sorted array ���� �迭)
	std::vector<int> sorted;		// ���ʰ� �������� ���ؼ� ���Ľ�Ų ���� ������ �ӽ� �����̳�
	sorted.assign(n, 0);			// n���� ������ �����Ͱ� 0���� �ʱ�ȭ�� �����迭�� ����
	int i = left;					// ���ʿ��� �����ϴ� �ε��� ��ȣ
	int j = mid + 1;                // int j = right <- �ȵ�!!!   
	int k = left;				    // ���ĵ� �ε������� ���� ù���� �ε��� ��ȣ

	// 2. arr �迭�ȿ� ����ִ� �� left ���� right �ε��� �� ���� ���� sorted�� ��������
	// left ������� , right ������� 

	while (i <= mid && j <= right)  //� ������ ����ؾ��ұ�? // ���� �Ǵ� ������ �ε����� ���� �������� �����ϼ���
	{
		if (arr[i] <= arr[j])
		{
			sorted[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			sorted[k] = arr[j];
			j++;
			k++;
		}
	}
	// 3. i�� �������� j�� �������� �������� ���� ä�켼��
	if (i > mid) //i�� �� ����� ���, ���� �ε����� j�� ���� ���
	{
		for (int t = j; t <= right; t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}
	else //j�� �ٻ���Ѱ��, i�� ��������
	{
		for (int t = i; t <= mid; t++)
		{
			sorted[k] = arr[t];
			k++;
		}

	}
	//4. sorted�� ���� ���ĵ� �����̴� arr ���� �����Ϳ� ���ĵ� �����͸� �Ű��ش�!!
	for (int t = left; t <= right; t++)
	{
		arr[t] = sorted[t];
	}
	
}

void mergesort(int arr[], int n, int left, int right)
{
	// ��������� mergesort

	//���ʺκ� mergesort
	//�����ʺκ� mergesort

	if (left < right) //���࿡ ����Ʈ ����Ʈ ����? ���Ұ� 1���̴�.
	{
		int mid = (left + right) / 2; //(left, right����ؼ� �����غ�����.)
		mergesort(arr, n, left, mid); // ���� �κ�
		mergesort(arr, n, mid + 1, right); // ������ �κ�

		merge(arr, n, left, mid, right);
	}
	
}