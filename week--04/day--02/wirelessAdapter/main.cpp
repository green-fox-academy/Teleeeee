#include "WirelessAdapter.h"
#include "Device.h"

int main( int argc, char* args[] )
{
    WirelessAdapter adapter(0, 2, 100);
    adapter.info();
}