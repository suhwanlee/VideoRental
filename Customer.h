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
  explicit Customer( const string& name );

  void addRental(Movie* movie, int rentedDay);
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
	return "Rental Record for " + customerName + "\n";
}

inline string Customer::receiptBody(string title, double cost) {
	return "\t" + title + "\t" + to_string(cost) + "\n";
}

inline string Customer::receiptBotton(double totalAmount, int frequentRenterPoints) {
	return "Amount owed is " + to_string(totalAmount) + "\n" 
		+ "You earned " + to_string(frequentRenterPoints) + " frequent renter points";
}

inline Customer::Customer( const string& name ):   customerName( name ) {}

inline void Customer::addRental(Movie* movie, int rentedDay) { customerRentals.push_back({ *movie,rentedDay }); }
#endif // CUSTOMER_HH
