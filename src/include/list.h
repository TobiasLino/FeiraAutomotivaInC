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
#ifndef SRC_INCLUDE_LIST_H_
#define SRC_INCLUDE_LIST_H_

#include "client.h"

struct client_cel {
        Client *client;
        struct client_cel *next;
};
struct vehicle_cel {

};

typedef struct {
        struct client_cel *head;
} List;

void sort_list(List *list);
void put_client(List *list, char key, Client *client);
void remove_client(List *list, char *name);

#endif  // SRC_INCLUDE_LIST_H_
