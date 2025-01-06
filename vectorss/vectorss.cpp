

#include <iostream>
#include <vector>
using namespace std;
int main()
{

    vector<int> v1;
    cout << "Enter several elements for vector v1 (end with 0):" << endl;
    int input;
    while (cin >> input && input != 0) {
        v1.push_back(input);
    }

    vector<int> v2(10, 0);

    int n;
    cout << "Enter the number of elements for vector v3: ";
    cin >> n;
    vector<int> v3(n);
    for (int i = 0; i < n; ++i) {
        v3[i] = i + 1;
    }

    vector<int> v4(v1);

    vector<int> v5(v3.begin() + 1, v3.end() - 1);


    cout << "Elements of vector v3: ";
    for (int x : v3) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Elements of vector v1 in reverse order: ";
    for (auto it = v1.rbegin(); it != v1.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; ++i) {
        v2[i] = i + 1;
    }
    v2.erase(v2.begin() + 1); 
    v2.pop_back();

    cout << "Elements of vector v2 after modifications: ";
    for (int x : v2) {
        cout << x << " ";
    }
    cout << endl;

    
    vector<int> temp;
    for (int x : v4) {
        temp.push_back(x);
        temp.push_back(x);
    }
    v4 = temp;

  
    v5.clear();
    for (int x : v4) {
        if (x % 2 == 0) {
            v5.push_back(x / 2);
        }
    }

    cout << "Elements of vector v5 after processing: ";
    for (int x : v5) {
        cout << x << " ";
    }
    cout << endl;

   
    int value;
    cout << "Enter a value to search in v5: ";
    cin >> value;

    cout << "Positions of elements in v5 equal to " << value << ": ";
    for (size_t i = 0; i < v5.size(); ++i) {
        if (v5[i] == value) {
            cout << i << " ";
        }
    }
    cout << endl;

    int count_value = 0;
    for (int x : v5) {
        if (x == value) {
            ++count_value;
        }
    }
    cout << "Count of elements in v5 equal to " << value << ": " << count_value << endl;

    
    swap(v4, v5);

    cout << "Elements of vector v4 after swapping: ";
    for (int x : v4) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Elements of vector v5 after swapping: ";
    for (int x : v5) {
        cout << x << " ";
    }
    cout << endl;


}


