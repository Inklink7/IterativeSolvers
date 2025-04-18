
#pragma once
#include "JacobiSolver.h"
#include "GaussSeidelSolver.h"

/**
 * @brief Rappresentazione dei metodi di risoluzione disponibili.
 */
enum class SolverMethod {
    Jacobi,
    GaussSeidel
};