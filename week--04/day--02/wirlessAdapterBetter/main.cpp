#include <iostream>
#include "WirelessAdapter.h"


int main( int argc, char* args[] )
{
    WirelessAdapter adapter(0, 2, 100);
    adapter.info();
}