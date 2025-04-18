
#pragma once
#include "IterativeSolver.h"

/**
 * @brief Implementazione del metodo di Jacobi per la risoluzione di sistemi lineari.
 * Consente di risolvere sistemi di equazioni lineari della forma Ax = b.
 * 
 * @see IterativeSolver
 */
class JacobiSolver : public IterativeSolver
{
    public:
        JacobiSolver() : IterativeSolver("Jacobi") {}

    protected:

        void update(const Eigen::VectorXd& prev, Eigen::VectorXd& next, const Eigen::MatrixXd& A, const Eigen::VectorXd& b) override;
        bool checkConvergenceCriteria(const Eigen::MatrixXd& A) override;
};