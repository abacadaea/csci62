#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Shape{//Abstract classes:  Have virtual method(s) and can't be instantiated.
private:
	std::size_t sides_;
public:
	Shape(){}
	Shape(std::size_t s){sides_=s;}
	std::size_t sides(){return sides_;}
	virtual double area() {};//Pure virtual method; denoted by = 0
	//virtual double area() = 0;//Pure virtual method; denoted by = 0
	virtual double perimeter() {};
};

class Rectangle: public Shape{
private:
	double w_, h_;
public:
	Rectangle():Shape(4){w_=h_=0;}
	Rectangle(double width, double height):Shape(4){w_=width; h_=height;}
	double w(){return w_;}
	double h(){return h_;}
	double area (){return w_*h_;}
	double perimeter() {
		cout<<"Rectangle"<<endl;
		return 2*w_+2*h_;}
};

class Square: public Rectangle{
public:
	Square():Rectangle(){}
	Square(double side):Rectangle(side, side){}
	//could hide w and h with private methods.
	double perimeter() {
		cout<<"Square"<<endl;
		return Rectangle::perimeter();}
};

class Triangle: public Shape{
private:
	double base_, height_, side1_, side2_;
public:
	Triangle():Shape(3){base_=height_=side1_=side2_=0;}
	Triangle(double b, double h, double s1, double s2):Shape(3){
		base_=b; height_=h;
		side1_=s1; side2_=s2;
	}
	double base(){return base_;}
	double height(){return height_;}
	double side1(){return side1_;}
	double side2(){return side2_;}
	double area(){ return (height_*base_)/2;}
	double perimeter(){
		cout<<"Triangle"<<endl;
		return base_+side1_+side2_;}
};

class RightTriangle: public Triangle{
public:
	RightTriangle():Triangle(){}
	RightTriangle(double a, double b): Triangle(a, b, b, sqrt(a*a+b*b)){}
	double hypotenuse(){return Triangle::side2();}
	double a(){return Triangle::base();}
	double b(){return Triangle::side1();}
	double perimeter(){
		cout<<"RightTriangle"<<endl;
		return Triangle::perimeter();
	}
};
int main(){
	vector<Shape*> v;
  Square* s = new Square(10);
  v.push_back(s);
  v.push_back(new Rectangle(3, 9));
  v.push_back(new RightTriangle(3, 4)); // which line of code figures out the third side length?

	for(auto e:v){
		cout<<e->perimeter()<<endl;;
	}

  Rectangle* r = new Square (10);
  cout << r->perimeter() << endl;
}
