
#include <iostream>
#include <string>
using namespace std;
int compare(string row1, string row2) {
    if (row1.length() > row2.length()) {
        return 1;
    }    
    if (row1.length() == row2.length()) {
        return 0;
    }    
    if (row1.length() < row2.length()) {
        return -1;
    }

}
void capitalise(string row1) {
    if (!row1.empty()) {
        row1[0] = toupper(row1[0]);
        cout << row1;
    }
}
void countVowels(string str) {
    int count = 0;
    string vowels = "AEIOUYaeiouy";
    const int Length = str.length();
    for (int i = 0; i < Length; i++)
    {
        if (vowels.find(str[i]) != string :: npos) {
            count++;
        }
    }
    cout << count;
}
string Shorter(string row, int size) {
    if (row.length() > size) {

        return row.substr(0, size - 3) + "...";
    }
    else
        return row;
}
void Palindrome(string row) {
    int left = 0;
    int right = row.length() - 1;
    bool palindrome = true;
    while (left < right) {
        if (row[left] == row[right]) {
            left++;
            right--;
        }
        else if (row[left] != row[right]) {
            palindrome = false;
        }
    }
    if (palindrome == true) {
        cout << "this word is palindrome";
    }
    else if (palindrome == false) {
        cout << "this word isn't palindrome";
    }
}
int word_count(string row) {
    int count = 0;
    int length = row.length();
    bool inword = false;
    for (size_t i = 0; i < length; i++)
    {
        if (isspace(row[i]) or ispunct(row[i])) {
            count++;
            inword = false;
        }
        else
            inword = true;
    }
    if (inword) {
        count++;
    }
    return count;
}
string longest_word(string row) {
    string longestWord;
    string currentWord;
    int length = row.length();
    for (size_t i = 0; i < length; i++)
    {
        if (isalnum(row[i])) {
            currentWord += row[i];
        }
        else {
            if (!currentWord.empty()) {
                if (currentWord.length() > longestWord.length()) {
                    longestWord = currentWord;
                }
                currentWord.clear();
            }
        }
    }
    if (!currentWord.empty() and currentWord.length() > longestWord.length()) {
        longestWord = currentWord;
    }
    return longestWord;
}
void average_word_size(string row) {
    int words = word_count(row);
    int length = row.length();
    int average = length / words;
    cout << "Average size of word is " << average;
}
void search(string row, char letter) {
    int length = row.length();
    int count = 0;
    cout << "Letter appearing as:" << endl;
    for (size_t i = 0; i < length; i++)
    {
        if (row[i] == letter) {
            cout << i + 1 << "\t";
            count++;
        }

    }
    cout << "letters";
    cout << endl;
    if (count > 0) {
        cout << "Letter " << letter << " appearead in row for " << count << "times.";
    }
    else {
        cout << "Letter " << letter << "Never appearead in row";
    }
}
int main()
{
    string row1 = "never give up";
    string row2 = "Stone dave upperrrr";
    string row3 = "aboba aboba aboba";
    cout << compare(row1, row2) << endl;
    capitalise(row1); 
    cout << endl;
    countVowels(row1);
    cout << endl;
    cout << Shorter(row1, 13);
    cout << endl;
    Palindrome(row3);
    cout << endl;
    cout << "Words in row is " << word_count(row3);
    cout << endl;
    cout << longest_word(row2);
    cout << endl;
    average_word_size(row2);
    cout << endl;
    search(row3, 'a');
}

