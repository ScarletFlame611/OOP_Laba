#include "Element.h"
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

    // Проверка доступа к полям
    assert(elem3.getName() == "Элемент 3");
    assert(elem2.getWidth() == 3);
    
    elem1.setName("Новый элемент");

    // Проверка сеттера
    assert(elem1.getName() == "Новый элемент");
    
    cout << "Все тесты успешно пройдены!" << endl;

    return 0;
}
