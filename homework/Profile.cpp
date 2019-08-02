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

GradeBean Profile::getSubjectDetail(std::string name, int dir) {
    if (dir == 1) {
        for (int i = 0; i < common.size(); i++) {
            if (common[i].name == name) {
                return GradeBean(this->name, this->id, common[i].getGrade(), common[i].getGPA());
            }
        }
    } else {
        for (int i = 0; i < elective.size(); i++) {
            if (elective[i].name == name) {
                return GradeBean(this->name, this->id, elective[i].getGrade(), elective[i].getGPA());
            }
        }
    }

    return GradeBean("", "", 0, 0);
}

GradeBean Profile::deleteCourse(std::string name, int dir) {
    int i;
    if (dir == 1) {
        for (i = 0; i < common.size(); i++) {
            if (common[i].name == name) {
                int grade = common[i].getGrade();
                double GPA = common[i].getGPA(), credit = common[i].getCredit(), t_g, t_G;
                common.erase(common.begin() + i);  // 删除成绩
                num_com--;
                t_g = overall_grade * overall_credit;
                t_G = overall_GPA * overall_credit;
                overall_credit -= credit;
                overall_grade = (t_g - grade * credit) / overall_credit;
                overall_GPA = (t_G - GPA * credit) / overall_credit;
                return GradeBean(grade, GPA);
            }
        }
    } else {
        for (i = 0; i < elective.size(); i++) {
            if (elective[i].name == name) {
                int grade = elective[i].getGrade();
                double GPA = elective[i].getGPA(), credit = elective[i].getCredit(), t_g, t_G;
                elective.erase(elective.begin() + i);  // 删除成绩
                num_elec--;
                t_g = overall_grade * overall_credit;
                t_G = overall_GPA * overall_credit;
                overall_credit -= credit;
                overall_grade = (t_g - grade * credit) / overall_credit;
                overall_GPA = (t_G - GPA * credit) / overall_credit;
                return GradeBean(grade, GPA);
            }
        }
    }
    return GradeBean();
}

GradeBean Profile::fixCourse(std::string name, int dir, int value) {
    int i;
    if (dir == 1) {
        for (i = 0; i < common.size(); i++) {
            if (common[i].name == name) {
                int grade = common[i].getGrade() - value;
                double pGPA = common[i].getGPA(), credit = common[i].getCredit(), t_g, t_G;
                common[i].setGrade(value);
                double GPA = pGPA - common[i].getGPA();
                t_g = overall_grade * overall_credit;
                t_G = overall_GPA * overall_credit;
                overall_grade = (t_g - grade * credit) / overall_credit;
                overall_GPA = (t_G - GPA * credit) / overall_credit;
                return GradeBean(grade, GPA);
            }
        }
    } else {
        for (i = 0; i < elective.size(); i++) {
            if (elective[i].name == name) {
                int grade = elective[i].getGrade() - value;
                double pGPA = elective[i].getGPA(), credit = elective[i].getCredit(), t_g, t_G;
                elective[i].setGrade(value);
                double GPA = pGPA - elective[i].getGPA();
                t_g = overall_grade * overall_credit;
                t_G = overall_GPA * overall_credit;
                overall_grade = (t_g - grade * credit) / overall_credit;
                overall_GPA = (t_G - GPA * credit) / overall_credit;
                return GradeBean(grade, GPA);
            }
        }
    }


    return GradeBean();
}


