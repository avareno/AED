//
// Created by avareno on 10/25/23.
//

#include "SearchUC.hpp"
#include <iostream>
#include <vector>
using namespace std;

SearchUC::SearchUC(const set<Student_class> &students_classes, const list<Class> &classes) {
    string nom= get_num();
    auto left = classes.begin();
    auto right = prev(classes.end());
    auto mid = classes.begin();

    while (left != next(right)) {
        auto mid = std::next(left, std::distance(left, right) / 2);

        if (mid->getCl().getUcCode() < nom) {
            left = std::next(mid);
        } else {
            right = std::prev(mid);
        }
    }
    cout << mid->getCl().getUcCode();




}

int SearchUC::getI() const {
    return i;
}

void SearchUC::back() {
    this->i=1;
}
string SearchUC::get_num() {
    string l;
    cout << "Introduza o UcCode: " << "\n";
    cin >> l;
    cin.clear();
    return l;
}