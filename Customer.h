// Customer.hh
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <sstream>
#include "Rental.h"

// The customer class represents the customer of the store

class Customer {
public:
  Customer();
  explicit Customer( const std::string& name );

  void addRental( const Rental& arg );
  std::string getName() const;

  // Generate a statement for the customer
  std::string statement();
  std::string getResultNew();

private:
  std::string customerName;
  std::vector< Rental > customerRentals;
  std::ostringstream resultNew;

};



inline Customer::Customer() {}

inline Customer::Customer( const std::string& name ): 
  customerName( name ) {}

inline void Customer::addRental( const Rental& arg ) { customerRentals.push_back( arg ); }

inline std::string Customer::getName() const { return customerName; }

// New Receipt
inline std::string Customer::getResultNew() { return resultNew.str();}

#endif // CUSTOMER_HH
