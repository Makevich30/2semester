#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_palindrome(const string &word) {
    int left = 0;
    int right = word.length() - 1;
    while (left < right) {
        if (tolower(word[left]) != tolower(word[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string input, word, result;
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    getline(infile, input);
    input += ' ';

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            if (is_palindrome(word)) {
                result += word;
                result += ' ';
            }
            word = "";
        } else if (isalpha(input[i])) {
            word += input[i];
        }
    }

    outfile << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
