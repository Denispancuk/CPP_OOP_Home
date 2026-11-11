#include <iostream>
using namespace std;
template<typename T>
class QueuePrinter
{
public:

    struct Document {
        string PositionPeople;
        int priority;
        T NameFile;
        Document() :PositionPeople("user"), priority(1), NameFile("") {}
        Document(string PositionPeople, int priority, T NameFile) :PositionPeople(PositionPeople), priority(priority), NameFile(NameFile) {}
        
        Document Init() {
            cout << "Enter position people: "; cin >> PositionPeople;
            if (PositionPeople == "user")
            {
                priority = 1;
            }
            else if (PositionPeople == "administrator")
            {
                priority = 2;
            }
            else if (PositionPeople == "manager")
            {
                priority = 3;
            }
            else if (PositionPeople == "director")
            {
                priority = 4;
            }
            else {
                priority = 1;
                PositionPeople = "user";
            }
            cout << "Enter name file: "; cin >> NameFile;
            return *this;
        }

        void Druk() {
            cout << NameFile << " : " << priority << " " << endl;
        }

    };
    Document CreateDocument() {
        Document element;
        return element.Init();
    }

private:
    Document* elements;
    int count;
public:

    QueuePrinter() :elements(nullptr), count(0) {}
    void Enqueue(Document el) {
        int index = 0;
        while (index < count && elements[index].priority >= el.priority)
        {
            index++;
        }
        Document* temp = new Document[count + 1];
        for (int i = 0; i < index; i++)
        {
            temp[i] = elements[i];
        }temp[index] = el;
        for (int i = index; i < count; i++)
        {
            temp[i + 1] = elements[i];
        }
        if (elements != nullptr)
        {
            delete[]elements;
        }
        elements = temp;
        count++;
    }
    bool IsEmpty() {
        return count == 0;
    }
    void Dequeque() {
        if (!IsEmpty())
        {
            for (int i = 0; i < count - 1; i++)
            {
                elements[i] = elements[i + 1];
            }
            count--;
        }

    }
    
    void Print() {
        cout << "---------------- Queue -------------" << endl;
        for (int i = 0; i < count; i++)
        {
            elements[i].Druk();
        }
    }
    void PrintDocument() {
        if (!IsEmpty())
        {
            cout << "Printing document: ";
            elements[0].Druk();
            Dequeque();
        }
        else {
            cout << "Queue is empty" << endl;
        }
    }
    ~QueuePrinter()
    {
        if (elements != nullptr)
        {
            delete[]elements;
        }
    }
};
template<typename T>
void Display(QueuePrinter<T>& Anyone) {
    while (true)
    {
        int choice;
        cout << "1.Add document" << endl;
        cout << "2.Delete document" << endl;
        cout << "3.Print all document" << endl;
        cout << "4.Print document" << endl;
        cout << "0.Exit" << endl;
        cout << "Enter yout choice[1-4]: "; cin >> choice;
        if (choice == 1)
        {
            
            Anyone.Enqueue(Anyone.CreateDocument());
        }
        else if (choice == 2)
        {
            Anyone.Dequeque();
        }
        else if (choice == 3) {
            Anyone.Print();
        }
        else if (choice == 4) {
            Anyone.PrintDocument();
        }
        else if (choice == 0)
        {
            break;
        }

    }
}
int main()
{
    QueuePrinter<string> AnyOne;

    AnyOne.IsEmpty();

    AnyOne.Enqueue(QueuePrinter<string>::Document("user", 1, "file1.txt"));
    AnyOne.Enqueue(QueuePrinter<string>::Document("director", 4, "file2.txt"));
    AnyOne.Enqueue(QueuePrinter<string>::Document("manager", 3, "file3.txt"));
    AnyOne.Enqueue(QueuePrinter<string>::Document("administrator", 2, "file4.txt"));

    AnyOne.IsEmpty();
    AnyOne.Print();

    AnyOne.PrintDocument();
    AnyOne.Print();

    AnyOne.Dequeque();
    AnyOne.Print();

    AnyOne.PrintDocument();
    AnyOne.PrintDocument();
    AnyOne.PrintDocument();
    AnyOne.PrintDocument();

    AnyOne.IsEmpty();

    Display(AnyOne);
}