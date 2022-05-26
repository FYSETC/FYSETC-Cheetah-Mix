/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../inc/MarlinConfig.h"

#if HAS_STATUS_MESSAGE

#include "../gcode.h"
#include "../../lcd/marlinui.h"

char ip_address[16];

/**
 * M117: Set LCD Status Message
 */
void GcodeSuite::M117() {

  char *p = parser.string_arg;
  int pc = 0;
  bool is_ip = true;
  
  if (parser.string_arg && parser.string_arg[0])
  {
    while(*p != '\0') {
      if( *p == '.' ) pc++;
      else if( *p<'0' && *p>'9' ) {
        is_ip = false;
        break;
      }
      p++;
    }
    if(is_ip && pc==3) strncpy(ip_address, parser.string_arg,16);

    ui.set_status(parser.string_arg);
  }
  else
    ui.reset_status();

}

/**
 * M711: Get IP
 */
void GcodeSuite::M711() {
  SERIAL_ECHOLN(ip_address);
}

#endif // HAS_STATUS_MESSAGE
