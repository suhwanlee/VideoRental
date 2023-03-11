#include <iostream>
#include "Customer.h"
#include "Movie.h"

using namespace std;

int main()
{
    Movie regular1{ "����������", Movie::REGULAR };
    Movie regular2{ "�ظ�����", Movie::REGULAR };
    Movie newRelease1{ "����", Movie::NEW_RELEASE };
    Movie newRelease2{ "ž��",Movie::NEW_RELEASE };
    Movie children1{ "�̴Ͼ���", Movie::CHILDRENS };
    Movie children2{ "�Ƿη�", Movie::CHILDRENS };
    Movie pop1{ "���۷θ�", Movie::POPULAR };
    Customer customer{ "��" };

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
