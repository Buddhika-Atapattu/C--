#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string question[10] = {"1. Which of the following is the correct syntax to include a header file in C++?",
                           "2. What is the output of the following code?\n\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n\tcout << \"Hello, C++!\";\n\treturn 0;\n}",
                           "3. What is the correct way to declare a constant variable in C++?",
                           "4. Which data type is used to represent a floating-point number in C++?",
                           "5. How do you create a single-line comment in C++?",
                           "6. What does the main() function return in C++?",
                           "7. How do you declare a pointer in C++?",
                           "8. What is the default value of a local variable in C++?",
                           "9. Which of the following is not a loop in C++?",
                           "10. What is the use of the new keyword in C++?"};

    string mcq[10][4] = {{"a) #include <header>", "b) include <header>", "c) #include \"header.h\"", "d) Both a and c"},
                         {"a) Hello, C++!", "b) Compilation Error", "c) Hello C++!", "d) Runtime Error"},
                         {"a) const int value = 10;", "b) int const value = 10;", "c) #define value 10", "d) All of the above"},
                         {"a) int", "b) char", "c) float", "d) bool"},
                         {"a) /* This is a comment */", "b) // This is a comment", "c) # This is a comment", "d) ** This is a comment **"},
                         {"a) void", "b) bool", "c) int", "d) float"},
                         {"a) int* ptr;", "b) int ptr*;", "c) ptr int*;", "d) int ptr;"},
                         {"a) 0", "b) null", "c) undefined", "d) garbage value"},
                         {"a) for", "b) while", "c) do-while", "d) repeat"},
                         {"a) To allocate memory dynamically", "b) To free memory", "c) To declare a variable", "d) To initialize a variable"}};

    string answer[10] = {"d", "a", "d", "c", "b", "c", "a", "d", "d", "a"};

    string userInput = "";
    int arrSize = sizeof(question) / sizeof(question[0]);
    int score = 0;

    for (int i = 0; i < arrSize; i++)
    {
        cout << question[i] << endl;
        for (int j = 0; j < (sizeof(mcq[i]) / sizeof(mcq[i][0])); j++)
        {

            cout << mcq[i][j] << endl;
        }
        cout << "Type the letter of the correct answer: ";
        cin >> userInput;
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
        if (userInput == answer[i])
        {
            score += 1;
        }
        cout << "\n"
             << endl;
    }
    cout << "Your final score is: " << score << "/" << arrSize << endl;

    return 0;
}