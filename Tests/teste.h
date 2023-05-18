//
// Created by Irimieş Vasile on 3/9/2023.
//
#pragma once
#ifndef LABORATORUL_2_4_TESTE_H
#define LABORATORUL_2_4_TESTE_H

#endif //LABORATORUL_2_4_TESTE_H
/***
 * Ruleaza toate testele
 */
void ruleaza_toate_testele();

/***
 * Ruleaza testele aferente domain-ului
 *      -> Creaaza
 *      -> Setteri
 *      -> EQ
 */
void ruleaza_teste_domain();

void ruleaza_teste_create();
void ruleaza_teste_set();
void ruleaza_teste_eq();

/***
 * Ruleaza testele aferente repository-ului
 *      -> Adauga
 *      -> Modifica
 *      -> Cauta dupa nr inmatriculare
 *      -> Sterge
 */
void ruleaza_teste_repository();

void ruleaza_teste_redimensionare();
void ruleaza_teste_adauga_repo();
void ruleaza_teste_modifica_repo();
void ruleaza_teste_cauta_repo();
void ruleaza_teste_inchiriere_si_retur_repo();
void ruleaza_teste_get_neinchiriate();

/***
 * Ruleaza testele aferente validatorului
 */
void ruleaza_teste_validator();

/***
 * Ruleaza testele aferente service-ului
 *      -> Adauga
 *      -> Modifica
 *      -> Cauta
 *      -> Sterge
 */
void ruleaza_teste_service();

void ruleaza_teste_adauga_service();
void ruleaza_teste_modifica_service();
void ruleaza_teste_cauta_service();
void ruleaza_teste_inchiriare_retur_service();
void ruleaza_teste_filtre();
void ruleaza_teste_sortare();
