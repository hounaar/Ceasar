#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Function to decode the input string using Caesar cipher
string decode(const string& input, int shift) {
    string decodedContent = input;
    for (char& c : decodedContent) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base - shift + 26) % 26 + base;
        }
    }
    return decodedContent;
}

// Function to encode the input string using Caesar cipher
string encode(const string& input, int shift) {
    string encodedContent = input;
    for (char& c : encodedContent) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }
    return encodedContent;
}

// Function to save content to a file
void saveToFile(const string& content, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
    } else {
        cerr << "Error: Unable to create or write to the file." << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <options> <input_file>" << endl;
        cout << "Options:" << endl;
        cout << "  -h: Help" << endl;
        cout << "  -e: Encode the file" << endl;
        cout << "  -d: Decode the file" << endl;
        cout << "  -ep: Encode and print" << endl;
        cout << "  -ed: Decode and print" << endl;
        cout << "  -epdf: Encode and save as PDF" << endl;
        cout << "  -dpdf: Decode and save as PDF" << endl;
        return 1;
    }

    string option = argv[1];

    if (option == "-h") {
        cout << "Help: Display help and usage information." << endl;
    } else if (option == "-e" || option == "-ep" || option == "-epdf") {
        if (argc < 4) {
            cerr << "Error: Missing input file or shift value." << endl;
            return 1;
        }
        int shift = atoi(argv[3]);
        string inputFileName = argv[2];
        ifstream inputFile(inputFileName);
        if (!inputFile.is_open()) {
            cerr << "Error: Unable to open the input file." << endl;
            return 1;
        }
        stringstream buffer;
        buffer << inputFile.rdbuf();
        string fileContent = buffer.str();
        inputFile.close();

        string encodedContent = encode(fileContent, shift);

        if (option == "-ep") {
            cout << encodedContent << endl;
        } else if (option == "-epdf") {
            // Implement PDF generation for encoded content (not shown in this example)
            cout << "PDF generation for encoded content is not implemented." << endl;
        } else {
            saveToFile(encodedContent, inputFileName);
        }
    } else if (option == "-d" || option == "-ed" || option == "-dpdf") {
        if (argc < 4) {
            cerr << "Error: Missing input file or shift value." << endl;
            return 1;
        }
        int shift = atoi(argv[3]);
        string inputFileName = argv[2];
        ifstream inputFile(inputFileName);
        if (!inputFile.is_open()) {
            cerr << "Error: Unable to open the input file." << endl;
            return 1;
        }
        stringstream buffer;
        buffer << inputFile.rdbuf();
        string fileContent = buffer.str();
        inputFile.close();

        string decodedContent = decode(fileContent, shift);

        if (option == "-ed") {
            cout << decodedContent << endl;
        } else if (option == "-dpdf") {
            // Implement PDF generation for decoded content (not shown in this example)
            cout << "PDF generation for decoded content is not implemented." << endl;
        } else {
            saveToFile(decodedContent, inputFileName);
        }
    } else {
        cerr << "Error: Invalid option." << endl;
        return 1;
    }

    return 0;
}
