// Name of Pragrammers: Leow Hui Xin, Looi Wei En, Wong Jia Yi
// Date Created: 11 December 2021
// Purpose of the program: To suggest devices based on their specifications and features

#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>

using namespace std;


int main()
{
	// variable definitions (do refer the report for more details of the variables)
	char feature1, feature2, feature3;
	
	int choices, budget, remainder, num;
	int price_1, price_2, price_3;
	int linecount = 0, max_rom=0, max_mainCam=0, count=0;
	int price, ROM, RAM, main_cam, front_cam, battery;
	int price_a, price_b, price_c, price_d, price_e;
	int ROM_line, speed_line, mainCam_line;
	
	long long int speed_count=1, ROM_count=1, mainCam_count =1;
	
	double speed, max_speed =0;
	
	string filename;
	string opt_1, opt_2, opt_3;
	string model, make, processor, speedName, line;
	string option1 = "Processor_speed", option2 = "ROM_size", option3 = "Main_camera";
	string suggestion1="", suggestion2="", suggestion3="";
	string selection;
	string a,b,c,d,e;
	
	
	
	ifstream inputFile;
	cout << "Please enter your file name: " <<endl;
    getline (cin,filename);
	inputFile.open(filename);
		
	// Beginning of user interface
	cout <<endl<<"%%%%%%%%%%%%%%%%%%%%%%    Smart Device Recommendation System    %%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout << "Features to determine the most suitable device: " <<endl;
	// Features available for users to choose are listed
	cout << "| Processor_speed (a) / ROM_size (b) / Main_camera (c) |" <<endl;
	
	cout << "\nPlease enter the number of features you want to take into consideration (1/2/3): ";
	cin >> choices;
	
	
	while (choices > 3 || choices < 1)
	{
		cout << "Please enter a number from 1 to 3.";
		cin >> choices;
	}
	
	cout << endl;
	
	
	// Get user's preference for features (at most 3 choices)
	if (choices == 3)
	{
		cout << "Enter your preferred features from the most required to the least required (a/b/c)." <<endl;
		cin >> feature1>> feature2>> feature3;
		if (feature1 == 'a')
		{
			opt_1 = "Processor_speed";
		}
		else if (feature1 == 'b')
		{
			opt_1 = "ROM_size";
		}
		else if (feature1 == 'c')
		{
			opt_1 = "Main_camera";
		}
		
		if (feature2 == 'a')
		{
			opt_2 = "Processor_speed";
		}
		else if (feature2 == 'b')
		{
			opt_2 = "ROM_size";
		}
		else if (feature2 == 'c')
		{
			opt_2 = "Main_camera";
		}
		
		if (feature3 == 'a')
		{
			opt_3 = "Processor_speed";
		}
		else if (feature3 == 'b')
		{
			opt_3 = "ROM_size";
		}
		else if (feature3 == 'c')
		{
			opt_3 = "Main_camera";
		}
	}
	
	else if (choices == 2)
	{
		cout << "Enter your preferred features from the most required to the least required. (a/b/c)" <<endl;
		cin >> feature1 >> feature2;
		if (feature1 == 'a')
		{
			opt_1 = "Processor_speed";
		}
		else if (feature1 == 'b')
		{
			opt_1 = "ROM_size";
		}
		else if (feature1 == 'c')
		{
			opt_1 = "Main_camera";
		}
		
		if (feature2 == 'a')
		{
			opt_2 = "Processor_speed";
		}
		else if (feature2 == 'b')
		{
			opt_2 = "ROM_size";
		}
		else if (feature2 == 'c')
		{
			opt_2 = "Main_camera";
		}
		cin.ignore();
	}
	
	else if (choices == 1)
	{
		cout << "Enter your most required feature. (a/b/c)" <<endl;
		cin >> feature1;
		if (feature1 == 'a')
		{
			opt_1 = "Processor_speed";
		}
		else if (feature1 == 'b')
		{
			opt_1 = "ROM_size";
		}
		else if (feature1 == 'c')
		{
			opt_1 = "Main_camera";
		}
		cin.ignore();
	}

	// End of first part of user interface
	cout <<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	        

	
	// While loop to count the number of lines of the input file
	while (inputFile)
	{
		getline(inputFile, line, '\n');
		linecount ++;
		if (inputFile.eof())
		{
			break;
		}
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	
	
	
	//************************************************************************************************************************************************************
	// Calculate the first suggestion
	while (getline(inputFile, model, '\t'))
	{
		getline(inputFile, make, '\t');
		
		inputFile >> price;
	    inputFile.ignore();

		getline(inputFile, processor, '\t');
		
		inputFile >> speed;
		
		getline (inputFile, speedName, '\t');
	
		inputFile >> ROM >> RAM >> main_cam >> front_cam >> battery;
		
		// Finding the max value of speed
		if (opt_1 == option1|| opt_2 == option1 ||opt_3 == option1)
		{
			speed_count = speed_count *10;
			if (speed> max_speed)
			{
				max_speed = speed;
				speed_count ++;
			}	
		}
	}
	
	
	
	
	
	// Obtaining the number of line of first suggestion
	speed_line = linecount;	
	while (speed_count != 0)
	{
		speed_count = speed_count / 10;
		speed_line = speed_line - 1;
		if (speed_count % 10 !=0)
		{
			break;
		}
	}
	
	// Returning to the beginning of the input file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	
	

	// Obtaining the model of the suggestion by rereading the file
	
	while (count < speed_line)
	{
		getline(inputFile, model, '\t');
		getline(inputFile, make, '\t');
		inputFile >> price;	
		inputFile.ignore();
		getline(inputFile, processor, '\t');
		inputFile >> speed;
		getline (inputFile, speedName, '\t');
		inputFile >> ROM >> RAM >> main_cam >> front_cam >> battery;
		count++;
	}

	if (option1 == opt_1)
	{
		suggestion1 = model;
		price_1 = price;
	}
	else if (option1 == opt_2)
	{
		suggestion2 = model;
		price_2 = price;
	}
	else if (option1 == opt_3)
	{
		suggestion3 = model;
		price_3 = price;
	}
	
	// Clear the remaining buffer and return to the beginning of the input file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	




	//************************************************************************************************************************************************************
	// Calculate the second suggestion
	while (getline(inputFile, model, '\t'))
	{
		getline(inputFile, make, '\t');
		
		inputFile >> price;
	    inputFile.ignore();
	   
		getline(inputFile, processor, '\t');
		
		inputFile >> speed;
		
		getline (inputFile, speedName, '\t');
	
		inputFile >> ROM >> RAM >> main_cam >> front_cam >> battery;
		
		// Find the max value of ROM
		if (opt_1 == option2|| opt_2 == option2 ||opt_3 == option2)
		{
			ROM_count = ROM_count *10;
			if (ROM> max_rom)
			{
				max_rom = ROM;
				ROM_count ++;
			}	
		}
	}

	
	// Obtaining the number of line of the suggestion
	ROM_line = linecount;
	while (ROM_count != 0)
	{
		ROM_count = ROM_count / 10;
		ROM_line = ROM_line - 1;
		if (ROM_count % 10 !=0)
		{
			break;
		}
	}
	
	// Returning to the beginning of the input file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	
	// Obtaining the model of the suggestion
		count =0;
		while (count < ROM_line)
		{
			getline(inputFile, model, '\t');
			getline(inputFile, make, '\t');
			inputFile >> price;	
			inputFile.ignore();
			getline(inputFile, processor, '\t');
			inputFile >> speed;
			getline (inputFile, speedName, '\t');
			inputFile >> ROM >> RAM >> main_cam >> front_cam >> battery;
			count++;
		}
	
		if (option2 == opt_1)
		{
			suggestion1 = model;
			price_1 = price;
		}
		else if (option2 == opt_2)
		{
			suggestion2 = model;
			price_2 = price;
		}
		else if (option2 == opt_3)
		{
			suggestion3 = model;
			price_3 = price;
		}
	
	
	// Returning to the beginning of the input file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	

	
	//************************************************************************************************************************************************************
	// Calculate the third suggestion
	while (getline(inputFile, model, '\t'))
	{
		getline(inputFile, make, '\t');
		
		inputFile >> price;
	    inputFile.ignore();
	   
		getline(inputFile, processor, '\t');
		
		inputFile >> speed;
		
		getline (inputFile, speedName, '\t');
	
		inputFile >> ROM >> RAM >> main_cam >> front_cam >> battery;
		
		// Find the max value of the main camera MP
		if (opt_1 == option3|| opt_2 == option3 ||opt_3 == option3)
		{
			mainCam_count = mainCam_count *10;
			if (main_cam> max_mainCam)
			{
				max_mainCam = main_cam;
				mainCam_count ++;
			}	
		}
	}
	

	
	// Obtaining the number of line of suggestion
	mainCam_line = linecount;
	while (mainCam_count != 0)
	{
		mainCam_count = mainCam_count / 10;
		mainCam_line = mainCam_line - 1;
		if (mainCam_count % 10 !=0)
		{
			break;
		}
	}
	
	// Returning to the beginning of the input file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	
	
	// Obtaining the model of the suggestion
	count =0;
	while (count < mainCam_line)
	{
		getline(inputFile, model, '\t');
		getline(inputFile, make, '\t');
		inputFile >> price;	
		inputFile.ignore();
		getline(inputFile, processor, '\t');
		inputFile >> speed;
		getline (inputFile, speedName, '\t');
		inputFile >> ROM >> RAM >> main_cam >> front_cam >> battery;
		count++;
	}
	if (option3 == opt_1)
	{
		suggestion1 = model;
		price_1 = price;
	}
	else if (option3 == opt_2)
	{
		suggestion2 = model;
		price_2 = price;
	}
	else if (option3 == opt_3)
	{
		suggestion3 = model;
		price_3 = price;
	}
	
	
	//************************************************************************************************************************************************************
	// Beginning of the second part of user interface
	// Display of suggestions on the console
	if (suggestion1.length() != 0)
	{
		cout << "\n*Suggestion 1* " <<endl << suggestion1 <<endl;
		if(opt_1 == option1)
		{
			cout << "This phone has the fastest processing speed."<<endl;
		}
		else if (opt_1 == option2)
		{
			cout << "This phone has the largest ROM size."<<endl;
		}
		else if (opt_1 == option3)
		{
			cout << "This phone has the highest megapixel for its main camera. "<<endl;
		}
	}	
	if (suggestion2.length() != 0)
	{
		cout << "\n*Suggestion 2* " <<endl << suggestion2 <<endl;
		if(opt_2 == option1)
		{
			cout << "This phone has the fastest processing speed."<<endl;
		}
		else if (opt_2 == option2)
		{
			cout << "This phone has the largest ROM size."<<endl;
		}
		else if (opt_2 == option3)
		{
			cout << "This phone has the highest megapixel for its main camera. "<<endl;
		}
	}
	if (suggestion3.length() != 0)
	{
		cout << "\n*Suggestion 3* " <<endl << suggestion3 <<endl;
		if(opt_3 == option1)
		{
			cout << "This phone has the fastest processing speed."<<endl;
		}
		else if (opt_3 == option2)
		{
			cout << "This phone has the largest ROM size."<<endl;
		}
		else if (opt_3 == option3)
		{
			cout << "This phone has the highest megapixel for its main camera. "<<endl;
		}
	}
	
	// Asking the user to make a selection among the suggestions
	if (suggestion2.length() == 0 && suggestion3.length() == 0 && suggestion1.length() != 0)
	{
		cout << suggestion1 << " is the best fit for you.";
		selection = suggestion1;
	}
	else if (suggestion2.length() != 0 && suggestion3.length() == 0 && suggestion1.length() != 0)
	{
		cout << "\nPlease choose one among the suggestions provided. (1/2)" <<endl;
		cin >> num;
		if (num == 1 )
		{
			selection = suggestion1;
			price = price_1;
		}
		else if (num == 2)
		{
			selection = suggestion2;
			price = price_2;
		}
	}
	else if (suggestion2.length() != 0 && suggestion3.length() != 0 && suggestion1.length() != 0)
	{
		cout << "\nPlease choose one among the suggestions provided. (1/2/3)" <<endl;
		cin >> num;
		if (num == 1 )
		{
			selection = suggestion1;
			price = price_1;
		}
		else if (num == 2)
		{
			selection = suggestion2;
			price = price_2;
		}
		else if (num == 3)
		{
			selection = suggestion3;
			price = price_3;
		}
	}
	
	

	// Display the price of the device and ask for the user's ceiling value
	cout <<endl << "-------------------------------------------------------------------------------------" <<endl;
	cout << selection << " is priced at RM" <<price <<"."<<endl;
	cout << "\nPlease define your ceiling value (RM): " ;
	cin >> budget;
	while (budget < price)
	{
		cout << "You need a higher ceiling value to cover the cost." <<endl;
		cout << "RM";
		cin >> budget;
	}
	
	// Calculate and display the remaining money
	remainder = budget - price;
	cout << "\nYour have RM" << remainder << " remaining." <<endl <<endl;
	
	// Accessories
	a = "A bluetooth speaker (RM 200)",
	b = "A pair bluetooth earphones (RM 80)",
	c = "A phone casing (RM 16)",
	d = "A wireless charging pad (RM 40)",
	e = "A power bank (RM 55)";
		   
    price_a = 200, price_b = 80, price_c = 16, price_d = 40, price_e=55;
	
	//Suggest accessories based on the remaining money
	if (remainder !=0)
	{
		if(remainder >price_a)
		{
			cout << "You could get : " << endl;
			cout << a <<endl;
			cout << b <<endl;
			cout << c <<endl;
			cout << d <<endl;
			cout << e <<endl;
		}
		else if (remainder >=price_b && remainder <price_a)
		{
			cout << "You could get : " << endl;
			cout << b <<endl;
			cout << c <<endl;
			cout << d <<endl;
			cout << e <<endl;
			
			
		}
		else if (remainder >= price_e && remainder <price_b )
		{
			cout << "You could get : " << endl;
			
			cout << c <<endl;
			cout << d <<endl;
			cout << e <<endl;
		}
		else if (remainder >= price_d && remainder < price_e)
		{
			cout << "You could get : " << endl;
			cout << c <<endl;
			cout << d <<endl;
		}
		else if (remainder >= price_c && remainder < price_d)
		{
			cout << "You could get : " << endl;
			cout << c <<endl;
		}
		else
		{
			cout << "Sorry, we could not find any suitable accessories for you.";
		}
	
	}
	cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~ Thank you for using our program!!!! ~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
	inputFile.close();
	
	return 0;
	
}
