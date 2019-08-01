//
// Created by Septieme on 2019/7/29.
//

#include "StacticScore.h"

StacticScore::StacticScore(std::string name, double GPA, double grade, double credit, int dir) {
    this->name = name;
    this->GPA = GPA;
    this->grade = grade;
    this->credit = credit;
    this->dir = dir;
    studentNum = 1;
}
