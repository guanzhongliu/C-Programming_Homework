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
    if (g >= 90)
        GPA = 4.0;
    else if (g >= 85)
        GPA = 3.7;
    else if (g >= 82)
        GPA = 3.3;
    else if (g >= 78)
        GPA = 3.0;
    else if (g >= 75)
        GPA = 2.7;
    else if (g >= 72)
        GPA = 2.3;
    else if (g >= 68)
        GPA = 2, 0;
    else if (g >= 64)
        GPA = 1.5;
    else if (g >= 63)
        GPA = 1.0;
    else
        GPA = 0;        //依照绩点计算规则
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

void Subject::setRank(int r) {
    rank = r;
}

int Subject::getRank() {
    return rank;
}



