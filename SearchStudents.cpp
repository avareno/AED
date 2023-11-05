#include "SearchStudents.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <stack>

/**
 * @file SearchStudents.cpp
 * @brief Implementation of the SearchStudents class for searching students and their classes.
 */

using namespace std;

/**
 * @brief Remove carriage return ('\r') characters from a string.
 *
 * This function removes any '\r' characters from the input string and returns the modified string.
 *
 * @param input The input string that may contain '\r' characters.
 * @return A string with '\r' characters removed.
 */
string removeCarriageReturn(const std::string& input) {
    std::string result;
    for (char c : input) {
        if (c != '\r') {
            result += c;
        }
    }
    return result;
}

/**
 * @brief Constructor for the SearchStudents class.
 *
 * Initializes the search process for students and their classes.
 *
 * @param students_classes Set of Student_class objects.
 * @param classes List of Class objects.
 */
SearchStudents::SearchStudents(const set<Student_class> &students_classes, const list<Class> &classes) {
    vector<Student_class> out; // Output vector of the search
    string num_mec = get_num();
    int i = 1;
    auto it = students_classes.lower_bound(Student_class(num_mec, "", "", ""));

    do {
        it = students_classes.lower_bound(Student_class(num_mec, "", "", ""));

        // Check if the student was found
        if (it != students_classes.end() && it->getStudentCode() == num_mec) {
            i = 0;
        } else {
            i = 1;
            cout << "Numero mecanográfico inválido introduza outro UC Code ou escreva 'q' para retroceder." << endl;
            cin >> num_mec;
            if (num_mec == "q") {
                back();
                break;
            }
        }

    } while (i == 1);

    if (i_ == 0) {
        auto pos2 = it;
        pos2--;
        while (it->getStudentCode() == num_mec) {
            out.push_back(*it);
            it++;
        }
        while (pos2->getStudentCode() == num_mec) {
            out.push_back(*pos2);
            pos2--;
        }

        string sr;
        cout << "1. UC's | 2. Classes Numbers | 3. Schedule | 4. Menu" << "\n";
        while (true) {
            cin >> sr;
            cin.clear();
            if (sr == "1") {
                // Search number of UC's the student has
                cout << out.size();
                break;
            } else if (sr == "2") {
                // Search all the names of the UC's
                for (Student_class st : out) {
                    cout << st.getCl().getUcCode() << "->" << st.getCl().getClassCode() << endl;
                }
                break;
            } else if (sr == "3") {
                // Search student schedule
                stack<string> mon, tue, wed, thu, fri;
                for (Student_class at : out) {
                    string l;
                    Class_per_uc cl_uc;
                    cl_uc = at.getCl();
                    for (Class at2 : classes) {
                        if (at2.getCl() == cl_uc) {
                            ostringstream out;
                            // Parse start hour
                            istringstream startStream(at2.getStartHour());
                            double startDouble;
                            startStream >> startDouble;
                            int startHours = static_cast<int>(startDouble);
                            int startMinutes = static_cast<int>((startDouble - startHours) * 60);

                            // Parse duration
                            istringstream durationStream(at2.getDuration());
                            double duration;
                            durationStream >> duration;

                            // Calculate the end time in minutes
                            int startTotalMinutes = startHours * 60 + startMinutes;
                            int endTotalMinutes = startTotalMinutes + static_cast<int>(duration * 60);

                            // Convert the end time to hours and minutes
                            int endHours = endTotalMinutes / 60;
                            int endMinutes = endTotalMinutes % 60;

                            out << "Start Hour: " << setfill('0') << setw(2) << startHours << ":" << setw(2) << startMinutes << ", End Hour: " << setfill('0') << setw(2) << endHours << ":" << setw(2) << endMinutes << ", Type: " << removeCarriageReturn(at2.getType()) << ", UcCode: " << cl_uc.getUcCode() << endl;
                            l = out.str();
                            if (at2.getWeekday() == "Monday") mon.push(l);
                            else if (at2.getWeekday() == "Tuesday") tue.push(l);
                            else if (at2.getWeekday() == "Wednesday") wed.push(l);
                            else if (at2.getWeekday() == "Thursday") thu.push(l);
                            else if (at2.getWeekday() == "Friday") fri.push(l);
                        }
                    }
                }
                if (!mon.empty()) cout << "                   Monday" << endl;
                while (!mon.empty()) {
                    cout << mon.top();
                    mon.pop();
                }
                if (!tue.empty()) cout << "                   Tuesday" << endl;
                while (!tue.empty()) {
                    cout << tue.top();
                    tue.pop();
                }

                if (!wed.empty()) cout << "                   Wednesday" << endl;
                while (!wed.empty()) {
                    cout << wed.top();
                    wed.pop();
                }

                if (!thu.empty()) cout << "                   Thursday" << endl;
                while (!thu.empty()) {
                    cout << thu.top();
                    thu.pop();
                }

                if (!fri.empty()) cout << "                   Friday" << endl;
                while (!fri.empty()) {
                    cout << fri.top();
                    fri.pop();
                }
                break;
            } else if (sr == "4") {
                // Go back to the menu
                back();
                break;
            } else {
                // Input error
                cout << "Select one of the options" << "\n";
            }
        }
    }
    cout << "\n";
}

/**
 * @brief Marks the search process as completed.
 */
void SearchStudents::back() {
    this->i_ = 1;
}

/**
 * @brief Get the student's code input from the user.
 *
 * @return The student's code as a string.
 */
string SearchStudents::get_num() {
    string l;
    cout << "Enter the Student Code: ";
    cin >> l;
    cin.clear();
    return l;
}


