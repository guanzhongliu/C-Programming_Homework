//
// Created by Septieme on 2019/7/26.
//

#ifndef HOMEWORK_SUBJECT_H
#define HOMEWORK_SUBJECT_H

#include "bits/stdc++.h"

//此类用于保存成绩相关的信息

class Subject {
private:    // 将成绩等不希望被直接访问的内容封装起来
    double credit;  // 科目学分
    int grade;      // 科目成绩
    double GPA;     // 科目绩点
public:
    std::string name;   // 科目名称
    int dir;      // 科目类别，用于区分其是大家都上的必修还是自选的选修
    Subject(std::string n, double c, int g, double G, int dir);

    Subject(std::string n, double c, int g, int dir);

    void setName(std::string n);

    void setCredit(double c);

    void setGrade(int g);

    void setGPA(double G);

    void setSubject(std::string n, double c, int g, double G, int dir);

    void setSubject(std::string n, double c, int g, int dir);  // 加入出现需要自行计算GPA的情况，故重载函数

    std::string getName();

    double getCredit();

    int getGrade();

    double getGPA();
};


#endif //HOMEWORK_SUBJECT_H
