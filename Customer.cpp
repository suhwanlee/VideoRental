// Customer.cc
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

std::string Customer::statement()
{
	double totalAmount = 0.;
	int frequentRenterPoints = 0;

	std::vector<Rental> myRent = customerRentals;

	// result will be returned by statement()
	std::ostringstream result;
	result << "Rental Record for " << getName() << "\n";

	for (Rental rent : myRent) {
		
		// Add rent cost
		double thisAmount = rent.calcCost(rent);

		// Add frequent renter points
		frequentRenterPoints = rent.calcRentPoint(rent);		

		// Show figures for this rental
		result << "\t" << rent.getMovie().getTitle() << "\t" << thisAmount << std::endl;
		totalAmount += thisAmount;
	}

	// Add footer lines
	result << "Amount owed is " << totalAmount << "\n";
	result << "You earned " << frequentRenterPoints << " frequent renter points";

	return result.str();
}
