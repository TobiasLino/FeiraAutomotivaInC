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
#ifndef SRC_MODEL_ADDRESS_H_
#define SRC_MODEL_ADDRESS_H_

#include <stdio.h>

typedef struct {
        char *street;
        unsigned long number;
        char *complement;
        char *neighborhood;
        char *city;
        char *state;
        unsigned long zip;
} Address;

void print_address(Address *address);

#endif  // SRC_MODEL_ADDRESS_H_
