/*********************************************************************
PicoTCP. Copyright (c) 2012 TASS Belgium NV. Some rights reserved.
See LICENSE and COPYING for usage.

.

Authors: Kristof Roelants, Simon Maes, Brecht Van Cauwenberghe
*********************************************************************/

#ifndef _INCLUDE_PICO_IGMP2
#define _INCLUDE_PICO_IGMP2

extern struct pico_protocol pico_proto_igmp2;

struct __attribute__((packed)) pico_igmp2_hdr {
  uint8_t type;
  uint8_t max_resp_time;
  uint16_t crc;
  uint32_t group_address;
};


// HOST FLAG DEFS
#define PICO_IGMP2_HOST_LAST         (0x1)
#define PICO_IGMP2_HOST_NOT_LAST     (0x0)

// EVENT DEFS
#define PICO_IGMP2_EVENT_LEAVE_GROUP      (0x0)
#define PICO_IGMP2_EVENT_JOIN_GROUP       (0x1)
#define PICO_IGMP2_EVENT_QUERY_RECV       (0x2)
#define PICO_IGMP2_EVENT_REPORT_RECV      (0x3)
#define PICO_IGMP2_EVENT_TIMER_EXPIRED    (0x4)

// MEMBERSHIP DEFS
#define PICO_IGMP2_STATES_NON_MEMBER      (0x0)
#define PICO_IGMP2_STATES_DELAYING_MEMBER (0x1)
#define PICO_IGMP2_STATES_IDLE_MEMBER     (0x2)

// 
#define PICO_IGMP2_TYPE_MEM_QUERY      (0x11)
#define PICO_IGMP2_TYPE_V1_MEM_REPORT  (0x12)
#define PICO_IGMP2_TYPE_V2_MEM_REPORT  (0x16)
#define PICO_IGMP2_TYPE_LEAVE_GROUP    (0x17)


//ALL_ROUTER_GROUP 224.0.0.2
#define PICO_IGMP2_ALL_ROUTER_GROUP              (0x020000E0)

//ALL_HOST_GROUP 224.0.0.1
#define PICO_IGMP2_ALL_HOST_GROUP                (0x010000E0)

#define PICO_IGMP2_DEFAULT_MAX_RESPONSE_TIME   (100)
#define PICO_IGMP2_UNSOLICITED_REPORT_INTERVAL (100)


//IGMP2 ERROR RETURN VALUES
#define PICO_IGMP2_ERR_RB_REMOVE             (0x02)
#define PICO_IGMP2_ERR_STRUCT_UNAVAILABLE    (0x03)
#define PICO_IGMP2_ERR_UNKOWN_PARAM          (0x04)
#define PICO_IGMP2_ERR_WRONG_CHECKSUM        (0x05) 
#define PICO_IGMP2_ERR_ACTION1_FAILED        (0x11) 
#define PICO_IGMP2_ERR_ACTION2_FAILED        (0x12) 
#define PICO_IGMP2_ERR_ACTION3_FAILED        (0x13) 
#define PICO_IGMP2_ERR_ACTION4_FAILED        (0x14) 
#define PICO_IGMP2_ERR_ACTION5_FAILED        (0x15) 
#define PICO_IGMP2_ERR_ACTION6_FAILED        (0x16) 
#define PICO_IGMP2_ERR_ACTION7_FAILED        (0x17) 
#define PICO_IGMP2_ERR_UNCONN_GROUP          (0x20) 
#define PICO_IGMP2_ERR_GROUP_CONNECTED       (0x21) 

int pico_igmp2_join_group(struct pico_ip4 *group_address, struct pico_ipv4_link *link);
int pico_igmp2_leave_group(struct pico_ip4 *group_address, struct pico_ipv4_link *link);

#endif /* _INCLUDE_PICO_IGMP2 */
