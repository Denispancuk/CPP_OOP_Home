#include <iostream>
#include <windows.h>
using namespace std;

class Animal
{
protected:
    string name;
    string place;
    float weight;
public:
    Animal() :name("no name"), place("no place"), weight(0) {}
    Animal(string n, string p, float w) :name(n), place(p)
    {
        weight = (w > 0) ? w : 0;
    }
    void Show()const
    {
        cout << "Name : " << name << endl;
        cout << "Place : " << place << endl;
        cout << "Weight : " << weight << endl;
    }
    virtual void MakeSound() = 0;
};

class Fox :public Animal {
    int age;
    bool isCunning;
public:
    Fox() :isCunning(true), age(0), Animal() {}
    Fox(bool isCunning, int age, string n, string p, float w) :isCunning(isCunning), age(age), Animal(n, p, w) {}
    void ChangeIsCunning() {
        isCunning = !isCunning;
    }
    void AddAge() {
        age++;
    }
    int GetAge() {
        return age;
    }
    void MakeSound() override {
        Beep(900, 50);
        Beep(1300, 70);
        Beep(500, 40);
        Beep(900, 50);
        Beep(1300, 70);
        Beep(500, 40);
        Beep(900, 50);
        Beep(1300, 70);
        Beep(500, 40);
        Beep(600, 20);
        Beep(700, 20);
        Beep(800, 20);
        Beep(900, 20);
        Beep(1000, 20);
        Beep(1100, 20);
        Beep(1200, 20);
        Beep(1300, 20);
        Beep(1400, 20);
        Beep(1500, 20);
        Beep(1600, 20);
        Beep(1700, 250);
        Beep(1600, 20);
        Beep(1500, 20);
        Beep(1400, 20);
        Beep(1300, 20);
        Beep(1200, 20);
        Beep(1100, 20);
        Beep(1000, 20);
        Beep(900, 20);
        Beep(800, 20);
        Beep(700, 20);
    }
};
class Rabbit :public Animal {
    float earLength;
    int age;
public:
    Rabbit() :earLength(0), age(0), Animal() {}
    Rabbit(float earLenght, int age, string n, string p, float w) :earLength(earLenght), age(age), Animal(n, p, w) {}
    void ChangeEarLength(float earLength) {
        this->earLength = earLength;
    }
    void AddEarLength(float earLength) {
        this->earLength += earLength;
    }
    void AddAge() {
        age++;
    }
    int GetAge() const {
        return age;
    }
    void MakeSound() override {
        Beep(150, 70);
        Beep(180, 70);
        Beep(150, 70);
        Beep(2200, 40);
        Beep(2600, 60);
        Beep(1800, 25);
        Beep(2000, 25);
        Beep(1800, 25);
        Beep(2000, 25);
        Beep(1800, 25);
        Beep(2000, 25);
        Beep(1800, 25);
        Beep(2000, 25);
        Beep(1800, 25);
        Beep(2000, 25);
        Beep(1800, 25);
        Beep(2000, 25);
    }
};
class Plants {
protected:
    string name;
    string place;
    float height;
public:
    Plants() :name("no name"), place("no place"), height(0) {}
    Plants(string n, string p, float h) :name(n), place(p)
    {
        height = (h > 0) ? h : 0;
    }
    void Show()const
    {
        cout << "Name : " << name << endl;
        cout << "Place : " << place << endl;
        cout << "Height : " << height << endl;
    }
};
class Grass :public Plants {
    string color;
    bool isMedicinal;
public:
    Grass() :color("None"), isMedicinal(false), Plants() {}
    Grass(string c, bool Medik, string n, string p, float h) :color(c), isMedicinal(Medik), Plants(n, p, h) {}
    void ChangeColor(string color) {
        this->color = color;
    }
    void ChangeIsMedicinal() {
        isMedicinal = !isMedicinal;
    }
};
class Life {
    Fox* foxes;
    int countFox;

    Rabbit* rabbits;
    int countRabbit;

    Grass* grasses;
    int countGrass;
public:
    Life() :foxes(nullptr), countFox(0), rabbits(nullptr), countRabbit(0), grasses(nullptr), countGrass(0) {}
    Life(int f, int r, int g) {
        if (f > 0)
        {
            if (f > 5)
            {
                countFox = 5;
                foxes = new Fox[countFox];
            }
            else {
                countFox = f;
                foxes = new Fox[countFox];
            }
        }
        else {
            countFox = 0;
            foxes = nullptr;
        }
        if (r > 0)
        {
            countRabbit = r;
            rabbits = new Rabbit[countRabbit];
        }
        else {
            countRabbit = 0;
            rabbits = nullptr;
        }
        if (g > 0)
        {
            countGrass = g;
            grasses = new Grass[countGrass];
        }
        else {
            countGrass = 0;
            grasses = nullptr;
        }
    }
    void ShowInfo() const {
        cout << "Foxes: " << countFox << " | Rabbits: " << countRabbit << " | Grass: " << countGrass << endl;
    }

    void Cycle() {
        for (int i = 0; i < countFox; i++)
        {
            foxes[i].AddAge();
        }
        for (int i = 0; i < countRabbit; i++)
        {
            rabbits[i].AddAge();
        }

        if (countGrass < countRabbit)
        {
            if (grasses != nullptr)
            {
                delete[] grasses;
                grasses = nullptr;
            }
            countGrass = 0;
        }
        else {
            countGrass -= countRabbit;
        }

        if (countRabbit > 0 and countRabbit < countFox)
        {
            countRabbit--;
            if (countRabbit == 0  and rabbits != nullptr)
            {
                delete[] rabbits;
                rabbits = nullptr;
            }
        }

        int Count = 0;
        for (int i = 0; i < countFox; i++)
        {
            if (foxes[i].GetAge() <= 5)
            {
                if (i != Count)
                    foxes[Count] = foxes[i];
                Count++;
            }
        }
        countFox = Count;

        if (countFox == 0 and foxes != nullptr)
        {
            delete[] foxes;
            foxes = nullptr;
        }

        Count = 0;
        for (int i = 0; i < countRabbit; i++)
        {
            if (rabbits[i].GetAge() <= 5)
            {
                if (i != Count)
                    rabbits[Count] = rabbits[i];
                Count++;
            }
        }
        countRabbit = Count;

        if (countRabbit == 0 and rabbits != nullptr)
        {
            delete[] rabbits;
            rabbits = nullptr;
        }

    }
    ~Life() {
        if (foxes != nullptr)
        {
            delete[] foxes;
        }
        if (rabbits != nullptr)
        {
            delete[] rabbits;
        }
        if (rabbits != nullptr)
        {
            delete[] grasses;
        }

    }
};
void RollCall(Animal& a)
{
    a.MakeSound();
}
int main()
{
    Fox singleFox(true, 2, "Red", "Forest", 5.5);
    Rabbit singleRabbit(12.5, 1, "Bunny", "Meadow", 2.1);
    Grass singleGrass("Green", true, "Clover", "Meadow", 0.3);

    singleFox.Show();
    singleRabbit.Show();
    singleGrass.Show();

    RollCall(singleFox);
    RollCall(singleRabbit);

    Life ecosystem(4, 3, 10);
    for (int i = 0; i < 7; i++)
    {
        ecosystem.Cycle();
        ecosystem.ShowInfo();
    }
    
}
