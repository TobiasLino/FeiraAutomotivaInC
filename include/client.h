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
#ifndef INCLUDE_CLIENT_H_
#define INCLUDE_CLIENT_H_

#include <stdio.h>
#include <stdlib.h>

#include "phone.h"
#include "address.h"
#include "vehicle.h"

typedef struct {
        int id;
        char *name;
        unsigned long cpf;
        Phone *phone;
        Address *address;
        Vehicle *vehicle;
} Client;

Client* __init_client();
void print_client(Client *client);

#endif  // INCLUDE_CLIENT_H_
