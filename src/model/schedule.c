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
#include "schedule.h"

int get_index(char letter);

Schedule* create_schedule() {
        /* Aloca memória para a agenda. */
        Schedule *novo = (Schedule*) malloc(sizeof(Schedule));
        /* Aloca memória para cada lista na agenda */
        for (int i = 0; i <= 26; ++i) {
                novo->list[i] = (List*) malloc(sizeof(List));
                novo->list[i]->head = NULL;
        }
        return novo;
}
/*
 * Libera a memória da schedule
 */
void free_schedule(Schedule *schedule) {
        for (int i = 0; i <= 26; ++i)
                free(schedule->list[i]);
        free(schedule);
}
/*
 * Adiciona o cliente na agenda.
 * O índice é extraído da primeira letra do nome do cliente.
 * A inserção é realizada no início da lista.
 */
void add_client(Schedule *schedule, Client *client) {
        int i = get_index(client->name[0]);
        if (!schedule->list[i]->head) {
                schedule->list[i]->head = malloc(sizeof(struct Cel));
                struct client_cel *novo = malloc(sizeof(struct client_cel));
                novo->client = client;
                novo->next = NULL;
                schedule->list[i]->head->next = novo;
        } else {
                struct client_cel *cel = malloc(sizeof(struct client_cel));
                cel->client = client;
                cel->next = schedule->list[i]->head->next;
                schedule->list[i]->head = cel;
        }
}
/*
 * Imprime os dados de cada cliente dentro da agenda
 */
void print_schedule(Schedule *schedule) {
        for (int i = 0; i <= 26; ++i) {
                struct client_cel *tmp = schedule->list[i]->head;
                for (; tmp; tmp = tmp->next) {
                  if (tmp->client) print_client(tmp->client);
                }
        }
}
/*
 * Retorna o índice a partir da primeira letra do cliente fornecido
 */
int get_index(char letter) {
        return toupper(letter) - 65;
}
