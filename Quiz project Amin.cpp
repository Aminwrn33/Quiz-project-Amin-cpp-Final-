#include <iostream>
#include <vector>
#include <string>




using namespace std;

class Quiz
{


public:
    string question;
    vector<string> options;
    int correctAnswer;

    Quiz(string q, vector<string> opts, int answer)
        : question(q), options(opts), correctAnswer(answer)
    {}
};

class Admin
{


public:


    vector<Quiz> quizzes;

    void createQuiz()
    {
        string question;
        vector<string> options(4);
        int answer;

        cout << "Sual daxil et: ";

        getline(cin, question);

        for (int i = 0; i < 4; ++i)
        {
            cout << "Secim daxil et " << i + 1 << ": ";
            getline(cin, options[i]);
        }
        cout << "Dogru olan cavabin nomresini yazin (1-4): ";
        cin >> answer;
        cin.ignore();

        quizzes.push_back(Quiz(question, options, answer - 1));
    }

    void viewQuizzes()
    {
        for (size_t i = 0; i < quizzes.size(); ++i)
        {
            cout << "Quiz " << i + 1 << ": " << quizzes[i].question << endl;

            for (size_t j = 0; j < quizzes[i].options.size(); ++j)

            {
                std::cout << j + 1 << ". " << quizzes[i].options[j] << endl;
            }
        }
    }
};

class Guest
{


public:
    void takeQuiz(const vector<Quiz>& quizzes)
    {
        for (const auto& quiz : quizzes)
        {
            cout << quiz.question << endl;
            for (size_t j = 0; j < quiz.options.size(); ++j)
            {
                cout << j + 1 << ". " << quiz.options[j] << endl;
            }
            int answer;
            cout << "Cavabinizi daxil edin (1-4): ";

            cin >> answer;

            if (answer - 1 == quiz.correctAnswer)
            {
                cout << "Dogru cavab!" << endl;
            }
            else {
                cout << "Yanlis! Duzgun olan cavab " << quiz.correctAnswer + 1 << "." << endl;
            }
        }
    }
};

int main()

{
    Admin admin;
    Guest guest;
    int choice;

    while (true)
    {
        cout << "Aminin quiz proyektine xos geldiniz!\n";
        cout << "\n";
        cout << "1. Admin Login\n2. Guest Login\n3. Exit\nSeciminizi daxil edin: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            int adminChoice;
            while (true)
            {
                cout << "1. Yeni quiz yarat\n2. Quizlere bax\n3. Cixis\nSeciminizi daxil edin: ";
                cin >> adminChoice;
                cin.ignore();

                if (adminChoice == 1)
                {
                    admin.createQuiz();
                }
                else if (adminChoice == 2)
                {
                    admin.viewQuizzes();
                }
                else {
                    break;
                }
            }
        }
        else if (choice == 2)
        {
            guest.takeQuiz(admin.quizzes);
        }
        else {
            break;
        }
    }

    return 0;





}