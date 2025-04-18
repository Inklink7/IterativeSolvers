
#pragma once
#include "Solution.h"
#include "Timer.h"
#include <Eigen/Dense>
#include <stdexcept>

/**
 * @brief Classe base per i metodi iterativi di risoluzione dei sistemi lineari.
 * Implementa il codice iterativo generico, delegando l'implementazione dei
 * criteri di aggiornamento alle classi derivate.
 * 
 * @see JacobiSolver, GaussSeidelSolver
 */
class IterativeSolver 
{
    public:

        virtual ~IterativeSolver() = default;

        /**
         * @brief Risolve il sistema Ax = b utilizzando un metodo iterativo.
         * 
         * @param A La matrice dei coefficienti.
         * @param b Il vettore dei termini noti.
         * @param tol La tolleranza per la convergenza (default: 1e-16).
         * @param maxIter Il numero massimo di iterazioni (default: 20000).
         * 
         * @return Il vettore soluzione x.
         * 
         * @throws std::runtime_error Se la matrice A non soddisfa i criteri di convergenza.
         */
        Solution solve(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, double tolerance = 1e-16, int maxIterations = 20000) 
        {
            // Avvio del timer per misurare il tempo di esecuzione
            Timer timer;
            timer.start();

            // Verifica di convergenza, delegata alla classe derivata poiché
            // ogni metodo richiede criteri di convergenza diversi
            if (!checkConvergenceCriteria(A)) 
            {
                throw std::runtime_error("La matrice A non soddisfa i criteri di convergenza di " + methodName);
            }

            // Vettore soluzione inizializzato a zero
            Eigen::VectorXd x = Eigen::VectorXd::Zero(A.rows());

            // Vettore soluzione precedente
            Eigen::VectorXd x_old = x;

            int iter = 0;
            for (; iter < maxIterations; ++iter) 
            {
                // La soluzione attuale, all'iterazione attuale, la soluzione
                // precedente, la nuova soluzione è calcolata a partire dalla
                // soluzione precedente attraverso la funzione update implementata
                // diversamente a seconda del metodo iterativo considerato
                x_old = x;
                update(x_old, x, A, b);
                
                // Calcoliamo del residuo scalato dell'iterazione
                Eigen::VectorXd residual = A * x - b;
                double residualNorm = residual.norm() / b.norm();

                // Verifica della convergenza attraverso il residuo, che deve
                // essere minore della tolleranza per la convergenza
                if (residualNorm < tolerance) {
                    break;
                }
            }

            // Il metood iterazivo è terminato, calcolo del tempo di esecuzione
            double elapsedTime = timer.stop();

            // La soluzione viene restituita quando si raggiunge la convergenza
            // oppure quando si raggiunge il numero massimo di iterazioni
            Solution solution(x, ((A * x - b).norm() / b.norm()), elapsedTime, getMethodName(), iter + 1);
            return solution;
            
        }

        /**
         * @brief Restituisce il nome del metodo iterativo.
         * 
         * @return Il nome del metodo iterativo.
         */
        std::string getMethodName() const
        {
            return methodName;
        }

        
    protected:

        // identificativo del metodo iterativo
        std::string methodName;

        /**
         * @brief Costruttore della classe IterativeSolver.
         * 
         * @param methodName Il nome del metodo iterativo.
         */
        IterativeSolver(const std::string& methodName) : methodName(methodName) {}

        /**
         * @brief Funzione virtuale per l'aggiornamento della soluzione.
         * Deve essere implementata dalle classi derivate.
         * 
         * @param prev La soluzione precedente.
         * @param next La nuova soluzione.
         * @param A La matrice dei coefficienti.
         * @param b Il vettore dei termini noti.
         */
        virtual void update(const Eigen::VectorXd& prev, Eigen::VectorXd& next, const Eigen::MatrixXd& A, const Eigen::VectorXd& b) = 0;

        /**
         * @brief Funzione virtuale per il controllo dei criteri di convergenza.
         * Deve essere implementata dalle classi derivate.
         * 
         * @param A La matrice dei coefficienti.
         * 
         * @return true Se i criteri di convergenza sono soddisfatti.
         * @return false Se i criteri di convergenza non sono soddisfatti.
         */
        virtual bool checkConvergenceCriteria(const Eigen::MatrixXd& A) = 0;
};