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
		
		double thisAmount = rent.getCost(rent);

		// Add frequent renter points
		frequentRenterPoints++;

		// Add bonus for a two day new release rental
		if ((rent.getMovie().getPriceCode() == Movie::NEW_RELEASE)
			&& rent.getDaysRented() > 1) frequentRenterPoints++;

		// Show figures for this rental
		result << "\t" << rent.getMovie().getTitle() << "\t"
			<< thisAmount << std::endl;
		totalAmount += thisAmount;
	}

	// Add footer lines
	result << "Amount owed is " << totalAmount << "\n";
	result << "You earned " << frequentRenterPoints
		<< " frequent renter points";

	return result.str();
}
