#include <iostream>
using namespace std;

// Базовый класс "Форма"
class Shape {
public:
    virtual void Show() = 0; // Чисто виртуальный метод для демонстрации фигуры
};

// Класс "Точка"
class Point {
    int X;
    int Y;
public:
    Point() : X(0), Y(0) {}

    void SetPoint(int iX, int iY) {
        X = iX;
        Y = iY;
    }

    void Show() {
        cout << "X: " << X << ", Y: " << Y << endl;
    }
};

// Класс "Цвет"
class Color {
    int red, green, blue;
public:
    Color(int r, int g, int b) : red(r), green(g), blue(b) {}

    void ShowColor() {
        cout << "Цвет RGB: (" << red << ", " << green << ", " << blue << ")" << endl;
    }
};

// Класс "Фигура", наследующийся от "Форма"
class Figura : public Shape {
    Point* obj;
    int count;
    Color color; // Агрегация: цвет существует независимо от фигуры
public:
    Figura(int r, int g, int b) : color(r, g, b) {
        count = 0;
        obj = nullptr;
    }

    void CreateFigura(int ct) {
        if (ct < 3) exit(0);
        count = ct;
        obj = new Point[count];
        if (!obj) exit(0);

        int tempX, tempY;
        for (int i = 0; i < count; i++) {
            cout << "Введите X координату для точки " << i + 1 << "\n";
            cin >> tempX;
            cout << "Введите Y координату для точки " << i + 1 << "\n";
            cin >> tempY;
            obj[i].SetPoint(tempX, tempY);
        }
    }

    void Show() override {
        color.ShowColor();
        cout << "Количество углов: " << count << endl;
        for (int i = 0; i < count; i++) {
            cout << "Точка " << i + 1 << ": ";
            obj[i].Show();
        }
    }

    ~Figura() {
        if (obj != nullptr) delete[] obj;
    }
};

int main() {
    Figura f(255, 0, 0); // Красная фигура
    f.CreateFigura(4); // Создание фигуры с 4 углами
    f.Show(); // Показ фигуры
    return 0;
}
