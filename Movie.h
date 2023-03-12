// Movie.hh
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

using namespace std;

class Movie {
public:
  static const int CHILDRENS   = 2;
  static const int REGULAR     = 0;
  static const int NEW_RELEASE = 1;

  Movie( const string& title, int priceCode = REGULAR );

  string getTitle() const;
  double movieCost(int dayRetned) {

	  double cost = 0.;
	  // Determine amounts for each rental
	  switch (moviePriceCode) {
	  case REGULAR:
		  cost = (dayRetned > 2) ? 2 + ((dayRetned - 2) * 1.5) : 2;
		  break;

	  case NEW_RELEASE:
		  cost = dayRetned * 3;
		  break;

	  case CHILDRENS:
		  cost = (dayRetned > 3) ? 1.5 + ((dayRetned - 3) * 1.5) : 1.5;
		  break;
	  }
	  return cost;
  }
  int moviePoint(int dayRented);

private:
  string movieTitle;
  int moviePriceCode;
};

inline int Movie::moviePoint(int dayRented) {
	return (moviePriceCode == NEW_RELEASE && dayRented > 1) ? 2 : 1;
}

inline Movie::Movie( const string& title, int priceCode ): 
  movieTitle( title ),
  moviePriceCode( priceCode )
{}

inline string Movie::getTitle() const { return movieTitle; }

#endif // MOVIE_H
