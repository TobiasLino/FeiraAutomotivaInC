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
#include "../include/schedule.h"

/* Protótipos */
int get_index(char letter);
void add_client_to_list(Schedule *schedule, Client* client, int index);
void add_client_to_nonexisting_list(Schedule *schedule, Client* client, int index);
void add_vehicle_to_map(Schedule *schedule, Vehicle *vehicle);
void add_vehicle_to_nonexisting_map(Schedule *schedule, Vehicle *vehicle);
struct vehicle_cel* allocate_new_cell(vehicle_list *new, Vehicle *to_add);
struct map_cel* allocate_new_map_cel(struct map_cel *head, Vehicle *to_add);
vehicle_list* allocate_new_list();

/* Aloca a memória necessária para operar em schedule. */
Schedule* create_schedule() {
        /* Aloca memória para a agenda. */
        Schedule *novo = (Schedule*) malloc(sizeof(Schedule));
        /* Aloca memória para cada lista na agenda */
        for (int i = 0; i <= 26; ++i) {
                novo->clients[i] = (client_list*) malloc(sizeof(client_list));
                novo->clients[i]->head = NULL;
        }
        novo->vehicles = (vehicle_map*) malloc(sizeof(vehicle_map));
        return novo;
}

/* Libera a memória da schedule. */
void free_schedule(Schedule *schedule) {
        for (int i = 0; i <= 26; ++i)
                free(schedule->clients[i]);
        free(schedule);
}

/*
 * Adiciona o cliente na agenda.
 * O índice é extraído da primeira letra do nome do cliente.
 * A inserção é realizada no início da lista.
 */
void add_client(Schedule *schedule, Client *client) {
        int i = get_index(client->name[0]);
        if (schedule->clients[i]->head)
                add_client_to_list(schedule, client, i);
        else
                add_client_to_nonexisting_list(schedule, client, i);
        if (client->vehicle) add_vehicle(schedule, client->vehicle);
}

void add_client_to_list(Schedule *schedule, Client* client, int index) {
        struct client_cel *cel = malloc(sizeof(struct client_cel));
        cel->client = client;
        cel->next = schedule->clients[index]->head->next;
        schedule->clients[index]->head = cel;
}

void add_client_to_nonexisting_list(Schedule *schedule, Client* client, int index) {
        schedule->clients[index]->head = malloc(sizeof(struct client_cel));
        struct client_cel *novo = malloc(sizeof(struct client_cel));
        novo->client = client;
        novo->next = NULL;
        schedule->clients[index]->head->next = novo;
}

/* Adiciona o veículo no map. */
void add_vehile(Schedule *schedule, Vehicle *vehicle) {
        if (schedule->vehicles->head)
                add_vehicle_to_map(schedule, vehicle);
        else
                add_vehicle_to_nonexisting_map(schedule, vehicle);
}

void add_vehicle_to_map(Schedule *schedule, Vehicle *vehicle) {
        struct map_cel *cel = malloc(sizeof(struct map_cel));
        if (vehicle->brand != NULL) {
                cel->key = vehicle->brand;
                if (cel->value) {
                        struct vehicle_cel *tmp_cel = allocate_new_cell(cel->value, vehicle);
                        cel->value->head = tmp_cel;
                } else {
                        vehicle_list *tmp_list = allocate_new_list();
                        struct vehicle_cel *tmp_cel = allocate_new_cell(tmp_list, vehicle);
                        tmp_list->head->next = tmp_cel;
                        cel->value = tmp_list;
                }
                schedule->vehicles->head->next = cel;
        }
}

void add_vehicle_to_nonexisting_map(Schedule *schedule, Vehicle *vehicle) {
        if (vehicle->brand != NULL) {
                struct map_cel *head = malloc(sizeof(struct map_cel));          // cria a head de map
                struct map_cel *new = allocate_new_map_cel(head, vehicle);      // cria a nova célula do map
                head->next = new;                                               // adiciona a nova célula no início do map
                schedule->vehicles->head = head;                                // adiciona head ao map.
        }
}

struct vehicle_cel* allocate_new_cell(vehicle_list *new, Vehicle *to_add) {
        struct vehicle_cel *l_cel = malloc(sizeof(struct vehicle_cel)); // cria uma nova célula da list
        l_cel->vehicle = to_add;                                        // adiciona o veículo na lista
        l_cel->next = new->head->next;                                  // aponta para o primeiro elemento, depois de head
        return l_cel;
}

struct map_cel* allocate_new_map_cel(struct map_cel *head, Vehicle *to_add) {
        struct map_cel *new = malloc(sizeof(struct map_cel));            // cria a célula a ser adicionada
        new->key = to_add->brand;                                        // a chave é a marca do carro
        new->value = malloc(sizeof(vehicle_list));                       // o valor é uma lista
        new->value->head = malloc(sizeof(struct vehicle_cel));           // aloca memória para head
        head->value->head->next = allocate_new_cell(new->value, to_add); // adiciona no início da lista
        new->next = head->next;                                          // para adicionar no início do map
        return new;
}

vehicle_list* allocate_new_list() {
        vehicle_list *new = malloc(sizeof(vehicle_list));
        new->head = malloc(sizeof(struct vehicle_cel));
        return new;
}

/* Imprime os dados de cada cliente dentro da agenda. */
void print_schedule(Schedule *schedule) {
        for (int i = 0; i <= 26; ++i) {
                struct client_cel *tmp = schedule->clients[i]->head;
                for (; tmp; tmp = tmp->next) {
                  if (tmp->client) print_client(tmp->client);
                }
        }
}

/* Retorna o índice a partir da primeira letra do cliente fornecido. */
int get_index(char letter) {
        return toupper(letter) - 65;
}
