
cmake_minimum_required(VERSION 3.10)
project(JacobiGaussSeidelSolver)

set(CMAKE_CXX_STANDARD 17)

# Include local Eigen headers
include_directories(include)

add_executable(solvers
    main.cpp
    src/JacobiSolver.cpp
    src/GaussSeidelSolver.cpp
    src/SolverTest.cpp
)