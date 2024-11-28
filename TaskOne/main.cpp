#include <iostream>

class figure_base
{
protected:
    int number_of_sides{0};
    figure_base(int set_number_of_sides):number_of_sides(set_number_of_sides){ }
public:
    figure_base() = default;
    // Возврашаем количестов соторон у объекта
    int ofSides(){
        return number_of_sides;
    }
};

class ractangel : public figure_base{
public:
ractangel():figure_base(4){
}
};

class triangel : public figure_base{
public:
triangel():figure_base(2){
}
};

int main(){
    figure_base fig;
    ractangel rect;
    triangel tria;

    std::cout << "Количество сторон: \n";
    std::cout<< "Фигура: " << rect.ofSides() << "\n";
    std::cout << "Треугольник: " << tria.ofSides() << "\n";
    std::cout << "Четырёхугольник: " << rect.ofSides() << "\n";

    // std::cout << "hello world!!!!";
    return 0;
}