/*Popular Baby Names
* Timothy Hall
* Module 9   Homework 9  

Algorithm:
1. Declare constants as the file names
2. Open the girl and boy name files and verify it opened successfully
3. Enter into an infinite loop and ask for a name to search for
4. Create two more loops searching through each file for the names, ranking, and amount of names registered
5. If names are found print the data, if it isn't print statement saying they were not found.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	string full_line;
	const string INPUT_FILE_GIRL = "GirlNames2023.txt"; //Initializing the input files of both girl and boy names.
	const string INPUT_FILE_BOY = "BoyNames2023.txt";

	ifstream input_file_girl; //Creating file variable and opening the file with girl names
	input_file_girl.open(INPUT_FILE_GIRL.c_str());
	if (!input_file_girl)
	{
		cout << "There was an error opening the file: " << INPUT_FILE_GIRL << endl; //If it cant open, print error message Otherwise print a success message
		return 1; 
	}
	else {
		cout << "Success." << endl;
	}
	input_file_girl >> full_line;
	cout << full_line;


	ifstream input_file_boy;
	input_file_boy.open(INPUT_FILE_BOY.c_str()); //Creating file variable and opening the file with boy names
	if (!input_file_boy)
	{
		cout << "There was an error opening the file: " << INPUT_FILE_BOY << endl; //If it cant open, print error message, Otherwise print a success message
		return 1;
	}
	else {
		cout << "Success." << endl;
	}



	while (true) //Enter an infinite loop to keep on asking names
	{
		
		string search_name; //Ask for a name 0 to exit
		cout << "Enter a name to search (0) to exit: ";
		cin >> search_name;

		if (search_name == "0") //If it is zero then exit
		{
			break;
		}

		string name;
		int amount; //variables for when searching for the name in a loop
		string full_line;

		int ranking_girl = 0;
		int ranking_boy = 0;
		int amount_girl = 0; //Ranking and amount of registered names for the boy and girl files
		int amount_boy = 0;
		bool found_girl = false; //Initializing the condition if the girl or boy name was found
		bool found_boy = false;

		int rank = 1;

		while (input_file_girl >> name >> amount) //Searching in the girl names file
		{
			if (search_name == name)
			{
				found_girl = true; //Changing condition to found 
				ranking_girl = rank; //Assigning the rank
				amount_girl = amount; //Assigning the amount registered
				break; //breaking out of searching for the names
			}
			++rank; //Incrementing each time it moves to the next line
			getline(input_file_girl, full_line); //Getting rid of the newline created by the >> operator

		}

		while (input_file_boy >> name >> amount) //Searching in the boy names file. Same concept as the girl names file while loop
		{
			if (search_name == name)
			{
				found_boy = true;
				ranking_boy = rank;
				amount_boy = amount;
				break;
			}
			++rank;
			getline(input_file_boy, full_line);
		}

		if (found_girl) //If the found condition is true print the raking and registered amount, if not print that it isn't rated
		{
			cout << search_name << " is ranked " << ranking_girl << " among girls with " << amount_girl << " registered births." << endl;
		}
		else {
			cout << search_name << " is not ranked among the top 1000 girl names." << endl;
		}

		if (found_boy) //Same as girl if statement above
		{
			cout << search_name << " is ranked " << ranking_boy << " among boys with " << amount_boy << " registered births." << endl;
		}
		else {
			cout << search_name << " is not ranked among the top 1000 boy names." << endl;
		}
	}
	

	cout << "Goodbye." << endl; //Goodbye
	return 0;
}