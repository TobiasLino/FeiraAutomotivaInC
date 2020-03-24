//
// Created by tobias on 23/03/2020.
//

#ifndef SRC_MODEL_VEHICLE_H_
#define SRC_MODEL_VEHICLE_H_

#include "client.h"

typedef struct {
        char *license_plate;
        char *model_version;
        char *brand;
        char *year_of_manufacture;
        double *purchase_price;
        Client *client;
} Vehicle;

#endif //SRC_MODEL_VEHICLE_H_
