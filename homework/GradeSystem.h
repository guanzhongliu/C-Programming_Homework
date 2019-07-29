//
// Created by Septieme on 2019/7/29.
//

#ifndef HOMEWORK_GRADESYSTEM_H
#define HOMEWORK_GRADESYSTEM_H

//成绩管理系统
#include "vector"
#include "Method.h"
#include "Profile.h"
#include "StacticalScore.h"

class GradeSystem : Method {
private:
    std::vector<Profile> students;
    std::vector<StacticalScore> scores;
public:
    void introduction() override;

    void searchById() override;

    void searchByName() override;

    void addInformationByFile() override;

    void addInformationByTap() override;

    void accountScore(std::string name) override;

    void addStudent() override;

    void searchStudent() override;
};


#endif //HOMEWORK_GRADESYSTEM_H
