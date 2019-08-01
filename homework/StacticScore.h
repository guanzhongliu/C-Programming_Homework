//
// Created by Septieme on 2019/7/29.
//

#ifndef HOMEWORK_STACTICSCORE_H
#define HOMEWORK_STACTICSCORE_H

#include <string>

class StacticScore {
public:
    std::string name;
    double GPA = 0;
    double grade = 0;
    double credit;
    int dir;        // 课程类型（必修/选修）
    int studentNum = 0;
    StacticScore();
    StacticScore(std::string name, double GPA, double grade, double credit, int dir);       // 构造函数
};


#endif //HOMEWORK_STACTICSCORE_H
