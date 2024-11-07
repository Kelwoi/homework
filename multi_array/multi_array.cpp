#include <iostream>
#include <ctime>
using namespace std;
void fill(int* arr, size_t length, int min = 1, int max = 10)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = min + rand() % (max - min + 1);
	}
}


void print(int* arr, size_t length, string prompt = "")
{
	if (!prompt.empty())
		cout << prompt << " :: ";
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}cout << endl;
}
void sort(int* arr1, const int size_arr1) {
	int temp = 0;
	for (size_t i = 0; i < size_arr1; i++)
	{
		for (size_t j = 0; j < size_arr1 - 1; j++)
		{
			if (arr1[j] < arr1[j + 1]) {
				temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;
			}
		}
	}
}

int unique_check(int* A, int* B, size_t size_a, size_t size_b)
{
	int counter = 0;
	if (size_a < size_b) {
		for (int i = 0; i < size_a; i++)
		{
			for (size_t j = 0; j < size_b; j++)
			{
				if (A[i] == B[j]) {
					counter++;
				}
			}
		}
	}
	else if (size_a > size_b) {
		for (int i = 0; i < size_a; i++)
		{
			for (size_t j = 0; j < size_b; j++)
			{
				if (B[j] == A[i]) {
					counter++;
				}
			}
		}
	}

	return counter;

}

int* clean_massive(int* A, int& size_a) {
	int counter = 0;
	for (size_t i = 0; i < size_a; i++)
	{
		if (A[i] == A[i + 1]) {
			counter++;
		}
	}
	int* clean_mass = new int[size_a - counter];
	int iter = 0;
	for (size_t i = 0; i < size_a - 1; i++)
	{
		if (A[i] != A[i + 1]) {
			clean_mass[iter] = A[i];
			iter++;
		}
	}
	clean_mass[iter] = A[size_a - 1];
	iter++;
	
	delete[] A;
	size_a = iter;
	return clean_mass;
	
}
void fill_res(int* A, int* B, size_t size_a, size_t size_b, int* arr_final, size_t arr_fin_size) {
	int j = 0;
	int i = 0;
	bool same = false;
	if (size_a < size_b) {
		for (; i < size_a;i++)
		{
			bool same = false;
			for (size_t x = 0; x < size_b; x++)
			{
				if (A[i] == B[x]) {
					same = true;
				}

			}
			if (same == false) {
				arr_final[j] = A[i];
				j++;
			}
		}
	}
	if (size_a > size_b) {
		for (; i < size_a; i++)
		{
			bool same = false;
			for (size_t x = 0; x < size_b; x++)
			{
				if (B[x] == A[i]) {
					same = true;
				}

			}
			if (same == false) {
				arr_final[j] = A[i];
				j++;
			}
		}
	}
	
}
void fill_arr(int* arr1, size_t length_arr1, int* arr2, size_t length_arr2, int* arr_fin, size_t arr_fin_size) {
	int iter = 0;
	if (length_arr1 <= length_arr2) {
		for (size_t i = 0; i < arr_fin_size; i++)
		{
			arr_fin[i] = arr2[i];


		}
		for (size_t j = length_arr2; j < arr_fin_size; j++)
		{
			arr_fin[j] = arr1[iter];
			iter++;
		}
	}
	else if (length_arr1 > length_arr2) {
		for (size_t i = 0; i < arr_fin_size; i++)
		{
			arr_fin[i] = arr1[i];


		}
		for (size_t j = length_arr1; j < arr_fin_size; j++)
		{
			arr_fin[j] = arr2[iter];
			iter++;
		}
	}

}
int main()
{
	srand(time(0));
	int A;
	int B;
	cout << "Enter first array size: ";
	cin >> A;
	cout << "Enter second array size: ";
	cin >> B;

	int* arr_a = new int[A];
	int* arr_b = new int[B];
	fill(arr_a, A);
	fill(arr_b, B);
	print(arr_a, A);
	print(arr_b, B);
	sort(arr_a, A);
	sort(arr_b, B);
	cout << "After sorting: " << endl;
	print(arr_a, A);
	print(arr_b, B);
	cout << "After cleaning: " << endl;
	arr_a = clean_massive(arr_a, A);
	print(arr_a, A);
	arr_b = clean_massive(arr_b, B);
	print(arr_b, B);
	int counter_a = unique_check(arr_a,arr_b,A,B);
	cout << "counter is " << counter_a << endl;
	int counter_final_a = A - counter_a;
	int* res_a = new int[counter_final_a];
	if (counter_final_a == 0) {
		cout << "No way bro, can't be less than 1";
	}
	else {
		fill_res(arr_a, arr_b, A, B, res_a, counter_final_a);
		cout << "A" << endl;
		print(res_a, counter_final_a);
	}
	// task 2, a and b
	int counter_b = unique_check(arr_b, arr_a, B, A);
	cout << "counter is " << counter_b << endl;
	int counter_final_b = B - counter_b;
	int* res_b = new int[counter_final_b];
	if (counter_final_b == 0) {
		cout << "No way bro, can't be less than 1";
	}
	else {
		fill_res(arr_b, arr_a, B, A, res_b, counter_final_b);
		cout << "B" << endl;
		print(res_b, counter_final_b);
	}
	int counter_final = counter_final_a + counter_final_b;
	int* arr_fin = new int[counter_final];
	fill_arr(res_a,counter_final_a, res_b, counter_final_b, arr_fin, counter_final);
	cout << "A + B" << endl;
	sort(arr_fin, counter_final);
	print(arr_fin, counter_final);

}