#include "Element.h"
#include "SoundElement.h"
#include "LightElement.h"
#include <iostream>
#include <vector>
#include <cassert>

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
    lightElem.setName("Светящийся Элемент 1");
    assert(lightElem.getName() == "Светящийся Элемент 1");
    
    // Проверяем соединения
    assert(!elem1.canConnect(lightElem));
    assert(!elem3.canConnect(lightElem));
    
    // Проверка методов включения и выключения
    assert(lightElem.isLightOn()!=true);
    lightElem.turnOn();
    assert(lightElem.isLightOn()==true);
    lightElem.turnOff();
    assert(lightElem.isLightOn()!=true);
    
    
    cout << "Все тесты успешно пройдены!" << endl;

    return 0;
}
