import sys
import os
from PyPDF2 import PdfFileWriter, PdfFileReader

# Function to decode the input string using Caesar cipher
def decode(input_content, shift):
    decoded_content = []
    for char in input_content:
        if char.isalpha():
            base = 'a' if char.islower() else 'A'
            decoded_char = chr(((ord(char) - ord(base) - shift) % 26) + ord(base))
            decoded_content.append(decoded_char)
        else:
            decoded_content.append(char)
    return ''.join(decoded_content)

# Function to encode the input string using Caesar cipher
def encode(input_content, shift):
    encoded_content = []
    for char in input_content:
        if char.isalpha():
            base = 'a' if char.islower() else 'A'
            encoded_char = chr(((ord(char) - ord(base) + shift) % 26) + ord(base))
            encoded_content.append(encoded_char)
        else:
            encoded_content.append(char)
    return ''.join(encoded_content)

# Function to save content to a file
def save_to_file(content, filename):
    with open(filename, 'w') as file:
        file.write(content)

def main():
    if len(sys.argv) < 2:
        print("Usage:", sys.argv[0], "<options> <input_file>")
        print("Options:")
        print("  -h: Help")
        print("  -e: Encode the file")
        print("  -d: Decode the file")
        print("  -ep: Encode and print")
        print("  -ed: Decode and print")
        print("  -epdf: Encode and save as PDF")
        print("  -dpdf: Decode and save as PDF")
        return 1

    option = sys.argv[1]

    if option == "-h":
        print("Help: Display help and usage information.")
    elif option in ["-e", "-ep", "-epdf"]:
        if len(sys.argv) < 4:
            print("Error: Missing input file or shift value.")
            return 1
        shift = int(sys.argv[3])
        input_filename = sys.argv[2]
        
        with open(input_filename, 'r') as file:
            file_content = file.read()

        encoded_content = encode(file_content, shift)

        if option == "-ep":
            print(encoded_content)
        elif option == "-epdf":
            # Implement PDF generation for encoded content (not shown in this example)
            print("PDF generation for encoded content is not implemented.")
        else:
            save_to_file(encoded_content, input_filename)
    elif option in ["-d", "-ed", "-dpdf"]:
        if len(sys.argv) < 4:
            print("Error: Missing input file or shift value.")
            return 1
        shift = int(sys.argv[3])
        input_filename = sys.argv[2]
        
        with open(input_filename, 'r') as file:
            file_content = file.read()

        decoded_content = decode(file_content, shift)

        if option == "-ed":
            print(decoded_content)
        elif option == "-dpdf":
            # Implement PDF generation for decoded content (not shown in this example)
            print("PDF generation for decoded content is not implemented.")
        else:
            save_to_file(decoded_content, input_filename)
    else:
        print("Error: Invalid option.")
        return 1

if __name__ == "__main__":
    sys.exit(main())
