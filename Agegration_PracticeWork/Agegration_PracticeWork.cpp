#include <iostream>
using namespace std;
class Engine {
    string fuelType;
    double volume;
    int horsepower;
public:
    Engine() :fuelType("None"), volume(0), horsepower(0) {}
    Engine(string f, double v, int h) :fuelType(f), volume(v), horsepower(h) {}
    void ChangeFuelType(string fuelType) {
        this->fuelType = fuelType;
    }
    void Show()const {
        cout << "fuel Type: " << fuelType << endl;
        cout << "volume: " << volume << endl;
        cout << "horse power: " << horsepower << endl;
    }
};
class Wheel {
    int radius;
    double pressure;
    string season;
public:
    Wheel() :radius(0), pressure(0), season("None") {}
    Wheel(int r, double p, string s) :radius(r), pressure(p), season(s) {}
    void ChangeSeason(string season) {
        this->season = season;
    }
    void ChangePressure(double pressure) {
        this->pressure = pressure;
    }
    void Show()const {
        cout << "Radius: " << radius << endl;
        cout << "pressure: " << pressure << endl;
        cout << "season: " << season << endl;
    }
};
class Headlight {
    string type;
    int brightness;
    bool isOn;
public:
    Headlight() :type("None"), brightness(0), isOn(false) {}
    Headlight(string t, int b, bool i) :type(t), brightness(b), isOn(i) {}
    void ChangeIsOn() {
        isOn = !isOn;
    }
    void ChangeType(string type) {
        this->type = type;
    }
    void ChangeBrightness(int brightness) {
        this->brightness = brightness;
    }
    void Show()const {
        cout << "type: " << type << endl;
        cout << "Brightness: " << brightness << endl;
        cout << "isOn: " << isOn << endl;
    }
};

class Door {
    string side;
    bool isOpen;
    bool isLocked;
public:
    Door() :side("None"), isOpen(false), isLocked(false) {}
    Door(string s, bool IO, bool IL) :side(s), isOpen(IO), isLocked(IL) {}
    void ChangeIsOpen() {
        isOpen = !isOpen;
    }
    void ChangeIsLocked() {
        isLocked = !isLocked;
    }
    void Show() const {
        cout << "Side: " << side << endl;
        cout << "is Open: " << isOpen << endl;
        cout << "Is Locked: " << isLocked << endl;
    }
};
class Body {
    string type;
    string color;
    string material;
public:
    Body():type("None"),color("None"),material("None") {}
    Body(string t,string c,string m):type(t),color(c),material(m) {}
    void ChangeColor(string color) {
        this->color = color;
    }
    void Show() const {
        cout << "type: " << type << endl;
        cout << "color: " << color << endl;
        cout << "material: " << material << endl;
    }

};
class Driver {
    string name;
    int age;
    int experience;
public:
    Driver():name("None"),age(0),experience(0){}
    Driver(string n,int a,int e):name(n),age(a),experience(e){}
    void ChangeName(string name) {
        this->name = name;
    }

    void ChangeAge(int age) {
        this->age = age;
    }

    void ChangeExperience(int experience) {
        this->experience = experience;
    }
    void Show() const {
        cout << "Name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "experience: " << experience << endl;
    }
};
class Car {
    string brand;
    string model;
    int year;
    int speed;

    Headlight headlights[2];
    Door doors[4];
    Wheel wheels[4];
    Engine engine;
    Body body;
    Driver driver;

public:
    Car() : brand("None"), model("None"), year(0), speed(0), headlights{ Headlight(), Headlight() }, doors{ Door(), Door(), Door(), Door() }, wheels{ Wheel(), Wheel(), Wheel(), Wheel() }, engine(), body(), driver() {}

    Car(string b, string m, int y, int s, Headlight h1, Headlight h2, Door d1, Door d2, Door d3, Door d4, Wheel w1, Wheel w2, Wheel w3, Wheel w4, Engine e, Body bo, Driver dr) : brand(b), model(m), year(y), speed(s), headlights{ h1, h2 }, doors{ d1, d2, d3, d4 }, wheels{ w1, w2, w3, w4 }, engine(e), body(bo), driver(dr) {}

    void Show() const {
        cout << "brand: " << brand << endl;
        cout << "model: " << model << endl;
        cout << "year: " << year << endl;
        cout << "speed: " << speed << endl;
    }
    void ChangeSpeed(int speed) {
        this->speed = speed;
    }

    void ChangeBrand(string brand) {
        this->brand = brand;
    }

    void ChangeModel(string model) {
        this->model = model;
    }
};
int main()
{
    Engine engine("Petrol", 2.0, 200);
    engine.ChangeFuelType("Diesel");
    engine.Show();

    Wheel wheel(17, 2.2, "Summer");
    wheel.ChangeSeason("Winter");
    wheel.ChangePressure(2.5);
    wheel.Show();

    Headlight headlight("LED", 1500, true);
    headlight.ChangeIsOn();
    headlight.ChangeType("Xenon");
    headlight.ChangeBrightness(2000);
    headlight.Show();

    Door door("Left", false, true);
    door.ChangeIsOpen();
    door.ChangeIsLocked();
    door.Show();

    Body body("Sedan", "Black", "Steel");
    body.ChangeColor("White");
    body.Show();

    Driver driver("Alex", 25, 5);
    driver.ChangeName("Max");
    driver.ChangeAge(30);
    driver.ChangeExperience(10);
    driver.Show();

    Car car("BMW", "M5", 2022, 100, headlight, headlight, door, door, door, door, wheel, wheel, wheel, wheel, engine, body, driver);
    car.ChangeSpeed(150);
    car.ChangeBrand("Audi");
    car.ChangeModel("RS7");
    car.Show();

}