//
// Created by Septieme on 2019/7/26.
//

#include "Profile.h"

Profile::Profile() {

}

Profile::Profile(std::string n, std::string id) {
    name = n;
    this->id = id;
}

void Profile::addCommonSubject(const Subject &sub) {
    common.push_back(sub);
}

void Profile::addElectiveSubject(const Subject &sub) {
    elective.push_back(sub);
}

void Profile::getCommonSubjects(std::vector<Subject> &cs) {
    for (int i = 0; i < common.size(); i++) {
        cs.push_back(common[i]);
    }
}

void Profile::getElectiveSubjects(std::vector<Subject> &es) {
    for (int i = 0; i < elective.size(); i++) {
        es.push_back(elective[i]);
    }

}

void Profile::addCommonSubjects(std::vector<Subject> &cs) {
    for (int i = 0; i < cs.size(); i++) {
        common.push_back(cs[i]);
    }
}

void Profile::addElectiveSubjects(std::vector<Subject> &es) {
    for (int i = 0; i < es.size(); i++) {
        elective.push_back(es[i]);
    }
}

void Profile::setGPA(double G) {
    overall_GPA = G;
}

void Profile::setGrade(double g) {
    overall_grade = g;
}

void Profile::setCredit(double c) {
    overall_credit = c;
}

void Profile::setRank(int n) {
    overall_rank = n;
}

double Profile::getGPA() {
    return overall_GPA;
}

double Profile::getGrade() {
    return overall_grade;
}

double Profile::getCredit() {
    return overall_credit;
}

double Profile::getRank() {
    return overall_rank;
}

void Profile::getAll(double &G, double &g, double &c, int &r) {
    G = overall_GPA;
    g = overall_grade;
    c = overall_credit;
    r = overall_rank;
}

void Profile::setAll(double G, double g, double c, int r) {
    overall_GPA = G;
    overall_grade = g;
    overall_credit = c;
    overall_rank = r;
}



