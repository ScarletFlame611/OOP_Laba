#include "SoundElement.h"
#include <iostream>
using namespace std;

// Конструктор по умолчанию
SoundElement::SoundElement() : Element(), soundType("Бип-Бип") {}

// Конструктор с параметрами
SoundElement::SoundElement(int h, int w, const vector<vector<char>>& s,
const string& name, const string& sound): Element(h, w, s, name), soundType(sound) {}

// Конструктор копирования
SoundElement::SoundElement(const SoundElement& other)
    : Element(other), soundType(other.soundType) {}

// Метод для установки типа звука
void SoundElement::setSoundType(const string& sound) {
    soundType = sound;
}

// Метод для получения типа звука
string SoundElement::getSoundType() const {
    return soundType;
}

// Виртуальный метод идентификации
string SoundElement::identify() const {
    return "Пищалка с типом звука " + soundType;
}

void SoundElement::beep() const {
    cout << "Пищалка издает звук: " << soundType << endl;
}
