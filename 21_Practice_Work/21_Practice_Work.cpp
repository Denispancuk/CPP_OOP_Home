#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct Time {
    short s, m, h;
    Time():s(0),m(0),h(0){}
    Time(short s, short m,short h){
        if (s >= 0 and s < 60)
        {
            this->s = s;
        }
        else {
            this->s = 0;
        }
        if (m >= 0 and m < 60)
        {
            this->m = m;
        }
        else {
            this->m = 0;
        }
        if (h >= 0 and h <= 23)
        {
            this->h = h;
        }
        else {
            this->h = 0;
        }
    }
    void ShowTime() {
        cout  << s << "/" << m << '/' << h << endl;
    }
    void Change(int s, int m,int h) {
        if (s >= 0 and s < 60)
        {
            this->s = s;
        }
        if (m >= 0 and m < 60)
        {
            this->m = m;
        }
        if (h >= 0 and h <= 23)
        {
            this->h = h;
        }
    }
    long long TimeToSeconds() {
        return (s)+(m * 60) + (h * 3600);
    }
};
class Train {
    int number;
    Time Departure;
    string Destination;
public:
    Train():number(0),Departure(),Destination("None") {}
    Train(int n,short s,short m,short h,string d):number(n),Departure(s,m,h), Destination(d) {}
    Train(int n,Time t,string d):number(n),Departure(t), Destination(d) {}
    int GetNumber() {
        return number;
    }
    void ShowTrain() {
        cout << "Number: " << number << endl;
        cout << "Departure: ";
        Departure.ShowTime();
        cout << "Destination: " << Destination << endl;
    }
    void ChangeTime(short s,short m,short h) {
        Departure.Change(s, m, h);
    }
    string GetDestination() {
        return Destination;
    }
    long long GetTime() {
        return Departure.TimeToSeconds();
    }
    friend ostream& operator<<(ostream& in, const Train& train) {
        in << train.number << " " << train.Departure.s << " " << train.Departure.m << " " << train.Departure.h << " " << train.Destination;
        return in;
    }

    friend istream& operator>>(istream& in, Train& train) {
        in >> train.number >> train.Departure.s >> train.Departure.m >> train.Departure.h >> train.Destination;
        return in;
    }
    

};
class RailWay {
    vector<Train> trains;
public:
    void AddTrain(Train t) {
        trains.push_back(t);
    }
    void ShowAllTrain() {
        for (int i = 0; i < trains.size(); i++)
        {
            trains[i].ShowTrain();
        }
    }
    void ShowOneTrain(int number) {
        for (int i = 0; i < trains.size(); i++)
        {
            if (number == trains[i].GetNumber())
            {
                trains[i].ShowTrain();
                break;
            }
            
        }
    }
    void ChangeTimeTrain(int number, int s, int m,int h) {
        for (int i = 0; i < trains.size(); i++)
        {
            if (number == trains[i].GetNumber())
            {
                trains[i].ChangeTime(s,m,h);
                break;
            }

        }
    }
    void ShowTrainByDestination(string Destination) {
        for (int i = 0; i < trains.size(); i++)
        {
            if (Destination == trains[i].GetDestination())
            {
                trains[i].ShowTrain();
            }

        }
    }
    void BubbleSortTrains() {
        Train temp;
        for (int i = 0; i < trains.size(); i++)
        {
            for (int j = trains.size() - 1; j > i; j--)
            {
                if (trains[j - 1].GetTime() > trains[j].GetTime()) {
                    temp = trains[j - 1];
                    trains[j - 1] = trains[j];
                    trains[j] = temp;
                }
            }
        }
    }

};
int main()
{
    RailWay railway;

    railway.AddTrain(Train(101, 30, 15, 8, "Kyiv"));
    railway.AddTrain(Train(102, 0, 45, 12, "Lviv"));
    railway.AddTrain(Train(103, 15, 20, 10, "Odesa"));
    railway.AddTrain(Train(104, 0, 10, 6, "Kyiv"));

    railway.ShowAllTrain();

    railway.ShowOneTrain(102);

    railway.ChangeTimeTrain(101, 0, 30, 9);

    railway.BubbleSortTrains();

    railway.ShowAllTrain();

    railway.ShowTrainByDestination("Kyiv");

    ofstream out("trains.txt");

    for (int i = 0; i < 4; i++)
    {
        out << Train(100 + i, 0, 30, 8 + i, "Kyiv") << endl;
    }

    out.close();

    ifstream in("trains.txt");
    Train t;

    while (in >> t)
    {
        railway.AddTrain(t);
    }

    in.close();

    railway.ShowAllTrain();

}