//
// Created by Septieme on 2019/7/29.
//

#ifndef HOMEWORK_METHOD_H
#define HOMEWORK_METHOD_H

#include <string>

// 此类中大多是主界面的一些方法
// 以抽象类的方式去约束限定成绩管理系统必须完善的一些功能，起到接口的做用
class Method {
public:
    virtual void introduction() = 0;

    virtual void addStudent() = 0;

    virtual void searchById() = 0;

    virtual void searchByName() = 0;

    virtual void addInformationByFile() = 0;

    virtual void addInformationByTap() = 0;

    virtual void accountScore(std::string name) = 0;

    virtual void addScore(std::string name, double GPA, int grade, double credit, int dir) = 0;

    virtual void searchStudent() = 0;

    virtual void sortScores() = 0;

    virtual void subjectInfo() = 0;

    virtual void studentRank() = 0;

    virtual void exit2Menu() = 0;

    virtual void readFromLocal() = 0;
};


#endif //HOMEWORK_METHOD_H
