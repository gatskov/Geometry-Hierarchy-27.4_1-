#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#define STR(text) #text
#define PRINT_TASK(STR)                                                        \
  std::cout << STR(                                                            \
      27.4 Practical work. Task 1. Geometry Hierarchy\n\n)

class Figure
{
public:
	 double x=0;
	 double y=0;
	
	enum color { red, blue, green, orange, none };

	void Color(color color)const {
		switch (color) {
		case red:std::cout << "red.\n"; break;
		case blue:std::cout << "blue.\n"; break;
		case green:std::cout << "green.\n"; break;
		case orange:std::cout << "orange.\n"; break;
		case none:std::cout << "none.\n"; break;
		default: std::cout << ".\n"; break;
		}
	}
};
class Circle : public Figure
{
public:
	double radius;
	void calc_square() const
	{
		std::cout << "Area Circle= " << atan(1) * 4 * radius << ", Color tringle-> ";
		Color(Figure::color::red);
	}
	void calc_squareRectangleDescribingFigure()const
	{
		std::cout << "The area of the rectangle describing the figure= " << (2*radius)*(2*radius) << ", Shape Descriptor Rectangle Color-> ";
		Color(Figure::color::none);		 
	}
	Circle(){}
	Circle(double inradius) : radius(inradius)
	{
		assert(inradius >= 0);
	}
};
class Triangle : public Figure
{
public:
	double a;
	void calc_square() const
	{
		std::cout << "Area Tringle= " << a * a * std::sqrt(3) / 4 << ", Color tringle-> ";
		Color(Figure::color::blue);
	}
	void calc_squareRectangleDescribingFigure()const
	{
		std::cout << "The area of the rectangle describing the figure= " << a * (a / 2 * 1.73) << ", Shape Descriptor Rectangle Color-> ";
		Color(Figure::color::none);
	}
	 
	  Triangle(){}
	  Triangle(double ina) : a(ina)
	  {
		  assert(ina >= 0);
	  }
};
class Square : public Figure
{
public:
	double a;
	void calc_square() const
	{
		std::cout << "Area Square= " << a * a  << ", Color tringle-> ";
		Color(Figure::color::green);
	}
	void calc_squareRectangleDescribingFigure()const
	{
		std::cout << "The area of the rectangle describing the figure= " << a * a << ", Shape Descriptor Rectangle Color-> ";
		Color(Figure::color::none);
	}
	Square() {}
	Square(double ina) : a(ina)
	{
		assert(ina >= 0);
	}
};
class Rectangle : public Figure
{
public:
	double a;
	double b;
	void calc_square() const
	{
		std::cout << "Area Rectangle= " << a * b << ", Color tringle-> ";
		Color(Figure::color::orange);
	}
	void calc_squareRectangleDescribingFigure()const
	{
		std::cout << "The area of the rectangle describing the figure= " << a * b << ", Shape Descriptor Rectangle Color-> ";
		Color(Figure::color::none);
	}
	Rectangle() {}
	Rectangle(double ina, double inb) : a(ina), b(inb)
	{
		assert(ina >= 0);
		assert(inb >= 0);
	}
};

template <typename T> T& validateInput(T& val) {
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please re-enter the value:";
		std::cin >> val;
	}
	return val = std::abs(val);
}

Figure* fig = new Figure;
Circle * cir = new Circle;
Triangle* tri = new Triangle;
Square* squ = new Square;
Rectangle* rec = new Rectangle;

void figire_senter()
{
	std::cout << "Enter the shape center coordinates figure (x, y)\nX-> ";
	double x = 0.0, y = 0.0;
	std::cin >> x;
	fig->x = validateInput(x);
	std::cout << "Y-> ";
	std::cin >> y;
	fig->y = validateInput(y);
}
void  circle() 
{	
	double radius= 0.0;
	figire_senter();
	std::cout << "Enter radius-> ";
	std::cin >> radius;
	cir->radius= validateInput(radius);
	std::cout << "Figure-> Circle\nthe center of the figure with coordinates X= " << fig->x << ", Y= " << fig->y << std::endl;
	cir->calc_square();
	cir->calc_squareRectangleDescribingFigure();
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
void  triangle()
{
	double  a = 0.0;
	figire_senter();
	std::cout << "Enter the length of the side (a)-> ";
	std::cin >> a;
	tri->a = validateInput(a);
	std::cout << "Figure-> Trianle\nthe center of the figure with coordinates X= " << fig->x << ", Y= " << fig->y << std::endl;
	tri->calc_square();
	tri->calc_squareRectangleDescribingFigure();
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
void  square()
{
	double  a = 0.0;
	figire_senter();
	std::cout << "Enter the length of the side (a)-> ";
	std::cin >> a;
	squ->a = validateInput(a); 
	std::cout << "Figure-> Square\nthe center of the figure with coordinates X= " << fig->x << ", Y= " << fig->y << std::endl;
	squ->calc_square();
	squ->calc_squareRectangleDescribingFigure();
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
void  rectangle()
{
	double  a = 0.0, b = 0.0;
	figire_senter();
	std::cout << "Enter the length of the side (a b)\na-> ";
	std::cin >> a;
	rec->a = validateInput(a);
	std::cout << "b-> ";
	std::cin >> b;
	rec->b = validateInput(b);
	std::cout << "Figure-> Rectangle\nthe center of the figure with coordinates X= " << fig->x << ", Y= " << fig->y << std::endl;
	rec->calc_square();
	rec->calc_squareRectangleDescribingFigure();
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
std::string CheckingLineEntry(std::string t) {
	while (!std::all_of(t.begin(), t.end(),
		[](char c) { return std::isalpha(c); })) {
		std::cout << "Enter the string correctly -> " << std::endl;
		std::cin >> t;
	}
	return t;
}
void test()
{
	std::string menu{};
	std::cout
		<< "+--------------------------------------------------+\n"
		<< "| (circle)    - Testing the shape of the Circle    |\n"
		<< "| (triangle)  - Testing the shape of the Triangle  |\n"
		<< "| (square)    - Testing the shape of the Square    |\n"
		<< "| (rectangle) - Testing the shape of the Rectangle |\n"
		<< "| (exit)      - Exit the program                   |\n"
		<< "+--------------------------------------------------+"
		<< std::endl;	 
	while (true) {
		std::cout << "     Enter the command !!!\n";
		std::cout << "     ~~~~~~~~~~~~~~~~~~~~~\n";
		std::cin >> menu;
		if (CheckingLineEntry(menu) == "circle") {
			circle();
		}
		if (CheckingLineEntry(menu) == "triangle") {
			triangle();
		}
		if (CheckingLineEntry(menu) == "square") {
			square();
		}
		if (CheckingLineEntry(menu) == "rectangle") {
			rectangle();
		}
		if (CheckingLineEntry(menu) == "exit") {
			std::cout << "     +-----+\n";
			std::cout << "     | END |\n";
			std::cout << "     +-----+\n";
			return;
		}
	}
}

int main()
{
	PRINT_TASK(STR);
		test(); 
	delete cir;
	delete tri;
	delete squ;
	delete rec;
}

