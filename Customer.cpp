// Customer.cc
#include <vector>
#include "Customer.h"

using namespace std;

string Customer::statement()
{
	double totalAmount = 0.;
	int frequentRenterPoints = 0;

	vector<Rental> myRent = customerRentals;

	// result will be returned by statement()
	string result = receiptTop();

	for (Rental rent : myRent) {
		
		// Add rent cost
		double thisAmount = rent.calcCost(rent);

		// Add frequent renter points
		frequentRenterPoints += rent.calcRentPoint(rent);		

		// Show figures for this rental
		result += receiptBody(rent.getMovie().getTitle(), thisAmount);
		totalAmount += thisAmount;
	}

	// Add footer lines
	result += receiptBotton(totalAmount, frequentRenterPoints);

	return result;
}