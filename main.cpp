#include "Element.h"
#include "SoundElement.h"
#include "LightElement.h"
#include <iostream>
#include <vector>
#include <cassert>
#include "Scheme.h"

using namespace std;

int main() {
    // Тест конструктора по умолчанию
    Element defaultElem;
    assert(defaultElem.getHeight() == 1);
    assert(defaultElem.getWidth() == 1);
    assert(defaultElem.getShape()[0][0] == 'O');
    assert(defaultElem.getName() == "ПоУмолчанию");
    
    // Тест конструктора инициализации
    vector<vector<char>> matrix1 = {
        {' ', 'O', ' '},
        {'O', 'O', 'O'},
        {' ', 'O', ' '}
    };
    Element elem1(3, 3, matrix1, "Элемент 1");
    assert(elem1.getHeight() == 3);
    assert(elem1.getWidth() == 3);
    assert(elem1.getName() == "Элемент 1");
    
    // Тест конструктора копирования
    Element elemCopy(elem1);
    assert(elemCopy.getHeight() == elem1.getHeight());
    assert(elemCopy.getWidth() == elem1.getWidth());
    assert(elemCopy.getName() == elem1.getName());
    
    // Тест соединения
    vector<vector<char>> matrix2 = {
        {'O', 'O', ' '},
        {'O', ' ', 'O'},
        {' ', 'O', 'O'}
    };
    Element elem2(3, 3, matrix2, "Элемент 2");

    // Проверка полного соединения
    assert(!elem1.canConnect(elem2));  // Полное соединение невозможно

    // Примеры с другими элементами для тестирования
    vector<vector<char>> matrix3 = {
        {' ', ' ', ' '},
        {' ', 'O', ' '},
        {' ', ' ', ' '}
    };
    Element elem3(3, 3, matrix3, "Элемент 3");

    assert(elem3.canConnect(elem1));  // Полное соединение для элемента 3 возможно
    assert(!elem3.canConnect(elem2));
    assert(!elem1.canConnect(elem3));
    assert(!elem2.canConnect(elem1));
    
    // Проверка доступа к полям
    assert(elem3.getName() == "Элемент 3");
    assert(elem2.getWidth() == 3);
    
    elem1.setName("Новый элемент");

    // Проверка сеттера
    assert(elem1.getName() == "Новый элемент");
    assert(elemCopy.getName()=="Элемент 1");
    
    // Проверка идентификатора 
    assert(elem1.identify() == "Обычный элемент: " + elem1.getName());
    
    // Начинаем тестировать пищалку
    
    // Тест конструктора по умолчанию
    SoundElement defaultSoundElem;
    assert(defaultSoundElem.getHeight() == 1);
    assert(defaultSoundElem.getWidth() == 1);
    assert(defaultSoundElem.getShape()[0][0] == 'O');
    assert(defaultSoundElem.getName() == "ПоУмолчанию");
    assert(defaultSoundElem.getSoundType() == "Бип-Бип");
    
    // Тест конструктора инициализации
    SoundElement soundElem(3, 3, matrix1, "Звуковой элемент", "Бип-Бип");
    assert(soundElem.getHeight() == 3);
    assert(soundElem.getWidth() == 3);
    assert(soundElem.getName() == "Звуковой элемент");
    assert(soundElem.getSoundType() == "Бип-Бип");
    
    // Тест конструктора копирования
    SoundElement soundElemCopy(soundElem);
    assert(soundElemCopy.getHeight() == soundElem.getHeight());
    assert(soundElemCopy.getWidth() == soundElem.getWidth());
    assert(soundElemCopy.getName() == soundElem.getName());
    assert(soundElemCopy.getSoundType() == soundElem.getSoundType());
    
    // Проверяем виртуальный метод
    assert(soundElem.identify() == "Пищалка с типом звука "+soundElem.getSoundType());
    
    // Проверка доступа к полям
    assert(soundElem.getWidth() == 3);
    assert(soundElem.getName() == "Звуковой элемент");
    
    soundElem.beep(); // Тут оно пищит
    
    // Проверяем сеттер
    soundElem.setSoundType("Буп-Буп");
    soundElem.beep();
    assert(soundElem.getSoundType() == "Буп-Буп");
    assert(soundElemCopy.getSoundType() == "Бип-Бип");
    soundElem.setName("Звуковой Элемент 1");
    assert(soundElem.getName() == "Звуковой Элемент 1");
    
    // Проверяем соединения
    assert(!soundElem.canConnect(elem2));
    assert(elem3.canConnect(soundElem));
    assert(!soundElem.canConnect(elem3));
    
    // Начинаем тестировать светящийся элемент
    
    // Тест конструктора по умолчанию
    LightElement defaultLightElem;
    assert(defaultLightElem.getHeight() == 1);
    assert(defaultLightElem.getWidth() == 1);
    assert(defaultLightElem.getShape()[0][0] == 'O');
    assert(defaultLightElem.getName() == "ПоУмолчанию");
    assert(defaultLightElem.getLightColor() == "Белый");
    
    // Тест конструктора инициализации
    LightElement lightElem(3, 3, matrix2, "Светящийся элемент", "Красный");
    assert(lightElem.getHeight() == 3);
    assert(lightElem.getWidth() == 3);
    assert(lightElem.getName() == "Светящийся элемент");
    assert(lightElem.getLightColor() == "Красный");
    
    // Тест конструктора копирования
    LightElement lightElemCopy(lightElem);
    assert(lightElemCopy.getHeight() == lightElem.getHeight());
    assert(lightElemCopy.getWidth() == lightElem.getWidth());
    assert(lightElemCopy.getName() == lightElem.getName());
    assert(lightElemCopy.getLightColor() == lightElem.getLightColor());
    
    // Проверяем виртуальный метод
    assert(lightElem.identify() == "Световой элемент, Цвет: "+lightElem.getLightColor());
    
    // Проверка доступа к полям
    assert(lightElem.getWidth() == 3);
    assert(lightElem.getName() == "Светящийся элемент");
    
    // Проверяем сеттер
    lightElem.setLightColor("Синий");
    assert(lightElem.getLightColor() == "Синий");
    assert(lightElemCopy.getLightColor() == "Красный");
    lightElem.setName("Светящийся Элемент 1");
    assert(lightElem.getName() == "Светящийся Элемент 1");
    
    // Проверяем соединения
    assert(!soundElem.canConnect(lightElem));
    assert(!elem3.canConnect(lightElem));
    
    // Проверка методов включения и выключения
    assert(lightElem.isLightOn()!=true);
    lightElem.turnOn();
    assert(lightElem.isLightOn()==true);
    lightElem.turnOff();
    assert(lightElem.isLightOn()!=true);
    
    // Начинаем тестировать схему
    
    // Тест конструктора по умолчанию
    Scheme defaultScheme;
    assert(defaultScheme.getHeight() == 1);
    assert(defaultScheme.getWidth() == 1);
    assert(defaultScheme.getDepth() == 1);
    assert(defaultScheme.getName() == "Default");
    
    // Тест конструктора инициализации
    Scheme scheme(2, 2, 2);
    
    scheme.setName("Моя схема");
    assert(scheme.getName() == "Моя схема");
    
    assert(scheme.getHeight() == 2);
    assert(scheme.getWidth() == 2);
    assert(scheme.getDepth() == 2);

    // Добавляем элементы и проверяем, что они добавлены на свои позиции
    assert(scheme.addElement(&elem1, 0, 0, 0));
    assert(scheme.getElement(0, 0, 0) == &elem1);

    assert(scheme.addElement(&elem2, 0, 1, 0));
    assert(scheme.getElement(0, 1, 0) == &elem2);

    assert(scheme.addElement(&elemCopy, 1, 0, 0));
    assert(scheme.getElement(1, 0, 0) == &elemCopy);

    // Попытка добавить элемент на занятую позицию должна вернуть false
    assert(!scheme.addElement(&elem3, 0, 0, 0));
    
    // Попытка добавить элемент на позицию на которой нельзя соединить с нижним
    assert(!scheme.addElement(&elem3, 0, 1, 1));
    
    assert(scheme.addElement(&elem3, 0, 0, 1));
    assert(scheme.getElement(0, 0, 1) == &elem3);
    
    assert(scheme.addElement(&lightElem, 0, 1, 1));
    assert(lightElem.getLightColor() == "Синий");
    
    // Тест конструктора копирования
    Scheme copyScheme(scheme);
    assert(copyScheme.getName() == "Моя схема");
    assert(copyScheme.getHeight() == 2);
    assert(copyScheme.getWidth() == 2);
    assert(copyScheme.getDepth() == 2);
    scheme.setName("Оригинальная схема");
    assert(copyScheme.getName() == "Моя схема");
    assert(copyScheme.getElement(0, 1, 0) == &elem2);
    
    // Отображаем структуру схемы
    scheme.displayStructure();

    // Удаляем элемент и проверяем
    assert(scheme.removeElement(0, 0, 0));
    assert(scheme.getElement(0, 0, 0) == nullptr);

    std::cout << "Все тесты успешно пройдены!" << std::endl;

    return 0;
}




