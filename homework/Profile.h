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
    int overall_rank;
public:
    int num_elec = 0;
    int num_com = 0;
    std::string name;
    std::string id;

    Profile(std::string n, std::string id);

    void addCommonSubject(Subject sub);

    void addElectiveSubject(Subject sub);

    void addCommonSubjects(std::vector<Subject> &cs);

    void addElectiveSubjects(std::vector<Subject> &es);

    void getCommonSubjects(std::vector<Subject> &cs);

    void getElectiveSubjects(std::vector<Subject> &es);
};


#endif //HOMEWORK_PROFILE_H
