/*******************************************************************************
This file is part of MADCAT, the Mass Attack Detection Acceptance Tool.
    MADCAT is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    MADCAT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with MADCAT.  If not, see <http://www.gnu.org/licenses/>.

 Diese Datei ist Teil von MADCAT, dem Mass Attack Detection Acceptance Tool.
    MADCAT ist Freie Software: Sie können es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veröffentlichten Version, weiter verteilen und/oder modifizieren.
    MADCAT wird in der Hoffnung, dass es nützlich sein wird, aber
    OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
    Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License für weitere Details.
    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <https://www.gnu.org/licenses/>.
*******************************************************************************/
/* MADCAT - Mass Attack Detecion Connection Acceptance Tool
 * UDP- and ICMP monitor library headerfile.
 *
 * Netfilter should be configured to block outgoing ICMP Destination unreachable (Port unreachable) packets, e.g.:
 *      iptables -I OUTPUT -p icmp --icmp-type destination-unreachable -j DROP
 *
 * BSI 2018-2023
*/


#ifndef UDP_IP_PORT_ICMP_HELPER_H
#define UDP_IP_PORT_ICMP_HELPER_H

#include "madcat.helper.h"

//UDP and ICMP HELPER
/**
  * \brief Saves and returns address of main buffer
  *
  *     Saves and returns address of main buffer to be freed by signal handler.
  *     Returns saved value, if parameter is set to NULL.
  *
  * \param buffer Pointer to main buffer
  *
  * \return Pointer to main buffer
  *
  */
void* saved_buffer(void * buffer); //saves and returns address of main buffer to be freed by signal handler

/**
  * \brief Signal Handler
  *
  *     Generic Signal Handler for gracefull shutdown
  *
  * \param signo Signal Number
  * \return void
  *
  */
void sig_handler(int signo);

/**
  * \brief Signal Handler
  *
  *     Generic Signal Handler for not-so-gracefull shutdown
  *
  * \param signo Signal Number
  * \return void
  *
  */
void sig_handler_abort(int signo); //Generic Signal Handler for not-so-gracefull shutdown

/**
  * \brief Fetches user IDs
  *
  *     Fetches user IDs for username, saved in user and writes them to the same struct.
  *
  * \param user pointer to struct user_t, containing user name
  * \return void, GID and PID of user are returned in struct user_t user, given as parameter
  *
  */
void get_user_ids(struct user_t* user); //adapted example code from manpage getpwnam(3)

#endif
