//
// Created by Septieme on 2019/7/26.
//

#include "Subject.h"

// 为了避免在函数调用时出现一些莫名其妙的错误，故此处没有使用std命名空间

// 因为部分参数为private，故使用初始化列表
Subject::Subject(std::string n, double c, int g, double G, int dir) : name(n), credit(c), grade(g), GPA(G), dir(dir) {}

Subject::Subject(std::string n, double c, int g, int dir) : name(n), credit(c), grade(g), dir(dir) {}

void Subject::setName(std::string n) {
    name = n;
}

void Subject::setCredit(double c) {
    credit = c;
}

void Subject::setGrade(int g) {
    grade = g;
}

void Subject::setGPA(double G) {
    GPA = G;
}

void Subject::setSubject(std::string n, double c, int g, double G, int dir) {
    name = n;
    credit = c;
    grade = g;
    GPA = G;
    this->dir = dir;
}

void Subject::setSubject(std::string n, double c, int g, int dir) {
    name = n;
    credit = c;
    grade = g;
    this->dir = dir;
}

std::string Subject::getName() {
    return name;
}

int Subject::getGrade() {
    return grade;
}

double Subject::getCredit() {
    return credit;
}

double Subject::getGPA() {
    return GPA;
}



