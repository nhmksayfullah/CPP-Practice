# ArrayCommander

ArrayCommander is a console-based program that demonstrates fundamental data structure concepts using arrays. It provides a hands-on approach to learning array operations such as insertion, deletion, updating, searching, and sorting. Written in C++, this project showcases the implementation of natural language command processing for interacting with the array.


## Video Preview

Here’s a video demonstrating ArrayCommander in action. Watch how natural language commands are used to interact with the program!

[![Click to watch the video](https://img.youtube.com/vi/Z6JRnW3nvZY/hqdefault.jpg)](https://github.com/user-attachments/assets/cdcb64a2-951c-43cb-9986-f3835e39edc6)



## Features

- **Natural Language Command Parsing:** Execute array operations by entering simple commands in plain English.
- **Core Array Operations:**
  - Insert values.
  - Update existing values.
  - Remove values.
  - Search for values.
  - Display the current state of the array.
  - Sort the array in ascending or descending order.
- **Interactive Console:** Receive immediate feedback for your commands and view the resulting changes.
- **Error Handling:** Ensures graceful handling of invalid commands, duplicate or missing values, and array overflow or underflow scenarios.

## Sample Commands
Here are some examples of commands you can use:
1. **Display the array:** ```display```
2. **Insert a number:** ```insert 10```
3. **Update a number:** ```update 10 by 12```
4. **Remove a number:** ```remove 12```
5. **Search for a number:** ```search 10```
6. **Sort the array in ascending order:** ```sort asnd```
7. **Sort the array in descending order:** ```sort disnd```
8. **Stop the program:** ```stop```



## How It Works

ArrayCommander processes user input through a command parser that extracts and interprets operations and values from natural language strings. It uses the following concepts:
- **Array Manipulation:** Directly interacts with a fixed-size array to perform operations.
- **String Parsing:** Extracts values and operations from user input using string methods.
- **Control Structures:** Implements loops and conditional statements for efficient array management.

## Learning Journey

This project is a significant milestone in my learning journey during my second semester at university as part of the Data Structures course. It helped me:
- Deepen my understanding of array-based data structures.
- Explore algorithmic problem-solving by implementing search, update, and sort functionalities.
- Develop skills in string manipulation and parsing natural language commands.
- Learn to build user-friendly console applications with clear instructions and feedback.

I am proud to share this project as a reflection of my growth as a budding software developer.

## Usage

1. Clone or download the repository.
2. Compile the program using a C++ compiler:
3. Run the compiled program:
4. Follow the on-screen instructions to interact with the program.

## Example Output

```plaintext
------Instruction------

0. Display the array like this: display
1. Insert a new number in array like this: insert 10
2. Update an existing number by new number: update 10 by 20
3. Remove a number from array like this: remove 20
4. Search if a number is available in your array: search 20
5.1. Sort the array in ascending: sort asnd
5.2. Sort the array in descending: sort disnd
6. Stop this process like this: stop

Command: insert 5
Output: Inserted Successfully.

Command: display
Output: 5

Command: search 5
Output: 5 exists in the array.

Command: stop
Thank you.
```

## Credit
- **Author:** Khalid Sayfullah
- **Year:** 2023
- **License:** This project is open-source and free to use for educational purposes

