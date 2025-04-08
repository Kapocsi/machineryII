/**
 * Group B: Thomas Kapocsi, Sylvie Mills
 * @file vector.h
 * @author Thomas Kapocsi (his code copy-pasted by Sylvie)
 * @brief Defines the function to install new ISR vectors
 */

 #ifndef VECTOR_H
 #define VECTOR_H
 
 /**
  * @typedef Vector
  * @brief A pointer to the start of a subroutine.
  */
 typedef void (*Vector)();
 
 /**Replaces a TOS subroutine with a new subroutine */
 Vector install_vector(int num, Vector vector);
 
 #endif
 