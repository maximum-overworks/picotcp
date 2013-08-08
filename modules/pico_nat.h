/*********************************************************************
PicoTCP. Copyright (c) 2012 TASS Belgium NV. Some rights reserved.
See LICENSE and COPYING for usage.

.
  
Authors: Kristof Roelants, Simon Maes, Brecht Van Cauwenberghe
*********************************************************************/

#ifndef _INCLUDE_PICO_NAT
#define _INCLUDE_PICO_NAT
#include "pico_frame.h"

#define PICO_NAT_PORT_FORWARD_DEL 0
#define PICO_NAT_PORT_FORWARD_ADD 1

#ifdef PICO_SUPPORT_NAT
void pico_ipv4_nat_print_table(void);
int pico_ipv4_nat_find(uint16_t pub_port, struct pico_ip4 *priv_addr, uint16_t priv_port, uint8_t proto);
int pico_ipv4_port_forward(struct pico_ip4 pub_addr, uint16_t pub_port, struct pico_ip4 priv_addr, uint16_t priv_port, uint8_t proto, uint8_t flag);

int pico_ipv4_nat_inbound(struct pico_frame *f, struct pico_ip4 *link_addr);
int pico_ipv4_nat_outbound(struct pico_frame *f, struct pico_ip4 *link_addr);
int pico_ipv4_nat_enable(struct pico_ipv4_link *link);
int pico_ipv4_nat_disable(void);
int pico_ipv4_nat_is_enabled(struct pico_ip4 *link_addr);
#else

#define pico_ipv4_nat_print_table() do{}while(0)
static inline int pico_ipv4_nat_is_enabled(struct pico_ipv4_link *link)
{
  pico_err = PICO_ERR_EPROTONOSUPPORT;
  return -1;
}

static inline int pico_ipv4_nat_inbound(struct pico_frame* f)
{
  pico_err = PICO_ERR_EPROTONOSUPPORT;
  return -1;
}

static inline int pico_ipv4_nat_outbound(struct pico_frame* f)
{
  pico_err = PICO_ERR_EPROTONOSUPPORT;
  return -1;
}

static inline int pico_ipv4_nat_enable(struct pico_ipv4_link *link)
{
  pico_err = PICO_ERR_EPROTONOSUPPORT;
  return -1;
}

static inline int pico_ipv4_nat_disable(struct pico_ipv4_link *link)
{
  pico_err = PICO_ERR_EPROTONOSUPPORT;
  return -1;
}

static inline int pico_ipv4_nat_is_enabled(struct pico_ipv4_link *link)
{
  pico_err = PICO_ERR_EPROTONOSUPPORT;
  return -1;
}

static inline int pico_ipv4_nat_find(uint16_t pub_port, struct pico_ip4 priv_addr, uint16_t priv_port, uint8_t proto)
{
  pico_err = PICO_ERR_EPROTONOSUPPORT;
  return -1;
}

static inline int pico_ipv4_port_forward(struct pico_ip4 pub_addr, uint16_t pub_port, struct pico_ip4 priv_addr, uint16_t priv_port, uint8_t proto, uint8_t flag)
{
  pico_err = PICO_ERR_EPROTONOSUPPORT;
  return -1;
}
#endif

#endif /* _INCLUDE_PICO_NAT */

