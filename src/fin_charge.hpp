#ifndef FIN_CHARGE_HPP
#define FIN_CHARGE_HPP

/**
 * @file fin_charge.hpp
 * @brief Verification de la carte lors de la procedure de deconnexion.
 */

/**
 * @brief Controle la carte presentee pour terminer une charge en cours.
 * @return 1 si la deconnexion est autorisee, sinon 0.
 */
int check_and_deconnect(void);

#endif
