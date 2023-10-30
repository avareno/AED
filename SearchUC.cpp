//
// Created by avareno on 10/25/23.
//

#include "SearchUC.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

SearchUC::SearchUC(const set<Student_class> &students_classes, const list<Class> &classes) {
    string nom= get_num();
    vector<Class> out;
    auto left = classes.begin();
    auto right = prev(classes.end());
    auto mid = classes.end();

    int i = 1;
    while(i==1)
    {
        while (left != next(right)) {
            mid = std::next(left, std::distance(left, right) / 2);
            if(mid->getCl().getUcCode()==nom){
                i=0;
                break;
            }else if (mid->getCl().getUcCode() < nom) {
                left = std::next(mid);

            } else {
                right = std::prev(mid);
            }
        }

        if(i==1)
        {
            cout << "UcCode inválido introduza outro UcCode ou escreva q para retroceder";
            nom = get_num();
            if(nom == "q")
            {
                back();
                break;
            }
            left = classes.begin();
            right = prev(classes.end());
        }
    }
    auto pos2 = mid;
    pos2--;
    while(mid->getCl().getUcCode()==nom)
    {
        out.push_back(*mid);
        mid++;
    }
    while(pos2->getCl().getUcCode()==nom)
    {
        out.push_back(*pos2);
        pos2--;
    }

        string l;
    cout << "Classes | other things to implement" << endl;
    cin >> l;
    if(l=="Classes"){
        for(auto at: out)
        {
            std::string type = at.getType();

            // Remove trailing carriage return ('\r') characters
            while (!type.empty() && type.back() == '\r') {
                type.pop_back();
            }
            cout << at.getCl().getClassCode() << "-" << type << ", ";
        }
    }




}

int SearchUC::getI() const {
    return i_;
}

void SearchUC::back() {
    this->i_=1;
}
string SearchUC::get_num() {
    string l;
    cout << "Introduza o UcCode: " ;
    cin >> l;
    cin.clear();
    return l;
}