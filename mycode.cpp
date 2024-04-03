#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
void modify(int score[], int test_num, int new_score) {
	if (test_num >= 1 || test_num <= 10) {
		score[test_num - 1] = new_score;
		cout << "Test number " << test_num << " has been updated to " << new_score << endl;
	}
	else {
		cout << "Invalid test number. Enter test number 1-10" << endl;
	}
}
float avg_score(int scores[], int arr_size) {
	float average = 0;
	for (int i = 0;i < arr_size;i++) {
		average = scores[i] + average;
	}
	return (float)average / arr_size;
}
void print_array(int arr[], int arr_size) {
	for (int i = 0;i < arr_size;i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}
void grade(float average) {
	char letter_grade = 0;
	if (average >= 9.3) {
		letter_grade = 'A';
	}
	if (average <= 9.3 && average >= 8.5) {
		letter_grade = 'B';

	}
	if (average <= 8.5 && average >= 7) {
		letter_grade = 'C';
	}
	if (average <= 7 && average >= 6) {
		letter_grade = 'D';
	}
	if (average < 6) {
		letter_grade = 'F';
	}
	cout << "Your final grade is: " << letter_grade << endl;
}