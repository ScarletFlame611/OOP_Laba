#ifndef SCHEME_H
#define SCHEME_H

#include "Element.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Scheme {
private:
    int height, width, depth;  // Размеры схемы
    string name; // Название схемы
    vector<vector<vector<Element*>>> structure;  // 3д-вектор для хранения указателей на элементы

public:
    // Конструктор по умолчанию: схема 1x1x1
    Scheme();

    // Конструктор с параметрами
    Scheme(int h, int w, int d);

    // Конструктор копирования
    Scheme(const Scheme& other);
    
    // Геттеры и сеттеры для имени
    void setName(const string& schemeName);
    string getName() const;
    
    // Геттеры для размеров
    int getHeight() const;
    int getWidth() const;
    int getDepth() const;

    // Метод для добавления элемента в схему
    bool addElement(Element* element, int x, int y, int z);

    // Метод для удаления элемента из схемы
    bool removeElement(int x, int y, int z);

    // Метод для получения элемента по координатам
    Element* getElement(int x, int y, int z) const;

    // Проверка доступности позиции
    bool isPositionAvailable(int x, int y, int z, Element* element) const;

    // Вывод схемы для визуализации
    void displayStructure() const;

};

#endif // SCHEME_H
