/*
 * InvestmentFunctions.cpp
 *
 *  Created on: Feb 3, 2021
 *      Author: blakecondrey
 */

#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<stdlib.h>
#include<stdexcept>
#include<unistd.h>
#include <cctype>
#include "InvestmentFunctions.h"
#include "InvestmentApp.h"
using namespace std;

/*
 * Function will prompt the user for input as string. String will parse and
 * convert to type double to then be utilized in Gather____Input functions
 * to create a double type variable as a parameter for the Investment object
 */
double ConvertToDouble(string prompt) {
	bool flag;						// exception handling
	string userInputInString;		// storage to be converted
	double userInput;				// converted for return

	/*
	 *  Spec calls for exception handling to validate input
	 *  do-while / try-catch exception handling to loop at
	 *  least once through
	 */

	do {
		flag = true;
		try {
			cout << prompt << endl;
			cin >> userInputInString;
			userInput = stod(userInputInString);
			// http://www.cplusplus.com/reference/string/stod/
		}
		catch (invalid_argument& excpt) {
			cout << "Invalid input. Please enter a number.\n\n";
			flag = false;
		}
	} while (!flag);
	return userInput;
}

/*
 * Utilizes ConvertToDouble Function to gather an entry to
 * become a parameter for Investment object
 */

double GatherInvestmentInput(string prompt) {
	bool flag;						// exception handling
	double investmentAmt;

	/*
	 *  Spec calls for exception handling to validate input
	 *  do-while / try-catch exception handling to loop at
	 *  least once through
	 */

	do {
		flag = true;
		try {
			investmentAmt = ConvertToDouble(prompt);
			if (investmentAmt < 1) {
				throw runtime_error("Invalid input. Enter a number greater than 0.");
			}
		}
		catch(runtime_error& excpt) {
			cout << "\n\n" << excpt.what() << endl;
			flag = false;
		}
	} while (!flag);

	return investmentAmt;
}

/*
 * Utilizes ConvertToDouble Function to gather an entry to
 * become a parameter for Investment object
 */

double GatherInterestRateInput(string prompt) {
	bool flag;
	double interestRate;
	/*
	 *  Spec calls for exception handling to validate input
	 *  do-while / try-catch exception handling to loop at
	 *  least once through
	 */
	do {
		flag = true;
		try {
			interestRate = ConvertToDouble(prompt);
			if (interestRate < 0) {
				throw runtime_error("Interest rate cannot be negative.");
			}
		}
		catch(runtime_error& excpt) {
			cout << "\n\n" << excpt.what() << endl;
			flag = false;
		}
	} while (!flag);

	return interestRate;

}
/*
 * Utilizes ConvertToDouble Function to gather an entry to
 * become a parameter for Investment object
 */

double GatherNumYearsInput(string prompt) {
	bool flag;
	double numYears;
	/*
	 *  Spec calls for exception handling to validate input
	 *  do-while / try-catch exception handling to loop at
	 *  least once through
	 */
	do {
		flag = true;
		try {
			numYears = ConvertToDouble(prompt);
			if (numYears < 1) {
				throw runtime_error("Invalid input. Enter 1 or more years.");
			}
		}
		catch(runtime_error& excpt) {
			cout << "\n\n" << excpt.what() << endl;
			flag = false;
		}
	} while (!flag);

	return numYears;
}
/*
 * Utilizes ConvertToDouble Function to gather an entry to
 * become a parameter for Investment object
 */

double GatherDepositInput(string prompt) {
	bool flag;
	double depositAmt;
	/*
	 *  Spec calls for exception handling to validate input
	 *  do-while / try-catch exception handling to loop at
	 *  least once through
	 */
	do {
		flag = true;
		try {
			depositAmt = ConvertToDouble(prompt);
			if (depositAmt < 1) {
				throw runtime_error("Invalid input. Enter a number great than 0.");
			}
		}
		catch(runtime_error& excpt) {
			cout << "\n\n" << excpt.what() << endl;
			flag = false;
		}
	} while (!flag);

	return depositAmt;
}
/*
 * Utilizes ConvertToDouble Function to gather an entry to
 * invoke GatherDepositInput or set recurring deposit
 * amount to 0.0
 */

double DepositDecision() {
	bool flag;
	double depositAmt;
	char userInput;
	/*
	 *  Spec calls for exception handling to validate input
	 *  do-while / try-catch exception handling to loop at
	 *  least once through
	 */
	do {
		flag = true;
		try {
			cout << "Do you wish to add a recurring monthly deposit? (Y/N) " << endl;
			cin >> userInput;
			if ((userInput != 'Y') && (userInput != 'y') && (userInput != 'N') && (userInput != 'n')) {
				throw runtime_error("Invalid response. Please enter Y or N.");
			}
		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
			flag = false;
		}
	} while(!flag);

	if ((userInput == 'Y') || (userInput == 'y')) {
		depositAmt = GatherDepositInput("Enter recurring deposit amount: ");
	}
	else {
		depositAmt = 0.0;
	}
	return depositAmt;
}

// easy function to call to print desired span without redundant code
void PrintBorder(int length, char charToPrint) {
	unsigned int i;
	for (i = 0; i < length; ++i) {
		cout << charToPrint;
	}
}

void DisplayInvestmentChart(Investment &investment) { // by reference for memory utilization
	const int CHART_WIDTH = 35;
	string menuTitle = " Data Input";
	char borderChar = '*';
	PrintBorder(CHART_WIDTH, borderChar);
	cout << endl;
	// to center and aesthetically output chart
	PrintBorder((((CHART_WIDTH - menuTitle.length()) / 2) - 1), borderChar);
	cout << menuTitle << " ";
	PrintBorder((((CHART_WIDTH - menuTitle.length()) / 2)), borderChar);
	cout << endl;
	cout << "Initial Investment Amount: $" << investment.GetInvestmentAmount() << endl;
	cout << "Monthly Deposit: $" << investment.GetMonthlyDeposit() << endl;
	cout << "Annual Interest: " << investment.GetInterestRate() << "%" << endl;
	cout << "Number of years: " << investment.GetNumYears() << endl;
	cout << endl << endl;
	sleep(1);
}

void DisplayInvestmentChart() {
	const int CHART_WIDTH = 35; // set width of chart to utilize print border function
	string menuTitle = " Data Input";
	char borderChar = '*';
	PrintBorder(CHART_WIDTH, borderChar);
	cout << endl;
	// to center and aesthetically output chart
	PrintBorder((((CHART_WIDTH - menuTitle.length()) / 2) - 1), borderChar);
	cout << menuTitle << " ";
	PrintBorder((((CHART_WIDTH - menuTitle.length()) / 2)), borderChar);
	cout << endl;
	cout << "Initial Investment Amount: $" << endl;
	cout << "Monthly Deposit: $" << endl;
	cout << "Annual Interest: "  << endl;
	cout << "Number of years: \n" << endl;
	cout << "Press ENTER key to continue . . . ";
	cin.get();
	cout << endl;
}

void DisplayInvestmentGrowth(Investment &investment, bool monthly) { // by reference for memory utilization
	unsigned int i; // outer for-loop
	unsigned int j;	// inner for-loop
	const int CHART_WIDTH = 80; // set width of chart to utilize print border function
	const double MONTHS_IN_YR = 12.00; // constant will not change thus improves calculation
	// to output two static charts
	string menuTitleOne = "Balance and Interest With Additional Monthly Deposits";
	string menuTitleTwo = "Balance and Interest Without Additional Deposits";
	string menuTitle;
	if (monthly) {		// if bool monthly parameter is true, chart WILL have recurring monthly deposits
		menuTitle = menuTitleOne;
	}
	else {				// no additional monthly deposits
		menuTitle = menuTitleTwo;
	}
	int whiteSpace = CHART_WIDTH - menuTitle.length(); // to center title for aesthetics
	string yearHeader = "Year";
	string endBalance = "Year End Balance";
	string earnedInterest = "Year End Earned Interest";
	char borderChar = '=';
	char cutLine = '-'; // all chars here are to be used in print border function
	char space = ' ';
	PrintBorder(CHART_WIDTH, borderChar);
	cout << endl;
	PrintBorder((whiteSpace / 2), space);
	cout << menuTitle;
	PrintBorder((whiteSpace / 2), space);
	cout << endl << endl;
	cout << yearHeader << "\t\t" << endBalance << "\t\t" << earnedInterest;
	cout << endl;
	PrintBorder(CHART_WIDTH, cutLine);
	cout << endl;

	double openingAmount = investment.GetInvestmentAmount(); // call accessor to return private member data
	/*
	 * for loop to loop through num years to calculate the final balance
	 * using interest rate and output the result
	 */
	for (i = 1; i <= investment.GetNumYears(); ++i) {
		int currentYear = i;
		double interestRate = investment.GetInterestRate() / 100.00;
		double earnedInterest;
		double totalInterest;
		double endingAmount;
		double monthEndBalance;
		if (monthly) {
			earnedInterest = 0;
			totalInterest = 0;
			/*
			 * inner for-loop to capture compounded monthly investment
			 * basic calculations inside to determine and save values
			 */
			interestRate = interestRate / MONTHS_IN_YR;
			for (j = 0; j < MONTHS_IN_YR; ++j) {
				openingAmount += investment.GetMonthlyDeposit();
				earnedInterest = (openingAmount * (1 + interestRate)) - openingAmount;
				monthEndBalance = openingAmount + earnedInterest;
				openingAmount = monthEndBalance;
				totalInterest += earnedInterest;
			}
		}
		// no monthly recurring deposits, only grows from interest
		else {
			totalInterest = (openingAmount * (1 + interestRate)) - openingAmount;
		}
		if (monthly) {
			endingAmount = openingAmount;
			// sets opening amount to end of year balance at exit
		}
		else {
			endingAmount = openingAmount + totalInterest;
			openingAmount = endingAmount;
			// set opening balance equal to ending balance for next iteration of loop
		}
		cout << currentYear;
		cout << "\t\t$" << setprecision(2) << fixed << endingAmount;
		cout << "\t\t\t$" << setprecision(2) << fixed << totalInterest << endl;
	}
}

// simple function to display next options for user to play with the investment app
void DisplayOptionsMenu() {
	vector<string> options(5);
	options[0] = "1 - Edit Initial Investment";
	options[1] = "2 - Edit Monthly Deposit Amount";
	options[2] = "3 - Edit Interest Rate";
	options[3] = "4 - Edit Amount of years";
	options[4] = "5 - Quit";

	const int MENU_WIDTH = 35;
	char borderChar = '=';
	PrintBorder(MENU_WIDTH, borderChar);
	cout << endl;
	for (int i = 0; i < options.size(); ++i) {
		cout << options[i] << endl;
	}
	PrintBorder(MENU_WIDTH, borderChar);
	cout << endl;
}
/*
 * Function will display options for user, then capture user input.
 * Based on user input, user will be asked to input new values requested,
 * or, exit the program. New values update the chart and output new values.
 */
void DisplayEditingTool(Investment &investment, double &initAmount, double &interestRate, double &numYears, double &monthlyDeposit) {
	// by reference for memory utilization
	bool flag;
	int userInput = 0;

	while (userInput != 5) {
		/*
		 *  Spec calls for exception handling to validate input
		 *  do-while / try-catch exception handling to loop at
		 *  least once through
		 */
		do {
			flag = true;
			try {
				DisplayOptionsMenu();
				cin >> userInput;
				if((userInput < 1) || (userInput > 5))  {
					throw runtime_error("Invalid entry.");
				}
			}
			catch (runtime_error& excpt) {
				cout << excpt.what() << endl;
				flag = false;
			}
		} while(!flag);
		cout << endl;

		/*
		 * Switch operation is better suited than if-else chain
		 * each case performs similar operations, mainly to update
		 * investment chart with new information after capturing from input
		 */

		switch(userInput) {
		case 1: // Edit investment amount
			DisplayInvestmentChart(investment);
			cout << endl;
			initAmount = GatherInvestmentInput("Enter new investment amount: ");
			investment.SetInvestmentAmount(initAmount);
			DisplayInvestmentChart(investment);
			DisplayInvestmentGrowth(investment, false);
			DisplayInvestmentGrowth(investment, true);
			break;
		case 2:
			DisplayInvestmentChart(investment);
			cout << endl;
			monthlyDeposit = GatherDepositInput("Enter new deposit amount: ");
			investment.SetMonthlyDeposit(monthlyDeposit);
			DisplayInvestmentChart(investment);
			DisplayInvestmentGrowth(investment, false);
			DisplayInvestmentGrowth(investment, true);
			break;
		case 3:
			DisplayInvestmentChart(investment);
			cout << endl;
			interestRate = GatherInterestRateInput("Enter a new interest rate: ");
			investment.SetInterestRate(interestRate);
			DisplayInvestmentChart(investment);
			DisplayInvestmentGrowth(investment, false);
			DisplayInvestmentGrowth(investment, true);
			break;
		case 4:
			DisplayInvestmentChart(investment);
			cout << endl;
			numYears = GatherNumYearsInput("Enter new number of years: ");
			investment.SetNumYears(numYears);
			DisplayInvestmentChart(investment);
			DisplayInvestmentGrowth(investment, false);
			DisplayInvestmentGrowth(investment, true);
			break;
		case 5:
			cout << "Goodbye.";
			exit(0); // exits program
		default:
			break;
		}
	}
}
