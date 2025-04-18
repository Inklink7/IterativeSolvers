
#include "GaussSeidelSolver.h"

/**
 * @brief Aggiornamento della soluzione nel metodo di Gauss-Seidel secondo la formula:
 * x_i^(k+1) = (b_i - sum(A_ij * x_j^(k+1)) - sum(A_ij * x_j^k)) / A_ii
 * 
 * @param prev La soluzione precedente.
 * @param next La nuova soluzione.
 * @param A La matrice dei coefficienti.
 * @param b Il vettore dei termini noti.
 */
void GaussSeidelSolver::update(const Eigen::VectorXd& prev, Eigen::VectorXd& next, const Eigen::MatrixXd& A, const Eigen::VectorXd& b) {
    int n = A.rows();
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (j < i) {
                    sum += A(i, j) * next(j); // Usa il valore aggiornato
                } else {
                    sum += A(i, j) * prev(j); // Usa il valore precedente
                }
            }
        }
        next(i) = (b(i) - sum) / A(i, i);
    }
}


/**
 * @brief Controllo dei criteri di convergenza per il metodo di Gauss-Seidel, i.e. 
 * verifica che la matrice A sia diagonalmente dominante.
 * 
 * @param A La matrice dei coefficienti.
 * 
 * @return true Se i criteri di convergenza sono soddisfatti.
 * @return false Se i criteri di convergenza non sono soddisfatti.
 */
bool GaussSeidelSolver::checkConvergenceCriteria(const Eigen::MatrixXd& A) {
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