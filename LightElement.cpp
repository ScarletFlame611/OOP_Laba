#include "LightElement.h"
#include <string>
#include <vector>

using namespace std;

// Конструктор по умолчанию
LightElement::LightElement() : Element(), lightColor("Белый") {}

// Конструктор с параметрами
LightElement::LightElement(int h, int w, const vector<vector<char>>& s,
const string& name, const string& color): Element(h, w, s, name), lightColor(color) {}

LightElement::LightElement(const LightElement& other)
    : Element(other), lightColor(other.lightColor), isOn(other.isOn) {}

// Метод для получения цвета света
string LightElement::getLightColor() const {
    return lightColor;
}

// Метод для установки цвета света
void LightElement::setLightColor(const string& color) {
    lightColor = color;
}

// Виртуальный метод идентификации
string LightElement::identify() const {
    return "Световой элемент, Цвет: " + lightColor;
}

void LightElement::turnOn() {
    isOn = true;
}

void LightElement::turnOff() {
    isOn = false;
}

bool LightElement::isLightOn() const {
    return isOn;
}
