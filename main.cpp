#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;	//open and write a file
using std::ifstream;	//read from a file

int main() {
	//string name;
	//int found = 0;
	//string users[8] = { "David", "Jose", "Mike", "Alishia", "Kate", "Dan", "Ellen", "Dan" };
	//while (found != 1) {
	//	cout << "What is your name? ";
	//	cin >> name;
	//	for (int i = 0;i < 8;i++) {	//row i
	//		if (users[i] == name) {
	//			found =1;
	//			break;
	//		}
	//	}	
	//	if (found == 1) {
	//		cout << "User " << name << " is found in the system" << endl;
	//	}
	//	else {
	//		cout << "User not found" << endl;
	//	}
	//}



	int choice = 0;
	string seats[24][6];
	ifstream myFile("seats.txt");
	for (int i = 0;i < 24;i++) {
		for (int j = 0;j < 6;j++) {
			myFile >> seats[i][j];
		}
	}
	myFile.close();

	while (choice != 4) {
		int avalible_seats = 0;
		int reserved_seats = 0;
		int aisle_seat = 0;
		int window_seat = 0;
		int update_row = 0;
		int update_column = 0;
		char update_status;
		cout << "Select the following options:" << endl << "1. Check Status" << endl << "2. Update Seat Selection" << endl << "3. Show Seat Chart" << endl << "4. Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			for (int i = 0;i < 24;i++) {
				for (int j = 0;j < 6;j++) {
					if (seats[i][j] == "A") {
						avalible_seats =avalible_seats + 1;
						if (j == 2 || j == 3) {
							aisle_seat++;
					}
						if (j == 0 || j == 5) {
							window_seat++;
						}
				}
					if (seats[i][j] == "R") {
						reserved_seats = reserved_seats + 1;
					}
				}
			}
			cout << "Avalible seats: " <<avalible_seats << endl;
			cout << "Avalible Aisle seats: " << aisle_seat << endl;
			cout << "Avalible Window seats: " << window_seat <<endl;
			cout << "Reserved Seats: " << reserved_seats <<endl;
			cout << endl;
			break;
		case 2:
			cout << "Enter row number (1-24): ";
			cin >> update_row;
			update_row--;
			cout << "Enter column number (1-6): ";
			cin >> update_column;
			update_column--;
			cout << "Status: " << seats[update_row][update_column] << endl;
			cout << "New Status (A= Avalible, R= Reserved): ";
			cin >> update_status;
			seats[update_row][update_column] = update_status;

			break;
		case 3:
			cout << "~~~~~~~~~~~~~~~~Seat Chart~~~~~~~~~~~~~~~~" << endl;
			for (int i = 0;i < 24;i++) {
				for (int j = 0;j < 6;j++) {
					cout << seats[i][j] << "\t";
				}
				cout << endl;
			}
			cout << endl << endl;
			break;
		case 4:
			cout << "Thank you for choosing Wentworth Seating system" << endl;
			break;
		default:
			cout << "Invalid Choice. Try Again." << endl;

		}
		//update the file
		ofstream updateFile("seats.txt");
		for (int i = 0;i < 24;i++) {
			for (int j = 0;j < 6;j++) {
				updateFile << seats[i][j] << "  ";
			}
			updateFile << endl;
		}
		//close file
		updateFile.close();

	}


	return 0;
}