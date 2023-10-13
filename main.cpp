#include <iostream>
#include <string>
#include <fstream>
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;	//open and write a file

int main() {
	string name[4][6];
	//open a file
	ifstream myFile("FindWord.txt");
	
	//store name from file to an array
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 6;j++) {
			myFile >> name[i][j];
		}
	}
	//close a file
	myFile.close();	
	//count how many joker in this group
	int count = 0;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 6;j++) {
			if (name[i][j] == "Joker") {
				count = count + 1;
				cout << "Joker is at row " << i << " column " << j << endl;
				if (count == 2) {
					name[i][j] = "Nick";
				}
			}
		}
	}
	cout << "There are " << count << " Jokers in the list" << endl;
//update the file
	ofstream updateFile("FindWord.txt");

	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 6;j++) {
			updateFile << name[i][j] << "  ";
		}
		updateFile << endl;
	}
	//close file
	updateFile.close();






	return 0;
}