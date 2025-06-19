#include <iostream>
#include <vector>

/*
* ������ �پ��� ������� ���� ����.
* �� ������ �ؾ��ϴ°�?
* ���ο� ������(ITEM) �����̳� �߰��� ��, 
  ���� �Ǿ� �ִ� ���·� �����̵Ǵ� ��찡 �ִ�.
*/

/*
* Ž��? : �����̳� �ȿ� �����Ͱ� �ִ��� ������ ã�´�.
* Ž���� ���α׷��� �ڵ�� �ѹ� �����غ���.
* (1) �տ��� ���� �����͸� ���ؼ� �ִ��� ������ Ȯ��
*     - ���� Ž�� ��� (LINEAR SEARCH)
* (2) ���� Ž�� (binary search)
*     - �����̳ʰ� ���� �Ǿ� ���� �� �߾� ���� �������� �����͸� ����� ã�� ���.
*/

/*
* ���� Ž���� ��쿡�� �ּ��� ���(best case) O(1) , �־��� ��� n �ð��� �ɸ�
* ��� O(n)�� �ð��� �ɸ���. �������� ������ �鸸�� �Ѿ�� ��ȿ�����̴�.
* ���� ���� �˰��� : ������ ����� ���� ������ �ذ��ϴ� ������� ������ Ǭ��.+
*/

#include <utility>

/*
* std::pair<int , Ŭ�����̸�> 
* std::pair<int, std::string>
* 
* std::vector<std::pair<int, std::string>> data;
* //pairŸ�� �����ϴ� ���
* data.push_back({0, "AAS"})
* //�ش��ϴ� �ε����� �ִٸ� �� �ε����� ����Ǿ� �ִ� ���ڸ� ����ϴ� �ڵ常���.
* 
* // ������ id�� ������ ���� ������ �����մϴ�. ������ ������ ID�� �������� �ش� ������ ������ 
*    �˻��ϴ� ����� �����غ�����
*/

/*
* �ڡڡ� Ž���� �ڷᱸ���� �����ؼ� �����غ��� �ڡڡ�
*  - vector      : ����Ž��, ����Ž��
*   - ���� : ����ϴ� �����̳ʰ� ������ �Ǿ� �־�� �Ѵ�.
*    - ��� ���� �����̳��� Ư¡ : ������ ���� �ٷ� ����, ������ ���� ������ �� ��ȿ�����̴�.
* 
*  - list		: ������ ���� ������ ��� �� �� �ִ�. 
     - mid index�� ���� target ��
	   - 0 -> mid ���������� Ž�� �� mid ���� ��ȯ�Ѵ�.
	     ��� : ���ͽ��

   ���� : logN�ð��� Ȯ��������, ����ϱ� ���� �ڷᱸ���� �������� �ʴ�.
   ���� �����̳� : set, map // Ʈ�� ������ ������ �Ǿ��ִ�.
*/

template<typename T1,typename T2>
struct mypair
{
	int first;
	int second;
	// ���� ����, �̵�, ������ �����ε�..... ���
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
	// ��ü ������ �ݺ��ؼ�
	// target�� ���� �����Ͱ� �����ϸ�

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == target)
		{
			std::cout << "�ش��ϴ� ������ :  " << target << "�� ã�ҽ��ϴ�" << std::endl;
			break; 
		}
		 std::cout << "�����͸� ã�� ���߽��ϴ�." << std::endl;
	}
}

void LinearSearch(std::vector<int> arr, int target)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == target)
		{
			std::cout << "�ش��ϴ� ������ :  " << target << "�� ã�ҽ��ϴ�" << std::endl;
			break;
		}
		std::cout << "�����͸� ã�� ���߽��ϴ�." << std::endl;
	}
}

// iterator ������� ������ ���� Ž���Դϴ�.


void BinarySearch(int arr[], int n, int target)
{
	// int mid = (left + right) / 2 - 20�� +20��
	// int mid = left +(right -left) / 2 ���� ������  �Ÿ� /2 �����ش�

	// i ���� arr[left] arr[right]
	int i = 0;
	// j ������
	int j = n - 1;

	while (i <= j) // ���ʰ� ������
	{
		// mid �� ���� �ٲ����ϱ⶧���� while ���� // ���� �������� �߾Ӱ��� �������ش�.
		int mid = i + (j - i) / 2;

		// ���� mid�� ���� target�� ���غ�����
		
		if (arr[mid] == target)						//target ã�����
		{
			std::cout << "�ش��ϴ� ������ :  " << target << "�� ã�ҽ��ϴ�" << std::endl;
			return;
		}
		else if (arr[mid] > target) 				//target�� �������
		{
			j = mid - 1; // mid�� �������� ��� j�� �ٲٸ� �ɱ�?

		}
		else										//target�� ū ���
		{
			i = mid + 1; //���� i�� mid�� �������� ��� �ٲ�� �ɱ�?
		}
	}
	std::cout << "�����͸� ã�� ���߽��ϴ�" << std::endl;
}

// ��� �Լ� ������� ������ ���� Ž��
void BinarySearchByRecursive(int arr[], int n, int target, int left, int right)
{
	//��� �Լ��� Ż���� �� �ִ� ����

	if (left > right)
	{
		std::cout << "�����͸� ã�� ���߽��ϴ�" << std::endl;
		return;
	}


	//�߾Ӱ� ȣ��
	int mid = left + (right - left) / 2;
	//�ڱ��ڽ��� �Լ��� ȣ��
	if (arr[mid]==target)
	{
		std::cout << "�ش��ϴ� ������ :  " << target << "�� ã�ҽ��ϴ�" << std::endl;
		return;
	}
	else if (arr[mid] > target) //���� (right = mid -1)
	{
		BinarySearchByRecursive(arr, n, target, left, mid -1);
	}
	else  //������ (left = mid + 1)
	{
		BinarySearchByRecursive(arr, n, target,mid+1,right);
	}

}

void Example()
{
	// pair ������ �ϳ��� ǥ���ϴ� ��� key, value ���� �����ؼ� �����ϴ� ���
	// ������ �����ε�, Ŭ���� �� ������.
	// ������ ID - "������ ��������"

	std::vector<std::pair<int, std::string>> data; //3��° ����
	data.push_back({ 0,"aaa" });
	data.push_back({ 1,"bbb" });
	data.push_back({ 2,"ccc" });
	data.push_back({ 3,"ddd" });
	data.push_back({ 4,"eee" });

	std::pair<int, std::string> a = { 1,"aaa" }; //1��° ����

	std::make_pair(1, "aaa");				     //2��° ����

	// ���� Ž��, ���� Ž���� ����ؼ� ������� ã������

	//Ÿ���� �ٸ��� ������ �ش��ϴ� Ÿ������ �ٽ� ����� ����Ѵ�.

	std::vector<int> temp;
	for (int i = 0; i < data.size(); i++)
	{
		temp.push_back(data[i].first); //���⼭ first int ���� ����Ŵ ù���粨 �ι�°�� ���
	}
	LinearSearch(temp, 4); //�� �ڵ��� ���� ���״�� "4"�� ã���� 4�� �����Ѵٸ�?
	std::cout << "�����Ͱ� �����մϴ� : (" << data[4].second << ")" << std::endl;  // �����尪�� ������϶�!

}

bool UserDataSearch(std::vector<std::pair<int, std::string>>data, int userID)
{
	//Ž�� �Լ��� + Pair Ŭ���� �ߺ��ؼ� �ڵ带 ǥ���� �� �ִ°�?
	//���� Ž��
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].first == userID)
		{
			std::cout << "�г��� : " << data[i].second << std::endl;
			return true;
		}
	}
	std::cout << "���� ���̵� �ش��ϴ� �����Ͱ� �����ϴ�" << std::endl;
	return false;
}

int main()
{
	std::cout << "���� ���̵�� �г��� �˻��ϱ� ����" << std::endl;
	std::vector < std::pair<int, std::string>> data3;
	data3.push_back({ 0,"aaa" }); data3.push_back({ 1,"bbb" });
	data3.push_back({ 2,"ccc" }); data3.push_back({ 3,"ddd" });
	if (UserDataSearch(data3, 3)) //�ش��ϴ� ���� ���̵� �����Ѵٸ�
	{
		data3[3].second = "eee";
		//������ �ؾ� �ұ�? data3[3] -> �����ϴ� �ڵ带 �ۼ��� ���ִ�.
		//�г����� �����ϼ��� // ��й�ȣ�� �Է��ϰ� �ش� �г������� �α��� �Ѵ�.
	}

	std::cout << "\n�迭�� ������ ���� Ž��" << std::endl;
	int arr[5] = { 0,5,2,4,9 };
	LinearSearch(arr, 5, 2);

	std::cout << "\n ���ͷ� ������ ���� Ž��" << std::endl;
	std::vector<int> data = { 0,5,2,4,9 };
	LinearSearch(data, 2);

	std::cout << "\n�迭�� ������ ���� Ž��" << std::endl;
	int arr2[5] = { 0,2,4,5,9 };
	BinarySearch(arr2, 5, 2);

	std::cout << "\n�迭�� ������ ��� ����� ���� Ž��" << std::endl;
	int arr3[5] = { 0,2,4,5,9 };
	BinarySearchByRecursive(arr3, 5, 2, 0, 4);

	std::cout << "\n ���ͷ� ������ ���� Ž��" << std::endl;

}
