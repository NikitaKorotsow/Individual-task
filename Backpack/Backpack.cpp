#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, ".1251");
    const int k = 5; // количество предметов
    const double W = 20; // вместимость рюкзака
    double w[k] = { 10, 4, 3, 12, 5 }; // масса
    double p[k] = { 12, 11, 1, 3, 36 }; // стоимость
    double mass[4][k]; //массив для расчетов
    double weight = 0; //суммарный вес
    double pay = 0; // суммарная стоимость
    for (int i = 0; i < k; i++)  //подсчет коэффициентов и заполнение строк массива
    {
        mass[0][i] = (p[i] / w[i]);
        mass[1][i] = w[i];
        mass[2][i] = p[i];
        mass[3][i] = i + 1;

    }
    for (int i = 0; i < k; i++) //распологаем в порядке убывания
    {
        for (int j = 0; j < k; j++)
        {
            double buffer;
            if (mass[0][i] > mass[0][j])
            {
                for (int z = 0; z < 4; z++)
                {
                    buffer = mass[z][i];
                    mass[z][i] = mass[z][j];
                    mass[z][j] = buffer;
                }

            }
        }
    }
    cout << "Подходящие предметы: ";
    for (int i = 0; i < k; i++)//выводим
    {
        weight += mass[1][i];
        if (weight <= W)
        {
            cout << mass[3][i] << " ";
            pay += mass[2][i];
        }
        else
        {
            weight -= mass[1][i];
        }
    }
    cout << endl << "Общий вес: " << weight << endl << "Сумма: " << pay << endl << endl;
    system("pause");
}
