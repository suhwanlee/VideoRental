#include <iostream>
#include "Customer.h"
#include "Movie.h"

using namespace std;

int main()
{
    Customer customer{ "고객" };

    customer.addRental(new Movie("일반 1", Movie::REGULAR), 2);
    customer.addRental(new Movie("일반 2", Movie::REGULAR), 3);
    customer.addRental(new Movie("신작 1", Movie::NEW_RELEASE), 1);
    customer.addRental(new Movie("신작 2", Movie::NEW_RELEASE), 2);
    customer.addRental(new Movie("어린이 1", Movie::CHILDRENS), 3);
    customer.addRental(new Movie("어린이 2", Movie::CHILDRENS), 4);

    cout << customer.statement() << endl;

    return 0;
}
