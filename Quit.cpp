/**
 * @file Quit.cpp
 * @brief Implementation of the Quit class for performing exit operations.
 */

#include "Quit.hpp"
using namespace std;

/**
 * @brief Constructor for the Quit class.
 *
 * This constructor performs exit operations, including writing data to output files.
 *
 * @param students_classes A set of Student_class objects.
 * @param classes_per_uc A set of Class_per_uc objects.
 * @param classes A list of Class objects.
 * @param change_log A queue of Change objects.
 */

Quit::Quit(set<Student_class> &students_classes, set<Class_per_uc> &classes_per_uc, list<Class>&classes, queue<Change> &change_log){
    ofstream outputFile1("output/classes_altered.csv");

    if (outputFile1.is_open()) {
        outputFile1 << "ClassCode,UcCode,Weekday,StartHour,Duration,Type" << endl;
        for (const Class& element : classes) {
            outputFile1 << element.getCl().getClassCode() << ","
                       << element.getCl().getUcCode() << ","
                       << element.getWeekday() << ","
                       << element.getStartHour() << ","
                       << element.getDuration() << ","
                       << element.getType() << endl;
        }
        outputFile1.close();
        cout << "Data successfully written in classes_altered.csv" << endl;
    }else{cout << "Failed to open file" << endl; return;}

    ofstream outputFile2("output/classes_per_uc_altered.csv");

    if (outputFile2.is_open()) {
        outputFile2 << "UcCode,ClassCode" << endl;
        for (const Class_per_uc& element : classes_per_uc) {
            outputFile2 << element.getUcCode() << ","
                        << element.getClassCode() << endl;
        }
        outputFile2.close();
        cout << "Data successfully written in classes_per_uc_altered.csv" << endl;
    }else{cout << "Failed to open file" << endl; return;}

    ofstream outputFile3("output/students_classes_altered.csv");

    if (outputFile3.is_open()) {
        outputFile3 << "StudentCode,StudentName,UcCode,ClassCode" << endl;
        for (const Student_class& element : students_classes) {
            outputFile3 << element.getStudentCode() << ","
                        << element.getStudentName() << ","
                        << element.getCl().getUcCode() << ","
                        << element.getCl().getClassCode() << endl;
        }
        outputFile3.close();
        cout << "Data successfully written in students_classes_altered.csv" << endl;
    }else{cout << "Failed to open file" << endl; return;}

    ofstream outputFile4("output/change_log.csv");

    if (outputFile4.is_open()) {
        outputFile4 << "Operation,StudentCode,PrevUcCode,PrevClassCode,FinalUcCode,FinalClassCode" << endl;
        while (!change_log.empty()) {
            outputFile4 << change_log.front().getOp() << ","
                        << change_log.front().getSnum() << ","
                        << change_log.front().getPrevCl().getUcCode() << ","
                        << change_log.front().getPrevCl().getClassCode() << ","
                        << change_log.front().getPostCl().getUcCode() << ","
                        << change_log.front().getPostCl().getClassCode() << endl;
            change_log.pop();
        }
        outputFile4.close();
        cout << "Data successfully written in change_log.csv" << endl;
    }else{cout << "Failed to open file" << endl; return;}
}