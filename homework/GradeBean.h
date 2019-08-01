//
// Created by Septieme on 2019/8/2.
//

#ifndef HOMEWORK_GRADEBEAN_H
#define HOMEWORK_GRADEBEAN_H

#include <string>

class GradeBean {
public:
    std::string name;
    std::string id;
    int grade;
    double GPA;

    GradeBean();

    GradeBean(int g, double G);

    GradeBean(std::string name, std::string id, int g, double G);

};


#endif //HOMEWORK_GRADEBEAN_H
