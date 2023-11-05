/**
 * @file SearchUC.cpp
 * @brief Implementation of the SearchUC class.
 */

#include "SearchUC.hpp"
#include <iostream>
#include <vector>
#include <stack>

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
            cout << "Please enter a valid UcCode or 'q' if you wish to return." << endl;
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
        string choice;
        cout << "1.Classes | 2. Number of people in the UC| 3.Class(es) with most students | 4.Sort Classes | 5.Back" << endl;

        while(true){
            cin >> choice;
            cin.clear();
            if (choice == "1") {
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
            } else if (choice == "2") {
                int res = 0;
                for(Class_per_uc at: classes_per_uc){
                    if(at.getUcCode()==nom){
                        res+=at.getSize();
                    }
                }
                cout << res <<endl;
                back();
                break;

            }else if (choice == "3"){
                int f = 0;
                stack<Class_per_uc> res;
                for(Class_per_uc at: classes_per_uc){
                    if(at.getUcCode()==nom){
                        if(at.getSize()>=f){
                            f=at.getSize();
                            res.push(at);
                        }
                    }
                }
                cout << "Class(es) with most students " << endl;
                while(res.top().getSize()==f){
                    cout << res.top().getClassCode() << endl;
                    res.pop();
                }
                back();
                break;
            }if (choice == "4") {
                string sortCriteria;
                cout << "Select sorting criteria: " << endl;
                cout << "1. Sort by Class Code" << endl;
                cout << "2. Sort by Size" << endl;
                cout << "Enter your choice: ";
                cin >> sortCriteria;

                // Create a new sorted list of classes
                list<Class> sortedClasses = classes;

                // Sort the new list based on the selected criteria
                if (sortCriteria == "1") {
                    // Sort by Class Code
                    sortedClasses.sort([](const Class& a, const Class& b) {
                        return a.getCl().getClassCode() < b.getCl().getClassCode();
                    });
                } else if (sortCriteria == "2") {
                    sortedClasses.sort([](const Class& a, const Class& b) {
                        return a.getCl().getSize()< b.getCl().getSize();
                    });
                } else {
                    cout << "Invalid choice. Please select a valid sorting criteria." << endl;
                    back();
                    return; // Exit the function to prevent displaying unsorted data.
                }

                // Display the sorted list of classes
                cout << "Sorted Classes:" << endl;
                for (const auto& classInfo : sortedClasses) {
                    if(classInfo.getCl().getUcCode()==nom)cout << classInfo.getCl().getUcCode() << " " << classInfo.getCl().getClassCode()<< " " <<  classInfo.getType() << endl;
                }

                back();
                break;
            }
            else if (choice == "5"){
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
    cout << "Enter the UcCode: ";
    cin >> l;
    cin.clear();
    return l;
}