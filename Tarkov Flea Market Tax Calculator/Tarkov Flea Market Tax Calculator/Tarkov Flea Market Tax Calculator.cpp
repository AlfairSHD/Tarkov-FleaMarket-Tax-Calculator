// Tarkov FleaMarket Tax Calculator.cpp 
#include <iostream>
#include <random>
#include <cmath>

int main()
{
    int BasePrice; // Your base price of the item
    int MinPrice; //Minimal price of the item on market
    int MaxPrice; //Maximal price of the item on market
    int TotalAmount; //Selling item count
    const int min = 3; //minimal pages count with current item
    const int max = 5; //maximal pages count with current item
    int output = min + (rand() % static_cast<int>(max - min + 1)); //random middle pages count with current item
    int Tic;// = 100 * output; then you dont know how much items on market exactly //Total offers of item on flea market| You can change it on exact number of offers (example: const int Tic = 30)
    bool Check; //if true

    std::cout << "=================================================================================================" << "\n";
    std::cout << "Input Your Price of Item (int): ";
    std::cin >> BasePrice;
    std::cout << "How much items you sell? (int): ";
    std::cin >> TotalAmount;
    std::cout << "Input minimal price of the item on flea market (int): ";
    std::cin >> MinPrice;
    std::cout << "Input maximal price of the item on flea market (int): ";
    std::cin >> MaxPrice;
    std::cout << "How many offers with your item on flea market? (int): ";
    std::cin >> Tic;
    std::cout << "Require price for all items (true) or each item (false) in offer? (bool): ";
    std::cin >> Check;

    int MeanPrice = round((MinPrice + MaxPrice) / 2); // arithmetic mean price of the item on market

    //is the "quantity" factor which is either 1 when "Require for all items in offer" is checked or the amount of items being offered otherwise
    int Q = 0;
    if (Check == true) {
        Q = 1;
    }
    else {
        Q = TotalAmount;
    }

    int Vzero = (((BasePrice + MeanPrice) / Tic) * Q);
    int Vr = ((BasePrice + MeanPrice) * TotalAmount);

    float Pzero = 0;

    if (Vr < Vzero)
    {
        Pzero = 1.08;
    }
    else
    {
        Pzero = log10(Vzero / Vr);
    }

    float Pr = 0;

    if (Vr >= Vzero)
    {
        Pr = 1.08;
    }
    else
    {
        Pr = log10(Vr / Vzero);
    }
    const float Ti = 0.07;
    const float Tr = 0.05;

    float Tax = round((Vzero * Ti * pow(4, Pzero) * Q) + (Vr * Tr * pow(4, Pr) * Q));
    std::cout << "=================================================================================================" << "\n";
    std::cout << "Your tax is :" << Tax << "\n";
}