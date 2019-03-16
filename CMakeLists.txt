cmake_minimum_required(VERSION 3.12)
project(untitled6)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled6 main.cpp Hospital/staff.h Hospital/staff.cpp Hospital/department.h Hospital/Staff-Members/doctor.h Hospital/Staff-Members/nurse.h Hospital/Staff-Members/nurse.cpp Hospital/department.cpp Hospital/Staff-Members/doctor.cpp Hospital/research_center.h Hospital/hospital.h Hospital/patient.h Hospital/visit.h Hospital/researcher.h Hospital/article.h)
