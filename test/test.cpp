#include <iostream>
using namespace std;

struct Point { int x, y; };

class Shape {
protected:
	const char* type;
public:
	Shape(const char* type) : type(type) {}
	virtual void Print() const = 0;
	virtual ~Shape() {}
};

class Line : public Shape {
	Point start, end;
public:
	Line(Point start, Point end) : Shape("Line"), start(start), end(end) {}
	void Print() const override {
		cout << type << ": (" << start.x << "," << start.y << ") -> ("
			<< end.x << "," << end.y << ")\n";
	}
};

class Rectangle : public Shape {
	Point topLeft;
	int width, height;
public:
	Rectangle(Point topLeft, int width, int height)
		: Shape("Rectangle"), topLeft(topLeft), width(width), height(height) {
	}
	void Print() const override {
		cout << type << ": лівий верхній кут (" << topLeft.x << "," << topLeft.y
			<< "), ширина " << width << ", висота " << height << "\n";
	}
};

class Polyline : public Shape {
	Point* points;
	int count;
public:
	Polyline(const Point* pts, int count) : Shape("Polyline"), count(count) {
		points = new Point[count];
		for (int i = 0; i < count; i++) points[i] = pts[i];
	}
	~Polyline() { delete[] points; }
	void Print() const override {
		cout << type << ":";
		for (int i = 0; i < count; i++)
			cout << " (" << points[i].x << "," << points[i].y << ")";
		cout << "\n";
	}
};

int main()
{
	Point pts[] = { {1, 1}, {4, 3}, {7, 2} };

	Line line({ 5, 1 }, { 10, 6 });
	Rectangle rect({ 10, 1 }, 20, 5);
	Polyline poly(pts, 3);

	line.Print();
	rect.Print();
	poly.Print();
}