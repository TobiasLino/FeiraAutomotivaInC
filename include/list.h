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
#ifndef INCLUDE_LIST_H_
#define INCLUDE_LIST_H_

#include "client.h"
#include "vehicle.h"

struct client_cel {
        Client *client;
        struct client_cel *next;
<<<<<<< HEAD:include/list.h
=======
};
struct vehicle_cel {

>>>>>>> 590bc6396bbe8662ef279865915d89b3f95b413c:src/include/list.h
};
struct vehicle_cel {
        Vehicle *vehicle;
        struct vehicle_cel *next;
};

typedef struct {
        struct client_cel *head;
} client_list;

typedef struct {
<<<<<<< HEAD:include/list.h
        struct vehicle_cel *head;
} vehicle_list;
=======
        struct client_cel *head;
} List;
>>>>>>> 590bc6396bbe8662ef279865915d89b3f95b413c:src/include/list.h

void sort_client_list(client_list *list);
void put_client(client_list *list, char key, Client *client);
void remove_client(client_list *list, char *name);

#endif  // INCLUDE_LIST_H_
