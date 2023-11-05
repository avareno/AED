/**
 * @file SearchUC.cpp
 * @brief Implementation of the SearchUC class.
 */

#include "SearchUC.hpp"
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Constructor for SearchUC.
 *
 * This constructor searches for UCs and associated classes.
 * @param classes_per_uc A set of Class_per_uc objects.
 * @param classes A list of Class objects.
 */
SearchUC::SearchUC(const set<Class_per_uc> classes_per_uc, const list<Class> &classes) {
    string nom = get_num();
    vector<Class> out;
    auto left = classes.begin();
    auto right = prev(classes.end());
    auto mid = classes.end();
    int i = 1;

    // Time Complexity: O(log(N)) where N is the number of elements in the classes list.

    while (i == 1) {
        while (left != next(right)) {
            mid = std::next(left, std::distance(left, right) / 2);
            if (mid->getCl().getUcCode() == nom) {
                i = 0;
                break;
            } else if (mid->getCl().getUcCode() < nom) {
                left = std::next(mid);
            } else {
                right = std::prev(mid);
            }
        }

        if (i == 1) {
            cout << "UcCode inválido introduza outro UcCode ou escreva 'q' para retroceder" << endl;
            nom = get_num();
            if (nom == "q") {
                back();
                break;
            }
            left = classes.begin();
            right = prev(classes.end());
        }
    }

    auto pos2 = mid;
    pos2--;
    while (mid->getCl().getUcCode() == nom) {
        out.push_back(*mid);
        mid++;
    }
    while (pos2->getCl().getUcCode() == nom) {
        out.push_back(*pos2);
        pos2--;
    }

    if(i_==0){
        string l;
        cout << "1.Classes | 2.Class_With_Most_students | 3.Back" << endl;

        while(true){
            cin >> l;
            cin.clear();
            if (l == "1") {
                for (auto at : out) {
                    std::string type = at.getType();

                    // Remove trailing carriage return ('\r') characters
                    while (!type.empty() && type.back() == '\r') {
                        type.pop_back();
                    }
                    cout << at.getCl().getClassCode() << "-" << type << ", ";
                }
                cout << endl;
                back();
                break;
            } else if (l == "2") {
                break;
                // Implement functionality for "Class_With_More_students" here.
            }else if (l == "3"){
                back();
                break;
            }else{
                cout << "Select one of the options" << "\n";
            }
        }

    }

}

/**
 * @brief Navigate back to a previous state.
 */
void SearchUC::back() {
    this->i_ = 1;
}

/**
 * @brief Get a UcCode from user input.
 * @return The entered UcCode as a string.
 */
string SearchUC::get_num() {
    string l;
    cout << "Introduza o UcCode: ";
    cin >> l;
    cin.clear();
    return l;
}