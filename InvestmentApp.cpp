/*
 * InvestmentApp.cpp
 *
 *  Created on: Feb 3, 2021
 *      Author: blakecondrey
 */

#include <iostream>
#include <memory>
#include "InvestmentApp.h"
using namespace std;

// default constructor initialized

Investment::Investment() {
	this->m_initAmount = 0;
	this->m_interestRate = 0;
	this->m_numYears = 0;
	this->m_monthlyDeposit = 0;
}
// constructor with parameters

Investment::Investment(double t_initAmount, double t_interestRate, double t_numYears, double t_monthlyDeposit) {
	m_initAmount = t_initAmount;
	m_interestRate = t_interestRate;
	m_numYears = t_numYears;
	m_monthlyDeposit = t_monthlyDeposit;
}

// Getters

double Investment::GetInvestmentAmount() const {
	return m_initAmount;
}

double Investment::GetInterestRate() const {
	return m_interestRate;
}

double Investment::GetNumYears() const {
	return m_numYears;
}

double Investment::GetMonthlyDeposit() const {
	return m_monthlyDeposit;
}

// Setters

void Investment::SetInvestmentAmount(double t_initAmount) {
	m_initAmount = t_initAmount;
}

void Investment::SetInterestRate(double t_interestRate) {
	m_interestRate = t_interestRate;
}

void Investment::SetNumYears(double t_numYears) {
	m_numYears = t_numYears;
}

void Investment::SetMonthlyDeposit(double t_monthlyDeposit) {
	m_monthlyDeposit = t_monthlyDeposit;
}
