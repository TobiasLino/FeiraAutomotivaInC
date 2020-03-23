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
#ifndef INCLUDE_VEHICLE_H_
#define INCLUDE_VEHICLE_H_

#include "client.h"

typedef struct {
        char *license_plate;
        char *model_version;
        char *brand;
        char *year_of_manufacture;
        double *purchase_price;
        struct Client *client;
} Vehicle;

#endif // INCLUDE_VEHICLE_H_
