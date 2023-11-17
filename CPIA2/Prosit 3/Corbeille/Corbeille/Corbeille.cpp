#include "pch.h"

using namespace std;

int main(void)
{
    Voiture* test = new VoitureSport(150, 3);
    while (!test->acceleration());

    return 0;
}
