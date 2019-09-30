#include <iostream>
#include "F16.h"
#include "Carrier.h"

int main() {

    F16 firstAirplane;
    F16 secondAirplane;
    F35 thirdAirplane;
    F35 fourthAirplane;

    F16 a;
    F16 b;
    F35 c;
    F35 d;
    F16 e;
    F16 f;
    F35 g;
    F35 h;



    Carrier UssEnterprise(5000, 0);
    Carrier UssMissouri(3000, 2000);

    UssMissouri.addAircraftF35(&g);
    UssMissouri.addAircraftF35(&c);
    UssMissouri.addAircraftF35(&d);
    UssMissouri.addAircraftF35(&h);

    UssEnterprise.addAircraftF16(&firstAirplane);
    UssEnterprise.addAircraftF16(&secondAirplane);
    UssEnterprise.addAircraftF16(&a);
    UssEnterprise.addAircraftF16(&b);
    UssEnterprise.addAircraftF16(&e);
    UssEnterprise.addAircraftF35(&thirdAirplane);
    UssEnterprise.addAircraftF35(&fourthAirplane);
    UssEnterprise.addAircraft(&a);
    UssEnterprise.addAircraft(&g);

    UssEnterprise.fill();
    UssEnterprise.fight(&UssMissouri);
    UssMissouri.fill();
    UssMissouri.fight(&UssEnterprise);
    UssEnterprise.fill();
    UssMissouri.fill();



    std::cout << UssEnterprise.getStatus() << std::endl;
    std::cout << UssMissouri.getStatus() << std::endl;


}