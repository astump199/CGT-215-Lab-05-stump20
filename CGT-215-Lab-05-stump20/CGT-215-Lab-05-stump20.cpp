// CGT-215-Lab-05-stump20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

// Function to translate a single character using the cipher vector
char translateChar(char c, const std::vector<char>& codeTable) {
    // IF char IS BETWEEN 65 AND 90 (is a capital letter 'A'-'Z')
    if (c >= 65 && c <= 90) {
        // RETURN THE CHAR AT SLOT char-65 IN CODE TABLE
        return codeTable[c - 65];
    }
    // ELSE IF char IS BETWEEN 97 AND 122 (is a lower case letter 'a'-'z')
    else if (c >= 97 && c <= 122) {
        // SET upperCaseLetter TO char - 32 (converts ASCII to upper case)
        char upperCaseLetter = c - 32;

        // SET upperCaseCode TO CHAR AT SLOT upperCaseLetter-65 IN CODE TABLE
        char upperCaseCode = codeTable[upperCaseLetter - 65];

        // RETURN upperCaseCode + 32 (convert code back to lower case)
        return upperCaseCode + 32;
    }
    // ELSE (is not a letter: spaces, punctuation, numbers, etc.)
    else {
        // RETURN char unchanged
        return c;
    }
}

// Function to translate an entire string line
std::string translateString(const std::string& input, const std::vector<char>& codeTable) {
    std::string result = "";
    for (char c : input) {
        result += translateChar(c, codeTable);
    }
    return result;
}

int main() {
    // Cipher substitution vector mapping A-Z (slots 0 to 25)
    std::vector<char> cipher = {
     'V', 'F', 'X', 'B', 'L', 'I', 'T', 'Z', 'J', 'R',
     'P', 'H', 'D', 'K', 'N', 'O', 'W', 'S', 'G', 'U',
     'Y', 'Q', 'M', 'A', 'C', 'E'
    };

    // Get input from the user using getline to support spaces
    std::string text;
    std::cout << "Input text to cypher: ";
    std::getline(std::cin, text);

    // Translate character by character
    std::string translatedText = translateString(text, cipher);

    // Output results
    std::cout << "Encoded Message: " << translatedText << std::endl;

    return 0;
}