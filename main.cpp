#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

class Shape2D{
    protected:
        std::string name; 

    public:
        virtual double getArea() = 0;
        virtual double getPerimeter() = 0;

        void printName(){
           std::cout << name << std::endl; 
        } 
};

class Circle: public Shape2D{
   private:
        double radius; 

    public:   
        Circle(double radius){
            this->radius = radius;
            name = "Circle"; 
        }

        double getArea() override{
            return M_PI * pow(radius, 2); 
        }
    
        double getPerimeter() override{
            return 2 * radius * M_PI;
        }
};

class Square: public Shape2D{
   private:
        double side; 
    
   public:
        Square(double side){
            this->side = side;
            name = "Square"; 
        }

        double getArea() override{
        return side * side; 
        }
        
        double getPerimeter() override{
        return 4 * side; 
        }
};

class Rectangle: public Shape2D{
   private:
        double base; 
        double height; 
    
   public:
        Rectangle(double base, double height){
            this->base = base;
            this->height = height;
            name = "Rectangle"; 
        }

        double getArea() override{
            return base * height; 
        }
        
        double getPerimeter() override{
            return (2 * base) + (2 * height);
        }
};

class Triangle: public Shape2D{
   private:
        double base; 
        double height; 
    
   public:
        Triangle(double base, double height){
            this->base = base;
            this->height = height;
            name = "Triangle";
        }

        double getArea() override{
            return (base*height) / 2; 
        }
        
        double getPerimeter() override{
            double side = sqrt(pow(base / 2, 2) + pow(height, 2)); 

            return base + (2 * side);
        }
};

class Shape3D : public Shape2D{
    public:
        virtual double getVolume() = 0;

};

class Sphere: public Shape3D{
    private:
        double radius;
    
    public:
        Sphere(double radius){
            this->radius = radius;
            name = "Sphere";
        }

        double getArea() override{
            return 4 * M_PI * pow(radius, 2); 
        }
        
        double getPerimeter() override{
           throw std::runtime_error("Sphere has no perimeter"); 
        }

        double getVolume() override{
            return (4.0 / 3.0) * M_PI * pow(radius, 3);    
       } 
            
};

class Cube: public Shape3D{
    private:
        double side;
    
    public:
        Cube(double side){
            this->side = side;
            name = "Cube";
        }

        double getArea() override{
            return 6 * pow(side, 2); 
        }
        
        double getPerimeter() override{
           return 12 * side; 
        }

       double getVolume() override{
           return pow(side, 3); 
       } 
};

class Prism: public Shape3D{
    private:
        double width;
        double height;
        double depth;
    
    public:
        Prism(double width, double height, double depth){
            this->width = width;
            this->height = height;
            this->depth = depth;
            name = "Prism";
        }

        double getArea() override{
            return (2 * width * height) + (2 * height * depth) + (2 * height * depth);
        }
        
        double getPerimeter() override{
           return (4 * width) + (4 * height) + (4 * depth);
        }

       double getVolume() override{
           return width * height * depth; 
       } 
};

class Cylinder: public Shape3D{
    private:
        double radius;
        double height;
    
    public:
        Cylinder(double radius, double height){
            this->radius = radius;
            this->height = height;
            name = "Cylinder";
        }

        double getArea() override{
           return (2 * M_PI * pow(radius, 2)) + (2 * M_PI * radius * height); 
        }
        
        double getPerimeter() override{
           return 4 * M_PI * radius; 
        }

       double getVolume() override{
            return M_PI * pow(radius, 2) * height; 
       } 
    
};

void printPerimeter(Shape2D* shape){
   std::cout << shape->getPerimeter() << std::endl; 
}

void printArea(Shape2D* shape){
   std::cout << shape->getPerimeter() << std::endl; 
}


int main(){
    Circle circle(1); 
    Square square(5);
    Triangle triangle(2, 3);
    Rectangle rectangle(2,3);

    Sphere sphere(10); 
    Cube cube(5);
    Prism prism(1,2,3);
    Cylinder cylinder(5, 2);
    
    std::cout << square.getArea() << std::endl;
    std::cout << square.getPerimeter() << std::endl;
    std::cout << sphere.getArea() << std::endl;
    std::cout << "*************" << std::endl;
    // std::cout << sphere.getPerimeter() << std::endl;
    std::cout << sphere.getVolume() << std::endl;
    circle.printName();
    sphere.printName(); 

    return 0;
}
