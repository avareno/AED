//
// Created by avareno on 10/24/23.
//
#include <iostream>
#include <string>
#include "Menu.hpp"
#include "Search.hpp"

using namespace std;



string Menu::homepage()
{
    string line;
    cout << "Search | Requests | Undo | Check Record" << '\n';
    cin >> line;
    return line;
}

void Menu::run() {
    if(homepage()=="Search")
    {
        Search search;
    }
}
