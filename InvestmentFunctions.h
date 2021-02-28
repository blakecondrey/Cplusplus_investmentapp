/*
 * InvestmentFunctions.h
 *
 *  Created on: Feb 3, 2021
 *      Author: blakecondrey
 */

#ifndef INVESTMENTFUNCTIONS_H_
#define INVESTMENTFUNCTIONS_H_

#include "InvestmentApp.h"

double ConvertToDouble(std::string prompt);
double GatherInvestmentInput(std::string prompt);
double GatherInterestRateInput(std::string prompt);
double GatherNumYearsInput(std::string prompt);
double GatherDepositInput(std::string prompt);
double DepositDecision();
void PrintBorder(int length, char charToPrint);
void DisplayInvestmentChart(Investment &investment);
void DisplayInvestmentChart();
void DisplayInvestmentGrowth(Investment &investment, bool monthly = false);
void DisplayOptionsMenu();
void DisplayEditingTool(Investment &investment, double &initAmount, double &interestRate,
		double &numYears, double &monthlyDeposit);


#endif /* INVESTMENTFUNCTIONS_H_ */
