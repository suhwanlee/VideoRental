#include <iostream>
#include "Customer.h"
#include "Movie.h"

using namespace std;

int main()
{
    Customer customer{ "��" };

    customer.addRental(new Movie("�Ϲ� 1", Movie::REGULAR), 2);
    customer.addRental(new Movie("�Ϲ� 2", Movie::REGULAR), 3);
    customer.addRental(new Movie("���� 1", Movie::NEW_RELEASE), 1);
    customer.addRental(new Movie("���� 2", Movie::NEW_RELEASE), 2);
    customer.addRental(new Movie("��� 1", Movie::CHILDRENS), 3);
    customer.addRental(new Movie("��� 2", Movie::CHILDRENS), 4);

    cout << customer.statement() << endl;

    return 0;
}
