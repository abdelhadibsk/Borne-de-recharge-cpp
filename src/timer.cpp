// #include <stdint.h> l'equivalent en c++ est <cstdint> et on peut aussi utiliser uint32_t sans le préfixe std:: car il est défini dans l'espace de nom global par l'en-tête <cstdint>
#include <cstdint>
#include "timer.hpp"

#include <chrono>

//constructeur de la classe Timer, initialise le timer
Timer::Timer()
{
    ref = std::chrono::steady_clock::now();
}

void Timer::timer_raz()
{
    ref = std::chrono::steady_clock::now();
}

uint32_t Timer::timer_valeur()
{
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - ref);
    return static_cast<uint32_t>(elapsed.count());
}