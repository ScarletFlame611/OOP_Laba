#ifndef SOUNDELEMENT_H
#define SOUNDELEMENT_H

#include "Element.h"
#include <string>
#include <vector>

using namespace std; 

class SoundElement : public Element {
private:
    string soundType; // Тип звука

public:
    // Конструктор по умолчанию
    SoundElement();

    // Конструктор с параметрами
    SoundElement(int h, int w, const vector<vector<char>>& s,
    const string& name, const string& sound);
    
    // Конструктор копирования
    SoundElement(const SoundElement& other);

    // Метод для установки звука
    void setSoundType(const string& sound);

    // Метод для получения звука
    string getSoundType() const;

    // Виртуальный метод идентификации
    string identify() const override;
    
    // Вызов звука
    void beep() const;
};

#endif // SOUNDELEMENT_H
