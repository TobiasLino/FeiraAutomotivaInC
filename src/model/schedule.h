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
#ifndef SRC_MODEL_SCHEDULE_H_
#define SRC_MODEL_SCHEDULE_H_

#include <stdlib.h>
#include <ctype.h>

#include "client.h"
#include "list.h"
/*
 * Schedule implementada como um vetor de listas circulares.
 * vai de 'A' até 'Z' onde cada elemento corresponde á lista de clientes
 * cujo nome começa com a letra correspondente.
 */
typedef struct {
        List *list[26];
} Schedule;

Schedule* create_schedule();
void free_schedule(Schedule *schedule);
void add_client(Schedule *schedule, Client *client);

void print_schedule(Schedule *schedule);

#endif  // SRC_MODEL_SCHEDULE_H_
