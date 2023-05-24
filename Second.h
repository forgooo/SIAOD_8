#ifndef INC_8_SECOND_H
#define INC_8_SECOND_H
#include <iostream>
#include <string>

int Cf = 0;
int Mf = 0;

bool isPalindrome(const std::string& str, int start, int end) {
    while (start < end) {
        Cf++;
        if (str[start] != str[end]) {
            Cf++;  // Increment counter for !=
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void preprocessBoyerMoore(const std::string& str, int* suffixShift, int* prefixShift) {
    int m = str.length();
    int lastPrefixPos = m;
    Mf+=2;

    // Initializing arrays
    for (int i = m - 1; i >= 0; i--) {
        if (isPalindrome(str, i + 1, m - 1)) {
            Cf++;  // Increment counter for function call
            lastPrefixPos = i + 1;
            Mf++;
        }
        suffixShift[i] = lastPrefixPos - (m - i);
        Mf++;
    }

    for (int i = 0; i < m; i++) {
        prefixShift[i] = m - 1 - i;
        Mf++;
    }

    for (int i = m - 2; i >= 0; i--) {
        if (suffixShift[i] == i + 1) {
            for (int j = 0; j < m - 1 - i; j++) {
                if (prefixShift[j] == m - 1 - i) {
                    Cf++;  // Increment counter for ==
                    prefixShift[j] = m - 1 - i;
                    Mf++;
                }
            }
        }
    }
}

std::string findLongestPalindrome(const std::string& str) {
    if (str.empty())
        return "";

    std::string paddedStr = "#";
    Mf++;
    for (char c : str) {
        paddedStr += c;
        paddedStr += '#';
    }

    int n = paddedStr.length();
    int maxLen = 0;
    int start = 0;
    Mf+=3;
    int* suffixShift = new int[n];
    int* prefixShift = new int[n];

    preprocessBoyerMoore(paddedStr, suffixShift, prefixShift);

    for (int i = 0; i < n; i++) {
        int j = 0;
        Mf++;
        while (i - j >= 0 && i + j < n && paddedStr[i - j] == paddedStr[i + j]) {
            Cf+=3;  // Increment counter for ==
            j++;
        }

        j--;

        if (j > maxLen) {
            maxLen = j;
            start = (i - j) / 2;
            Mf+=2;
            Cf++;
        }
    }

    delete[] suffixShift;
    delete[] prefixShift;
    std::cout << Cf << "+" << Mf << " TIME = ";
    return str.substr(start, maxLen);
}

std::string generateRandomString(int length) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 35);

    std::string result;
    const std::string chars = "abcdefghijklmnopqrstuvwxyz0123456789";

    for (int i = 0; i < length; ++i) {
        result += chars[dis(gen)];
    }

    return result;
}

#endif //INC_8_SECOND_H
