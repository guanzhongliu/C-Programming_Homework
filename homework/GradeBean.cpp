//
// Created by Septieme on 2019/8/2.
//

#include "GradeBean.h"

GradeBean::GradeBean(int g, double G) : grade(g), GPA(G) {}

GradeBean::GradeBean() {

}

GradeBean::GradeBean(std::string name, std::string id, int g, double G) : name(name), id(id), grade(g), GPA(G) {

}
