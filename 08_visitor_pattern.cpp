#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Circle;
class Rectangle;
class Triangle;

// Visitor interface
class ShapeVisitor {
public:
    virtual void visit(const Circle& circle) = 0;
    virtual void visit(const Rectangle& rectangle) = 0;

    // New element class requires adding a new visit method
    virtual void visit(const Triangle& triangle) = 0;

    virtual ~ShapeVisitor() {}
};

// Base element
class Shape {
public:
    virtual void accept(ShapeVisitor& visitor) const = 0;
    virtual ~Shape() {}
};

// Concrete element 1
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }

    void accept(ShapeVisitor& visitor) const override {
        visitor.visit(*this);
    }
};

// Concrete element 2
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    void accept(ShapeVisitor& visitor) const override {
        visitor.visit(*this);
    }
};

// New concrete element
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    double getBase() const {
        return base;
    }

    double getHeight() const {
        return height;
    }

    void accept(ShapeVisitor& visitor) const override {
        visitor.visit(*this);
    }
};

// Concrete visitor 1
class AreaVisitor : public ShapeVisitor {
public:
    void visit(const Circle& circle) override {
        double area = 3.14 * circle.getRadius() * circle.getRadius();
        cout << "Circle area: " << area << endl;
    }

    void visit(const Rectangle& rectangle) override {
        double area = rectangle.getWidth() * rectangle.getHeight();
        cout << "Rectangle area: " << area << endl;
    }

    // This method had to be added after Triangle appeared
    void visit(const Triangle& triangle) override {
        double area = triangle.getBase() * triangle.getHeight() / 2;
        cout << "Triangle area: " << area << endl;
    }
};

// Concrete visitor 2
class InfoVisitor : public ShapeVisitor {
public:
    void visit(const Circle& circle) override {
        cout << "Info: Circle with radius " << circle.getRadius() << endl;
    }

    void visit(const Rectangle& rectangle) override {
        cout << "Info: Rectangle "
             << rectangle.getWidth() << " x " << rectangle.getHeight() << endl;
    }

    // This method also had to be added after Triangle appeared
    void visit(const Triangle& triangle) override {
        cout << "Info: Triangle with base "
             << triangle.getBase() << " and height " << triangle.getHeight() << endl;
    }
};

int main() {
    cout << "Task 8: Visitor pattern and new element class" << endl;
    cout << "------------------------------------------------" << endl;

    vector<unique_ptr<Shape>> shapes;

    shapes.push_back(unique_ptr<Shape>(new Circle(5)));
    shapes.push_back(unique_ptr<Shape>(new Rectangle(4, 6)));

    cout << "Initially system had Circle and Rectangle." << endl;
    cout << "Now new concrete element Triangle was added." << endl;
    shapes.push_back(unique_ptr<Shape>(new Triangle(8, 3)));

    cout << endl;

    AreaVisitor areaVisitor;
    InfoVisitor infoVisitor;

    cout << "1. AreaVisitor result:" << endl;
    for (const auto& shape : shapes) {
        shape->accept(areaVisitor);
    }

    cout << endl;

    cout << "2. InfoVisitor result:" << endl;
    for (const auto& shape : shapes) {
        shape->accept(infoVisitor);
    }

    cout << "------------------------------------------------" << endl;
    cout << "Conclusion: adding Triangle required changes in Visitor interface" << endl;
    cout << "and in all concrete visitors, such as AreaVisitor and InfoVisitor." << endl;

    return 0;
}