/*
 * main.cpp
 *
 *  Created on: Feb 3, 2021
 *      Author: blakecondrey
 */

#include<iostream>

#include "InvestmentApp.h"
#include "InvestmentFunctions.h"

using namespace std;

int main() {
	// starts with displaying empty chart
	DisplayInvestmentChart();
	// declare double variables to call Gather____Input functions to create parameters
	// for parameterized Investment constructor
	double initialInvestment = GatherInvestmentInput("Enter initial investment amount: ");
	double interestRate = GatherInterestRateInput("Enter interest rate: ");
	double numYears = GatherNumYearsInput("Enter number of years: ");
	double monthlyDeposit = DepositDecision();
	Investment myInvestment(initialInvestment, interestRate, numYears, monthlyDeposit); // instantiate Investment object
	// output with new object
	DisplayInvestmentChart(myInvestment);
	DisplayInvestmentGrowth(myInvestment, false);
	cout << endl;
	DisplayInvestmentGrowth(myInvestment, true);
	cout << endl;

	cout << "\n\n\n";
	DisplayEditingTool(myInvestment, initialInvestment, interestRate, numYears, monthlyDeposit);
	return 0;
}
