
# Cesar Cipher File Encoder/Decoder

This is a collection of command-line scripts in Python, C++, and Perl for encoding and decoding text files using the Caesar cipher. Each script provides several options for working with input files, including encoding, decoding, printing, and saving to PDF.

## Options

- `-h`: Display help and usage information.
- `-e <shift> <input_file>`: Encode the input file using Caesar cipher with the specified shift value and save the result to the input file.
- `-d <shift> <input_file>`: Decode the input file using Caesar cipher with the specified shift value and save the result to the input file.
- `-ep <shift> <input_file>`: Encode the input file using Caesar cipher with the specified shift value and print the result.
- `-ed <shift> <input_file>`: Decode the input file using Caesar cipher with the specified shift value and print the result.
- `-epdf <shift> <input_file>`: Encode the input file using Caesar cipher with the specified shift value and save the result as a PDF file.
- `-dpdf <shift> <input_file>`: Decode the input file using Caesar cipher with the specified shift value and save the result as a PDF file.

## Python Version

### Caesar Cipher File Encoder/Decoder (Python)

This is a command-line Python script for encoding and decoding text files using the Caesar cipher.

#### Usage

##### Examples

- Encode a text file and save the result:
  ```bash
  python caesar_cipher.py -e 3 input.txt
  ```

- Decode a text file and print the result:
  ```bash
  python caesar_cipher.py -ed 3 input.txt
  ```

- Encode a text file, print the result, and save it as a PDF:
  ```bash
  python caesar_cipher.py -epdf 3 input.txt
  ```

#### Requirements

- Python (tested on Python 3.8)
- [PyPDF2](https://pypi.org/project/PyPDF2/) module for PDF generation (only required for PDF-related options)

#### License

This script is released under the [MIT License](LICENSE).

## C++ Version

### Caesar Cipher File Encoder/Decoder (C++)

This is a command-line C++ program for encoding and decoding text files using the Caesar cipher.

#### Usage

##### Examples

- Encode a text file and save the result:
  ```bash
  ./caesar_cipher -e 3 input.txt
  ```

- Decode a text file and print the result:
  ```bash
  ./caesar_cipher -ed 3 input.txt
  ```

- Encode a text file, print the result, and save it as a PDF:
  ```bash
  ./caesar_cipher -epdf 3 input.txt
  ```

#### License

This program is released under the [MIT License](LICENSE).

## Perl Version

### Caesar Cipher File Encoder/Decoder (Perl)

This is a command-line Perl script for encoding and decoding text files using the Caesar cipher.

#### Usage

##### Examples

- Encode a text file and save the result:
  ```bash
  perl caesar_cipher.pl -e 3 input.txt
  ```

- Decode a text file and print the result:
  ```bash
  perl caesar_cipher.pl -ed 3 input.txt
  ```

- Encode a text file, print the result, and save it as a PDF:
  ```bash
  perl caesar_cipher.pl -epdf 3 input.txt
  ```

#### Requirements

- Perl (tested on Perl 5.30.0)
- [File::Slurp](https://metacpan.org/pod/File::Slurp) module for reading and writing files
- [PDF::API2](https://metacpan.org/pod/PDF::API2) module for PDF generation (only required for PDF-related options)

#### License

This script is released under the [MIT License](LICENSE).
