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
};

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;
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

    void print_info(Triangle* tgl) {
        std::cout << tgl->get_name() << ": " << std::endl;
        std::cout << "Стороны: " << std::endl;
        std::cout << "a=" << tgl->get_a() << "; " << "b=" << tgl->get_b() << "; " << "c=" << tgl->get_c() << std::endl;
        std::cout << "Углы: " << std::endl;
        std::cout << "A=" << tgl->get_A() << "; " << "B=" << tgl->get_B() << "; " << "C=" << tgl->get_C() << std::endl;
        std::cout << std::endl;
    }
};

class Triangle_p : public Triangle {
public:
    Triangle_p(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, C = 90) {
        name = "Прямоугольный треугольник";
    }
};

class Triangle_rb : public Triangle {
public:
    Triangle_rb(int a, int b, int A, int B) : Triangle(a, b, c = a, A, B, C = A) {
        name = "Равнобедренный треугольник";
    }
};

class Triangle_rs : public Triangle {
public:
    Triangle_rs(int a) : Triangle(a, b = a, c = a, A = 60, B = 60, C = 60) {
        name = "Равносторонний треугольник";
    }
};

class Quadrangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;
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

    void print_info(Quadrangle* qgl) {
        std::cout << qgl->get_name() << ": " << std::endl;
        std::cout << "Стороны: " << std::endl;
        std::cout << "a=" << qgl->get_a() << "; " << "b=" << qgl->get_b() << "; " << "c=" << qgl->get_c() << "; " << "d=" << qgl->get_d() << std::endl;
        std::cout << "Углы: " << std::endl;
        std::cout << "A=" << qgl->get_A() << "; " << "B=" << qgl->get_B() << "; " << "C=" << qgl->get_C() << "; " << "D=" << qgl->get_D() << std::endl;
        std::cout << std::endl;
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, c = a, d = b, A, B, C = A, D = B) {
        name = "Параллелограмм";
    }
};

class Romb : public Parallelogram {
public:
    Romb(int a, int A, int B) : Parallelogram(a, b = a, A, B) {
        name = "Ромб";
    }
};

class Parallel_p : public Parallelogram {
public:
    Parallel_p(int a, int b) : Parallelogram(a, b, A = 90, B = 90) {
        name = "Прямоугольник";
    }
};

class Square : public Parallel_p {
public:
   Square(int a) : Parallel_p(a, b = a) {
        name = "Квадрат";
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    Triangle t(10, 20, 30, 50, 60, 70);
    Triangle_p tp(10, 20, 30, 50, 60);
    Triangle_rb trb(10, 20, 50, 60);
    Triangle_rs trs(30);

    t.print_info(&t);
    tp.print_info(&tp);
    trb.print_info(&trb);
    trs.print_info(&trs);

    Quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
    Parallelogram p(20, 30, 80, 100);
    Parallel_p pp(10, 20);
    Romb r(30, 30, 40);
    Square s(20);

    q.print_info(&q);
    pp.print_info(&pp);
    s.print_info(&s);
    p.print_info(&p);
    r.print_info(&r);

    return 0;
}