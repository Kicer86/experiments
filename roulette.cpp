
#include <cassert>
#include <iostream>
#include <random>
#include <set>

enum Colour
{
    Green,
    Red,
    Black
};


Colour colourForNumber(int n)
{
    static const std::set<int> black =
    {
        2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35
    };

    static const std::set<int> red =
    {
        1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36
    };

    if (n == 0)
        return Colour::Green;
    else if (red.find(n) != red.end())
        return Colour::Red;
    else if (black.find(n) != black.end())
        return Colour::Black;
    else
        assert(!"n is out of scope");
}

int main()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(0, 36);

    int cash_spent = 0;
    int cash_won = 0;
    int bet = 1;
    constexpr int tries = 1000000;

    int histo[37];
    for (int i = 0; i < 37; i++)
        histo[i] = 0;

    int c_histo[3];
    for (int i = 0; i < 3; i++)
        c_histo[i] = 0;

    for(int i = 0; i < tries; i++)
    {
        const int n = dist(mt);
        const Colour c = colourForNumber(n);

        histo[n]++;
        c_histo[c]++;

        cash_spent += bet;

        if (c == Colour::Red)   // won!  get twice as bet, start beting from 1
        {
            cash_won += bet *2;
            bet = 1;
        }
        else
            bet *= 2;          // we lose, double the bet
    }

    std::cout << "won:   " << cash_won << std::endl;
    std::cout << "spent: " << cash_spent << std::endl;
    std::cout << "income: " << cash_won - cash_spent << std::endl;

    for (int i = 0; i < 37; i++)
        std::cout << "Number " << i << ": " << histo[i] * 100.0 / tries << "%" << std::endl;

    std::cout << "Green: " << c_histo[Green] * 100.0 / tries << "%" << std::endl;
    std::cout << "Red:   " << c_histo[Red]   * 100.0 / tries << "%" << std::endl;
    std::cout << "Black: " << c_histo[Black] * 100.0 / tries << "%" << std::endl;

    return 0;
}
