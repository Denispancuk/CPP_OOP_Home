#include <iostream>
#include <fstream>
#include <windows.h>  
using namespace std;
void gotoxy(int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
struct Point {
	int x;
	int y;
	Point():x(0),y(0){

	}
	Point(int point):x(point),y(point){

	}
	Point(int x,int y):x(x),y(y){

	}
	void ChangeCoords(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void Show() const  {
		cout << "X: " << x << " | Y: " << y << endl;
	}
};
class Shape {
protected:
	string type;
public:
	Shape() :type("None") {}
	Shape(string type) :type(type) {}
	virtual void Print() const = 0;
	virtual void Save(const string filename) const = 0;
	virtual ~Shape() {};

};
class Line : public Shape {
	Point start;
	Point end;
public:
	Line() :start(),end(),Shape("line") {}
	Line(int point) :start(point),end(point), Shape("line") {}
	Line(int start, int end) :start(start,end), end(start, end), Shape("line") {}
	Line(int start, int end,int start1, int end1) :start(start,end),end(start1,end1), Shape("line") {}
	void PrintStart() const {
		cout << "Start:\n";
		start.Show();
	}
	void PrintEnd() const {
		cout << "End:\n";
		end.Show();
	}
	void SetStart(int x, int y) {
		start.ChangeCoords(x, y);
	}
	void SetEnd(int x, int y) {
		end.ChangeCoords(x, y);
	}
	Point GetStart() {
		return start;
	}
	Point GetEnd() {
		return end;
	}
	void Save(const string filename) const override {
		ofstream in(filename, ios_base::app);
		in << type << " " << start.x << " " << start.y << " " << end.x << " " << end.y << endl;
	}
	void Print()const override {
		cout << "Start:\n"; 
		start.Show();
		cout << "End:\n"; 
		end.Show();
		cout << endl;
	}
	
};

class Rectanglee :public Shape {
	Point CoordTopLeftCorner;
	int width;
	int height;
public:
	Rectanglee() :CoordTopLeftCorner(0), width(0), height(0),Shape("Rectangle") {}
	Rectanglee(int dimension) :CoordTopLeftCorner(0), width(dimension), height(dimension), Shape("Rectangle") {}
	Rectanglee(int width, int height) :CoordTopLeftCorner(0), width(width), height(height), Shape("Rectangle") {}
	Rectanglee(Point CoordTopLeftCorner, int width, int height) :CoordTopLeftCorner(CoordTopLeftCorner), width(width), height(height), Shape("Rectangle") {}
	Point GetCoordTopLeftCorner()const {
		return CoordTopLeftCorner;
	}
	int GetWidth() const{
		return width;
	}
	int GetHeight()const{
		return height;
	}
	void SetCoordTopLeftCorner(Point CoordTopLeftCorner){
		this->CoordTopLeftCorner = CoordTopLeftCorner;
	}
	void SetWidth(int width){
		this->width = width;
	}
	void SetHeight(int height){
		this->height = height;
	}
	void Print() const override {
		cout << "Coord Top Left Corner: ";
		CoordTopLeftCorner.Show();
		cout << "Width: " << width << endl;
		cout << "Height: " << height << endl;
	}
	void Save(const string filename) const override {
		ofstream in(filename, ios_base::app);
		in << type << " " << CoordTopLeftCorner.x << " " << CoordTopLeftCorner.y << " " << width << " " << height << endl;
	}
};
class PolyLine : public Shape {
	Point* points;
	int count;
public:
	PolyLine():count(0),points(nullptr),Shape("PolyLine") {}
	PolyLine(int count):Shape("PolyLine") {
		if (count > 0)
		{
			this->count = count;
			points = new Point[count];
		}
		else {
			this->count = 0;
			points = nullptr;
		}
	}
	PolyLine(Point* pts,int count):Shape("PolyLine")
	{
		this->count = count;
		points = new Point[count];
		for (int i = 0; i < count; i++)
		{
			points[i] = pts[i];
		}
	}
	void Print() const override {
		cout << "Count points: " << count << endl;
		cout << "Points: \n";
		for (int i = 0; i < count; i++)
		{
			points[i].Show();
		}
	}
	void Save(const string filename) const override {
		ofstream in(filename, ios_base::app);
		in << type << " " << count;
		for (int i = 0; i < count; i++)
			in << " " << points[i].x << " " << points[i].y;
		in << endl;
	}
	~PolyLine()
	{
		if (points != nullptr)
		{
			delete[]points;
		}
	}
};
int main()
{
	Point p1;
	Point p2(5);
	Point p3(10, 20);

	p1.ChangeCoords(15, 25);
	p1.Show();

	Line l1;
	Line l2(5);
	Line l3(10, 20);
	Line l4(10, 20, 30, 40);

	l4.SetStart(1, 2);
	l4.SetEnd(3, 4);

	Point start = l4.GetStart();
	Point end = l4.GetEnd();

	l4.PrintStart();
	l4.PrintEnd();
	l4.Print();
	l4.Save("shapes.txt");

	Rectanglee r1;
	Rectanglee r2(50);
	Rectanglee r3(100, 200);
	Rectanglee r4(Point(10, 20), 100, 200);

	r4.SetCoordTopLeftCorner(30);
	r4.SetWidth(150);
	r4.SetHeight(250);

	Point corner = r4.GetCoordTopLeftCorner();
	int width = r4.GetWidth();
	int height = r4.GetHeight();

	r4.Print();
	r4.Save("shapes.txt");

	Point pts[3] = {
		Point(10, 20),
		Point(30, 40),
		Point(50, 60)
	};

	PolyLine pl1;
	PolyLine pl2(3);
	PolyLine pl3(pts, 3);

	pl3.Print();
	pl3.Save("shapes.txt");

	Shape* shapes[3];

	shapes[0] = new Line(10, 20, 30, 40);
	shapes[1] = new Rectanglee(Point(5, 5), 100, 200);
	shapes[2] = new PolyLine(pts, 3);

	for (int i = 0; i < 3; i++)
	{
		shapes[i]->Print();
		shapes[i]->Save("shapes.txt");
		delete shapes[i];
	}

}