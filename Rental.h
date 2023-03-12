// Rental.hh
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
  Rental( const Movie& movie, int daysRented = 1 );

  const Movie& getMovie() const;
  double calcCost();
  int calcRentPoint();

private:
  Movie rentedMovie;
  int nDaysRented;
};

inline double Rental::calcCost() {
	return rentedMovie.movieCost(nDaysRented);
}

inline int Rental::calcRentPoint() {
	return rentedMovie.moviePoint(nDaysRented);
}
inline Rental::Rental( const Movie& movie, int daysRented ):
  rentedMovie( movie ),
  nDaysRented( daysRented ) {}

inline const Movie& Rental::getMovie() const { return rentedMovie; }

#endif // RENTAL_H
