#include "Element.h"
#include <iostream>
using namespace std;


void Element::validateShape() const {
    // Проверяем, что матрица имеет правильные размеры и в ней допустимые значения
    if (shape.size() != height) {
        cout << "Ошибка: количество строк в матрице не соответствует высоте." << endl;
        exit(1); 
    }
    for (const auto& row : shape) {
        if (row.size() != width) {
            cout << "Ошибка: количество столбцов в матрице не соответствует ширине." << endl;
            exit(1); 
        }
        
        for (char c : row) {
            if (c != 'O' && c != ' ') {
                cout << "Ошибка: матрица содержит недопустимые символы." << endl;
                exit(1); 
            }
        }
    }
}

// Конструктор по умолчанию
Element::Element() : height(1), width(1), shape({{'O'}}), name("ПоУмолчанию") {}

// Конструктор
Element::Element(int h, int w, const vector<vector<char>>& s, const string& name)
    : height(h), width(w), shape(s), name(name) {
    // Проверка положительности высоты и ширины
    if (height <= 0 || width <= 0) {
        cout << "Ошибка: высота и ширина должны быть положительными числами." << endl;
        exit(1); // Завершаем выполнение программы
    }

    // Проверка формы элемента
    validateShape();
}


// Конструктор копирования
Element::Element(const Element& other) : width(other.width), height(other.height), shape(other.shape), name(other.name) {}

// Метод для проверки соединения
bool Element::canConnect(const Element& other) const {
    if (other.getHeight()<height||other.getWidth()<width){
        return false;
    }
    int totalConnectors = 0;
    int matchingConnections = 0;    // Количество совпадений

    // Проходим по всем ячейкам
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (shape[i][j] == 'O') { 
                totalConnectors++; // Увеличиваем общее количество соединителей

                if (i < other.getHeight() && j < other.getWidth()) {
                    if (other.getShape()[i][j] == 'O') {
                        matchingConnections++; // Найдено совпадение
                    }
                }
            }
        }
    }

        return matchingConnections == totalConnectors; // Все соединители должны быть закрыты
    
}

// Методы доступа
int Element::getHeight() const {
    return height;
}

int Element::getWidth() const {
    return width;
}

const vector<vector<char>>& Element::getShape() const {
    return shape;
}

string Element::getName() const {
    return name;
}

// Сеттер для имени
void Element::setName(const string& newName) {
    name = newName;
}
