#include<iostream>
#include<string>
using namespace std;


/*************************������Ķ��ֲ���*********************************/

int BinarySearchUp(int * nums,int numslen,int key){//�����������,�ǵݹ�ʵ��
	int high, low, mid;
	high = numslen - 1;
	low = 0;
	while (low <= high){
		mid = high - (high - low) / 2;//����mid��λ��
		if (key == nums[mid]){//�ҵ���
			return mid;
		}
		else if (key < nums[mid]){//key������
			high = mid - 1;
		}
		else{//key���Ұ��
			low = mid + 1;
		}
	}
	return -1;
}

int BinarySearchDown(int * nums, int numslen, int key){//��Խ������飬�ǵݹ�ʵ��
	int high, low, mid;
	high = numslen - 1;
	low = 0;
	while (low <= high){
		mid = high - (high - low) / 2;//����mid��λ��
		if (key == nums[mid]){//�ҵ���
			return mid;
		}
		else if (key < nums[mid]){//key���Ұ��
			low = mid + 1;
		}
		else{//key������
			high = mid - 1; 
		}
	}
	return -1;
}

int BinarySearchUpRecursive(int * nums, int low, int high, int key){//����������飬���õݹ�ʵ��
	//�߽������ж�
	if (low > high){
		return -1;
	}

	int mid = low + (high - low) / 2;//����mid��λ��
	if (key == nums[mid]){//�ҵ���
		return mid;
	}
	else if (key > nums[mid]){//key���Ұ��
		return BinarySearchUpRecursive(nums, mid + 1, high, key);
	}
	else{//key������
		return BinarySearchUpRecursive(nums, low, mid - 1, key);
	}
}


/*************************����Ŀ��ֵ�������߽�*******************************************/
/*************************������Ŀ��ֵ��ȵĵ�һ��Ԫ��λ��*********************************/
/*************************���ҵ�һ����С��Ŀ��ֵ��Ԫ��λ��*********************************/


int BinarySearchLowerBound(int * nums, int numslen, int key){
	int low = 0, high = numslen - 1, mid;
	while (low <= high){
		mid = low + (high - low) / 2;
		if (key <= nums[mid]){//�����Ұ��
			high = mid - 1;
		}
		else{//���Ұ��
			low = mid + 1;
		}
	}
	if (nums[low] == key){//low < numslen && 
		return low;
	}
	else{
		return -1;
	}
}

/*************************����Ŀ��ֵ������ұ߽�*******************************************/
/*************************������Ŀ��ֵ��ȵ����һ��Ԫ��λ��*********************************/
/*************************���ҵ�һ��������Ŀ��ֵ��Ԫ��λ��*********************************/

int BinarySearchUpperBound(int * nums,int numslen, int key){
	int low = 0, high = numslen - 1, mid;
	while (low <= high){
		mid = low + (high - low) / 2;
		if (key >= nums[mid]){//�������
			low = mid + 1;
		}
		else{//�����
			high = mid - 1;
		}
	}
	if (key == nums[high]){ //high >= 0 &&
		return high;
	}
	else{
		return -1;
	}
}

/*************************���ҵ�һ������Ŀ��ֵ����*******************************************/
/*************************���ұ�Ŀ��ֵ������ӽ�Ŀ��ֵ����*********************************/
/*
�����Ѿ��ҵ������һ��������Ŀ��ֵ��������ô�������һλ��
����high + 1�����ǵ�һ������Ŀ��ֵ������*/
int BinarySearchBiggerOne(int * nums,int numslen,int key){
	int low = 0, high = numslen - 1, mid;
	while (low <= high){
		mid = low + (high - low) / 2;
		if (key >= nums[mid]){//�������
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	if (high+1 < numslen && key == nums[high]){
		return high + 1;
	}
	else{
		return -1;
	}
}
/*************************�������һ��С��Ŀ��ֵ����*******************************************/
/*************************���ұ�Ŀ��ֵС������ӽ�Ŀ��ֵ����*********************************/
int BinarySearchLessOne(int * nums, int numslen, int key){
	int low = 0, high = numslen - 1, mid;
	while (low <= high){
		mid = low + (high - low) / 2;
		if (key <= nums[mid]){//�����ұ�
			high = mid - 1;
		}
		else{//���ұ�
			low = mid + 1;
		}
	}
	if (low - 1 >= 0 && key == nums[low]){
		return low - 1;
	}
	else{
		return -1;
	}
}

/*************************������ת�������СֵԪ���±꣨���費�����ظ����֣�*********************************/
int BinarySearchRotateMinUnique(int * nums, int numslen){
	int low = 0, high = numslen - 1, mid;
	while (low < high){
		mid = low + (high - low) / 2;
		if (nums[mid] > nums[high]){//˵����Сֵ���Ұ��
			low = mid + 1;
		}
		else{//˵����Сֵ�����Ұ��
			high = mid;
		}
	}
	return high;//��ʱlow=high,дreturn high;һ����
}

/*************************������ת�������СֵԪ���±꣨��������ظ����֣�*********************************/
int BinarySearchRotateMinRepeated(int * nums, int numslen){
	int low = 0, high = numslen - 1, mid;
	while (low < high){
		mid = low + (high - low) / 2;
		if (nums[mid] > nums[high]){//��Сֵ���Ұ��
			low = mid + 1;
		}
		else if (nums[mid] < nums[high]){//��Сֵ�����Ұ��
			high = mid;
		}
		else{//��Сֵ����Ϊ��ǰֵ��Ҳ���������ߣ�Ҳ�������Ұ��
			high--;//С��ǰ��
		}
	}
	return low;
}

/*************************����ת�������������������費�����ظ����֣�*********************************/
int BinarySearchKeyInRotateUnique(int * nums, int numslen, int key){
	int low = 0, high = numslen - 1, mid;
	while (low <= high){
		mid = low + (high - low) / 2;
		if (key == nums[mid]){
			return mid;
		}
		else if (nums[low] <= nums[mid]){//�����������
			if (key >= nums[low] && key < nums[mid]){//key������
				high = mid - 1;
			}
			else{//key���Ұ��
				low = mid + 1;
			}
		}
		else if (nums[mid] <= nums[high]){//�Ұ���������
			if (key>nums[mid] && key <= nums[high]){//key���Ұ��
				low = mid + 1;
			}
			else{//key������
				high = mid - 1;
			}
		}
	}
	return -1;
}
/*************************����ת������������������������ظ����֣�*********************************/
bool BinarySearchKeyInRotateRepeat(int * nums, int numslen, int key){
	int low = 0, high = numslen - 1, mid;
	while (low <= high){
		mid = low + (high - low) / 2;
		if (key == nums[mid]){
			return true;
		}
		else if (nums[low] < nums[mid]){//��������
			if (key >= nums[low] && key < nums[mid]){//key������
				high = mid;
			}
			else{//key���Ұ��
				low = mid + 1;
			}
		}
		else if (nums[mid] < nums[high]){//�Ұ������
			if (key > nums[mid] && key <= nums[high]){//key���Ұ��
				low = mid + 1;
			}
			else{//key������
				high = mid;
			}
		}
		else {
			high--;
		}
	}
	return false;
}

int main(){
	int data[] = { 6, 5, 4, 3, 2, 1 };
	int data2[] = { 1, 2, 3, 4, 5, 6 };
	int data3[] = { 1, 3, 7, 7, 7, 14, 14, 14 };
	int data4[] = { 4, 5, 6, 7, 8, 1, 2, 3 };
	int data5[] = { 5, 5, 5, 6, 7,7,7, 8,8, 2, 2, 2, 3 };

	
	bool num = BinarySearchKeyInRotateRepeat(data5, 13, 2);//���������ʾ�����л���
	
	cout << "Index of the number is " << num <<"."<<endl;
	system("pause");
	return 0;
}