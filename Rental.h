// Rental.hh
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
  Rental( const Movie& movie, int daysRented );

  int getDaysRented() const;
  const Movie& getMovie() const;
  double calcCost(Rental rent) {
	  double cost = 0.;
	  // Determine amounts for each rental
	  switch (rent.getMovie().getPriceCode()) {

	  case Movie::REGULAR:
		  cost += 2.;
		  if (rent.getDaysRented() > 2)
			  cost += (rent.getDaysRented() - 2) * 1.5;
		  break;

	  case Movie::NEW_RELEASE:
		  cost += rent.getDaysRented() * 3;
		  break;

	  case Movie::CHILDRENS:
		  cost += 1.5;
		  if (rent.getDaysRented() > 3)
			  cost += (rent.getDaysRented() - 3) * 1.5;
		  break;
	  }

	  return cost;
  }

  int calcRentPoint(Rental rent) {
	  int point;
	  // Add bonus for a two day new release rental
	  if ((rent.getMovie().getPriceCode() == Movie::NEW_RELEASE) && rent.getDaysRented() > 1) 
		  point = 2;
	  else
		  point = 1;

	  return point;
  }

private:
  Movie rentedMovie;
  int nDaysRented;
};

inline Rental::Rental( const Movie& movie, int daysRented ):
  rentedMovie( movie ),
  nDaysRented( daysRented ) {}

inline int Rental::getDaysRented() const { return nDaysRented; }

inline const Movie& Rental::getMovie() const { return rentedMovie; }

#endif // RENTAL_H
