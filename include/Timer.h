#pragma once
#include <chrono>

/**
 * @brief Cronometro per la misurazione del tempo di esecuzione dei metodi iterativi.
 */
class Timer 
{
    public:
    
        /**
         * @brief Costruttore: avvia automaticamente il timer.
         */
        Timer() 
        {
            start();
        }

        /**
         * @brief Avvia o riavvia il timer.
         */
        void start() 
        {
            startTime = std::chrono::high_resolution_clock::now();
        }

        /**
         * @brief Ferma il timer e restituisce il tempo trascorso in millisecondi.
         * 
         * @return Il tempo trascorso in millisecondi.
         */
        double stop() 
        {
            auto endTime = std::chrono::high_resolution_clock::now();
            

            std::chrono::duration<double> elapsed = endTime - startTime;
            elapsedTime = elapsed.count();
            elapsedTime *= 1000.0;

            return elapsedTime;
        }

    private:

        // Punto di partenza del timer, il tempo trascorso viene calcolato
        // per sottrazione da questo valore.
        std::chrono::high_resolution_clock::time_point startTime;

        // Tempo trascorso in secondi.
        double elapsedTime = 0.0;
};