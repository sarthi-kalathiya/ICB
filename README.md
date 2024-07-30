# String Calculator

## Introduction

The String Calculator is a simple program that takes a string of numbers separated by delimiters and returns their sum. It supports various features such as custom delimiters, multiple delimiters, and exception handling for negative numbers.

## Features

1. **Basic Addition**:
   - An empty string returns 0.
   - A single number returns the number itself.
   - A string with two numbers separated by a comma returns their sum.

2. **Handling New Lines**:
   - The add method can handle new lines between numbers (e.g., "1\n2,3" returns 6).

3. **Custom Delimiters**:
   - To change the delimiter, the beginning of the string will contain a separate line that looks like this: `//[delimiter]\n[numbers...]`. For example, "//;\n1;2" where the delimiter is ";" should return 3.

4. **Dynamic Length Delimiters**:
   - Delimiters of any length can be specified with the format `//[delimiter]\n`. For example, "//[***]\n1***2***3" returns 6.

5. **Multiple Delimiters**:
   - Multiple delimiters can be specified in the format `//[delim1][delim2]\n`. For example, "//[*][%]\n1*2%3" returns 6.

6. **Exception Handling for Negative Numbers**:
   - Calling add with a negative number will throw an exception: "negative numbers not allowed <negative_number>".
   - If there are multiple negative numbers, all of them are shown in the exception message, separated by commas.
