#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Car
{
private:
    string brand;
    double fuelConsumption;

public:
    Car(string b, double fc) : brand(b), fuelConsumption(fc) {}

    friend double calculateFuelCost(const Car &car, double distance, double fuelPrice);
};

double calculateFuelCost(const Car &car, double distance, double fuelPrice)
{
    double fuelNeeded = (car.fuelConsumption * distance) / 100.0;
    double totalCost = fuelNeeded * fuelPrice;
    return totalCost;
}

int main()
{
    string brand;
    double fuelConsumption, distance, fuelPrice;

    getline(cin, brand);
    cin >> fuelConsumption >> distance >> fuelPrice;

    Car car(brand, fuelConsumption);
    double fuelCost = calculateFuelCost(car, distance, fuelPrice);

    cout << fixed << setprecision(2) << fuelCost << endl;

    return 0;
}
