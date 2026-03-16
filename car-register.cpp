#include <iostream>

using namespace std;

class Vehicle
{

private:
    int vehicleID, year;
    string manufacturer, model;

public:
    static int totalVehicles;

    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
    }

    Vehicle(int id, string manufac, string model, int year)
    {
        this->vehicleID = id;
        this->manufacturer = manufac;
        this->model = model;
        this->year = year;

        totalVehicles++;
    };

    ~Vehicle(){};

    int returnTotalVehicle()
    {
        return totalVehicles;
    }
    int returnVehicleID()
    {
        return vehicleID;
    }

    void Setter(int id, string manufac, string model, int year)
    {
        this->vehicleID = id;
        this->manufacturer = manufac;
        this->model = model;
        this->year = year;
    }

    virtual void Getter()
    {
        cout << "\nVehicleID is : " << this->vehicleID << endl;
        cout << "Manufacturer is : " << this->manufacturer << endl;
        cout << "Model is : " << this->model << endl;
        cout << "Year is : " << this->year << endl;
    }
};

class Aircraft
{
private:
    int flightRange;

public:
    Aircraft()
    {
        this->flightRange = 0;
    }
    Aircraft(int range)
    {
        this->flightRange = range;
    }
    void Getter()
    {
        cout << "Flight Range : " << flightRange << " KM " << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{

private:
    string fuelType;

public:
    Car() {}
    Car(int id, string manu, string model, int year, string fuel) : Vehicle(id, manu, model, year)
    {
        this->fuelType = fuel;
    }

    void Getter()
    {
        Vehicle::Getter();
        cout << "Fueltype is : " << this->fuelType << endl;
    }
};

class ElectricCar : public Car
{

private:
    int BatteryCapacity;

public:
    ElectricCar() {}
    ElectricCar(int id, string manu, string model, int year, string fuel, int capacity) : Car(id, manu, model, year, fuel)
    {
        this->BatteryCapacity = capacity;
    }

    void Getter()
    {
        Car::Getter();
        cout << "Battery Capacity : " << this->BatteryCapacity << " KWH" << endl;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar(int id, string manu, string model, int year, string fuel, int range) : Car(id, manu, model, year, fuel), Aircraft(range) {}

    void Getter()
    {
        Car::Getter();
        Aircraft::Getter();
    }
};

class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportsCar() {}
    SportsCar(int id, string manu, string model, int year, string fuel, int capacity, int speed) : ElectricCar(id, manu, model, year, fuel, capacity)
    {
        this->topSpeed = speed;
    }

    void Getter()
    {
        ElectricCar::Getter();
        cout << "Top Speed (km/h)  : " << this->topSpeed << endl;
    }
};

class Sedan : public Car
{
public:
    Sedan(int id, string manu, string model, int year, string fuel) : Car(id, manu, model, year, fuel) {}

    void Getter()
    {
        cout << "Vehicle Type: Sedan" << endl;
        Car::Getter();
    }
};

class SUV : public Car
{
public:
    SUV(int id, string manu, string model, int year, string fuel) : Car(id, manu, model, year, fuel) {}

    void Getter()
    {
        cout << "Vehicle Type: SUV" << endl;
        Car::Getter();
    }
};

class VehicleRegistery
{

private:
    Vehicle *vehicles[100];
    int count;

public:
    VehicleRegistery()
    {
        count = 0;
    }

    void addVehicles(Vehicle *v)
    {
        vehicles[count++] = v;
    }

    void displayVehicles()
    {
        for (int i = 0; i < count; i++)
        {
            cout << "\n-----------------------------";
            vehicles[i]->Getter();
            cout << "-----------------------------\n"
                 << endl;
        }
    }

    void searchVehicle(int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->returnVehicleID() == id)
            {
                cout << "Vehicle found : ";
                vehicles[i]->Getter();
                return;
            }
        }
        cout << "Vehicle Not Found." << endl;
    }
};

int main()
{
    VehicleRegistery regi;
    int choice, id, year, battery, speed, range;
    string manu, model, fuel;
menu:

    cout << "\n---------- Vehicle Registry System ----------" << endl;
    cout << "1. Add Car" << endl;
    cout << "2. Add Electric Car" << endl;
    cout << "3. Add Sports Car" << endl;
    cout << "4. Add Flying Car" << endl;
    cout << "5. Add Sedan Car" << endl;
    cout << "6. Add SUV Car" << endl;
    cout << "7. View All Vehicles" << endl;
    cout << "8. Search Vehicle by ID" << endl;
    cout << "9. Exit" << endl;

    cout << "Enter Your Choice : ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    // Car
    case 1:
    {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();

        cout << "Manufacturer: ";
        getline(cin, manu);

        cout << "Model: ";
        getline(cin, model);

        cout << "Year: ";
        cin >> year;
        cin.ignore();

        cout << "Fuel Type: ";
        getline(cin, fuel);

        regi.addVehicles(new Car(id, manu, model, year, fuel));

        goto menu;
    }

    // Electric
    case 2:
    {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();

        cout << "Manufacturer: ";
        getline(cin, manu);

        cout << "Model: ";
        getline(cin, model);

        cout << "Year: ";
        cin >> year;
        cin.ignore();

        cout << "Fuel Type: ";
        getline(cin, fuel);

        cout << "Battery Capacity (kwh): ";
        cin >> battery;

        regi.addVehicles(new ElectricCar(id, manu, model, year, fuel, battery));

        goto menu;
    }

    // sports
    case 3:
    {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();

        cout << "Manufacturer: ";
        getline(cin, manu);

        cout << "Model: ";
        getline(cin, model);

        cout << "Year: ";
        cin >> year;
        cin.ignore();

        cout << "Battery Capacity (kwh): ";
        cin >> battery;

        cout << "Fuel Type: ";
        getline(cin, fuel);

        cout << "Top Speed : ";
        cin >> speed;

        regi.addVehicles(new SportsCar(id, manu, model, year, fuel, battery, speed));

        goto menu;
    }

    // flying
    case 4:
    {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();

        cout << "Manufacturer: ";
        getline(cin, manu);

        cout << "Model: ";
        getline(cin, model);

        cout << "Year: ";
        cin >> year;
        cin.ignore();

        cout << "Fuel Type: ";
        getline(cin, fuel);

        cout << "Flight Range (km) : ";
        cin >> range;

        regi.addVehicles(new FlyingCar(id, manu, model, year, fuel, range));

        goto menu;
    }

    // Sedan
    case 5:
    {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();

        cout << "Manufacturer: ";
        getline(cin, manu);

        cout << "Model: ";
        getline(cin, model);

        cout << "Year: ";
        cin >> year;
        cin.ignore();

        cout << "Fuel Type: ";
        getline(cin, fuel);

        regi.addVehicles(new Sedan(id, manu, model, year, fuel));

        goto menu;
    }

    // SUV
    case 6:
    {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();

        cout << "Manufacturer: ";
        getline(cin, manu);

        cout << "Model: ";
        getline(cin, model);

        cout << "Year: ";
        cin >> year;
        cin.ignore();

        cout << "Fuel Type: ";
        getline(cin, fuel);

        regi.addVehicles(new SUV(id, manu, model, year, fuel));

        goto menu;
    }

    // view vehicle list
    case 7:
        regi.displayVehicles();
        goto menu;

    // search vehicle
    case 8:
    {
        cout << "Enter Vehicle ID : " << endl;
        cin >> id;
        regi.searchVehicle(id);

        goto menu;
    }

    // exit
    case 9:
        cout << "Exiting...." << endl;
        break;

    default:
        cout << "Please Enter Valid Choice." << endl;
        goto menu;
    }
}