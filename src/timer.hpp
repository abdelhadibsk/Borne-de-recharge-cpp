#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

class Timer {
public:
    Timer();

    void timer_raz();        // équivalent timer_raz
    uint32_t timer_valeur();    // équivalent timer_valeur (en secondes)

private:
    std::chrono::steady_clock::time_point ref;
};
/*utilisation :
Timer t; // crée un timer et l'initialise
t.timer_raz(); // réinitialise le timer
uint32_t elapsed = t.timer_valeur(); // récupère le nombre de secondes écoulées depuis la dernière réinitialisation
*/


#endif