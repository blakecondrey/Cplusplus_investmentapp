/*
 * InvestmentApp.h
 *
 *  Created on: Feb 3, 2021
 *      Author: blakecondrey
 */

#ifndef INVESTMENTAPP_H_
#define INVESTMENTAPP_H_

class Investment {		// create investment object
	// public members, accessible to class users
	public:
		// Default constructor
		Investment();
		// Constructor w/ parameters
		/*
		 * spec calls for function parameters to be named with the
		 * t_ prefic to distinguish the function parameters from
		 * other variables within scope. Since monthly deposit will
		 * have option to display with no addt'l monthly deposit, this
		 * parameter will be defaulted to zero.
		 */
		Investment(double t_initAmount, double t_interestRate, double t_numYears, double t_monthlyDeposit = 0);

		/*
		 * Accessors and mutators (getters and setters)
		 * Getters will be defined with const to feed compiler that the
		 * value will not be changed, thus the setters can mutate the values
		 */

		// Getters

		double GetInvestmentAmount() const;
		double GetInterestRate() const;
		double GetNumYears() const;
		double GetMonthlyDeposit() const;

		// Setters

		void SetInvestmentAmount(double t_initAmount);
		void SetInterestRate(double t_interestRate);
		void SetNumYears(double t_numYears);
		void SetMonthlyDeposit(double t_monhtlyDeposit);

	// private members, not accessible to class users
	// only accessible within class
	private:
		// distinguish private members with m_ prefix per spec
		double m_initAmount;
		double m_interestRate;
		double m_numYears;
		double m_monthlyDeposit;
};



#endif /* INVESTMENTAPP_H_ */
