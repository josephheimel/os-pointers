// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <iomanip>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("Please enter the student's id number: ",0,999999999);

    student.f_name = new char[128];
    student.l_name = new char[128];

    std::cout << "Please enter the student's first name: ";
    std::cin >> student.f_name;

    std::cout << "Please enter the student's last name: ";
    std::cin >> student.l_name;

    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 0, 134217728);

    std::cout << "\n";

    student.grades = new double[student.n_assignments];

    for (int i = 0; i < student.n_assignments; i++)
    {
        std::cout << "Please enter grade for assignment " << i << ": ";
        student.grades[i] = promptDouble("",0,1000);
    }

    std::cout << "\n";
    // Call `CalculateStudentAverage(???, ???)`
    double* ave;
    calculateStudentAverage(&student, ave);
    average = *ave;

    // Output `average`
    std::cout << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]";
    std::cout << "\n";
    std::cout << "  Average grade: " << std::setprecision(3) << average;


    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    int num;
    bool run = true;
    std::cout << message;
    std::cin >> num;

    return num;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double dub;
    std::cin >> dub;
    return dub;
}


/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    Student stu = *((struct Student*)object);
    
    double tot;

    for(int i = 0; i < stu.n_assignments; i++)
    {
        tot += stu.grades[i];
    }

    *avg = tot/stu.n_assignments;
}
