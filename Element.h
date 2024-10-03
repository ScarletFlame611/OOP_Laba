#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <string>

using namespace std; 

class Element {
private:
    int height;
    int width;
    vector<vector<char>> shape; // Матрица, где 'O' - место где деталь есть, ' ' - где её нет
    string name;
    void validateShape() const;

public:
    // Конструктор по умолчанию
    Element(); 
    
    // Конструктор
    Element(int h, int w, const vector<vector<char>>& s, const string& name);
    
    // Конструктор копирования
    Element(const Element& other);
    
    // Метод для проверки соединения
    bool canConnect(const Element& other) const;

    // Методы доступа
    int getHeight() const;
    int getWidth() const;
    const vector<vector<char>>& getShape() const;
    string getName() const; 
    
    // Сеттер для изменения имени
    void setName(const string& newName);
};

#endif // ELEMENT_H
