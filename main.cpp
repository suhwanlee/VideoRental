#include <iostream>
#include "Customer.h"
#include "Movie.h"

using namespace std;

int main()
{
    Movie regular1{ "반지의제왕", Movie::REGULAR };
    Movie regular2{ "해리포터", Movie::REGULAR };
    Movie newRelease1{ "영웅", Movie::NEW_RELEASE };
    Movie newRelease2{ "탑건",Movie::NEW_RELEASE };
    Movie children1{ "미니언즈", Movie::CHILDRENS };
    Movie children2{ "뽀로로", Movie::CHILDRENS };
    Movie pop1{ "더글로리", Movie::POPULAR };
    Customer customer{ "고객" };

    customer.addRental({ regular1, 2 });
    customer.addRental({ regular2, 3 });
    customer.addRental({ newRelease1, 1 });
    customer.addRental({ newRelease2, 2 });
    customer.addRental({ children1, 3 });
    customer.addRental({ children2, 4 });
    customer.addRental({ pop1 , 2 });

    cout << customer.statement() << endl;
    cout << customer.getResultNew() << endl;

    return 0;
}
