//
// Created by avareno on 10/25/23.
//

#include "SearchStudents.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <stack>
using namespace std;

SearchStudents::SearchStudents(const set<Student_class> &students_classes, const list<Class> &classes) {
    vector<Student_class> out; // output vector of the search
    string num_mec = get_num();
    int i = 1;
    auto it = students_classes.lower_bound(Student_class(num_mec, "", "", ""));

    do{

        it = students_classes.lower_bound(Student_class(num_mec, "", "", ""));

        // Check if the student was found
        if (it != students_classes.end() && it->getStudentCode() == num_mec) {
            i=0;
        } else {
            i=1;
            cout << "Numero mecanográfico inválido introduza outro UC Code ou escreva 'q' para retroceder." << endl;
            cin >> num_mec;
            if(num_mec == "q")
            {
                back();
                break;
            }
        }

    }while(i==1);



    if(i_==0)
    {
        auto pos2 = it;
        pos2--;
        while(it->getStudentCode()==num_mec)
        {
            out.push_back(*it);
            it++;
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
                    cout << st.getCl().getUcCode() << "->" << st.getCl().getClassCode() << endl;
                }
                break;
            }else if(sr == "Schedule")//search student schedule
            {
                stack<string> mon,tue,wed,thu,fri;
                for(Student_class at: out) {
                    string l;
                    Class_per_uc cl_uc;
                    cl_uc = at.getCl();
                    for (Class at2: classes) {
                        if (at2.getCl() == cl_uc) {
                            ostringstream out;
                            // Parse start hour
                            std::istringstream startStream(at2.getStartHour());
                            int startHours, startMinutes;
                            char colon;
                            startStream >> startHours >> colon >> startMinutes;

                            // Parse duration
                            std::istringstream durationStream(at2.getDuration());
                            double duration;
                            durationStream >> duration;
                            // Calculate the end time in minutes
                            int startTotalMinutes = startHours * 60 + startMinutes;
                            int endTotalMinutes = startTotalMinutes + static_cast<int>(duration * 60);

                            // Convert the end time to hours and minutes
                            int endHours = endTotalMinutes / 60;
                            int endMinutes = endTotalMinutes % 60;


                            out << "Start Hour: " << setfill('0') << setw(2) << startHours << ":" << setw(2) << startMinutes << ", End Hour: " << setfill('0') << setw(2) << endHours << ":" << setw(2) << endMinutes << ", Type: " <<at2.getType().substr(0, at2.getType().length() - 1)<< ", UcCode: "<<cl_uc.getUcCode()<<endl;
                            l = out.str();
                            if(at2.getWeekday()=="Monday")mon.push(l);
                            else if(at2.getWeekday()=="Tuesday")tue.push(l);
                            else if(at2.getWeekday()=="Wednesday")wed.push(l);
                            else if(at2.getWeekday()=="Thursday")thu.push(l);
                            else if(at2.getWeekday()=="friday")fri.push(l);
                        }
                    }
                }
                if(!mon.empty())cout << "                   Monday" << endl;
                while(!mon.empty()){
                    cout << mon.top();
                    mon.pop();
                }
                if(!tue.empty())cout << "                   Tuesday" << endl;
                while(!tue.empty()){
                    cout << tue.top();
                    tue.pop();
                }

                if(!wed.empty())
                    cout << "                   Wednesday" << endl;
                while(!wed.empty()){
                    cout << wed.top();
                    wed.pop();
                }

                if(!thu.empty())cout << "                   Thursday" << endl;
                while(!thu.empty()){
                    cout << thu.top();
                    thu.pop();
                }

                if(!fri.empty())cout << "                   Friday" << endl;
                while(!fri.empty()){
                    cout << fri.top();
                    fri.pop();
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
    return i_;
}

void SearchStudents::back() {
    this->i_=1;
}

string SearchStudents::get_num() {
    string l;
    cout << "Introduza o número mecanográfico: " ;
    cin >> l;
    cin.clear();
    return l;
}


