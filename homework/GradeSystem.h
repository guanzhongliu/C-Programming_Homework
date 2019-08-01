//
// Created by Septieme on 2019/7/29.
//

#ifndef HOMEWORK_GRADESYSTEM_H
#define HOMEWORK_GRADESYSTEM_H

//成绩管理系统
#include "vector"
#include "Method.h"
#include "Profile.h"
#include "StacticScore.h"

class GradeSystem : Method {
private:
    std::vector<Profile> students;
    std::vector<StacticScore> scores;
public:
    void introduction() override;

    void searchById() override;

    void searchByName() override;

    void addInformationByFile() override;

    void addInformationByTap() override;

    void addScore(std::string name, double GPA, int grade, double credit, int dir) override;

    void addStudent() override;

    void searchStudent() override;

    void sortScores() override;

    void studentRank() override;

    void subjectInfo() override;

    void exit2Menu() override;

    void readFromLocal() override;
};


#endif //HOMEWORK_GRADESYSTEM_H
