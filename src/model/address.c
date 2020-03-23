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
#include "address.h"

void print_address(Address *address)
{
  printf("\n\tAddress:\n");
  printf("\t\tStreet: %s \n", address->street);
  printf("\t\tNumber: %ld \n", address->number);
  printf("\t\tComplement: %s \n", address->complement);
  printf("\t\tNeighborhood: %s \n", address->neighborhood);
  printf("\t\tCity: %s \n", address->city);
  printf("\t\tState: %s \n", address->state);
  printf("\t\tZIP: %ld \n", address->zip);
}
