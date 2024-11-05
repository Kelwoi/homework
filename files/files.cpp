#include <iostream>
#include <string>
#include<fstream>
using namespace std;
void compare_files(string name_file1, string name_file2) {
    int lineNum = 1;
    string line1, line2;
    bool allMatch = true;
	ifstream file1(name_file1);
	ifstream file2(name_file2);
    while (getline(file1, line1) and getline(file2, line2)) {
        if (line1 != line2) {
            allMatch = false;
            cout << "line " << lineNum << " doesn't match:" << endl;
            cout << "file 1: " << line1 << endl;
            cout << "file 2: " << line2 << endl << endl;
        }
        lineNum++;
        line1.clear();
        line2.clear();
    }
    if (allMatch) {
        cout << "all lines match" << endl;
    }

    file1.close();
    file2.close();

}
void file_statistic(string name_file1, string file_name2) {
    ifstream file(name_file1);
    int symbols = 0;
    int numeric = 0;
    int vowel_letter = 0;
    string vowels = "AEIOUYaeiouy";
    int consonant_letter = 0;
    string consonant = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
    string line;
    int lineNum = 1;
    while (getline(file, line)) {
        symbols += line.length();
        for (int i = 0; i < line.length(); i++)
        {
            if (isdigit(line[i])) {
                numeric++;
            }
            else if (vowels.find(line[i]) != string :: npos) {
                vowel_letter++;
            }
            else if (consonant.find(line[i]) != string::npos) {
                consonant_letter++;
            }
        }
        lineNum++;
        line.clear();
        

    }
    file.close();
    ofstream file1(file_name2);
    while (true) {
        file1 << "symbol count: " << symbols << endl;
        file1 << "lines count: " << lineNum << endl;
        file1 << "Vowels count: " << vowel_letter << endl;
        file1 << "Consonant count: " << consonant_letter << endl;
        file1 << "number count: " << numeric << endl;
        break;
    }
}
void Caesars_cipher(string out_file, string in_file, int movement) {
    ifstream file(out_file);
    string line;
    if (!file) {
        cout << "NO FILE!!!!!";
    }
    else {
        while (getline(file, line)) {
            for (size_t i = 0; i < line.length(); i++)
            {
                line[i] += movement;
            }
        }

    }
    file.close();
    ofstream file_in(in_file);
    if (!file_in) {
        cout << "No file to write in";
    }
    else {
        file_in << line;
    }
    file_in.close();
}
int main()
{
	string name_file1 = "my.txt";
	string name_file2 = "myy.txt";
	string name_file3 = "statistic.txt";
    string name_file4 = "Caesar_out.txt";
    string name_file5 = "Caesar_in.txt";
	compare_files(name_file1, name_file2);
    file_statistic(name_file1,name_file3);
    Caesars_cipher(name_file4, name_file5, 3);

}


