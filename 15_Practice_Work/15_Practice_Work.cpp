#include <iostream>
using namespace std;

class Shape {
protected:
	string name;
public:
	Shape() :name("No name") {}
	Shape(string name) :name(name) {}
	virtual void Show() const = 0;
	virtual void GetArea() const = 0;
};

class Rectangle : public Shape {
	int width;
	int lenght;
public:
	Rectangle() :width(0), lenght(0), Shape("Rectangle") {}
	Rectangle(int width, int lenght) :width(width), lenght(lenght), Shape("Rectangle") {}
	void GetArea() const override {
		cout << "Area: " << width * lenght << endl;
	}
	void Show() const override {
		cout << "Name: " << name << endl;
		cout << "Width: " << width << endl;
		cout << "lenght: " << lenght << endl;
		GetArea();

	}
};
class Triangle : public Shape {
	int FirstSide;
	int SecondSide;
	int height;
public:
	Triangle() :FirstSide(0), SecondSide(0), height(0), Shape("Triangle") {}
	Triangle(int FirstSide, int SecondSide, int height) :FirstSide(FirstSide), SecondSide(SecondSide), height(height), Shape("Triangle") {}
	void GetArea() const override {
		cout << "Area: " << 0.5 * FirstSide * height << endl;
	}
	void Show() const override {
		cout << "Name: " << name << endl;
		cout << "FirstSide: " << FirstSide << endl;
		cout << "SecondSide: " << SecondSide << endl;
		cout << "Height: " << height << endl;
		GetArea();
	}
};
class RightTriangle : public Shape {
	int FirstSide;
	int SecondSide;
public:
	RightTriangle() :FirstSide(0), SecondSide(0), Shape("Right Triangle") {}
	RightTriangle(int FirstSide, int SecondSide) :FirstSide(FirstSide), SecondSide(SecondSide), Shape("Right Triangle") {}
	void GetArea() const override {
		cout << "Area: " << 0.5 * FirstSide * SecondSide << endl;
	}
	void Show() const override {
		cout << "Name: " << name << endl;
		cout << "FirstSide: " << FirstSide << endl;
		cout << "SecondSide: " << SecondSide << endl;
		GetArea();
	}
};
class Circle : public Shape {
	int Radius;
	int Diameter;
	const float PI = 3.14159;
public:
	Circle() :Radius(0), Diameter(0),Shape("Circle") {}
	Circle(int Radius) :Radius(Radius), Diameter(Radius * 2),Shape("Circle") {}
	Circle(int Radius, int Diameter) :Radius(Radius), Diameter(Diameter),Shape("Circle") {}
	void GetArea() const override {
		cout << "Area: " << PI * (Radius * Radius) << endl;
	}
	void Show() const override {
		cout << "Name: " << name << endl;
		cout << "Radius: " << Radius << endl;
		cout << "Diameter: " << Diameter << endl;
		GetArea();
	}
};
class Trapeze : public Shape {
	int FirstBasis;
	int SecondBasis;
	int Height;
public:
	Trapeze():FirstBasis(0),SecondBasis(0),Height(0),Shape("Trapeze") {}
	Trapeze(int Basis, int Height):FirstBasis(Basis),SecondBasis(Basis),Height(Height), Shape("Trapeze") {}
	Trapeze(int FirstBasis,int SecondBasis, int Height):FirstBasis(FirstBasis),SecondBasis(SecondBasis),Height(Height), Shape("Trapeze") {}
	void GetArea() const override {
		cout << "Area: " << 0.5 * (FirstBasis + SecondBasis) * Height << endl;
	}
	void Show() const override {
		cout << "Name: " << name << endl;
		cout << "First Basis: " << FirstBasis << endl;
		cout << "Second Basis: " << SecondBasis << endl;
		cout << "Height: " << Height << endl;
		GetArea();
	}
};
void TestShape(Shape& shape)
{
	shape.Show();

}
int main()
{
	Rectangle rectangle(10, 5);
	Triangle triangle(10, 8, 6);
	RightTriangle rightTriangle(3, 4);
	Circle circle(5);
	Trapeze trapeze(6, 10, 4);

	TestShape(rectangle);
	TestShape(triangle);
	TestShape(rightTriangle);
	TestShape(circle);
	TestShape(trapeze);

}