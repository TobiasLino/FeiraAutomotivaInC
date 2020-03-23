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
#include "client.h"
/*
 * Função 'construtora' do cliente,
 * note que vehicle, phone e address estão nulos.
 */
Client* __init_client(int id) {
        Client *new = malloc(sizeof(Client));
        new->id = id++;
        new->name = "";
        new->cpf = 0;
        return new;
}
/* Imprime os dados do cliente */
void print_client(Client *client) {
        printf("\nClient Data.\n");
        printf("\tID: %d\n", client->id);
        printf("\tName: %s\n", client->name);
        printf("\tCPF: %ld\n", client->cpf);
        if (tmp->client->phone) print_phone(tmp->client->phone);
        if (tmp->client->address) print_address(tmp->client->address);
}
