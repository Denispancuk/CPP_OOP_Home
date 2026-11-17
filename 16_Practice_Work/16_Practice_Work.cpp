#include <iostream>
using namespace std;
//Завдання N 1
//Створити базовий клас Employer(служ -
//    бовець) з чисто віртуальною функцією Print().Створіть
//    три похідних класи : President, Manager, Worker.Переви -
//    значите функцію Print() для виведення інформації, що
//    відповідає кожному типу службовця.
//    Завдання N 2
//    Створити базовий клас «Транспортний
//    засіб» і похідні класи «Автомобіль», «Велосипед», «Віз».
//    Підрахувати час і вартість перевезення пасажирів і
//    вантажів кожним транспортним засобом.
struct PIB {
    string FirstName;
    string MiddleName;
    string LastName;
    PIB() :FirstName("No first Name"), MiddleName("No middle name"), LastName("No last name") {}
    PIB(string FN, string MN, string LN) :FirstName(FN), MiddleName(MN), LastName(LN) {}
    void PrintPIB() const {
        cout << "First name: " << FirstName << endl;
        cout << "Middle name: " << MiddleName << endl;
        cout << "Last name: " << LastName << endl;
    }

};
class Employer {
protected:
    PIB Name;
    long long number;
    int salary;
public:
    Employer() :Name(), number(0), salary(0) {}
    Employer(string FN, string MN, string LN, long long number, int salary) :Name({ FN,MN,LN }), number(number), salary(salary) {}
    Employer(PIB name, long long number, int salary) :Name(name), number(number), salary(salary) {}
    void ChangeNumber(long long number) {
        this->number = number;
    }
    void ChangeSalary(int salary) {
        this->salary = salary;
    }
    virtual void Print() const = 0;


};
class President : public Employer {
    string CompanyName;
    int CompanyMonthlyEarnings;
public:
    President():CompanyName("None"),CompanyMonthlyEarnings(0),Employer() {}
    President(string CompanyName, int CompanyMonthlyEarnings, string FN, string MN, string LN, long long number, int salary):CompanyName(CompanyName),CompanyMonthlyEarnings(CompanyMonthlyEarnings),Employer({FN,MN,LN},number,salary) {}
    President(string CompanyName, int CompanyMonthlyEarnings, PIB name, long long number, int salary):CompanyName(CompanyName),CompanyMonthlyEarnings(CompanyMonthlyEarnings),Employer(name,number,salary) {}
    void ChangeCompanyName(string CompanyName) {
        this->CompanyName = CompanyName;
    }
    void ChangeCompanyMonthlyEarnings(int CompanyMonthlyEarnings) {
        this->CompanyMonthlyEarnings = CompanyMonthlyEarnings;
    }
    virtual void Print() const override{
        Name.PrintPIB();
        cout << "Number: " << number << endl;
        cout << "Salary: " << salary << endl;
        cout << "Company Name: " << CompanyName << endl;
        cout << "Company Monthly Earnings: " << CompanyMonthlyEarnings << endl;
    }
};
class Manager : public Employer {
    string NameCurrentProject;
    int CompletedProjects;
public:
    Manager():NameCurrentProject("None"),CompletedProjects(0),Employer() {}
    Manager(string NameCurrentProject, int CompletedProjects, string FN, string MN, string LN, long long number, int salary):NameCurrentProject(NameCurrentProject),CompletedProjects(CompletedProjects),Employer({ FN,MN,LN }, number, salary) {}
    Manager(string NameCurrentProject, int CompletedProjects, PIB name, long long number, int salary):NameCurrentProject(NameCurrentProject),CompletedProjects(CompletedProjects),Employer(name, number, salary) {}
    void ChangeNameCurrentProject(string NameCurrentProject) {
        this->NameCurrentProject = NameCurrentProject;
    }
    void ChangeCompletedProjects(int Completedprojects) {
        this->CompletedProjects = Completedprojects;
    }
    void AddCompletedProjects() {
        CompletedProjects++;
    }
    virtual void Print() const override {
        Name.PrintPIB();
        cout << "Number: " << number << endl;
        cout << "Salary: " << salary << endl;
        cout << "Name Current Project: " << NameCurrentProject << endl;
        cout << "Completed Projects: " << CompletedProjects << endl;
    }
};
class Worker : public Employer {
    string WorkShop;
    int WorkHours;
public:
    Worker():WorkShop("None"),WorkHours(0),Employer() {}
    Worker(string WorkShop, int WorkHours, string FN, string MN, string LN, long long number, int salary):WorkShop(WorkShop),WorkHours(WorkHours),Employer({ FN,MN,LN }, number, salary) {}
    Worker(string WorkShop, int WorkHours, PIB name, long long number, int salary):WorkShop(WorkShop),WorkHours(WorkHours),Employer(Name, number, salary) {}
    void ChangeWorkShop(string WorkShop) {
        this->WorkShop = WorkShop;
    }
    void ChangeWorkHours(int WorkHours) {
        this->WorkHours = WorkHours;
    }
    void AddWorkHours(int WorkHours) {
        this->WorkHours += WorkHours;
    }
    virtual void Print() const override {
        Name.PrintPIB();
        cout << "Number: " << number << endl;
        cout << "Salary: " << salary << endl;
        cout << "Work Shop: " << WorkShop << endl;
        cout << "Work Hours: " << WorkHours << endl;
    }
};

class Vehicle {
protected:
    string Type;
    string Name;
public:
    Vehicle():Type("None"),Name("None") {}
    Vehicle(string Type,string Name):Type(Type),Name(Name) {}
    void ChangeType(string Type) {
        this->Type = Type;
    }
    void ChangeName(string Name) {
        this->Name = Name;
    }
    void ShowInfo() {
        cout << "Type: " << Type << endl;
        cout << "Name: " << Name << endl;
    }
    virtual void PrintSumTrips() const = 0;
    virtual void PrintTravelTime() const = 0;

};
class AutoMobile : public Vehicle {
    float Distance;
    float AverageSpeed;
    float FuelConsumption;
    float FuelPrice;
public:
    AutoMobile():Distance(0),AverageSpeed(0),FuelConsumption(0),FuelPrice(0),Vehicle("Automobile","None") {}
    AutoMobile(float Distance,float AverageSpeed,float FuelConsumption,float FuelPrice,string Name):Distance(Distance),AverageSpeed(AverageSpeed),FuelConsumption(FuelConsumption),FuelPrice(FuelPrice),Vehicle("Automobile",Name) {}
    void ChangeDistance(float Distance) {
        this->Distance = Distance;
    }
    void ChangeAverageSpeed(float AverageSpeed) {
        this->AverageSpeed = AverageSpeed;
    }
    void ChangeFuelConsumption(float FuelConsumption) {
        this->FuelConsumption = FuelConsumption;
    }
    void ChangeFuelPrice(float FuelPrice) {
        this->FuelPrice = FuelPrice;
    }
    void PrintSumTrips() const override {
        cout << "Sum trip: " << (Distance / 100) * FuelConsumption * FuelPrice << endl;
    }
    void PrintTravelTime() const override {
        cout << "Travel Time: " << Distance / AverageSpeed << endl;
    }

};
class Bicycle : public Vehicle {
    float Distance;
    float AverageSpeed;
    int ResourceConsumption;
    float ResourcePrice;
public:
    Bicycle():Distance(0),AverageSpeed(0),ResourceConsumption(0),ResourcePrice(0),Vehicle("Bicycle","None") {}
    Bicycle(float Distance, float AverageSpeed, int ResourceConsumption, float ResourcePrice,string Name):Distance(Distance),AverageSpeed(AverageSpeed),ResourceConsumption(ResourceConsumption),ResourcePrice(ResourcePrice),Vehicle("Bicycle",Name) {}
    void ChangeDistance(float Distance) {
        this->Distance = Distance;
    }
    void ChangeAverageSpeed(float AverageSpeed) {
        this->AverageSpeed = AverageSpeed;
    }
    void ChangeResourceConsumption(int ResourceConsumption) {
        this->ResourceConsumption = ResourceConsumption;
    }
    void ChangeResourcePrice(int ResourcePrice) {
        this->ResourcePrice = ResourcePrice;
    }
    void AddResourseConsumption(int ResourceConsumption) {
        this->ResourceConsumption = ResourceConsumption;
    }
    void AddOneResourseConsumption() {
        this->ResourceConsumption++;
    }
    void PrintSumTrips() const override {
        cout << "Sum trip: " << (Distance / 100) * ResourceConsumption * ResourcePrice << endl;
    }
    void PrintTravelTime() const override {
        cout << "Travel Time: " << Distance / AverageSpeed << endl;
    }
};
class Cart : public Vehicle {
    float Distance;
    float AverageSpeed;
    int ResourceConsumption;
    float ResourcePrice;
public:
    Cart() :Distance(0), AverageSpeed(0), ResourceConsumption(0), ResourcePrice(0), Vehicle("Cart", "None") {}
    Cart(float Distance, float AverageSpeed, int ResourceConsumption, float ResourcePrice, string Name) :Distance(Distance), AverageSpeed(AverageSpeed), ResourceConsumption(ResourceConsumption), ResourcePrice(ResourcePrice), Vehicle("Cart", Name) {}
    void ChangeDistance(float Distance) {
        this->Distance = Distance;
    }
    void ChangeAverageSpeed(float AverageSpeed) {
        this->AverageSpeed = AverageSpeed;
    }
    void ChangeResourceConsumption(int ResourceConsumption) {
        this->ResourceConsumption = ResourceConsumption;
    }
    void ChangeResourcePrice(int ResourcePrice) {
        this->ResourcePrice = ResourcePrice;
    }
    void AddResourseConsumption(int ResourceConsumption) {
        this->ResourceConsumption = ResourceConsumption;
    }
    void AddOneResourseConsumption() {
        this->ResourceConsumption++;
    }
    void PrintSumTrips() const override {
        cout << "Sum trip: " << (Distance / 100) * ResourceConsumption * ResourcePrice << endl;
    }
    void PrintTravelTime() const override {
        cout << "Travel Time: " << Distance / AverageSpeed << endl;
    }

};
int main()
{
    President president("Google", 500000, "John", "Michael", "Smith", 1001, 150000);
    Manager manager("AI Project", 5, "David", "James", "Brown", 1002, 50000);
    Worker worker("Production", 40, "Alex", "Robert", "Wilson", 1003, 20000);

    president.Print();
    manager.Print();
    worker.Print();

    president.ChangeNumber(2001);
    president.ChangeSalary(160000);
    president.ChangeCompanyName("Microsoft");
    president.ChangeCompanyMonthlyEarnings(700000);

    manager.ChangeNumber(2002);
    manager.ChangeSalary(55000);
    manager.ChangeNameCurrentProject("Website");
    manager.ChangeCompletedProjects(10);
    manager.AddCompletedProjects();

    worker.ChangeNumber(2003);
    worker.ChangeSalary(25000);
    worker.ChangeWorkShop("Assembly");
    worker.ChangeWorkHours(50);
    worker.AddWorkHours(5);

    president.Print();
    manager.Print();
    worker.Print();

    AutoMobile car(200, 80, 8, 60, "BMW");
    Bicycle bicycle(100, 20, 1, 30, "Trek");
    Cart cart(50, 5, 2, 10, "Wooden Cart");

    car.ShowInfo();
    bicycle.ShowInfo();
    cart.ShowInfo();

    car.PrintSumTrips();
    car.PrintTravelTime();

    bicycle.PrintSumTrips();
    bicycle.PrintTravelTime();

    cart.PrintSumTrips();
    cart.PrintTravelTime();

    car.ChangeDistance(300);
    car.ChangeAverageSpeed(100);
    car.ChangeFuelConsumption(10);
    car.ChangeFuelPrice(65);

    bicycle.ChangeDistance(150);
    bicycle.ChangeAverageSpeed(25);
    bicycle.ChangeResourceConsumption(2);
    bicycle.ChangeResourcePrice(35);
    bicycle.AddResourseConsumption(3);
    bicycle.AddOneResourseConsumption();

    cart.ChangeDistance(70);
    cart.ChangeAverageSpeed(7);
    cart.ChangeResourceConsumption(3);
    cart.ChangeResourcePrice(15);
    cart.AddResourseConsumption(4);
    cart.AddOneResourseConsumption();

    car.PrintSumTrips();
    car.PrintTravelTime();

    bicycle.PrintSumTrips();
    bicycle.PrintTravelTime();

    cart.PrintSumTrips();
    cart.PrintTravelTime();

}