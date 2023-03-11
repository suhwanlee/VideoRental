// Customer.hh
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>
#include "Rental.h"

using namespace std;
// The customer class represents the customer of the store

class Customer {
public:
  Customer();
  explicit Customer( const string& name );

  void addRental(Movie* movie, int rentedDay);
  string getName() const;

  // Generate a statement for the customer
  string statement();
  string receiptTop();
  string receiptBotton(double totalAmount, int frequentRenterPoints);
  string receiptBody(string title, double cost);

private:
  string customerName;
  vector< Rental > customerRentals;

};

inline string Customer::receiptTop() {
	return "Rental Record for " + getName() + "\n";
}

inline string Customer::receiptBody(string title, double cost) {
	return "\t" + title + "\t" + to_string(cost) + "\n";
}

inline string Customer::receiptBotton(double totalAmount, int frequentRenterPoints) {

	string bottom1 = "Amount owed is " + to_string(totalAmount) + "\n";
	string bottom2 = "You earned " + to_string(frequentRenterPoints) + " frequent renter points";

	return bottom1 + bottom2;
}

inline Customer::Customer() {}

inline Customer::Customer( const string& name ): 
  customerName( name ) {}

inline void Customer::addRental(Movie* movie, int rentedDay) { customerRentals.push_back({ *movie,rentedDay }); }

inline string Customer::getName() const { return customerName; }

#endif // CUSTOMER_HH
