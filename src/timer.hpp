#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

/**
 * @file timer.hpp
 * @brief Chronometre simple base sur std::chrono.
 */

/**
 * @class Timer
 * @brief Fournit un compteur de temps ecoule en secondes.
 */
class Timer {
public:
    /**
     * @brief Construit un timer et memorise l'instant de reference.
     */
    Timer();

    /**
     * @brief Reinitialise le point de depart du timer.
     */
    void timer_raz();

    /**
     * @brief Retourne le temps ecoule depuis la derniere remise a zero.
     * @return Nombre de secondes ecoulees.
     */
    uint32_t timer_valeur();

private:
    std::chrono::steady_clock::time_point ref;
};
#endif