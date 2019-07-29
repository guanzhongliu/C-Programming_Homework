//
// Created by Septieme on 2019/7/29.
//

#include "GradeSystem.h"
#include "iostream"

void GradeSystem::introduction() {
    std::cout << "***************************************************************************" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓〓  ☆   学 生 成 绩 管 理 系  统     ☆  〓〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         1.增加学生成绩         ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         2.显示学生成绩         ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         3.排序统计成绩         ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         4.查找学生成绩         ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         5.删除学生成绩         ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         6.修改学生成绩         ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         7.查看成绩总览         ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         0.安全退出系统         ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
}

void GradeSystem::searchById() {

}

void GradeSystem::searchByName() {

}

void GradeSystem::addInformationByFile() {

}

void GradeSystem::addInformationByTap() {
    std::cout << "" << std::endl;
}

void GradeSystem::accountScore(std::string name) {

}

void GradeSystem::addStudent() {
    std::cout << "***************************************************************************" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓〓  ☆          学生信息录入          ☆  〓〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         1.通过输入增加(少量)   ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         2.通过文件增加(大量)   ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         0.返回                ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
    char move;
    while (std::cin >> move) {
        switch (move - '0') {
            case 0:
                return;
            case 1:
                addInformationByTap();
                return;
            case 2:
                addInformationByFile();
                return;
            default:
                std::cout << " 您输入的指令不存在！" << std::endl;
                std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         1.通过输入增加(少量)   ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
                std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         2.通过文件增加(大量)   ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
                std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         0.返回                ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
        }
    }

}

void GradeSystem::searchStudent() {
    std::cout << "***************************************************************************" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓〓  ☆          学生成绩查询          ☆  〓〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         1.通过姓名查询         ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         2.通过学号查询         ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         0.返回                ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
    char move;
    while (std::cin >> move) {
        switch (move - '0') {
            case 0:
                return;
            case 1:
                searchByName();
                return;
            case 2:
                searchById();
                return;
            default:
                std::cout << " 您输入的指令不存在！" << std::endl;
                std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         1.通过姓名查询         ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
                std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         2.通过学号查询         ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
                std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         0.返回                ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
        }
    }
}
