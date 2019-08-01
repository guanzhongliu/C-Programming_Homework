//
// Created by Septieme on 2019/7/26.
//

#ifndef HOMEWORK_PROFILE_H
#define HOMEWORK_PROFILE_H

#include "bits/stdc++.h"
#include "Subject.h"
#include "GradeBean.h"

class Profile {
private:
    std::vector<Subject> common;
    std::vector<Subject> elective;
    double overall_GPA = 0;
    double overall_grade = 0;
    double overall_credit = 0;
    int overall_rank = 0;
public:
    int num_elec = 0;
    int num_com = 0;
    std::string name;
    std::string id;

    Profile();

    Profile(std::string n, std::string id);

    void addCommonSubject(const Subject &sub);

    void addElectiveSubject(const Subject &sub);

    void addCommonSubjects(std::vector<Subject> &cs);

    void addElectiveSubjects(std::vector<Subject> &es);

    void getCommonSubjects(std::vector<Subject> &cs);

    void getElectiveSubjects(std::vector<Subject> &es);

    void setGPA(double G);

    void setGrade(double g);

    void setCredit(double c);

    void setRank(int n);

    double getGPA();

    double getGrade();

    double getCredit();

    double getRank();

    void getAll(double &G, double &g, double &c, int &r);

    void setAll(double G, double g, double c, int r = 0);

    GradeBean getSubjectDetail(std::string name, int dir);  // 获取科目信息

};


#endif //HOMEWORK_PROFILE_H
