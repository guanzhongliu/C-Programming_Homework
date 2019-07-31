//
// Created by Septieme on 2019/7/29.
//

#include <libloaderapi.h>
#include <io.h>
#include "GradeSystem.h"
#include "iostream"
#include "fstream"


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
    char buff[1000];
    _getcwd(buff, 1000);
    std::cout << "请在当前提示的目录内建立一个名为\"scores.txt\" 的文本文档(建议使用GBK编码，UTF-8可能会导致出现乱码)， 并按照指定格式输入成绩" << std::endl;
    std::cout << "输入要求: 第一行为输入的学生数量, 从第二行开始为每位学生的姓名、学号和科目数量n" << std::endl;
    std::cout << buff << std::endl;
    std::cout << "以下n行依照：科目  科目学分  成绩  课程类型（1必修 0选修）的格式输入成绩" << std::endl;
    std::cout << "文档编辑完毕后输入任意字符开始录入" << std::endl;
    std::string move;
    std::cin >> move;
    strcat(buff, "\\scores.txt");//在当前路径后添加子路径
    if (freopen(buff, "r", stdin) == nullptr) {
        std::cout << "文件不存在！" << std::endl;
        return;
    }
    int t;
    std::cin >> t;
    for (int j = 0; j < t; j++) {
        std::string name, id, sub;
        int num;
        std::cin >> name >> id >> num;
        students.push_back(Profile(name, id));
        Profile a = students.back();
        for (int i = 0; i < num; i++) {
            double credit;
            int grade, dir;
            std::cin >> sub >> credit >> grade >> dir;
            try {
                if (std::cin.fail())
                    throw 1;
            }                   // 异常处理 防止出现输入格式错误导致程序崩溃
            catch (int) {
                std::cin.clear();
                std::cin.sync();
                std::cout << "学生 " << a.name << " 的" << "科目 " << sub << " 输入格式出现了错误，读取过程结束" << std::endl;
                students.pop_back();   // 输入错误的学生信息将被删除
                return;
            }
            Subject subject(sub, credit, grade, dir);
            if (subject.dir == 1) {
                a.addCommonSubject(subject);
                a.num_com++;
            } else {
                a.addElectiveSubject(subject);
                a.num_elec++;
            }
        }
        std::cout << "您本次为学生 " << a.name << " 登记了 " << a.num_com << " 门必修课成绩和 " << a.num_elec << " 门选修课成绩"
                  << std::endl;
    }
    fclose(stdin);
}

void GradeSystem::addInformationByTap() {
    std::string name, id;
    char flag;
    std::cout << "请输入该学生的姓名：" << std::endl;
    std::cin >> name;
    std::cout << "请输入该学生的学号：" << std::endl;
    std::cin >> id;
    std::cout << "您输入的学生信息为: 姓名: " << name << " 学号： " << id << std::endl;
    std::cout << "正确请输入 1 ， 有误请输入 2 并重新输入，返回请输入 0" << std::endl;
    std::cin >> flag;
    switch (flag - '0') {
        case 0:
            return;
        case 1:
            break;
        case 2:
            addInformationByTap();
            return;
    }
    students.push_back(Profile(name, id));
    std::cout << "请按照如下格式输入该学生的成绩：" << std::endl;
    std::string sub;
    int grade, dir;
    double credit;
    std::cout << "科目  科目学分  成绩  课程类型（1必修 0选修）(四个项目均为0则代表结束）" << std::endl;
    while (1) {
        std::cin >> sub >> credit >> grade >> dir;
        try {
            if (std::cin.fail())
                throw 1;
        }                   // 异常处理 防止出现输入格式错误导致程序崩溃
        catch (int) {
            std::cin.clear();
            std::cin.sync();
            std::cout << "输入格式出现了错误, 请从科目名称开始重新输入当前科目：" << std::endl;
            continue;
        }
        if (sub == "0" && grade == 0 && credit == 0 && dir == 0)
            break;
        Subject subject(sub, credit, grade, dir);

        if (subject.dir == 1) {
            students.back().addCommonSubject(subject);
            students.back().num_com++;
        } else {
            students.back().addElectiveSubject(subject);
            students.back().num_elec++;
        }
    }
    Profile a = students.back();
    std::cout << "您本次为学生 " << a.name << " 登记了 " << a.num_com << " 门必修课成绩和 " << a.num_elec << " 门选修课成绩" << std::endl;

}

void GradeSystem::accountScore(std::string name) {

}

void GradeSystem::addStudent() {
    std::cout << "***************************************************************************" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓〓  ☆          学生信息录入          ☆  〓〓〓〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓" << std::endl;
    std::cout << "〓〓〓〓〓〓〓〓〓★  ☆         1.通过输入增加(单人)   ☆  ★〓〓〓〓〓〓〓〓〓" << std::endl;
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
