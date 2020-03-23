#include <stdio.h>
#include <stdlib.h>

#include "model/address.h"
#include "model/phone.h"
#include "model/client.h"
#include "model/schedule.h"

int main() {

        Client *client = (Client*) malloc(sizeof(Client));
        client->id = 0;
        client->name = "Tobias";

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
