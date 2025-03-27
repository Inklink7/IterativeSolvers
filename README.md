# Iterative Solvers for Symmetric Positive Definite Matrices (C++)

## Project Description
This project implements a mini-library in **C++** for solving linear systems \(Ax = b\) using iterative solvers, limited to **symmetric positive definite matrices**. The implemented methods include:

1. **Jacobi Method**
2. **Gauss-Seidel Method**
3. **Gradient Method**
4. **Conjugate Gradient Method**

The implementation is based on an open-source numerical library (such as **Eigen**, **Armadillo**, or **BLAS/LAPACK**) to handle matrix and vector operations. However, built-in solvers from these libraries **cannot** be used.

## Requirements
The library must:
- Be well-structured rather than a collection of independent functions.
- Implement all four iterative solvers from scratch.
- Start with an initial guess of the zero vector \(x_0 = 0\).
- Stop when:
  - The relative residual \( \frac{||Ax_k - b||}{||b||} < \text{tol} \) (user-defined tolerance) is met.
  - The number of iterations exceeds a set maximum (not less than **20,000**).

## Input and Output
The executable must take as input:
- A **symmetric positive definite matrix** \(A\) (from `.mtx` files).
- A right-hand side vector **b**.
- The exact solution vector **x**.
- A **tolerance** value (user-defined).

For each method, the program must:
- Compute the approximate solution \( x_k \).
- Print:
  - The relative error between \( x \) and \( x_k \).
  - The number of iterations required.
  - The computation time.

## Validation Procedure
To validate the solvers, the following steps must be performed:
1. Define the exact solution \( x = [1, 1, 1, ..., 1] \).
2. Compute \( b = Ax \).
3. Solve for \( x_k \) using all four iterative methods.
4. Measure:
   - The **relative error** between \( x \) and \( x_k \).
   - The number of iterations required.
   - The computation time.

This procedure must be repeated for multiple tolerance values: 
\( \text{tol} = [10^{-4}, 10^{-6}, 10^{-8}, 10^{-10}] \).

## `.mtx` File Format
The input matrices are provided in **Matrix Market (.mtx) format**, a standard format for storing sparse matrices. More details can be found at:
[Matrix Market Format](https://math.nist.gov/MatrixMarket/formats.html)

The given files:
- `spa1.mtx`
- `spa2.mtx`
- `vem1.mtx`
- `vem2.mtx`

contain different symmetric positive definite matrices to test the solvers.

## Implementation Notes
- **Programming Language:** C++.
- **Matrix Operations:** Use an open-source library (**Eigen**, **Armadillo**, or similar) but without built-in solvers.
- **Execution:** Command-line interface, with input from `.mtx` files and results printed to standard output.

---
**Author:** _Marcaccio Riccardo, Broccoletti Anrea_  
**Repository:** _[GitHub Repository URL](https://github.com/Inklink7/IterativeSolvers)_
