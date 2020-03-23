/*
        This file is part of FeiraAutomotiva.

        FeiraAutomotiva is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        FeiraAutomotiva is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with Foobar.  If not, see <https://www.gnu.org/licenses/>.

 */
/*
 * Implementa uma funcionalidade simples de um map
 * onde a chave representa a marca do veículo e
 * o valor representa uma lista de veículos cuja marca
 * seja a mesma que a chave.
 */
#ifndef INCLUDE_MAP_H_
#define INCLUDE_MAP_H_

#include "list.h"
/* Célula única */
struct map_cel {
        char *key;
        vehicle_list *value;
        struct vector_cel *next;
};
/*
 * Implementada como uma lista encadeada
 * para podermos aumentar o tamanho do map
 * a medida que adicionamos veículos com novas
 * marcas.
 */
typedef struct {
        struct vector_cel *head;
} vehicle_map;
/* Adiciona veículo no map */
void push(vehicle_map *map, Vehicle *vehicle);
void remove_vehicle(vehicle_map *map, char *model);

#endif //INCLUDE_MAP_H_
