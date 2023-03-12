// Movie.hh
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

class Movie {
public:
  static const int CHILDRENS   = 2;
  static const int REGULAR     = 0;
  static const int NEW_RELEASE = 1;

  Movie( const std::string& title, int priceCode = REGULAR );

  int getPriceCode() const;
  void setPriceCode( int arg );
  std::string getTitle() const;
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

private:
  std::string movieTitle;
  int moviePriceCode;
};

inline Movie::Movie( const std::string& title, int priceCode ): 
  movieTitle( title ),
  moviePriceCode( priceCode )
{}

inline int Movie::getPriceCode() const { return moviePriceCode; }

inline void Movie::setPriceCode( int arg ) { moviePriceCode = arg; }

inline std::string Movie::getTitle() const { return movieTitle; }

#endif // MOVIE_H
