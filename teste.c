#include <stdlib.h>

#include "include/phone.h"
#include "include/client.h"
#include "include/schedule.h"

int main() {

        Client *client = (Client*) malloc(sizeof(Client));
        client->id = 0;
        client->name = "Tobias";
        Phone *phone = malloc(sizeof(Phone));
        phone->number = "12996819353";
        client->phone = phone;

        Client *cl2 = malloc(sizeof(Client));
        cl2->id = 1;
        cl2->name = "Tabata";

        Schedule *agenda = create_schedule();
        add_client(agenda, client);
        add_client(agenda, cl2);
        print_schedule(agenda);

        goto exit;

        exit:
                free_schedule(agenda);
                free(client);
                return 0;
}
