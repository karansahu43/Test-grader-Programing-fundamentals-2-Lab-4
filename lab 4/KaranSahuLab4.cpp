// Author:  Karan Sahu
// Assignment Number: Lab 4
// File Name: KaranSahuLab4.cpp
// Course/Section: COSC 1337 Section 003
// Due Date:  
// Instructor: Bernard Ku
//
//  This program will grade a driving test (based on set answer sheet) and show wrong answers
//
#include <iostream>
#include <string>     // std::string, std::stoi
#include <iomanip>
#include <stdexcept>
#include<sstream>



using namespace std;

const int SIZE = 20; // Number of qns in the test

class TestGrader

{ 

private:    char answers[SIZE];        // Holds the correct answers   
			char newanswer[SIZE];
			int getNumWrong();
			void missedQuestions();

public:     void setKey(string);   // Initialize object with standard keys
			void setAnswer(string);
            void grade();    // Grades the answers from tester

};


//e.g. TestGrader::setkey

/************************************** *          

** TestGrader::setKey        

* * Stores the correct data passed to  

* * the function in the answers array.

* *************************************/ 

void TestGrader::setKey(string key)

{ 

    if (key.length() != SIZE) 

    { 

        cout << "Error in key data.\n"; 

        return; 

    } 

    for (int pos = 0; pos < SIZE; pos++)     
	{
		answers[pos] = key[pos];
	}

}

void TestGrader::setAnswer(string grade)

{ 

    if (grade.length() != SIZE) 

    { 

          cout << "Error in grade data.\n"; 

          return; 

    } 

    for (int pos = 0; pos < SIZE; pos++)        
	{
        newanswer[pos] = grade[pos];

	}
            

}

void TestGrader::grade()
{
	int numWrong = getNumWrong();
	

	
	if(numWrong <= 5)
		cout << "Congratulations. You passed the exam. \n";
	else 
		cout << "You did not pass the exam. \n";
		
	cout << "You got " << (SIZE - numWrong) << " questions correct. \n";
	
	if (numWrong > 0)
	{
		cout << "You missed the following " << numWrong << " questions: ";
		missedQuestions();
	}
}
int TestGrader::getNumWrong()
{
	int numWrong = 0;

    for (int pos = 0; pos < SIZE; pos++)    
	{
		if(newanswer[pos] != answers[pos])
			numWrong = numWrong + 1;
		
		
	}
	
	return numWrong;
	
} 

void TestGrader::missedQuestions()
{

    for (int pos = 0; pos < SIZE; pos++)    
	{
		int Qnumber = pos + 1;
		if(newanswer[pos] != answers[pos])
			cout << Qnumber << ", ";
		
		
	}
	
} 





// Function prototypes
bool isLetter(string);


int main()
{
	TestGrader test1;
	bool gradeCondition, namecondition;
	string name;
	test1.setKey("BDAACABACDBCDADCCBDA");
	string grade = "";
	string gradeAdder;
	

	
	namecondition = true;
	while (namecondition)
	{	
		cout << "Applicant Name: ";
		getline(cin, name);

		namecondition = isLetter(name);
	}
	
	cout << "Enter answers for " << name << endl << "Use only letters A, B, C, and D." << endl << endl;
	
	
	
    for (int pos = 0 ; pos < SIZE ; pos++)  
    {
    	do
    	{
    		gradeAdder = "NO";
    		cout << "Q " << pos + 1 << ": ";
    		cin >> gradeAdder;
    		
    		
    		
    		if(gradeAdder == "A" || gradeAdder == "B" || gradeAdder == "C" || gradeAdder == "D" || gradeAdder == "a" || gradeAdder == "b" || gradeAdder == "c" || gradeAdder == "d" )
    		{
    			gradeCondition = false;
    			//gradeAdder = toupper( gradeAdder );
    			
			}
			else 
			{
				cout << "Must enter character A, B, C, D  " << endl;
				gradeCondition = true;
			}
    	
		
		}while (gradeCondition == true);
		
		if(gradeAdder == "a")
			gradeAdder = "A";
		else if(gradeAdder == "b")
			gradeAdder = "B";
		else if(gradeAdder == "c")
			gradeAdder = "C";
		else if (gradeAdder == "d")
			gradeAdder = "D";
		
		grade = grade + gradeAdder;
		


	} 
	test1.setAnswer(grade);
	cout << endl;
	cout << "Results for " << name << endl;
	test1.grade();
	
	

 
   return 0;
}


bool isLetter(string name)
{
	for(int i = 0; i < name.length(); i++)
	{
		char ch = name[i];
		if(ch != ' ' && isalpha(ch) == 0)
		{
			cout << "Name must be alphabetical characters only!\n";
			return true;
		}

	}
	return false;
}








/* SAMPLE OUTPUT
Applicant Name: qwxs23
Name must be alphabetical characters only!
Applicant Name: Karan Sahu
Enter answers for Karan Sahu
Use only letters A, B, C, and D.

Q 1: a
Q 2: b
Q 3: c
Q 4: d
Q 5: A
Q 6: B
Q 7: C
Q 8: D
Q 9: s223
Must enter character A, B, C, D
Q 9: swc
Must enter character A, B, C, D
Q 9: tr
Must enter character A, B, C, D
Q 9: 2
Must enter character A, B, C, D
Q 9: a
Q 10: b
Q 11: b
Q 12: b
Q 13: b
Q 14: b
Q 15: b
Q 16: b
Q 17: b
Q 18: b
Q 19: b
Q 20: b

Results for Karan Sahu
You did not pass the exam.
You got 2 questions correct.
You missed the following 18 questions: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14
, 15, 16, 17, 19, 20,

---------------------------------------------------------------------------------------------------


Applicant Name: Karab
Enter answers for Karab
Use only letters A, B, C, and D.

Q 1: b
Q 2: d
Q 3: a
Q 4: a
Q 5: C
Q 6: A
Q 7: B
Q 8: A
Q 9: C
Q 10: D
Q 11: B
Q 12: C
Q 13: D
Q 14: A
Q 15: D
Q 16: C
Q 17: C
Q 18: B
Q 19: D
Q 20: A

Results for Karab
Congratulations. You passed the exam.
You got 20 questions correct.


-------------------------------------------------------------

Applicant Name: wer3qr
Name must be alphabetical characters only!
Applicant Name: dsced
Enter answers for dsced
Use only letters A, B, C, and D.

Q 1: a
Q 2: a
Q 3: a
Q 4: a
Q 5: a
Q 6: a
Q 7: a
Q 8: a
Q 9: a
Q 10: a
Q 11: a
Q 12: a
Q 13: a
Q 14: a
Q 15: a
Q 16: a
Q 17: a
Q 18: a
Q 19: a
Q 20: a

Results for dsced
You did not pass the exam.
You got 6 questions correct.
You missed the following 14 questions: 1, 2, 5, 7, 9, 10, 11, 12, 13, 15, 16, 17
, 18, 19,


*/
