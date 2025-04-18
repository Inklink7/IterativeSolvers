
#include "JacobiSolver.h"

/**
 * @brief Aggiornamento della soluzione nel metodo di Jacobi secondo la formula
 * di Jacobi: x_i^(k+1) = (b_i - sum(A_ij * x_j^k)) / A_ii
 * 
 * @param prev La soluzione precedente.
 * @param next La nuova soluzione.
 * @param A La matrice dei coefficienti.
 * @param b Il vettore dei termini noti.
 */
void JacobiSolver::update(const Eigen::VectorXd& prev, Eigen::VectorXd& next, const Eigen::MatrixXd& A, const Eigen::VectorXd& b) {
    int n = A.rows();
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j) sum += A(i, j) * prev(j);
        }
        next(i) = (b(i) - sum) / A(i, i);
    }
}


/**
 * @brief Controllo dei criteri di convergenza per il metodo di Jacobi, i.e. 
 * verifica che la matrice A sia diagonalmente dominante.
 * 
 * @param A La matrice dei coefficienti.
 * 
 * @return true Se i criteri di convergenza sono soddisfatti.
 * @return false Se i criteri di convergenza non sono soddisfatti.
 */
bool JacobiSolver::checkConvergenceCriteria(const Eigen::MatrixXd& A) {
    int n = A.rows();
    for (int i = 0; i < n; ++i) {
        double diag = std::abs(A(i, i));
        double sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j) sum += std::abs(A(i, j));
        }
        if (diag <= sum) return false;
    }
    return true;
}