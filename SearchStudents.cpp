//
// Created by avareno on 10/25/23.
//

#include "SearchStudents.hpp"
#include <iostream>
#include <vector>
using namespace std;

SearchStudents::SearchStudents(const set<Student_class> &students_classes, const list<Class> &classes) {
    vector<Student_class> out; // output vector of the search
    string num_mec = get_num();
    int i = 1;
    do{

        auto it = students_classes.lower_bound(Student_class(num_mec, "", "", ""));

        // Check if the student was found
        if (it != students_classes.end() && it->getStudentCode() == num_mec) {
            i=0;
        } else {
            i=1;
            cout << "UcCode inválido introduza outro UcCode ou escreva q para retroceder" << endl;
            cin >> num_mec;
            if(num_mec == "q")
            {
                back();
                i=2;
                break;
            }


        }

    }while(i==1);

    auto lower = students_classes.lower_bound(Student_class(num_mec, "", "", ""));
    auto upper = students_classes.upper_bound(Student_class(num_mec, "", "", ""));
    for (auto it = lower; it != upper; ++it) {
        out.push_back(*it);
    }

    if(i==0)
    {
        string sr;
        cout << "UC's | Num_de_UC's | Schedule | Menu" << "\n";
        while(true){                // resolver bug de imprimir várias vezes quandfdo o cin tem vários espaços
            cin >> sr;
            cin.clear();
            if(sr == "Num_de_UC's")//search number of UC's the student has
            {
                cout << out.size();
                break;
            }else if(sr == "UC's")// search all the name sof the UC's
            {
                for(Student_class st: out)
                {
                    cout << st.getCl().getUcCode() << " ";
                }
                break;
            }else if(sr == "Schedule")//search student schedule
            {
                for(Student_class at: out)
                {

                }
                break;
            }else if(sr == "Menu")//go back to menu
            {
                back();
                break;
            }
            else{//input error
                cout << "Selecione uma opção" << "\n";
            }
        }
    }




    cout << "\n";



}

int SearchStudents::getI() const {
    return i;
}

void SearchStudents::back() {
    this->i=1;
}
string SearchStudents::get_num() {
    string l;
    cout << "Introduza o número mecanográfico: " ;
    cin >> l;
    cin.clear();
    return l;
}