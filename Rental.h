// Rental.hh
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
  Rental( const Movie& movie, int daysRented );

  int getDaysRented() const;
  const Movie& getMovie() const;
  double calcCost();

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

inline double Rental::calcCost() {
	return rentedMovie.movieCost(nDaysRented);
}

inline Rental::Rental( const Movie& movie, int daysRented ):
  rentedMovie( movie ),
  nDaysRented( daysRented ) {}

inline int Rental::getDaysRented() const { return nDaysRented; }

inline const Movie& Rental::getMovie() const { return rentedMovie; }

#endif // RENTAL_H
