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

  std::vector< Rental >::iterator iter = customerRentals.begin();
  std::vector< Rental >::iterator iter_end = customerRentals.end();

  // result will be returned by statement()
  std::ostringstream result;
  
  result << "Rental Record for " << getName() << "\n";

  resultNew << "\nRenttal Record for" << getName() << "\n";
  //출력형식 : (장르 제목 대여기간 가격)
  resultNew << "\tGenre\tTitle\tRentedDay\tPrice\n";

  // Loop over customer's rentals
  for ( ; iter != iter_end; ++iter ) {

    double thisAmount = 0.;
    Rental each = *iter;
    std::string genre;

    // Determine amounts for each rental
    switch ( each.getMovie().getPriceCode() ) {

      case Movie::REGULAR:
        thisAmount += 2.;
        genre = "Regular";
        if ( each.getDaysRented() > 2 )
          thisAmount += ( each.getDaysRented() - 2 ) * 1.5 ;
        break;

      case Movie::NEW_RELEASE:
        thisAmount += each.getDaysRented() * 3;
        genre = "NewRelease";
        break;

      case Movie::CHILDRENS:
        thisAmount += 1.5;
        if ( each.getDaysRented() > 3 )
          thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
        genre = "Regular";
        break;
      case Movie::POPULAR:
          thisAmount += 2.5;
          if (each.getDaysRented() > 2)
              thisAmount += (each.getDaysRented() - 3) * 2.5;
          genre = "Popular";
          break;
    }

    // Add frequent renter points
    frequentRenterPoints++;

    // Add bonus for a two day new release rental
    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && each.getDaysRented() > 1 ) frequentRenterPoints++;

    // Show figures for this rental
    result << "\t" << each.getMovie().getTitle() << "\t"
           << thisAmount << std::endl;
    resultNew << "\t" << genre << "\t" << each.getMovie().getTitle() << "\t"
        << each.getDaysRented() << "\t" << thisAmount << std::endl;

    totalAmount += thisAmount;
  }

  // Add footer lines
  result << "Amount owed is " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints
         << " frequent renter points";

  resultNew << "Amount owed is " << totalAmount << "\n";
  resultNew << "You earned " << frequentRenterPoints
      << " frequent renter points";

  return result.str();
}
