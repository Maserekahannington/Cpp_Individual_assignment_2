#include <iostream>

// This program compares each student's multiple-choice answers against the
// official answer key and reports how many questions each student answered
// correctly.

int main() {
    // Each row represents one student, and each column represents one answer
    // for a question from 1 to 10.
    const char answers[8][10] = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
    };

    // This is the correct answer for every question.
    const char key[10] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    // The outer loop goes through each student in the list.
    for (int student = 0; student < 8; ++student) {
        int correctAnswers = 0;  // Counts matches between the student's answers and the key.

        // The inner loop checks each of the 10 questions for the current student.
        for (int question = 0; question < 10; ++question) {
            if (answers[student][question] == key[question]) {
                ++correctAnswers; // Increase the score only when the answer matches.
            }
        }

        // Display the total number of correct answers for this student.
        std::cout << "Student " << student << " correct answers: "
                  << correctAnswers << '\n';
    }

    return 0;
}
