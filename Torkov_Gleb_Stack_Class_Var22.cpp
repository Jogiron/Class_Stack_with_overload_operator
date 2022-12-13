// Torkov_Gleb_Stack22Var.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <ctime>
#include "Class_Comp_Game1.cpp"

using namespace std;
using namespace CompGame;

int try_action(string action)
{
returne:
    cout << "Вводимое значение: ";
    getline(cin >> std::ws, action);
    cout << endl;
    try
    {
        std::stoi(action);
    }
    catch (std::invalid_argument ex)
    {
        cout << "Неправильный ввод данных!" << endl;
        goto returne;
    }
    catch (std::out_of_range ex)
    {
        cout << "Слишком огромное значение!" << endl;
        goto returne;
    }
    return std::stoi(action);
}


int main()
{
    setlocale(LC_ALL, "RU-ru");
    string action;
    Stack* StackNotOverFlow = new Stack();
    Stack* StackStillNotOverFlow = new Stack();

    while (true)
    {
        cout << endl << "Введите 1 для добавления элемента в СТЕК" << endl
            << "Введите 2 для разрушающего чтения элемента СТЕКА" << endl
            << "Введите 3 для возвращения количества элементов СТЕКА" << endl
            << "Введите 4 для проверки состояния на наличие элементов в СТЕКЕ" << endl
            << "Введите 5 для удаления верхнего элемента из СТЕКА" << endl
            << "Введите 6 для очистки структуры данных СТЕКА" << endl
            << "Введите 7 для выхода из программы!" << endl
            << "Введите 8 для приравнивания верхнего элемента к нижнему" << endl
            << "Введите 9 для сравнения верхнего элемента с нижним" << endl
            << "Введите 10 для чтения с удалением всех элементов(перегрузка <<)" << endl
            << "Введите 11, чтобы проверить операторы для элементов класса игры" << endl
            << "Введите 12, чтобы проверить операторы для структур класса стэк" << endl;

        switch (try_action(action))
        {
        case 1:
            *StackNotOverFlow >> cin;
            break;
        case 2:
            StackNotOverFlow->get_Obj_Data();
            break;
        case 3:
            StackNotOverFlow->cout_Count();
            break;
        case 4:
            StackNotOverFlow->Check();
            break;
        case 5:
            StackNotOverFlow->Del_Head();
            break;
        case 6:
            StackNotOverFlow->Destroy_All_Elements();
            break;
        case 7:
            cout << "Выход из программы!" << endl;
            return(0);
            break;
        case 8:
            StackNotOverFlow->Assignment();
            break;
        case 9:
            StackNotOverFlow->Different();
            break;
        case 10:
            *StackNotOverFlow << cout;
            break;
        case 11:
            StackNotOverFlow->Proverka_Operatorov_Games();
            break;
        case 12:
            cout << "StackNotOverFlow->return_count_elements() > StackStillNotOverFlow->return_count_elements() == " << (StackNotOverFlow->return_count_elements() > StackStillNotOverFlow->return_count_elements()) << endl;
            cout << "StackNotOverFlow->return_count_elements() >= StackStillNotOverFlow->return_count_elements() == " << (StackNotOverFlow->return_count_elements() >= StackStillNotOverFlow->return_count_elements()) << endl;
            cout << "StackNotOverFlow->return_count_elements() < StackStillNotOverFlow->return_count_elements() == " << (StackNotOverFlow->return_count_elements() < StackStillNotOverFlow->return_count_elements()) << endl;
            cout << "StackNotOverFlow->return_count_elements() <= StackStillNotOverFlow->return_count_elements() == " << (StackNotOverFlow->return_count_elements() <= StackStillNotOverFlow->return_count_elements()) << endl;
            break;
        default:
            cout << "Введённое значение не входит в список!" << endl;
            break;
        }
    }
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
