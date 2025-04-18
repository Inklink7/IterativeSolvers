
#include "SolverTest.h"
#include "LinearSystem.h"
#include "SolverMethod.h"

void SolverTest::runTests() {
    
    Eigen::MatrixXd A(3,3);
    A << 10, -1, 2,
        -1, 11, -1,
         2, -1, 10;

    Eigen::VectorXd b(3);
    b << 6, 25, -11;

    LinearSystem ls(A, b);

    SolverMethod method = SolverMethod::Jacobi;

    std::cout<< ls.solve(method).toString() << std::endl;


    method = SolverMethod::GaussSeidel;
    std::cout<<std::endl<<std::endl;
    std::cout<< ls.solve(method).toString() << std::endl;

}
