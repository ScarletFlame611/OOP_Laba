#ifndef LIGHTELEMENT_H
#define LIGHTELEMENT_H

#include "Element.h"
#include <string>
#include <vector>

using namespace std; 

class LightElement : public Element {
private:
    string lightColor;  // Цвет света
    bool isOn = false; // Состояние света: включен или выключен


public:
    // Конструктор по умолчанию
    LightElement();

    // Конструктор с параметрами
    LightElement(int h, int w, const vector<vector<char>>& s,
    const string& name, const string& color);
    
    // Конструктор копирования
    LightElement(const LightElement& other);

    // Метод для получения цвета света
    string getLightColor() const;

    // Метод для установки цвета света
    void setLightColor(const string& color);

    // Виртуальный метод идентификации
    string identify() const override;
    
    // Методы включения и выключения света
    void turnOn();
    void turnOff();

    // Метод проверки состояния света
    bool isLightOn() const;
};

#endif // LIGHTELEMENT_H
