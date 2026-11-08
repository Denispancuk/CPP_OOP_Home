#include <iostream>
using namespace std;

template<typename T>
class List {
    struct Node {
        T value;
        Node* next;
        Node(T value, Node* next) :value(value), next(next) {}
        Node(T value) :value(value), next(nullptr) {}
    };
    Node* head;
public:
    List()
    {
        head = nullptr;
    }
    void AddToHead(T value) {
        Node* newNode = new Node(value, head);
        /*newNode->value = value;
        newNode->next = head;*/
        head = newNode;
    }
    void Print() {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
    void AddToTail(T value) {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }

    }
    void DeleteFromTail() {
        if (head == nullptr)return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }
    void DeleteHead() {
        Node* current = head;
        if (head == nullptr)return;
        else {
            head = current->next;
            delete current;
        }
    }
    ~List() {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
};


class Point {
    int X;
    int Y;
public:
    Point() :X(0), Y(0) {};
    Point(int value)
    {
        X = Y = value;
    }
    Point(int X, int Y)
    {
        this->X = X;
        this->Y = Y;
    }
    friend ostream& operator << (ostream& out, const Point& point)
    {
        out << "X [" << point.X << "]" << "  Y[" << point.Y << "]";
        return out;
    }
};


class Vector {
    int size;
    List<Point> points;
public:
    Vector()
    {
        size = 0;
    }
    Vector(Point el)
    {
        size = 1;
        points.AddToHead(el);

    }
    void Show() {
        points.Print();

    }
    void DeleteFirst() {
        points.DeleteHead();
    }
    void DeleteLast() {
        points.DeleteFromTail();
    }
    void AddFirst(Point el) {
        points.AddToHead(el);
    }
    void AddLast(Point el) {
        points.AddToTail(el);
    }
};


int main()
{
    Vector v1;

    Point p1(2, 3);
    Point p2(5, 5);
    Point p3(10, 15);
    Point p4(20, 25);

    Vector v2(p1);

    v2.Show();

    v2.AddFirst(p2);
    v2.Show();

    v2.AddLast(p3);
    v2.Show();

    v2.AddLast(p4);
    v2.Show();

    v2.DeleteFirst();
    v2.Show();

    v2.DeleteLast();
    v2.Show();

    v2.DeleteLast();
    v2.Show();

    v2.DeleteLast();
    v2.Show();

    v2.DeleteFirst();
    v2.Show();

    v1.AddFirst(p1);
    v1.AddLast(p2);
    v1.Show();

    v1.DeleteFirst();
    v1.DeleteLast();
    v1.Show();
}