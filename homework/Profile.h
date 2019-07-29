//
// Created by Septieme on 2019/7/26.
//

#ifndef HOMEWORK_PROFILE_H
#define HOMEWORK_PROFILE_H

#include "bits/stdc++.h"
#include "Subject.h"

class Profile {
private:
    std::vector<Subject> common;
    std::vector<Subject> elective;
    double overall_GPA;
    double overall_grade;
public:
    std::string name;
    std::string id;
    Profile(std::string n, std::string id);
    void addCommonSubjects(Subject sub);
    void addElectiveSubjects(Subject sub);
    void getCommonSubjects(std::vector<Subject>& cs);
    void getElectiveSubjects(std::vector<Subject>& es);
};


#endif //HOMEWORK_PROFILE_H
