#include <iostream>
#include <string>
#include "header.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;


int main() {
	int array_size = 10;
	float avg = 0;
	int choice = 0;
	int test_num = 0;
	int new_score = 0;
	int scores[10] = { 8, 10, 8, 5, 7, 8, 9, 10, 6, 7 };
	int updated = 0;
	while (choice != 5) {
		cout << "Please select an option:" << endl << "1.Change grade" << endl << "2.Average Score" << endl << "3.Display Scores" << endl << "4.Final Grade" << endl << "5. Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Change grade" << endl;
			cout << "Enter test number: ";
			cin >> test_num;
			cout << "Enter new grade(1-10): ";
			cin >> new_score;
			modify(scores, test_num, new_score);
			break;
		case 2:
			avg =avg_score(scores, array_size);
			cout << "The average score is: " << (float)avg << endl;
			break;
		case 3:
			cout << "The test scores are: ";
			print_array(scores, array_size);
			break;
		case 4: 
			grade(avg);
			break;
		case 5:
			cout << "Thank you for using grading system." << endl;
			break;
		default:
			cout << "This is not a valid option try again" << endl;
			break;
		}
	}

	cout << "-----------------------" << endl;
	
	return 0;
}