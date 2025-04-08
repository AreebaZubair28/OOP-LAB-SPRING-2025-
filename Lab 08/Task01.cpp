#include "iostream"
using namespace std;

class Humidity;

class Temperature{
    float temp;

public:
  
    Temperature(float temp) : temp(temp) {}

    friend float calculateHeatIndex(Temperature& t, Humidity& h);  // or calculateHeatIndex(Temperature t, Humidity h)
};

class Humidity{
    float humidity;

public:
  
    Humidity(float h) : humidity(h) {}

    friend float calculateHeatIndex(Temperature& t, Humidity& h);
};

float calculateHeatIndex(Temperature& t, Humidity& h)
{
    return t.temp + h.humidity;
}

int main()
{
    Temperature t(32);
    Humidity h(70);

    cout <<"Heat Index: " << calculateHeatIndex(t,h) << endl;
}
