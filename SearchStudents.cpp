//
// Created by avareno on 10/25/23.
//

#include "SearchStudents.hpp"
#include <iostream>
#include <vector>
using namespace std;

SearchStudents::SearchStudents(const set<Student_class> &students_classes, const list<Class> &classes) {


    string num_mec = get_num();
    vector<Student_class> out; // output vector of the search
    Student_class c = Student_class(num_mec, "", "", "");
    auto pos = students_classes.lower_bound(c);
    while(pos->getStudentCode()!=num_mec)//resolver o bug do buffer
    {

        cout << "Número mecanográfico inválido introduza outro número ou escreva q para retroceder" << "\n";
        num_mec = get_num();
        if(num_mec == "q")
        {
            back();
            break;
        }
        c = Student_class(num_mec, "", "", "");
        auto pos = students_classes.lower_bound(c);


    }
    if(pos->getStudentCode()==num_mec)//push to vector out all instances of student where StudentCode = num_mec
    {
        auto pos2 = pos;
        pos2--;
        while(pos->getStudentCode()==num_mec)
        {
            out.push_back(*pos);
            pos++;
        }
        while(pos2->getStudentCode()==num_mec)
        {
            out.push_back(*pos2);
            pos2--;
        }

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