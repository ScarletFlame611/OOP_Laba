#include "Scheme.h"
#include <iostream>
using namespace std;

// Конструктор по умолчанию
Scheme::Scheme() 
    : height(1), width(1), depth(1), name("Default"), structure(1, vector<vector<Element*>>(1, vector<Element*>(1, nullptr))) {}

// Конструктор с параметрами
Scheme::Scheme(int h, int w, int d) 
    : height(h), width(w), depth(d), name("Scheme"), structure(h, vector<vector<Element*>>(w, vector<Element*>(d, nullptr))) {}

// Конструктор копирования
Scheme::Scheme(const Scheme& other)
    : height(other.height), width(other.width), depth(other.depth), name(other.name), structure(other.structure) {}
    
// Сеттер для имени схемы
void Scheme::setName(const string& schemeName) {
    name = schemeName;
}

// Геттер для имени схемы
string Scheme::getName() const {
    return name;
}

// Геттеры для размеров схемы
int Scheme::getHeight() const { return height; }
int Scheme::getWidth() const { return width; }
int Scheme::getDepth() const { return depth; }

// Метод добавления элемента в схему
bool Scheme::addElement(Element* element, int x, int y, int z) {
    // Передаём в isPositionAvailable для проверки соединения
    if (isPositionAvailable(x, y, z, element)) {
        structure[x][y][z] = element;
        return true;
    }
    return false;
}


// Метод для удаления элемента из схемы
bool Scheme::removeElement(int x, int y, int z) {
    if (x >= height || y >= width || z >= depth || !structure[x][y][z]) return false;
    structure[x][y][z] = nullptr;
    return true;
}

// Метод для получения элемента по координатам
Element* Scheme::getElement(int x, int y, int z) const {
    if (x < 0 || x >= width || y < 0 || y >= height || z < 0 || z >= depth) {
        return nullptr;
    }
    return structure[x][y][z];
}

// Проверка доступности позиции
bool Scheme::isPositionAvailable(int x, int y, int z, Element* element) const {
    if (x < 0 || x >= height || y < 0 || y >= width || z < 0 || z >= depth) {
        return false;
    }

    // если z == 0, то это первый слой и допускаем добавление без проверки
    if (z == 0) {
        return structure[x][y][z] == nullptr;
    }

    // иначе проверка наличия элемента на позиции (x, y, z-1)
    Element* lowerElement = structure[x][y][z - 1];
    if (lowerElement == nullptr) {
        return false; // если нет элемента на предыдущем слое то и соединять не с чем
    }

    // Соединение с элементом на предыдущем слое
    if (element->canConnect(*lowerElement)) {
        return structure[x][y][z] == nullptr;
    }

    return false; // Нельзя добавить элемент, так как соединение невозможно
}


// Вывод структуры схемы (Ну просто чтобы красивенько было)
void Scheme::displayStructure() const {
    for (int z = 0; z < depth; ++z) {
        cout << "Слой " << z + 1 << ":\n";
        for (int x = 0; x < height; ++x) {
            for (int y = 0; y < width; ++y) {
                if (structure[x][y][z]) {
                    cout << structure[x][y][z]->getName() << " ";
                } else {
                    cout << "- ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
}


