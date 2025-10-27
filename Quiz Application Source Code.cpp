#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

// Structure to store question details
struct Question {
    string question;
    string options[4];
    char correctAnswer;
    string category;
};

// Function declarations
void displayWelcome();
void displayCategories();
int selectCategory();
void loadQuestions(Question questions[], int category);
void displayQuestion(Question q, int qNum, int total);
void takeQuiz(Question questions[], int numQuestions, string category);
void displayResults(int score, int total, int correctAnswers[], int userAnswers[], Question questions[]);
string getGrade(float percentage);
void displayLeaderboard(string playerNames[], int scores[], int count);

// Global variables for leaderboard
string playerNames[10];
int playerScores[10];
int leaderboardCount = 0;

int main() {
    Question questions[15];
    int choice;
    
    displayWelcome();
    
    do {
        cout << "\n====================================\n";
        cout << "         MAIN MENU\n";
        cout << "====================================\n";
        cout << "1. Start Quiz\n";
        cout << "2. View Leaderboard\n";
        cout << "3. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            int category = selectCategory();
            
            if (category >= 1 && category <= 4) {
                loadQuestions(questions, category);
                int numQuestions = 10;
                
                string categoryName;
                if (category == 1) categoryName = "General Knowledge";
                else if (category == 2) categoryName = "Science";
                else if (category == 3) categoryName = "Mathematics";
                else if (category == 4) categoryName = "Programming";
                
                takeQuiz(questions, numQuestions, categoryName);
            }
        } else if (choice == 2) {
            displayLeaderboard(playerNames, playerScores, leaderboardCount);
        } else if (choice == 3) {
            cout << "\n====================================\n";
            cout << "Thanks for playing! Goodbye!\n";
            cout << "====================================\n";
        } else {
            cout << "\nInvalid choice! Please try again.\n";
        }
        
    } while (choice != 3);
    
    return 0;
}

// Display welcome message
void displayWelcome() {
    cout << "\n============================================\n";
    cout << "    WELCOME TO THE QUIZ APPLICATION!\n";
    cout << "============================================\n";
    cout << "Test your knowledge across various topics!\n";
    cout << "============================================\n";
}

// Display available categories
void displayCategories() {
    cout << "\n====================================\n";
    cout << "      SELECT A CATEGORY\n";
    cout << "====================================\n";
    cout << "1. General Knowledge\n";
    cout << "2. Science\n";
    cout << "3. Mathematics\n";
    cout << "4. Programming\n";
    cout << "5. Back to Main Menu\n";
    cout << "====================================\n";
}

// Select quiz category
int selectCategory() {
    int category;
    displayCategories();
    cout << "Enter category number: ";
    cin >> category;
    return category;
}

// Load questions based on category
void loadQuestions(Question questions[], int category) {
    if (category == 1) {
        // General Knowledge Questions
        questions[0] = {"What is the capital of India?", 
                       {"Mumbai", "New Delhi", "Kolkata", "Chennai"}, 'B', "General Knowledge"};
        questions[1] = {"Who wrote 'Romeo and Juliet'?", 
                       {"Charles Dickens", "William Shakespeare", "Jane Austen", "Mark Twain"}, 'B', "General Knowledge"};
        questions[2] = {"Which is the largest ocean on Earth?", 
                       {"Atlantic", "Indian", "Arctic", "Pacific"}, 'D', "General Knowledge"};
        questions[3] = {"In which year did India gain independence?", 
                       {"1945", "1947", "1950", "1952"}, 'B', "General Knowledge"};
        questions[4] = {"What is the national animal of India?", 
                       {"Lion", "Elephant", "Tiger", "Peacock"}, 'C', "General Knowledge"};
        questions[5] = {"Who is known as the Father of the Nation in India?", 
                       {"Jawaharlal Nehru", "Mahatma Gandhi", "Subhas Chandra Bose", "Sardar Patel"}, 'B', "General Knowledge"};
        questions[6] = {"Which planet is known as the Red Planet?", 
                       {"Venus", "Mars", "Jupiter", "Saturn"}, 'B', "General Knowledge"};
        questions[7] = {"How many continents are there?", 
                       {"5", "6", "7", "8"}, 'C', "General Knowledge"};
        questions[8] = {"What is the currency of Japan?", 
                       {"Yuan", "Won", "Yen", "Ringgit"}, 'C', "General Knowledge"};
        questions[9] = {"Which river is the longest in the world?", 
                       {"Amazon", "Nile", "Yangtze", "Mississippi"}, 'B', "General Knowledge"};
    } 
    else if (category == 2) {
        // Science Questions
        questions[0] = {"What is the chemical symbol for water?", 
                       {"H2O", "CO2", "O2", "N2"}, 'A', "Science"};
        questions[1] = {"What is the speed of light?", 
                       {"300,000 km/s", "150,000 km/s", "450,000 km/s", "600,000 km/s"}, 'A', "Science"};
        questions[2] = {"What is the smallest unit of life?", 
                       {"Atom", "Molecule", "Cell", "Organ"}, 'C', "Science"};
        questions[3] = {"How many bones are in the human body?", 
                       {"186", "206", "226", "246"}, 'B', "Science"};
        questions[4] = {"What gas do plants absorb from the atmosphere?", 
                       {"Oxygen", "Nitrogen", "Carbon Dioxide", "Hydrogen"}, 'C', "Science"};
        questions[5] = {"What is the hardest natural substance on Earth?", 
                       {"Gold", "Iron", "Diamond", "Platinum"}, 'C', "Science"};
        questions[6] = {"What is the center of an atom called?", 
                       {"Electron", "Proton", "Neutron", "Nucleus"}, 'D', "Science"};
        questions[7] = {"What planet is closest to the Sun?", 
                       {"Venus", "Earth", "Mercury", "Mars"}, 'C', "Science"};
        questions[8] = {"What is the boiling point of water?", 
                       {"90°C", "100°C", "110°C", "120°C"}, 'B', "Science"};
        questions[9] = {"Which organ pumps blood through the body?", 
                       {"Liver", "Kidney", "Heart", "Lungs"}, 'C', "Science"};
    }
    else if (category == 3) {
        // Mathematics Questions
        questions[0] = {"What is 15 × 12?", 
                       {"160", "170", "180", "190"}, 'C', "Mathematics"};
        questions[1] = {"What is the square root of 144?", 
                       {"10", "11", "12", "13"}, 'C', "Mathematics"};
        questions[2] = {"What is 25% of 200?", 
                       {"40", "45", "50", "55"}, 'C', "Mathematics"};
        questions[3] = {"What is the value of π (pi) approximately?", 
                       {"2.14", "3.14", "4.14", "5.14"}, 'B', "Mathematics"};
        questions[4] = {"What is 8²?", 
                       {"56", "64", "72", "80"}, 'B', "Mathematics"};
        questions[5] = {"How many sides does a hexagon have?", 
                       {"5", "6", "7", "8"}, 'B', "Mathematics"};
        questions[6] = {"What is 100 ÷ 4?", 
                       {"20", "25", "30", "35"}, 'B', "Mathematics"};
        questions[7] = {"What is the sum of angles in a triangle?", 
                       {"90°", "180°", "270°", "360°"}, 'B', "Mathematics"};
        questions[8] = {"What is 15 + 27 - 8?", 
                       {"32", "34", "36", "38"}, 'B', "Mathematics"};
        questions[9] = {"What is 7 × 8?", 
                       {"54", "56", "58", "60"}, 'B', "Mathematics"};
    }
    else if (category == 4) {
        // Programming Questions
        questions[0] = {"Which language is known as the 'mother of all languages'?", 
                       {"Java", "C", "Python", "Assembly"}, 'B', "Programming"};
        questions[1] = {"What does HTML stand for?", 
                       {"Hyper Text Markup Language", "High Tech Modern Language", "Home Tool Markup Language", "Hyperlinks and Text Markup Language"}, 'A', "Programming"};
        questions[2] = {"Which symbol is used for single-line comments in C++?", 
                       {"//", "/*", "#", "<!--"}, 'A', "Programming"};
        questions[3] = {"What is the file extension for C++ files?", 
                       {".c", ".cpp", ".java", ".py"}, 'B', "Programming"};
        questions[4] = {"Which loop is guaranteed to execute at least once?", 
                       {"for", "while", "do-while", "foreach"}, 'C', "Programming"};
        questions[5] = {"What does SQL stand for?", 
                       {"Structured Query Language", "Simple Question Language", "System Quality Language", "Standard Queue Language"}, 'A', "Programming"};
        questions[6] = {"Which data type is used to store true/false values?", 
                       {"int", "char", "boolean", "float"}, 'C', "Programming"};
        questions[7] = {"What is the size of int in C++ (typically)?", 
                       {"2 bytes", "4 bytes", "8 bytes", "16 bytes"}, 'B', "Programming"};
        questions[8] = {"Which operator is used to access members of a structure?", 
                       {".", "->", "::", "*"}, 'A', "Programming"};
        questions[9] = {"What does OOP stand for?", 
                       {"Object Oriented Programming", "Only One Program", "Organized Object Processing", "Optimal Operation Procedure"}, 'A', "Programming"};
    }
}

// Display individual question
void displayQuestion(Question q, int qNum, int total) {
    cout << "\n====================================\n";
    cout << "Question " << qNum << " of " << total << "\n";
    cout << "====================================\n";
    cout << q.question << "\n\n";
    cout << "A. " << q.options[0] << "\n";
    cout << "B. " << q.options[1] << "\n";
    cout << "C. " << q.options[2] << "\n";
    cout << "D. " << q.options[3] << "\n";
    cout << "====================================\n";
}

// Take the quiz
void takeQuiz(Question questions[], int numQuestions, string category) {
    string playerName;
    char userAnswer;
    int correctAnswers[15];
    int userAnswers[15];
    int score = 0;
    
    cin.ignore();
    cout << "\nEnter your name: ";
    getline(cin, playerName);
    
    cout << "\n====================================\n";
    cout << "Category: " << category << "\n";
    cout << "Total Questions: " << numQuestions << "\n";
    cout << "====================================\n";
    cout << "\nPress Enter to start...";
    cin.get();
    
    // Ask all questions
    for (int i = 0; i < numQuestions; i++) {
        displayQuestion(questions[i], i + 1, numQuestions);
        
        cout << "Your answer (A/B/C/D): ";
        cin >> userAnswer;
        
        // Convert to uppercase
        if (userAnswer >= 'a' && userAnswer <= 'd') {
            userAnswer = userAnswer - 32;
        }
        
        // Validate input
        while (userAnswer != 'A' && userAnswer != 'B' && userAnswer != 'C' && userAnswer != 'D') {
            cout << "Invalid input! Please enter A, B, C, or D: ";
            cin >> userAnswer;
            if (userAnswer >= 'a' && userAnswer <= 'd') {
                userAnswer = userAnswer - 32;
            }
        }
        
        userAnswers[i] = userAnswer;
        correctAnswers[i] = questions[i].correctAnswer;
        
        // Check answer
        if (userAnswer == questions[i].correctAnswer) {
            score++;
            cout << "\n✓ Correct!\n";
        } else {
            cout << "\n✗ Wrong! Correct answer is: " << questions[i].correctAnswer << "\n";
        }
        
        if (i < numQuestions - 1) {
            cout << "\nPress Enter for next question...";
            cin.ignore();
            cin.get();
        }
    }
    
    // Display results
    displayResults(score, numQuestions, correctAnswers, userAnswers, questions);
    
    // Add to leaderboard
    if (leaderboardCount < 10) {
        playerNames[leaderboardCount] = playerName;
        playerScores[leaderboardCount] = score;
        leaderboardCount++;
        
        // Sort leaderboard (bubble sort)
        for (int i = 0; i < leaderboardCount - 1; i++) {
            for (int j = 0; j < leaderboardCount - i - 1; j++) {
                if (playerScores[j] < playerScores[j + 1]) {
                    // Swap scores
                    int tempScore = playerScores[j];
                    playerScores[j] = playerScores[j + 1];
                    playerScores[j + 1] = tempScore;
                    
                    // Swap names
                    string tempName = playerNames[j];
                    playerNames[j] = playerNames[j + 1];
                    playerNames[j + 1] = tempName;
                }
            }
        }
    }
}

// Display quiz results
void displayResults(int score, int total, int correctAnswers[], int userAnswers[], Question questions[]) {
    float percentage = (float)score / total * 100;
    string grade = getGrade(percentage);
    
    cout << "\n============================================\n";
    cout << "           QUIZ COMPLETED!\n";
    cout << "============================================\n";
    cout << "Your Score: " << score << "/" << total << "\n";
    cout << "Percentage: " << fixed << setprecision(2) << percentage << "%\n";
    cout << "Grade: " << grade << "\n";
    cout << "============================================\n";
    
    // Performance message
    if (percentage >= 90) {
        cout << "🌟 Outstanding! You're a genius!\n";
    } else if (percentage >= 75) {
        cout << "👍 Great job! Keep it up!\n";
    } else if (percentage >= 60) {
        cout << "👌 Good effort! You can do better!\n";
    } else if (percentage >= 40) {
        cout << "📚 Need more practice. Don't give up!\n";
    } else {
        cout << "💪 Keep learning! Practice makes perfect!\n";
    }
    
    cout << "============================================\n";
    
    // Show detailed answers
    char showDetails;
    cout << "\nView detailed answers? (Y/N): ";
    cin >> showDetails;
    
    if (showDetails == 'Y' || showDetails == 'y') {
        cout << "\n====================================\n";
        cout << "       DETAILED ANSWERS\n";
        cout << "====================================\n";
        
        for (int i = 0; i < total; i++) {
            cout << "\nQ" << (i + 1) << ". " << questions[i].question << "\n";
            cout << "Your Answer: " << (char)userAnswers[i];
            
            if (userAnswers[i] == correctAnswers[i]) {
                cout << " ✓ Correct\n";
            } else {
                cout << " ✗ Wrong\n";
                cout << "Correct Answer: " << (char)correctAnswers[i] << "\n";
            }
        }
        cout << "====================================\n";
    }
}

// Calculate grade
string getGrade(float percentage) {
    if (percentage >= 90) {
        return "A+";
    } else if (percentage >= 80) {
        return "A";
    } else if (percentage >= 70) {
        return "B+";
    } else if (percentage >= 60) {
        return "B";
    } else if (percentage >= 50) {
        return "C";
    } else if (percentage >= 40) {
        return "D";
    } else {
        return "F";
    }
}

// Display leaderboard
void displayLeaderboard(string playerNames[], int scores[], int count) {
    cout << "\n====================================\n";
    cout << "         LEADERBOARD\n";
    cout << "====================================\n";
    
    if (count == 0) {
        cout << "No scores yet. Be the first to play!\n";
    } else {
        cout << left << setw(5) << "Rank" 
             << setw(20) << "Player Name" 
             << setw(10) << "Score" << "\n";
        cout << "------------------------------------\n";
        
        for (int i = 0; i < count; i++) {
            cout << left << setw(5) << (i + 1)
                 << setw(20) << playerNames[i]
                 << setw(10) << (scores[i]) << "/10\n";
        }
    }
    cout << "====================================\n";
}