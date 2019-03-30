cmake_minimum_required(VERSION 3.12)
project(untitled6)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled6 main.cpp Hospital/Staff/staff.h Hospital/Staff/staff.cpp Hospital/department.h Hospital/Staff/Type/doctor.h Hospital/Staff/Type/nurse.h Hospital/Staff/Type/nurse.cpp Hospital/department.cpp Hospital/Staff/Type/doctor.cpp Hospital/hospital.h Hospital/patient.h Hospital/ResearchCenter/researcher.h Hospital/ResearchCenter/article.h Hospital/hospital.cpp Hospital/patient.cpp Hospital/ResearchCenter/researcher.cpp Hospital/ResearchCenter/article.cpp Hospital/Shared/date.h Hospital/Shared/date.cpp Hospital/Shared/consts.h Hospital/visit.h Hospital/visit.cpp Hospital/Shared/validators.cpp Hospital/Shared/validators.h)
