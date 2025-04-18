
#pragma once
#include <Eigen/Dense>


class Solution
{
    public:

        /**
         * @brief Una soluzione è rappresentata dal vettore delle soluzioni e da
         * alcune informazioni sull'esecuzione
         * 
         * @param x il vettore delle soluzioni
         * @param residual il residuo della soluzione, ovvero l'errore relativo
         * @param elapsedTime il tempo di calcolo dell'applicazione del metodo
         * @param methodName il nome del metodo iterativo utilizzato
         * @param iterations il numero di iterazioni effettuate
         */
        Solution(const Eigen::VectorXd& x, double residual, double elapsedTime,
                 const std::string& methodName, int iterations)
            : x(x), residual(residual), elapsedTime(elapsedTime),
              methodName(methodName), iterations(iterations) {}

        /**
         * @brief Rappresentazione per la stampa della soluzione
         * 
         * @return std::string la rappresentazione della soluzione
         */
        std::string toString() const
        {
            std::ostringstream oss;
            oss << "Metodo: " << methodName << "\n"
                << "Iterazioni: " << iterations << "\n"
                << "Tempo di calcolo: " << elapsedTime << " secondi\n"
                << "Residuo: " << residual << "\n"
                << "Soluzione: " << x.transpose();
            return oss.str();
        }
    
    protected:

        // Vettore delle soluzioni
        Eigen::VectorXd x;

        // Errore relativo ottenuto dall'applicazione del metodo iterativo
        double residual;

        // Tempo di calcolo dell'applicazione del metodo iterativo
        double elapsedTime;

        // identificativo del metodo iterativo
        std::string methodName;

        // Numero di iterazioni effettuate
        int iterations;

};