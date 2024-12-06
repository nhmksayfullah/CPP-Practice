/*
 * This program showcases fundamental array operations through a console-based interface.
 * It processes natural language commands, performs the requested actions in the background,
 * and displays the results in a clear and user-friendly manner.
 * (C) 2023, Khalid Sayfullah.
 */


#include <iostream>
using namespace std;

const int arraySize = 10;
int privateIndex = 0;
int privateArray[arraySize];
int extractedCommand[3];

int indexFinder(int value) {
    for (int i = 0; i <= privateIndex; ++i) {
        if(privateArray[i] == value) {
            return i;
        }
    }
    return -1;
}

int insertValue(int value) {
    if(privateIndex < arraySize) {
        privateArray[privateIndex] = value;
        privateIndex++;
        return 1;
    }
    return -1;
}

int updateValue(int value, int updatingValue) {
    for (int i = 0; i < arraySize; ++i) {
        if(value == privateArray[i]) {
            privateArray[i] = updatingValue;
            return i;
        }
    }
    return -1;
}

int removeValue(int value) {
    int index;
    int tempArray[arraySize];
    index = updateValue(value, 0);

    for (int i = 0; i <= privateIndex; ++i) {
        if(i < index) {
            tempArray[i] = privateArray[i];
        } else {
            tempArray[i] = privateArray[i + 1];
        }
    }
    privateIndex--;
    for (int j = 0; j <= privateIndex; ++j) {
        privateArray[j] = tempArray[j];
    }

    return 1;
}

int display() {
    if (privateIndex == 0) {
        cout << "Output: No value available to show" << endl;
        return -1;
    }
    cout << "Output ";
    for (int i = 0; i < privateIndex; ++i) {
        cout << privateArray[i] << " ";
    }
    cout << endl;
    return 1;
}

int search(int value) {
    for (int i = 0; i < privateIndex; ++i) {
        if(privateArray[i] == value) {
            return i;
        }
    }
    return -1;
}

int sort(int order) {
    for (int i = 0; i < privateIndex; ++i) {
        for (int j = i + 1; j < privateIndex; ++j) {
            if(order == 1) {    //ascending
                if (privateArray[j] > privateArray[i]) {
                    int temp = privateArray[i];
                    privateArray[i] = privateArray[j];
                    privateArray[j] = temp;
                }
            } else {    //descending
                if (privateArray[j] < privateArray[i]) {
                    int temp = privateArray[i];
                    privateArray[i] = privateArray[j];
                    privateArray[j] = temp;
                }
            }

        }
    }
    return 1;
}


int getValue(string command, int start, int end) {
    string valueFinder;
    int value;
    for (int i = start; i < end; ++i) {
        valueFinder += command[i];
    }
    value = stoi(valueFinder);
    return value;
}


int extractCommand(string command) {
    // cleared the extractedCommand array.
    for (int & i : extractedCommand) {
        i = 0;
    }

    int value;
    int startingIndex1 = 0, startingIndex2 = 0;

    //extract stop operation.
    if(command.find("stop") != -1) {
        return 6;
    }
    // extract display operation.
    if (command.find("display") != -1) {
        extractedCommand[0] = 0;
        return 0;
    }

    // extract insert operation.
    if(command.find("insert") != -1) {
        extractedCommand[0] = 1;
        startingIndex1 = command.find("insert") + 7;
        value = getValue(command, startingIndex1, command.size());
        extractedCommand[1] = value; // inserting value is available in index 1 of extractedCommand[].
        return 1;
    }

    // extract update operation.
    if (command.find("update") != -1) {
        extractedCommand[0] = 2;

        startingIndex1 = command.find("update") + 7;
        startingIndex2 = command.find("by") + 3;

        value = getValue(command, startingIndex1, startingIndex2 - 4);
        extractedCommand[1] = value; // old value is available in index 1 of extractedCommand[].

        value = getValue(command, startingIndex2, command.size());
        extractedCommand[2] = value; // new value is available in index 1 of extractedCommand[].
        return 2;
    }

    // extract remove operation.
    if (command.find("remove") != -1) {
        extractedCommand[0] = 3;
        startingIndex1 = command.find("remove") + 7;
        value = getValue(command, startingIndex1, command.size());
        extractedCommand[1] = value; // removing value is available in index 1 of extractedCommand[].
        return 3;
    }

    //extract search operation.
    if(command.find("search") != -1) {
        extractedCommand[0] = 4;
        startingIndex1 = command.find("search") + 7;
        value = getValue(command, startingIndex1, command.size());
        int index = search(value);
        if(index == -1) {
            extractedCommand[1] = 0; // 0 means not found
            extractedCommand[2] = value; // get index number of the value in array.
        } else {
            extractedCommand[1] = 1; // 1 means available
            extractedCommand[2] = value; // get index number of the value in array.
        }
        return 4;
    }
    if(command.find("sort asnd")) {
        sort(1);
        return 5;
    }
    if(command.find("sort disnd")) {
        sort(2);
        return 5;
    }



    return -1;
}
void instruction() {
    cout << "------Instruction------" << endl << endl;
    cout << "0. Display the array like this: display" << endl;
    cout << "1. Insert a new number in array like this: insert 10" << endl;
    cout << "2. Update an existing number by new number: update 10 by 20" << endl;
    cout << "3. Remove a number from array like this: remove 20" << endl;
    cout << "4. Search if a number is available in your array: search 20" << endl;
    cout << "5.1. Sort the array in ascending: sort asnd" << endl;
    cout << "5.2. Sort the array in descending: sort  disnd" << endl;
    cout << "6. Stop this process like this: stop" << endl << endl;
}

void ArrayCommander() {
    instruction();
    string command;
    int response;
    while (true) {
        cout << "Command:";
        getline(cin, command);
        int operation = extractCommand(command);

        if(operation == 6) {
            cout << "Thank you." << endl << endl;
            break;
        }
        switch (operation) {
            case 0: // display the array.
                response = display();
                break;
            case 1: // insert a value.
                response = insertValue(extractedCommand[1]);
                if(response == 1) {
                    cout << "Output: Inserted Successfully." << endl;
                } else {
                    cout << "Output: No space available." << endl;
                }
                break;
            case 2: // update a value.
                response = updateValue(extractedCommand[1], extractedCommand[2]);
                if (response != -1) {
                    cout << "Output: Updated Successfully." << endl;
                }
                break;
            case 3:
                response = removeValue(extractedCommand[1]);
                if(response == 1) {
                    cout << "Output: Removed Successfully." << endl;
                }
                break;
            case 4:
                if (extractedCommand[1] == 1) {
                    cout << "Output: " << extractedCommand[2] << " exist in the array." << endl;
                } else {
                    cout << "Output: " << extractedCommand[2] << " doesn't exist in the array." << endl;
                }
                break;
            case 5:
                cout << "Output: ";
                for (int i = 0; i < privateIndex; ++i) {
                    cout << privateArray[i] << " ";
                }
                cout << endl;
                break;

        }
    }
}

int main() {
      ArrayCommander();

    return 0;
}
