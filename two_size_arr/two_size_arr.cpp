#include <iostream>
using namespace std;
template <typename T>
void fill(T** arr, const size_t row, const size_t col, int min = 1, int max = 10)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr[i][j] = min + rand() % (max - min + 1);
        }
    }
}
template <typename T>
void print(T** arr, const size_t row, const size_t col, string prompt = "")
{
    if (!prompt.empty())
        cout << prompt << " :: " << endl;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << arr[i][j] << "\t";
        }cout << endl;
    }
}

template<typename T>
void insertCol(T** arr, const size_t& row, int& col, const size_t& index, T value = T())
{
    if (index > col) {
        cout << "Error! The index is out of range" << endl;
        return;
    }
    for (size_t i = 0; i < row; i++)
    {
        T* tmp = new T[col + 1];
        for (size_t j = 0; j < col; j++)
        {
            if (j < index)
                tmp[j] = arr[i][j];
            else
                tmp[j + 1] = arr[i][j];
        }
        tmp[index] = value;
        delete[] arr[i];
        arr[i] = tmp;
    }
    col++;
}
template<typename T>
void add_startCol(T** arr, const size_t& row, int& col, T value = T()) {
    int start = 0;
    for (size_t i = 0; i < row; i++)
    {
        T* tmp = new T[col + 1]; 
        for (size_t j = 0; j < col; j++)
        {
            tmp[j + 1] = arr[i][j];
        }
        tmp[start] = value;
        delete[] arr[i];
        arr[i] = tmp;
    }
    col++;
}
template<typename T>
void add_endCol(T** arr, const size_t& row, int& col, T value = T()) {
    int end = col;
    for (size_t i = 0; i < row; i++)
    {
        T* tmp = new T[col + 1];
        for (size_t j = 0; j < col; j++)
        {
            tmp[j] = arr[i][j];
        }
        tmp[end] = value;
        delete[] arr[i];
        arr[i] = tmp;
    }
    col++;
}
template <typename T>
void removeCol(T** arr, const size_t& row, int& col, const size_t& index) {
    if (index >= col)
    {
        cout << "Error! The index is out of range" << endl;
        return;
    }
    col--;
    for (size_t i = 0; i < row; i++)
    {
        T* tmp = new T[col];
        for (size_t j = 0; j < col; j++)
        {
            if (j < index)
                tmp[j] = arr[i][j];
            else
                tmp[j] = arr[i][j + 1];
        }
        delete[] arr[i];
        arr[i] = tmp;
    }
}
template <typename T>
void remove_startCol(T** arr, const size_t& row, int& col) {
    col--;
    for (size_t i = 0; i < row; i++)
    {
        T* tmp = new T[col];
        for (size_t j = 0; j < col; j++)
        {
                tmp[j] = arr[i][j + 1];
        }
        delete[] arr[i];
        arr[i] = tmp;
    }
}
template <typename T>
void remove_endCol(T** arr, const size_t& row, int& col) {
    int start = col;
    col--;
    for (size_t i = 0; i < row; i++)
    {
        T* tmp = new T[col];
        for (size_t j = 0; j < col; j++)
        {
            tmp[j] = arr[i][j];
        }
        delete[] arr[i];
        arr[i] = tmp;
    }
}
// row
template <typename T>
void remove(T**& arr, int& row, const size_t& index)
{
    if (index >= row) {
        cout << "Error. out-of-range index" << endl;
        return;
    }
    T** temp = new T * [--row];
    for (size_t i = 0; i < row; i++)
    {
        if (i < index)
        {
            temp[i] = arr[i];
        }
        else {
            temp[i] = arr[i + 1];
        }
    }
    delete[] arr[index];
    delete[] arr;
    arr = temp;
}
template <typename T>
void remove_startRow(T**& arr, int& row)
{
    int start = 0;
    T** temp = new T * [--row];
    for (size_t i = 0; i < row; i++)
    {
        temp[i] = arr[i + 1];
    }
    delete[] arr[start];
    delete[] arr;
    arr = temp;
}
template <typename T>
void remove_endRow(T**& arr, int& row)
{
    int start = row - 1;
    T** temp = new T * [--row];
    for (size_t i = 0; i < row; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr[start];
    delete[] arr;
    arr = temp;
}
template <typename T>
void insert(T**& arr, int& row, const size_t& col, const size_t& index)
{
    if (index > row) {
        cout << "Error! out range !!" << endl;
        return;
    }
    T** tmp = new T * [row + 1];
    for (size_t i = 0; i < row; i++)
    {
        if (i < index)
        {
            tmp[i] = arr[i];
        }
        else {
            tmp[i + 1] = arr[i];
        }
    }
    tmp[index] = new T[col]{};
    delete[] arr;
    row++;
    arr = tmp;
}
template <typename T>
void insert_startRow(T**& arr, int& row, const size_t& col)
{

    T** tmp = new T * [row + 1];
    for (size_t i = 0; i < row; i++)
    {
        tmp[i + 1] = arr[i];
    }
    tmp[0] = new T[col]{};
    delete[] arr;
    row++;
    arr = tmp;
}
template <typename T>
void insert_endRow(T**& arr, int& row, const size_t& col)
{

    T** tmp = new T * [row + 1];
    for (size_t i = 0; i < row; i++)
    {
        tmp[i] = arr[i];
    }
    tmp[row] = new T[col]{};
    delete[] arr;
    row++;
    arr = tmp;
}
int main()
{
    int row = 4, col = 5;

    int** arr = new int* [row];

    for (size_t i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    fill(arr, row, col);
    cout << "Before; " << endl;
    print(arr, row, col);
    insertCol(arr, row, col, 0);
    cout << "After" << endl;
    print(arr, row, col);
    cout << "Before; " << endl;
    print(arr, row, col);
    add_startCol(arr, row, col);
    cout << "After" << endl;
    print(arr, row, col);
    cout << "Before; " << endl;
    print(arr, row, col);
    add_endCol(arr, row, col);
    add_endCol(arr, row, col);
    cout << "After" << endl;
    print(arr, row, col);
    cout << "Before; " << endl;
    print(arr, row, col);
    remove_startCol(arr, row, col);
    cout << "After" << endl;
    print(arr, row, col);
    cout << "Before; " << endl;
    print(arr, row, col);
    remove_endCol(arr, row, col);
    cout << "After" << endl;
    print(arr, row, col);
    cout << "Before; " << endl;
    print(arr, row, col);
    insert_startRow(arr, row,col);    
    insert_endRow(arr, row,col);    

    cout << "After" << endl;
    print(arr, row, col);
}
