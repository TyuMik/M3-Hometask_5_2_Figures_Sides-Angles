#include <iostream>
#include <string>

class Figure {
protected:
    std::string name;
public:
    Figure() : name("Фигура") { }
    std::string get_name() {
        return name;
    }
    virtual void print_info() {
        std::cout << get_name() << ": " << std::endl;
    }
};

class Triangle : public Figure {
protected:
    int a, b, c, A, B, C;
public:
    Triangle(int a, int b, int c, int A, int B, int C) {
        name = "Треугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }

    void print_info() {
        Figure::print_info();
        std::cout << "Стороны: " << std::endl;
        std::cout << "a=" << get_a() << "; " << "b=" << get_b() << "; " << "c=" << get_c() << std::endl;
        std::cout << "Углы: " << std::endl;
        std::cout << "A=" << get_A() << "; " << "B=" << get_B() << "; " << "C=" << get_C() << std::endl;
        std::cout << std::endl;
    }
};

class Triangle_p : public Triangle {
public:
    Triangle_p(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }
};

class Triangle_rb : public Triangle {
public:
    Triangle_rb(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
        name = "Равнобедренный треугольник";
    }
};

class Triangle_rs : public Triangle {
public:
    Triangle_rs(int a) : Triangle(a, a, a, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }
};

class Quadrangle : public Figure {
protected:
    int a, b, c, d, A, B, C, D;
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
        name = "Четырёхугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }

    void print_info() {
        Figure::print_info(); 
        std::cout << "Стороны: " << std::endl;
        std::cout << "a=" << get_a() << "; " << "b=" << get_b() << "; " << "c=" << get_c() << "; " << "d=" << get_d() << std::endl;
        std::cout << "Углы: " << std::endl;
        std::cout << "A=" << get_A() << "; " << "B=" << get_B() << "; " << "C=" << get_C() << "; " << "D=" << get_D() << std::endl;
        std::cout << std::endl;
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }
};

class Romb : public Parallelogram {
public:
    Romb(int a, int A, int B) : Parallelogram(a, a, A, B) {
        name = "Ромб";
    }
};

class Parallel_p : public Parallelogram {
public:
    Parallel_p(int a, int b) : Parallelogram(a, b, 90, 90) {
        name = "Прямоугольник";
    }
};

class Square : public Parallel_p {
public:
   Square(int a) : Parallel_p(a, a) {
        name = "Квадрат";
    }
};

void printInfo(Figure* f) {
    f->print_info();
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Triangle t(10, 20, 30, 50, 60, 70);
    Triangle_p tp(10, 20, 30, 50, 60);
    Triangle_rb trb(10, 20, 50, 60);
    Triangle_rs trs(30);
    
    printInfo(&t);
    printInfo(&tp);
    printInfo(&trb);
    printInfo(&trs);

    Quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
    Parallelogram p(20, 30, 80, 100);
    Parallel_p pp(10, 20);
    Romb r(30, 30, 40);
    Square s(20);

    printInfo(&q);
    printInfo(&pp);
    printInfo(&s);
    printInfo(&p);
    printInfo(&r);

    return 0;
}