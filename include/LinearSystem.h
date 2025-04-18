
#pragma once
#include "SolverMethod.h"
#include <Eigen/Dense>
#include <stdexcept>

/**
 * \brief Questa classe rappresenta un sistema lineare, che è definito 
 * da una matrice dei coefficienti e un vettore dei termini noti.
 */
class LinearSystem
{
    public:

        /**
         * \brief Costruttore della classe LinearSystem, che costruisce il
         * sistema lineare a partire da una matrice dei coefficienti e un
         * vettore dei termini noti.
         * 
         * \param A La matrice dei coefficienti del sistema lineare.
         * \param b Il vettore dei termini noti del sistema lineare.
         * 
         * \throw std::invalid_argument Se le dimensioni della matrice A e del
         * vettore b non sono compatibili.
         */
        LinearSystem(const Eigen::MatrixXd& A, const Eigen::VectorXd& b): A_(A), b_(b)
        {
            if (A_.rows() != b_.size())
            {
                throw std::invalid_argument("Matrix A and vector b dimensions do not match.");
            }
        }

        Solution solve(SolverMethod& solver)
        {
            if (solver == SolverMethod::Jacobi)
            {
                JacobiSolver jacobi;
                return jacobi.solve(A_, b_);
            }
            else if (solver == SolverMethod::GaussSeidel)
            {
                GaussSeidelSolver gaussSeidel;
                return gaussSeidel.solve(A_, b_);
            }
            else
            {
                throw std::invalid_argument("Metodo di risoluzione non valido.");
            }
        }


    protected:

        // Matrice dei coefficienti
        Eigen::MatrixXd A_;

        // Vettore dei termini noti
        Eigen::VectorXd b_;
};