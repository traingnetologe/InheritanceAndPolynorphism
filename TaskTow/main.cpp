#include <iostream>

class figure_base
{
protected:
    std::string type_figure;
    int number_of_sides{ 0 };
    figure_base(int set_number_of_sides) :number_of_sides(set_number_of_sides) { }
    figure_base(std::string set_type_figure) : type_figure(set_type_figure) { }
    figure_base(std::string set_type_figure,int set_number_of_sides) : type_figure(set_type_figure), number_of_sides(set_number_of_sides){ }

public:
    figure_base() = default;
    // Возврашаем количестов соторон у объекта
    int ofSides() { return number_of_sides; }
    // Добавлям функционал для третей задачи
    virtual void print_info(){};
    virtual bool check() {return false;};

    std::string get_type_figure() {return type_figure;}
};

//////////////////////////////////////////////////////////////////////////////////////////////////

// прямоугольники
class quadrange : public figure_base{
protected:
    // a, b, c, d - стороны
    // A, B, C, D - углы 
    int a{}, b{}, c{}, d{}, A{}, B{}, C{}, D{};

public:
    //  основной конструктор класса здесь вся магия.
    quadrange(std::string set_type_figure, int set_a, int set_b, int set_c, int set_d, int set_A, int set_B, int set_C, int set_D)
    :figure_base(set_type_figure),
    a(set_a),
    b(set_b),
    c(set_c),
    d(set_d),
    A(set_A),
    B(set_B),
    C(set_C),
    D(set_D) { }
//........................................
    int get_a() {return a;}
    int get_b() {return b;}
    int get_c() {return c;}
    int get_d() {return d;}


    int get_A() {return A;}
    int get_B() {return B;}
    int get_C() {return C;}
    int get_D() {return D;}
//........................................

    void print_info() override{
            std::cout << get_type_figure()
            << ":\nСтороны "
            << "a=" << a
            << " b=" << b
            << " c=" << c
            << " d=" << d
            << "\nУглы: "
            << "A=" << A
            << " B=" << B
            << " C=" << C
            << " D=" << D
            << "\n";
        }

};

class rectangel : public quadrange {
    public:
    rectangel(std::string set_type_figure, int set_a, int set_b, int set_c, int set_d, int set_A, int set_B, int set_C, int set_D)
    :quadrange(
        set_type_figure,
        set_a,
        set_b,
        set_c,
        set_d,
        set_A,
        set_B,
        set_C,
        set_D) {}
};

class  parallelogram : public rectangel { 
    public: parallelogram(int set_size_side_ac,int set_size_side_bd,int set_cornersAC, int set_cornersBD):
    rectangel("Параллелограм",
    set_size_side_ac,
    set_size_side_bd,
    set_size_side_ac,
    set_size_side_bd,
    set_cornersAC,
    set_cornersBD,
    set_cornersAC,
    set_cornersBD) { } };

class  square : public rectangel {
    private:
    int cornerc_this_figure = 90;

    public: square( int set_size_side):
    rectangel("Квадрат", 
    set_size_side,
    set_size_side,
    set_size_side,
    set_size_side,
    cornerc_this_figure, cornerc_this_figure, cornerc_this_figure, cornerc_this_figure) { } };

class  rhombus : public rectangel {

    public: rhombus(int set_size_side, int set_corners):
    rectangel("Ромб",
    set_size_side,
    set_size_side,
    set_size_side,
    set_size_side,
    set_corners,
    set_corners,
    set_corners,
    set_corners) { } };

//////////////////////////////////////////////////////////////////////////////////////////////////
// треугольники
class triangel : public figure_base {
protected:
    // a, b, c - стороны
    // A, B, C - углы 
    int a{}, b{}, c{}, A{}, B{}, C{};

public:
    //  основной конструктор класса здесь вся магия.
    triangel(std::string set_type_figure, int set_a, int set_b, int set_c, int set_A, int set_B, int set_C)
    :figure_base(set_type_figure),
    a(set_a),
    b(set_b),
    c(set_c),
    A(set_A),
    B(set_B),
    C(set_C) { }

int get_a() {return a;}
int get_b() {return b;}
int get_c() {return c;}

int get_A() {return A;}
int get_B() {return B;}
int get_C() {return C;}

};

// class triangel : public triangel_Base {
//     public: triangel() 
//     :triangel_Base("Треугольник", 10, 20, 30, 50, 60, 70) {} 
//     };

class straing_angle_triangel : public triangel {
    public: 
    straing_angle_triangel() 
    :triangel("Прямоуголный треугольник", 10, 20, 30, 50, 60, 90) {} 
};

class equal_third_party_triangel :public triangel { 
    public: 
    equal_third_party_triangel(int set_size_abc, int set_corners) 
    :triangel("Равносторонний треугольник", set_size_abc, set_size_abc, set_size_abc, set_corners, set_corners, set_corners) {} 
};

// void print_info(rectangel* figure) {
//             std::cout << figure->get_type_figure()
//             << ":\nСтороны: "
//             << "a=" << figure->get_a()
//             << " b=" << figure->get_b()
//             << " c=" << figure->get_c()
//             << " d=" << figure->get_d()
//             << "\nУглы: "
//             << "A=" << figure->get_A()
//             << " B=" << figure->get_B()
//             << " C=" << figure->get_C()
//             << " D=" << figure->get_D()
//             << "\n";
// }

// void print_info(triangel_Base* figure) {
//             std::cout << figure->get_type_figure()
//             << ":\nСтороны: "
//             << "a=" << figure->get_a()
//             << " b=" << figure->get_b()
//             << " c=" << figure->get_c()
//             << "\nУглы: "
//             << "A=" << figure->get_A()
//             << " B=" << figure->get_B()
//             << " C=" << figure->get_C()
//             << "\n";
// }

int main() {
    std::setlocale(LC_ALL, "Russian");
    // четырех гранники
    quadrange qu("Четырехуголник",10,20, 10,40, 50,60,70,80);
    qu.print_info();

    parallelogram par(20,30,30,40);
    par.print_info(); 

    // треуголоники
    // triangel tri; straing_angle_triangel st; equal_third_party_triangel eq;
    // std::cout << "hello world!!!!";
    return 0;
}